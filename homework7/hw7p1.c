//
//  main.c
//  hw7p1
//
//  Created by dakotatokad on 3/11/15.
//

#include <stdio.h>
#include <math.h>
#include <ctype.h>

float magnitude(float array[3]);
float dotproduct(float array1[3], float array2[3]);
float angletheta(float dotprods, float v1magnitude, float v2magnitude);
float anglephi(float v1magnitude, float v2magnitude, float v3magnitude);
void crossproduct(float array1[3], float array2[3], float *Xproduct);

int main(void) {
    
    float v1[3];
    float v2[3];
    float Xproduct[3];
    float v1magnitude; float v2magnitude; float v3magnitude;
    int i;
    float dotprods, theta, phi;
    char choice;
    
    printf("Enter 'M' to calculate the magnitude of a single 3-D vector\nEnter D to calculate the dot product of two 3-D vectors\nEnter C to calculate the cross product of two 3-D vectors\n");
    printf("User Choice: ");
    scanf("%c", &choice);
    choice = toupper(choice);
    
    switch(choice) {
            case 'M':
            
                printf("Enter three values for V1 seperated by a space: ");
                    for(i = 0; i < 3; ++i) {
                        scanf("%f", &v1[i]);
                    }
                v1magnitude = magnitude(v1);
                printf("\nThe magnitude of Vector 1 [<%f, %f, %f,>] is %f.\n", v1[0], v1[1], v1[2], v1magnitude);
            
            break;
            
            case 'D':
            
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
                theta = angletheta(dotprods, v1magnitude, v2magnitude);
                printf("\nV1 dot V2 = %.3f\n", dotprods);
                printf("Angle between V1 & V2 = %.3f\n", theta);
            
            break;
            
            case 'C':
                printf("Enter three values for V1 seperated by a space: ");
                    for(i = 0; i < 3; ++i) {
                        scanf("%f", &v1[i]);
                    }
                printf("Enter three values for v2 seperated by a space: ");
                    for(i = 0; i < 3; ++i) {
                        scanf("%f", &v2[i]);
                    }
            
            crossproduct(v1, v2, Xproduct);
            v1magnitude = magnitude(v1);
            v2magnitude = magnitude(v2);
            v3magnitude = magnitude(Xproduct);
            phi = anglephi(v1magnitude, v2magnitude, v3magnitude);
            
            printf("\nV1 X V2 = <%f, %f, %f>\n", Xproduct[0], Xproduct[1], Xproduct[2]);
            printf("The angle between the two vectors are: %f degrees.\n", phi);
            
            break;
            
        default:
            printf("\nThis is not an option.\n");
    }

    
    return 0;
}


float magnitude(float array[3]) {
    
    float magnitude;
    
    magnitude = sqrt(pow(array[0], 2) + pow(array[1], 2) + pow(array[2], 2));
    
    return fabs(magnitude);
}

float anglephi(float v1magnitude, float v2magnitude, float v3magnitude) {
    
    float phi;
    
    phi = asin(v3magnitude/(v1magnitude * v2magnitude)) * (180/M_PI);
    
    return phi;
}

float dotproduct(float array1[3], float array2[3]) {
    
    float dotprods;
    
    dotprods = (array1[0] * array2[0]) + (array1[1] * array2[1]) + (array1[2] * array2[2]);
    
    return dotprods;
}

float angletheta(float dotprods, float v1magnitude, float v2magnitude) {
    
    float theta;
    
    theta = acos(dotprods/(v1magnitude * v2magnitude)) * (180 / M_PI);
    
    return theta;
}

void crossproduct(float array1[3], float array2[3], float *Xproduct) {
    
    
    Xproduct[0] = array1[1] * array2[2] - array2[1] * array1[2];
    Xproduct[1] = -array1[0] * array2[2] + array2[0] * array1[2];
    Xproduct[2] = array1[0] * array2[1] - array2[0] * array1[1];
    
    
    return;
}
