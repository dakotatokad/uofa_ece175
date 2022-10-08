//
//  main.c
//  hw1p1
//
//  Created by dakotatokad on 1/20/15.
//

//   To determine the Temperature of a freezer after t hours since power failure.  Inputs: Time.  Outputs: Temperature.  Time is used in formula to determine the temperature.

#include <stdio.h>
#include <math.h>


int main(void) {
    
    float TimeMin          = 0.00;
    float TimeHour         = 0.00;
    float TimeTotalH       = 0.00;
    float Temperature      = 0.00;
    
    printf("Please enter the amount of hours since power failure.\n");
    scanf(" %f", &TimeHour);
    
    printf("Please enter the amount of minutes since power failure.\n");
    scanf(" %f", &TimeMin);
    
    TimeMin = TimeMin / 60;  //converts minutes to an hour decimal
    
    TimeTotalH = TimeHour + TimeMin; //combines time in hours and minutes
    
    Temperature = ((4 * pow(TimeTotalH, 2.00)) / (TimeTotalH + 2)) - 20;  //calculates temperature from equation
    
    printf("The Temperature is around %.2f degrees celcius after %.2f hours.\n", Temperature, TimeTotalH);
    
    return 0;
}

//Code works - 6 Test Cases Work
