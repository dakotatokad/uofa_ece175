//
//  main.c
//  hw3p2
//
//  Created by dakotatokadd on 2/4/15.
//

//  Takes user set of inputs for C and X and calculates the root of the polynomial and if it converges.  
//  Inputs: 6 C values, X starting value
//  Outputs: Convergence, Roots

#include <stdio.h>
#include <math.h>

int main() {
    
    double c1      = 0;
    double c2      = 0;
    double c3      = 0;
    double c4      = 0;
    double c5      = 0;
    double c0      = 0;
    double xorin   = 0;
    double x       = 0;
    double y       = 0;
    double yprime  = 0;
    int i          = 0;
    
    
    printf("This program is to find one root of 5th-order polynomials using Newton-Rhapson method.\ny = C5x^5 + C4x^4 + C3x^3 + C2x^2 + C1x + C0\n");
    
    printf("Please enter the coefficients in the form C5,C4,C3,C2,C1,C0 : ");
    scanf("%lf,%lf,%lf,%lf,%lf,%lf", &c5, &c4, &c3, &c2, &c1, &c0);
    // Comments for 0,0,1,-3,-760,-1500 and x=0
    
    printf("Please enter an intitial X value: ");
    scanf("%lf", &xorin);
    
    printf("\n");
    
    x = xorin;  // Assigns x and keeps xorin for later
    
    while (i <= 500) {
    
    y = (c5 *  pow(x, 5)) + (c4 * pow(x, 4)) + (c3 * pow(x, 3)) + (c2 * pow(x, 2)) + (c1 * pow(x, 1) + c0); // GOOD I1
    //printf("\n%f\n", y);  //-1500
        
        if(fabs(y) <= 0.00000001) {
            printf("Algorithm has converged with y = %.4lf\nYour initial guess for X: %.4lf\n", y, xorin);
            printf("Your polynomial is: y = %.2lfx^5 + %.2lfx^4 + %.2lfx^3 + %.2lfx^2 + %.2lfx + %.2lf\n", c5, c4, c3, c2, c1, c0);
            printf("One of the roots of this polynomial is: %.4lf.\nIt takes %d iterations to obtain this answer.\n", x, i);
            return(0);
        }
        
        else {
            yprime = (5 * c5 * pow(x, 4)) + (4 * c4 * pow(x, 3)) + (3 * c3 * pow(x, 2)) + (2 * c2 * x) + c1; // GOOD I1
                // If program doesnt converge, calculate y' and create new x value
               //printf("%f", yprime); //-760
        
        if(yprime == 0) {
            printf("\ny' can not equal zero.  Shifting X value.\n");
            x = x + 25;  // If y' = 0, add x values to continue program
        }
            
        x = x - (y / yprime);  // GOOD I1
            
        //printf("%f", x); // -1.97
            
        } // Else statement

    ++i;
        
    } // While loop
    
    
    printf("Error.  Program failed with %d iterations.  Roots of the function may be complex.\n", i);

    
    
        return 0;
}
