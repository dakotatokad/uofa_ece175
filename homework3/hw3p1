//
//  main.c
//  hw3p1
//
//  Created by dakotatokad on 2/4/15.
//

//  Calculates the half life of yttrium-90 with a half life period of 2 days.  Safe level is less than or equal to .90 millirems.
//  Inputs: Initial Radiation in millirems, Days to calculate radiation for.
//  Outputs: Day, Radiation, Safety.
//  Days control amount of outputs, initial half life is reduced for each iteration and determines whether system prints "safe" or "unsafe".

#include <stdio.h>
#define _CRT_Secure_No_Warnings

int main() {
    
    float rads      = 0.00;
    int days        = 0;
    int i           = 0;
    
    // Safe <= .90 Millirems
    
    printf("Enter the initial amount of radiation in millirems: ");
    scanf_s("%f", &rads);  // Requests initial radiation
    
    if(rads >= .90) {  // If rads are unsafe, continue program
        printf("Enter a total days to display: ");
        scanf_s("%d", &days);  // Requests days to calculate
        if(days / 2 != 0) { // If days are odd, will add 1 day to create even value
            days = days + 1;
        }
        printf("\n");
        printf("Day\t Radiation\t Status\n");
        if(rads >= 10) {  // Output Formatting
            printf("%d\t %.4f", i, rads);  // Prints original value
            printf("\t(Unsafe)\n");
        }
        else { // Output Formatting
            printf("%d\t %.4f", i, rads);
            printf("\t\t(Unsafe)\n");
        }
    }
    else {  // If rads are safe, stop program and display message
        printf("The value entered is under .90 millirems.  The area is safe.\n");
        return(0);
    }
   
    
    i = 2;  // Resets i to day 2 to begin cycle
    
    while(i <= days) {
        rads = (rads / 2);  // Calculates radiation after half life
        if(rads <= .90) {
            printf("%d\t %.4f", i, rads);
            printf("\t\t(Safe)\n");
        }
        else if(rads >= 10) {  // Output Formatting
            printf("%d\t %.4f", i, rads);
            printf("\t(Unsafe)\n");
        }
        else {  // Output Formatting
            printf("%d\t %.4f", i, rads);
            printf("\t\t(Unsafe)\n");
        }
        i = i + 2;  // Itterates days by 2
        
    }
    
    
    printf("\n");
    
    return 0;
}
