//
//  main.c
//  LabPracticleP2
//
//  Created by dakotatokad on 2/26/15.
//
//  This really makes me thankful for <math.h>

#include <stdio.h>

double return_rads (double theta);
double long power(double long rads, int ii);
double factorial(int ii);
double taylorseries(double p, double f);

int main(void) {
    
    double theta = 0;
    double long rads;
    int ii;
    double long p;
    double f;
    double cos = 0.0;
    int count;
    double sum;
    double long endgame;
  
    
    printf("Enter a value for theta: ");
    scanf(" %lf", &theta);
    
    while(theta > 180 || theta < -180) {
        if(theta > 180) {
            theta = theta - 360;
        }
        if(theta < -180) {
            theta = theta + 360;
        }
    }
    
    //User enters theta, program changes theta within +-180
    
    rads = return_rads (theta); // Calls function to change degrees to radians
    //printf("%Lf\n", rads);
    
    count = 1;  // Sets counter
    sum = 0;  // Sets sum to 0
    
    for(ii = 2; ii <= 20; ii = ii + 2) {  // Tallys the "value" of the square and factorial
        if (count % 2 == 0) {  // if computation is the "2nd" of the taylor series will add values to the running sum
            p = power(rads, ii);
            f = factorial(ii);
            cos = taylorseries(p, f);
            sum = sum + cos;
        }
        else {  // if computation is "1st" of taylor series will subtract value
            p = power(rads, ii);  // determines power of numerator theta
            f = factorial(ii);   // determines factorial of  denominator 
            cos = taylorseries(p, f);  // divides power by factorial
            sum = sum - cos;
        }
        ++count;  // advances count
    }
    
    //printf("%lf\n", p);
    //printf("%lf\n", f);
    
    endgame = 1 + sum;  // compensates for the reversing the +, - order earlier but i'm really tired so i don't feel like changing it and this is really just the same thing
    
    printf("Cos(%Lf) = %Lf\n", rads, endgame);  // prints radians by user and engame amount of series
    
    return 0;
}

double return_rads (double theta) {
    
    double rads;
    double M_PI = 3.14159265358979;
    
    rads = theta * (M_PI / 180.00);
    
    return rads;
}  // GOOD

double taylorseries(double p, double f) {
    
    double cos;
    
    cos = (p / f);
    
    return cos;
}

double long power(double long rads, int ii) {
    
    
    double long p = rads;
    int i;
    
    for(i = 1; i<ii; i = 1 + i) {
        (p *= rads);
    }
    
    return(p);
}

double factorial(int ii) {
    double f = 1.0;
    int i;
    
    for(i = 1; i <= ii; i = i + 1) {  // Will give true 20!
        (f *= i);
    }
    
   
    return(f);
}