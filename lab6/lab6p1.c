//
//  main.c
//  lab6p1
//
//  Created by dakotatokad on 3/5/15.
//

#include <stdio.h>

int main(void) {
    
    int i, op = 0;
    float sum;
    int array[12];
    
    printf("Enter 12 integers to be stored to array seperated by a space.  Press enter when finished: ");
    
    i = 0;
    sum = 0;
    
    for(i = 0; i < 12; ++i) {
        scanf("%d", &array[i]);
    }
    for(i = 0; i < 12; ++i) {
        sum = sum + array[i];
    }
    sum = sum / 12;
    
    printf("The average of these points are: %.2f\n", sum);
    
    for(i = 11; i >= 0; --i) {
        printf("%d ", array[i]);
    }
    printf("\n");
    
    for(i = 0; i < 12; ++i) {
            if(array [i] == array[11 - i]) {
                op = 1;
            }
            else {
                op = 2;
            }
    }
    
    switch(op) {
        case 1:
    printf("The array is symmetric.\n");
            break;
        case 2:
    printf("The array is not symmetric.\n");
            break;
    }
    
    
    return 0;
}
