//
//  main.c
//  Midterm2P2
//
//  Created by dakotatokad on 4/2/15.
//

#include <stdio.h>
#include <string.h>
#define SIZE 200

int main(void) {
    
    FILE *input;
    char fname[SIZE];
    char search[SIZE];
    char word[SIZE] = {'\0'};
    int count=0, line = 0;
    float userlength =0;
    char newline = '\n';
 
    
    printf("Enter a file name: ");
    gets(fname);
    input = fopen(fname, "r");
    // Gettysberg.txt
    
    if(input == NULL) {
        printf("Error.  File not found or Search Mispelled.\n");
    return 0;
    }
    
    fflush(stdin);
    
    printf("Enter in the string you would like to search for:\n");
    gets(search);
    userlength = strlen(search);
    
    printf("\nSearching ");
    fputs(fname, stdout);
    printf("\n\n");
    
    
    
    if(userlength > 1) {
        
        while(fscanf(input, "%s", word) != EOF) {
            if(strcmp(word, search) == 0) {
                count += 1;
            }
            if(strcmp(word, &newline) == 0)
                line +=1;
    }
        if (count > 0) {
            printf("Found \"%s\" on line %d: The line is: %s", search, line, search);
        }
    }
    else {
        while(fscanf(input, "%c", word) != EOF) {
            if(strcmp(word, search) == 0) {
                count += 1;
            }
        }
        if (count > 0) {
            printf("Found \"%s\" on line %d: The line is: %s\n", search, line, search);
        }
    }
    
   
    
    
    printf("\nThe string \"");
    fputs(search, stdout);
    printf("\" was found %d time(s) in the file ", count);
    fputs(fname, stdout);
    printf("\n");
   
    
    
    
    return 0;
}
