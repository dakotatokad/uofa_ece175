//
//  main.c
//  practice exam tests
//
//  Created by dakotatokad on 2/23/15.
//

#include <stdio.h>

double changer(double i, double j) {
    int k;
    
    k = i / j;
    
    return (k);
}

int main(void) {
    
//    int i,j;
//    int h = 4;
//    
//    for (i = 1; i <= h; ++i) {
//        for(j = 1; j <= i - 1; ++j)
//            printf(" ");
//        for(j = 1; j <= h - i + 1; ++j)
//            printf("%d ", j);
//        printf("\n");
//    }
   
    
    int j = 4, i = 5, k = 10, l = 0;
    
    k = changer(i, j);
    l = changer(j, i);
    printf("%d %d\n", k, l);
    
    return 0;
}
