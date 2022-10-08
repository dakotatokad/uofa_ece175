//
//  main.c
//  PracticeExamP2
//
//  Created by dakotatokad on 2/17/15.
//

#include <stdio.h>
#include <stdlib.h>

void coins(float Initial);

int main(void) {
    
    float sum = 0;
    float amount = 0;
    FILE *expenses;
    
    expenses = fopen("expenses.txt", "r");
    
    if(expenses == NULL) {
        printf("File Not Found");
        return -1;
    }
    
    while(fscanf(expenses, "%f", &amount) != EOF) {
        sum = sum + amount;
    }
   
    coins(sum);
    
    fclose(expeneses);
    
    return 0;
}

void coins(float Initial) {
    const int dollar$    = 100.0;
    const int quarter$    = 25.0;
    const int dime$       = 10.0;
    const int nickel$     = 5.0;
    int amount = 0;
    int dollar, quarter, dime, nickel, penny        = 0;
    int pquarters = 0;
    int pdime = 0;
    int pnickel = 0;
    int ppenny = 0;
    
    amount = Initial * 100;
    
    dollar = amount / dollar$;
    pquarters = amount % dollar$;
    quarter = pquarters / quarter$;
    pdime = pquarters % quarter$;
    dime = pdime / dime$;
    pnickel = pdime % dime$;
    nickel = pnickel / nickel$;
    ppenny = pnickel % nickel$;
    penny = ppenny;
    
    printf("%d Dollars, %d Quarters, %d Dimes, %d Nickels, %d Pennies.\n", dollar, quarter, dime, nickel, penny);
    
    return;

}

