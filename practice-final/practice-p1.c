//
//  main.c
//  PracticeExamP1
//
//  Created by dakotatokad on 2/16/15.
//

#include <stdio.h>
#include <math.h>

void amountChange(float Paid, float Due);

int main(void) {
   
    float amntPaid          = 0;
    float amntDue           = 0;
    char contconfirm        = 'q';
    
    do {
    printf("Enter Amount Paid: ");
    scanf("%f", &amntPaid);
    
    printf("Enter Amount Due: ");
    scanf("%f", &amntDue);
        
        printf("\n");
        
    amountChange(amntPaid, amntDue);
        
    printf("\nPress any key to continue or press \"q\" to quit.\n");
    scanf(" %c", &contconfirm);
    
    } while (contconfirm != 'q');
    
    return 0;
}

void amountChange(float Paid, float Due) {
    const int dollar$     = 100.0;
    const int quarter$    = 25.0;
    const int dime$       = 10.0;
    const int nickel$     = 5.0;
    float change          = 0;
    int changeint         = 0;
    float dollar, quarter, dime, nickel, penny        = 0;
    int pquarters     = 0;
    int pdime         = 0;
    int pnickel       = 0;
    int ppenny        = 0;
    
    
    if(Paid == Due) {
        printf("You have paid the correct amount.");
        return;
    }
    else if(Paid < Due) {
        printf("You have underpaid you fucker.");
        return;
    }
    
    change = Paid - Due;  // calculates change
    
    changeint = change * 100;  // changes dollars to cents
    
    dollar = changeint / dollar$;
    pquarters = changeint % dollar$;
    quarter = pquarters / quarter$;
    pdime = pquarters % quarter$;
    dime = pdime / dime$;
    pnickel = pdime % dime$;
    nickel = pnickel / nickel$;
    ppenny = pnickel % nickel$;
    penny = ppenny;
    
    printf("Amount Paid: %.2f\nAmount Due: %.2f\n\nThe amount of change is:\nDollars: %f\nQuarters: %f\nDimes: %f\nNickels: %f\nPennies: %f\n", Paid, Due, dollar, quarter, dime, nickel, penny);
    
    return;
}