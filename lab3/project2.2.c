//
//  main.c
//  lab3p3.2
//
//  Created by dakotatokad on 2/5/15.
//

#include <stdio.h>
#include <math.h>

int main() {
    
    int x       = -1;
    int m       = 0;
    
    while(x < 0) {
    
    printf("Please enter a positive value for X: ");
    scanf("%d", &x);
    //x = fabs(x);
    
    }
    
    while( x != 0) {
        
        
        
        m = x % 2;
        
        if( m == 1) {
            printf("1");
        }
        else {
            printf("0");
        }
        
        x = (x - m) / 2;
    }
    
    printf("\n");
    return 0;
}
