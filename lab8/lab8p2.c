//
//  main.c
//  Lab8p2
//
//  Created by dakotatokad on 3/26/15.
//

#include <stdio.h>
#define SWAP 1
#define NO_SWAP 0
#define MAX_LINE 100
#define MAX_LEN 1000

void swap(int *a, int *s);
void bubblesort(int x[], int size, int indexArray[]);

int main(void) {
    
    FILE *quotations;
    char string[MAX_LINE][MAX_LEN];
    int sort[MAX_LINE], sort_index[MAX_LINE];
    int line = 0;
    int i, j, k;
    
    quotations = fopen("Quotations.txt", "r");
    if(quotations == NULL) {
        printf("Error.");
        return 0;
    }
        
        line = 0;
        do {
            sort_index[line] = line;
            fgets(string[line], MAX_LEN, quotations);
            line = line + 1;
        } while(!feof(quotations));
    
    
    for(j = 0; j < MAX_LINE; ++j){  // Changes letters to numbers
        for (k = 0; k < MAX_LEN; ++k) {
            if(string[j][k] >= 65) {
                sort[j] = string[j][k];
                if(sort[j] <= 122 && sort[j] >= 97) {
                    sort[j] = sort[j] - 32;
                } // IF 122
                break;
            } // If 65
        } // for K
    } // for J
    
    for(j = 0; j < MAX_LINE; ++j) {
        sort_index[j] = j;
    }
    
    
    bubblesort(sort, line, sort_index);

    j = 0;
    
    for(i = 0; i < line; ++i)
    printf("%s", string[sort_index[i]]);
    printf("\n");
    
    
    // filled the sort array which first letter in each row
    // sort sort array and also sort index using sort array
    // print string using the indexes of sort index
    return 0;
}

void swap(int *a, int *b) {
    int temp = *a;
    
    
    *a = *b;
    *b = temp;
    return;
}

void bubblesort(int x[], int size, int indexArray[]) {
    int i, flag = SWAP;
    
    while(flag == SWAP) {
        flag = NO_SWAP;
        for(i = 0; i < size -1; ++i) {
            if(x[i] < x[i + 1]){
                swap(&x[i], &x[i+1]);
                swap(&indexArray[i], &indexArray[i+1]);
                flag = SWAP;
            }
        }
    }
    
}



// Fill array SORT with first letter of matrix columns
// Match Sort position to Sort Index position
// Use bubble sort
    // Array X = Sort
// Use Sort Index to print from original array
