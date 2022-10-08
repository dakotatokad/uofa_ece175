//
//  main.c
//  hw1p2
//
//  Created by dakotatokad on 1/20/15.
//

//To determine the cost of an open top cylindrical container by radius and height.  Inputs: Hight, Radius, Cost per square centimeter, Number of containers.  Outputs: One container surface area, cost of one container, total cost of all container.
// Circle Area = pi * r^2

#include <stdio.h>
#include <math.h>


int main(void) {
   
    const double pi         = 3.14159265358979323846;
    float Height            = 0.00;
    float Radius            = 0.00;
    float CostperCm         = 0.00;
    float ContainerNumber   = 0.00;
    float CircleA           = 0.00;
    float TotalSurfaceA     = 0.00;
    float CostperContainer  = 0.00;
    float TotalCost         = 0.00;
    
    printf("Please enter the radius of the cylinder in centimeters.\n");
    scanf(" %f", &Radius);
    
    printf("Please enter the height of the cylinder in centimeters.\n");
    scanf(" %f", &Height);
    
    printf("Please enter the cost per square centimeter in dollars.\n");
    scanf(" %f", &CostperCm);
    
    printf("Please enter the number of containers you would like to produce.\n");
    scanf(" %f", &ContainerNumber);
    
    CircleA = pi * pow(Radius, 2); //Top lid's surface area
    
    TotalSurfaceA = ((2 * pi * Radius * Height) + (2 * pi * pow(Radius, 2))) - CircleA; //Total surface area of cylinder minus the top lids area
    
    CostperContainer = CostperCm * TotalSurfaceA; //Cost per surface area
    
    TotalCost = CostperContainer * ContainerNumber; //Total cost of containers
    
    printf("\nThe total surface area of one container is %.3f square centimeters.\n", TotalSurfaceA);
    
    printf("\nThe cost to manufacture one container is $%.2f.\n", CostperContainer);
    
    printf("\nThe cost to manufacture %.0f cylinders will be $%.2f.\n\n", ContainerNumber, TotalCost);
    
    
    return 0;
