//
//  main.c
//  hw2p2
//
//  Created by dakotatokad on 1/27/15.
//

//  By using a user entered measurment value program will display the currect running average value and cycle back through the process 10 times.
//  Inputs: User measurement
//  Outputs: Runner average, Iteration
//  User measurement is used to calculate runners average based on the iteration

#include <stdio.h>

int main(void) {
    
    float measure   = 0.00;
    float runavg    = 0.00;
    int i           = 0;
    
    i = 0;
    runavg = 0;
    
    while( i < 10) {  // Loops while i < 10
        printf("Please enter a measurment value.\n");
        scanf(" %f", &measure);  // Scans for user input
        runavg = ((i * runavg) + measure) / (i + 1);  //  Determines the runners average using input and equation
        printf("The average for iteration %d is %.2f\n", i + 1, runavg);  //  Displays the interation and current running average
        ++i;  //  Cycles i +1
    }
    
    printf("Thank you.\n");
    
    
    return 0;
}
