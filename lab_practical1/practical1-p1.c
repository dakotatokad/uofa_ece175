//
//  main.c
//  LabPracticleP1
//
//  Created by dakotatokad on 2/26/15.
//

//Count amount of numbers
//Count even numbers
//Calculate product divisible by 9

#include <stdio.h>

int main(void) {
    
    int number;
    int tot = 0;
    int eve = 0;
    int sum = 1;
    FILE *input;
    
    
    input = fopen("input.txt", "r");  // Opens file for reading - file must exist
    
    while(fscanf(input, "%d", &number) != EOF) {  // Scanfs for int until EOF
        
        tot = tot + 1; // Totals "scans"
        
        if(number % 2 == 0) { // If divisable by 2 total even numbers
            eve = eve + 1;
        }
        
        if(number % 9 == 0) {
            sum = sum * number;  // If divisable by 9 multiple the numbers by the sum so far
        }
        
    }
    
    printf("Total Data Points: %d\nAmount of Even Numbers: %d\nProduct of Numbers Divisible by 9: %d\n", tot, eve, sum);

    return 0;
}
