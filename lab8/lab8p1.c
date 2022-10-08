//
//  main.c
//  Lab8p1
//
//  Created by dakotatokad on 3/26/15.
//

#include <stdio.h>

void magic_square_test(int magicsquare[6][6]);

int main(void) {
    
    FILE *array;
    int magicsquare[6][6];
    int i = 0, j;
    int sum_row = 0, test_row = 0;
    int sum_column = 0, test_column = 0;
    int sum_diag = 0, test_diag = 0;
    int magictest = 0;
    
    array = fopen("array.txt", "r");
    
    for(j = 0; j < 6; ++j) {  // READ ARRAY - GOOD
        for(i = 0; i < 6; ++i) {
            fscanf(array, "%d", &magicsquare[j][i]);
        }
    }
    
    
    for(j = 0; j < 6; ++j) {  // Rows
        if (sum_row == test_row) {
            sum_row = 0;
            for(i = 0; i < 6; ++i) {
                sum_row += magicsquare[j][i];
            }
            test_row = sum_row;
        }
        else {
            printf("No Dice R.\n");
            magictest = 1;
            break;
        }
    }
    
    for(j = 0; j < 6; ++j) {  // Columns
        if (sum_column == test_column) {
            sum_column = 0;
            for(i = 0; i < 6; ++i) {
                sum_column += magicsquare[i][j];
            }
            test_column = sum_column;
        }
        else {
            printf("No Dice C.\n");
            magictest = 1;
            break;
        }
    }
    
    for(i = 0; i < 6; ++i) {  // Diags
                sum_diag += magicsquare[i][i];
    }
    i = 0;
    for(i = 0; i < 6; ++i) {
                test_diag += magicsquare[i][5-i];
    }
    
        if (sum_diag == test_diag) {
        }
        else {
            printf("No Dice D.\n");
            magictest = 1;
        }
    
    
    if(magictest == 1) {
        printf("Not a magic square.\n");
    }
    else {
        printf("ITS MAGIC\n# %d\n", test_row);
    }
    
    
    return 0;
}
