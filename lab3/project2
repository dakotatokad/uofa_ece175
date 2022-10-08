//
//  main.c
//  lab3p2
//
//  Created by dakotatokad on 2/5/15.
//

#include <stdio.h>
#include <math.h>

int main() {
    
    int x, c, k       = 0;
    
    
    printf("Please enter a positive integer: ");
    scanf("%d", &x);
    x = fabs(x);
    
    printf("%d in binary is: ", x);
    
    for (c = 31; c >= 0; c--)
    {
        k = x >> c;
        
        if (k & 1)
            printf("1");
        else
            printf("0");
    }
    
    printf("\n");

   
    return 0;
}
