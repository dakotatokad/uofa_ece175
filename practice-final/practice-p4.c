//
//  main.c
//  PracticeExamP4
//
//  Created by dakotatokad on 2/17/15.
//

#include <stdio.h>
#include <math.h>

float radiusrounder(float r);

int main(void) {
    
    float x1, y1 = 0;
    float x2, y2 = 0;
    float r  = 0;
    float justify   = 0;
    char contcheck = 'a';
    
    do{
    
    printf("Enter the coordinates (x1,y1) of the center of a cirle: ");
    scanf("%f,%f", &x1, &x2);
        
    printf("Enter a whole number radius: ");
    scanf("%f", &r);
    
    printf("Enter the coordinates (x2,y2) of a point in the cartesian plane: ");
    scanf("%f,%f,", &x2, &y2);
        
    printf("\n");
        
        r = radiusrounder(r);
    
        justify = pow((x2 - x1), 2) + pow((y2 - y1), 2);
    
    if (justify < r) {
        printf("The point (%.2lf, %.2lf) is inside the circle with radius %.0f.\n", x2, y2, r);
    }
    else if (justify > r) {
        printf("The point (%.2lf, %.2lf) is outside the circle with radius %.0f.\n", x2, y2, r);
    }
    else {
        printf("The point (%.2lf, %.2lf) is on the circle with radius %.0f.\n", x2, y2, r);
    }
    
        printf("Do you want to continue?  Enter 'q' to quit or any other key to continue.\n");
        scanf(" %c", &contcheck);
        
    } while(contcheck != 'q');
   
    return 0;
}

float radiusrounder ( float r) {
    
    r = roundf(r);
    
    return r;
}
