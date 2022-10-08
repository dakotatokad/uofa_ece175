//
//  main.c
//  PracticeExamP3
//
//  Created by dakotatokad on 2/17/15.
//

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int term(int x);

int main(void) {
    
    int x = 0;
    
    printf("Enter a value for X: ");
    scanf("%d", &x);
   
    term(x);
    
    return 0;
}


int term(int x) {
    int intA = 0;
    int num = 0;
    int sum = 0;
    int i = 0;
    FILE *Coef;
    
    Coef = fopen("Coef.txt", "r");
    
    if(Coef == NULL) {
        printf("Error: Could not open file.");
        return -1;
    }
    
    while(fscanf(Coef, "%d", &intA) != EOF) {
        num = intA * pow(x, i);
        sum = sum + num;
        ++i;
    }
    
    printf("P(%d) = %d\n", x, sum);
    
    fclose(Coef);
    
    return 0;
}