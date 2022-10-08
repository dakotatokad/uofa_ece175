//
//  main.c
//  lab9P1
//
//  Created by dakotatokad on 4/9/15.
//

#include <stdio.h>
#include <string.h>
#include <ctype.h>
#define STR_SIZE 30

typedef struct {
    char name[STR_SIZE];
    char address[STR_SIZE];
    char city[STR_SIZE];
    char state[3];
    int zipcode;
    double amount;
} donor_t;

void scan_donor(donor_t *x, FILE *inFile);

int main(void) {
    
    int i, j;
    double donation_total= 0;
    char searchfield[STR_SIZE];
    char nameUPPER[STR_SIZE];
    char continues = 'a';
  
    FILE *inFile;
    inFile = fopen("Input.txt", "r");
    
    donor_t users[12];
    
    for (i = 0; i < 12; i++) {
        scan_donor(&users[i], inFile);
        donation_total += users[i].amount;
    }
    
    printf("Current Users:\n\n");
    for(i = 0; i < 12; i++)
        printf("%s", users[i].name);
    
    printf("\nTotal Donations: $%.2lf\n", donation_total);
    
    do {  ///////
    
    printf("Enter a name for information: ");
    fgets(searchfield, STR_SIZE, stdin);

    
    for(i = 0; i < 12; i++) {
        strcpy(nameUPPER, users[i].name);
        
        for(j = 0; j < STR_SIZE; j++) {
        nameUPPER[j] = toupper(nameUPPER[j]);
        searchfield[j] = toupper(searchfield[j]);
        }
        
    if(strstr(searchfield, nameUPPER) != NULL) {
        printf("Found.\n");
        printf("%s", users[i].name);
        printf("%s", users[i].address);
        printf("%s", users[i].city);
        printf("%s", users[i].state);
        printf("\n%d\n", users[i].zipcode);
        printf("Amount: %.2lf", users[i].amount);
        printf("\n");
        break;
    }
    else {
        if(i == 11) {
            printf("%s not found.\n", searchfield);
            break;
        }
    }

    } //For
    
        
        printf("Do you want to continue? (Q to quit): ");
        fgets(&continues, 3, stdin);
        continues = toupper(continues);
        
    } while(continues != 'Q');
    
    printf("Goodbye.\n");
    
    return 0;
}

void scan_donor(donor_t *x, FILE *inFile) {
    char temp;
    
    fgets(x->name, STR_SIZE, inFile);
    fgets(x->address, STR_SIZE, inFile);
    fgets(x->city, STR_SIZE, inFile);
    fscanf(inFile, "%s", x->state);
    fscanf(inFile, "%d%lf", &x->zipcode, &x->amount);
    fscanf(inFile, "%c", &temp);
    
    return;
}