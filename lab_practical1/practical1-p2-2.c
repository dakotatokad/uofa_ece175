//
//  main.c
//  LabPracticleP2.2
//
//  Created by dakotatokad on 2/26/15.
//

#include <stdio.h>

double return_rads (double theta);
double power(double rads);
double factorial(int ii);
double taylorseries(double p, double f);

int main(void) {
    
    double theta = 0;
    double rads;
    int ii = 20;
    double p;
    double f;
    double cos;
    
    do {
        printf("Enter a value for theta: ");
        scanf(" %lf", &theta);
    } while (theta > 180.00 || theta < -180.00);
    
    rads = return_rads (theta);
    
    power(rads);

    
    return 0;
}

double return_rads (double theta) {
    
    double rads;
    double M_PI = 3.14159265358979;
    
    rads = theta * (M_PI / 180.00);
    
    return rads;
}  // GOOD

double power(double rads) {
    
    int i = 2;
    int pow = 1;
    
    while(pow <= 40) {
        rads = rads * rads;
        ++pow;
        
    }
}