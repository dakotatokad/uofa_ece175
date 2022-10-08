//
//  main.c
//  hw6p1
//
//  Created by dakotatokad on 3/5/15.
//
// Inputs: Initial loan amnt, Monthly patment, APR
// Outputs: Loan amount, APR, Monthly payment, time, $$ owed, $$ payed
// Calulates payments over time based on initial values

#include <stdio.h>
#include <math.h>

int main(void) {
    
    double amntOwed[12600] = {0};  // Initiallize arrays to 35 years in days with values 0
    double amntPayed[12600] = {0};
    double time[12600] = {0};
    double initialLoan;
    double APR;
    double monthlyPay;
    double r, todayspayment = 0.0;
    int i, day;
    
    printf("Enter the total loan amount: ");
    scanf("%lf", &initialLoan);
    printf("Enter the Annual Percentage Rate (APR): ");
    scanf("%lf", &APR);
    printf("Enter the monthly payment amount: ");
    scanf("%lf", &monthlyPay);
    
    r = APR/(100 * 365.242);  // Calulates decimal value of APR
    
    amntOwed[0] = initialLoan; // Sets initial loan to the element 0 of array owed
    amntPayed[0] = 0;          // Sets element 0 of array payed to 0
    day = 1;                  // Starts days at 1
    
    for(i = 1; i <= 12600; ++i) {  // Will loop to max of arrays
        
        
        if (day == 30) {  // If 30 days (1 month) passes todays payment is now the montly pay
            todayspayment = monthlyPay;
            day = 1;  // Resets day to 1
        }
        else {
            todayspayment = 0;  // During month no payment
            ++day;
        }
        
        time[i] = i / 365.242;  // updates time array
        
        amntOwed[i] = amntOwed[i - 1] * exp((r * 1)) - todayspayment;  // updates the amnt owned array
        
        amntPayed[i] = amntPayed[i - 1] + todayspayment;  // updates payment array
        
        if (amntOwed[i] <= 0) {  // if owned array is less than zero loop will break off, payment fulfilled
            break;
        }
    }
    
    printf("\n\nTotal loan amount = $%.2lf\n", initialLoan);  // Displays printout
    printf("APR: %% %.2lf\n", APR);
    printf("Monthly payment amount = $%.2lf\n", monthlyPay);
    printf("After %.3lf years you will owe $%.2lf and the total payment will be $%.2lf\n", time[i], amntOwed[i], amntPayed[i]);
    
    
    
 
    return 0;
}
