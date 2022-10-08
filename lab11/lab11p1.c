//
//  main.c
//  Lab11
//
//  Created by dakotatokad on 4/30/15.
//

#include <stdio.h>

void int2bin(int x) {
    if(x == 0 || x == 1) {
        printf("%d", x);
    }
    else {
        int2bin(x/2);
        printf("%d", x%2);
    }
}

int main(void) {
    int x = -1;
    
    do {
    printf("Enter a positive integer: ");
        scanf("%d", &x);
    } while(x < 0);
    
    int2bin(x);
    
    printf("\n");
    
    return 0;
}
