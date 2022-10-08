//
//  main.c
//  problem2
//
//  Created by dakotatokad on 4/30/15.
//

#include <stdio.h>

int collatz(int a) {

    
    if(a == 1) {
        printf("%d ", a);
        a = 1;
    }
    
    else if(a % 2 == 0) {
        printf("%d ", a);
        a = a / 2;
        collatz(a);
    }
    else {
        printf("%d ", a);
        a = ((3 * a) + 1);
        collatz(a);
    }
    
    return 1;
}

int main(void) {
    
    int a;
    
    do {
        printf("Enter a starting number (postive integer): ");
        scanf("%d", &a);
    } while( a <= 0);
    
    printf("The sequence is: ");
    
    a = collatz(a);
    
    printf("\nIt eventually reaches %d!\n", a);
    
    
    return 0;
}
