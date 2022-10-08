//
//  main.c
//  lab6p2
//
//  Created by dakotatokad on 3/5/15.
//

#include <stdio.h>
#include <math.h>

float magnitude(float array[3]);
float dotproduct(float array1[3], float array2[3]);
float angle(float dotprods, float v1magnitude, float v2magnitude);

int main(void) {
  
    float v1[3];
    float v2[3];
    float v1magnitude; float v2magnitude;
    int i;
    float dotprods, theta;
    
    printf("Enter three values for V1 seperated by a space: ");
    for(i = 0; i < 3; ++i) {
        scanf("%f", &v1[i]);
    }
    
    printf("Enter three values for v2 seperated by a space: ");
    for(i = 0; i < 3; ++i) {
        scanf("%f", &v2[i]);
    }
    
    v1magnitude = magnitude(v1);
    
    v2magnitude = magnitude(v2);
    
    dotprods = dotproduct(v1, v2);
    
    theta = angle(dotprods, v1magnitude, v2magnitude);
    
    printf("\n\n");
    printf("V1 dot V2 = %.3f\n", dotprods);
    printf("Mag(V1) = %.3f\n", v1magnitude);
    printf("Mag(V2) = %.3f\n", v2magnitude);
    printf("Angle between V1 & V2 = %.3f\n", theta);
    
    if(theta == 0) {
        printf("V1 and V2 are parallel\n");
    }
    
    return 0;
}


float magnitude(float array[3]) {
    
    float magnitude;
    
    magnitude = sqrt(pow(array[0], 2) + pow(array[1], 2) + pow(array[2], 2));
    
    return fabs(magnitude);
}

float dotproduct(float array1[3], float array2[3]) {
    
    float dotprods;
    
    dotprods = (array1[0] * array2[0]) + (array1[1] * array2[1]) + (array1[2] * array2[2]);
    
    return dotprods;
}

float angle(float dotprods, float v1magnitude, float v2magnitude) {
    
    float theta;
    
    theta = acos(dotprods/(v1magnitude * v2magnitude)) * (180 / M_PI);
    
    return theta;
}