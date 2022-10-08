//
//  main.c
//  lab4p1
//
//  Created by dakotatokad on 2/12/15.
//

#include <stdio.h>
#include <math.h>

/* int main(void) {

    int i           = 100;
    int sum         = 0;
    int n           = 0;
    
    
    do {
        printf("\n");
    printf("To find the sum of number from 100-250 that are divisible by 'n'\nEnter a value for n (from 1-10): ");
    scanf(" %d", &n);
    
    } while( n < 0 || n > 10);

    
    while (i <= 250) {
        if(i % n == 0) {
            sum = sum + i;
        }
    ++i;
}
    
    printf("The sum of numbers 1-150 divisible by %d is %d\n", n, sum);

    
    return 0;
} */


// Pass by pointer test

//#include <stdio.h>
//void CoordTransform(int xValNew, int yValNew, int* xVal, int* yVal) {
//    
//    *xVal = (xValNew + 1) * 2;
//    *yVal = (yValNew + 1) * 2;
//    
//    return;
//}
//
//int main(void) {
//    int xValNew = 0;
//    int yValNew = 0;
//    
//    CoordTransform(3, 0, &xValNew, &yValNew);
//    printf("(3, 4) becomes (%d, %d)\n", xValNew, yValNew);
//    
//    return 0;
//}


int main(void) {
    float x = 7.6;
    float negx = -7.6;
    float y = 2.3;
    float negy = -2.3;
    
    printf("Ceil: %2.f  Floor: %-4.f\n", ceil(x), floor(x));
    printf("Ceil: %-2.f  Floor: %4.f\n", ceil(negx), floor(negx));
    printf("Ceil: %2.f  Floor: %-4.f\n", ceil(y), floor(y));
    printf("Ceil: %-2.f  Floor: %4.f\n", ceil(negy), floor(negy));
    
    return 0;
}
