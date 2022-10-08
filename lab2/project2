//
//  main.c
//  project 2
//
//  Created by dakotatokad on 1/29/15.
//

#include <stdio.h>
#include <math.h>

int main(void) {
    
    double Degrees           = 0.00;
    double Radians           = 0.00;
    double initialVel        = 0.00;
    double distanceF         = 0.00;
    double time              = 0.00;
    const double g           = 9.81;
    
    
    
    printf("Hello.\n");
    printf("Please enter an angle of elevation in degrees.\n");
    scanf(" %lf", &Degrees);
    
    if(Degrees <= 90 && Degrees > 0) {
        
        printf("Please enter a positive inital velocity in meters/second.\n");
        scanf(" %lf", &initialVel);
        
        if(initialVel > 0) {
        
            Radians = Degrees * (M_PI/180);  //GOOD
            //printf("Angle: %f\n", Radians);
            
            distanceF = ((pow(initialVel, 2.00)) * sin(2 * Radians))/ g; //GOOD
            //printf("Distance: %lf\n", distanceF);
            
            time = fabs(distanceF / (initialVel * cos(Radians))); //GOOD
            
            printf("The horizontal distance is %.3lf meters and the time of flight is %.2lf seconds.\n", distanceF, time);
        }
        
        else {
            printf("Error: The velocity needs to be greater than zero.\n");
        return 0;
        }
        
    } // if degrees
    
    else {
        printf("Error: The angle needs to be within 0 and 90 degrees.\n");
    }
    
    
    
    
    return 0;
}
