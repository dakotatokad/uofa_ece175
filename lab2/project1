//
//  main.c
//  Project 1
//
//  Created by dakotatokad on 1/29/15.
//

#include <stdio.h>

int main(void) {
    
    float x1      = 0.00;
    float x2      = 0.00;
    float y1      = 0.00;
    float y2      = 0.00;
    float m       = 0.00;
    float userx   = 0.00;
    float y       = 0.00;
    float b       = 0.00;
    char scan     = 'A';
    
    
    
   
        
    printf("Helllo.\n");
    
    while(scan != 'Z') {  //scans end for exit or iteration
        
    printf("Please enter an X1 coordinate followed by an Y1 coordinate seperated by a space.\n");
        scanf(" %f %f", &x1, &y1);
    printf("Thank you, now please enter an X2 coordinate followed by a Y2 coordinate seperated by a space.\n");
        scanf(" %f %f", &x2, &y2);
    
    
    m = (y2 - y1)/(x2 - x1);
    
    if( x2 != x1) {
    
        printf("Please enter an X value.\n");
            scanf(" %f", &userx);
        
        b = y1 - (m * x1);
        
        y = m * userx + b;
        
        printf("The expected output is: %.2f.\n", y);
            
    }
    else {
        printf("Error, you can not divide by 0.\n");
    }
        printf("Helllo.  Enter 'Z' to exit or any key to continue.\n");
        scanf(" %c", &scan);
        
       
    
    } //while scan
    
    printf("Goodbye.\n");
    
   
    return 0;
}
