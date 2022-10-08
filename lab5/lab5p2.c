//
//  main.c
//  Lab5P2
//
//  Created by dakotatokad on 2/19/15.
//

#include <stdio.h>
#include <math.h>

double flow_water(double RealDeapth);

double RealWidth = 15;
double Slope = .0015;
double N  = .014;

int main(void) {
    
    double DepthGuess       = 5.0;
    double Target_Flow      = 0.0;
    double Error            = 0.0;
    double Diff             = 0.0;
    double Q                = 0.0;
    
    printf("Enter a target flow: ");
    scanf("%lf", &Target_Flow);
    
    Q = flow_water(DepthGuess);
    
    printf("At Depth %.3lf feet the flow is %lf cu. ft/sec.\n", DepthGuess, Q);
    
    do {
    printf("Enter your guess the depth: ");
    scanf(" %lf", &DepthGuess);
    
    Q = flow_water(DepthGuess);
    
    Error = ((Target_Flow - Q)/(Target_Flow)) * 100;
        
    Diff = (Target_Flow - Q);
        
    printf("\nAt depth: %.3lf\nFlow: %.4lf cfs\nTarget: %.3lf\nDifference: %+.3lf\n\nError: %lf\n\n", DepthGuess, Q, Target_Flow, Diff, Error);
        
    } while( fabs(Error) >= .1);
        
    printf("Within .1%% Error.\nYay.\n");
    
    return 0;
}

double flow_water(double DepthGuess) {
    double Q = 0.0;
    double R = 0.0;
    
    R = (DepthGuess * RealWidth)/(2.0 * DepthGuess + RealWidth);
    Q = (1.486 / N) * sqrt(Slope) * (RealWidth * DepthGuess) * pow(R, 2.00/3);
    return Q;
}

