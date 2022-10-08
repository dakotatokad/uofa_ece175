//
//  main.c
//  hw7p1.1
//
//  Created by dakotatokad on 3/11/15.
//
// Program to take in a users choice to find either the magnitude, dot product, or cross product and find the angle between them.
// Inputs: User choice, vector(s)
// Outputs: Magnitude/dot product/cross product,  theta/phi

#include <stdio.h>
#include <math.h>
#include <ctype.h>

float VectorMagnitude(float v1[3]);
void DotProduct(float v1[3], float v2[3], float *DotProduct, float *Theta);
void CrossProduct(float v1[3], float v2[3], float *CrossProduct, float *Phi);

int main(void) {
    
    float v1[3];
    float v2[3];
    float Crossproduct[3];
    float v1magnitude;
    int i;
    float theta, phi;
    float DotProds;
    char choice;
    
    printf("Enter 'M' to calculate the magnitude of a single 3-D vector\nEnter 'D' to calculate the dot product of two 3-D vectors\nEnter 'C' to calculate the cross product of two 3-D vectors\n");
    printf("User Choice: ");
    scanf("%c", &choice);               // Take in user choice
    choice = toupper(choice);           // Changes choice character to uppercase
    
    switch(choice) {
        case 'M':
            
            printf("Enter three values for V1 seperated by a space: ");
            for(i = 0; i < 3; ++i) {    // Reads in user values to array V1
                scanf("%f", &v1[i]);
            }
            
            v1magnitude = VectorMagnitude(v1);      // Calls VectorMagnitude with V1
            
            printf("\nThe magnitude of |V1| is |<%f, %f, %f>| is %f.\n", v1[0], v1[1], v1[2], v1magnitude);     // Prints vector places and v1 magnitude
            
            break;
            
        case 'D':
            
            printf("Enter three values for V1 seperated by a space: ");
            for(i = 0; i < 3; ++i) {
                scanf("%f", &v1[i]);    // Reads in user values to arrays V1 & V2
            }
            
            printf("Enter three values for V2 seperated by a space: ");
            for(i = 0; i < 3; ++i) {
                scanf("%f", &v2[i]);
            }
            
            DotProduct(v1, v2, &DotProds, &theta);      // Calls DotProduct user v1, v2, and passes back dotprods, theta
            
            printf("\nV1 dot V2 = %.3f\n", DotProds);
            printf("Angle between V1 & V2 = %.3f degrees\n", theta);
            
            break;
            
        case 'C':
            
            printf("Enter three values for V1 seperated by a space: ");
            for(i = 0; i < 3; ++i) {
                scanf("%f", &v1[i]);    // Reads in user values to arrays V1, V2
            }
            printf("Enter three values for V2 seperated by a space: ");
            for(i = 0; i < 3; ++i) {
                scanf("%f", &v2[i]);
            }
            
            CrossProduct(v1, v2, Crossproduct, &phi);   // Calls CrossProduct with v1, v2, and passes back crossproduct and phi
            
            printf("\nV1 X V2 = <%f, %f, %f>\n", Crossproduct[0], Crossproduct[1], Crossproduct[2]);
            printf("The angle between the two vectors are: %f degrees.\n", phi);
            
            break;
            
        default:
            printf("\nThis is not an option.\n");
    }
    
    
    return 0;
}

float VectorMagnitude(float array[3]) {
    
    float v1magnitude;
    
    v1magnitude = sqrt(pow(array[0], 2) + pow(array[1], 2) + pow(array[2], 2));     // Calculates magnitude of vector
    
    return v1magnitude;
}

void DotProduct(float array1[3], float array2[3], float *DotProduct, float *Theta) {
    
    double v1magnitude, v2magnitude, coss1 = 0, coss2 = 0;
    
    *DotProduct = (array1[0] * array2[0]) + (array1[1] * array2[1]) + (array1[2] * array2[2]);  // Calculates dotproduct of original vectors V1 & V2
    
    v1magnitude = VectorMagnitude(array1); // Finds magnitude of original vectors V1 & V2
    v2magnitude = VectorMagnitude(array2);
    
    coss1 = *DotProduct / (v1magnitude * v2magnitude);  // Calculates inner function of cos-1
    
    if(fabs(coss1) > .99999 && fabs(coss1) < 1) {  // Fixes precision error
        coss1 = 1;
    }
    
    coss2 = acos(coss1);
    *Theta =  coss2 * (180 / M_PI);  // Calculates theta, passes back to main
    
    return;
}

void CrossProduct(float array1[3], float array2[3], float *CrossProduct, float *Phi) {
    
    float v1magnitude, v2magnitude, v3magnitude;
    
    v1magnitude = VectorMagnitude(array1);  // Calculates magnitude of original vectors V1 & V2
    v2magnitude = VectorMagnitude(array2);
    
    CrossProduct[0] = array1[1] * array2[2] - array2[1] * array1[2];        // Finds cross product of each array position
    CrossProduct[1] = -array1[0] * array2[2] + array2[0] * array1[2];
    CrossProduct[2] = array1[0] * array2[1] - array2[0] * array1[1];
    
    v3magnitude = VectorMagnitude(CrossProduct);  // Calculates magnitude of new cross product
    
    *Phi = asin(v3magnitude / (v1magnitude * v2magnitude)) * (180 / M_PI);  //  Finds phi from equation
    
    return;
}

