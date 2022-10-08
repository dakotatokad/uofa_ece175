//
//  main.c
//  hw5p2
//
//  Created by dakotatokad on 2/24/15.
//
//  Program asks user for two complex numbers and asks what operation the user wants to perform: Add, Subtract, Multiply, Divide
//  Inputs: 2 complex numbers, Operation
//  Outputs: Complex number



#include <stdio.h>
#include <math.h>
#include <ctype.h>

//  Declare functions

void print_complex(float z1_r, float z1_i, float z2_r, float z2_i, float z3_r, float z3_i, char symbol);
void add_complex(float z1_r, float z1_i, float z2_r, float z2_i, float *z3_r, float *z3_i);
void subtract_complex(float z1_r, float z1_i, float z2_r, float z2_i, float *z3_r, float *z3_i);
void mul_complex(float z1_r, float z1_i, float z2_r, float z2_i, float *z3_r, float *z3_i);
void div_complex(float z1_r, float z1_i, float z2_r, float z2_i);


int main(void) {
    
    float z1_r, z1_i;
    float z2_r, z2_i;
    float z3_r = 0.0, z3_i = 0.0;
    char symbol;
    char operation;
    char repeat = 'a';
    
    
    printf("Zee Vundaba Complex Numarical Calculator!  (a + bi) = (Real + Imaginary * i)\n");
    
    while ( repeat != 'Q') {  // Program loop

    printf("-------------------------------------------------------------------");
    printf("\nEnter the 1st complex number (real and imaginary) [seperated by a space]: ");
    scanf("%f %f", &z1_r, &z1_i);
    printf("Enter the 2nd complex number (real and imaginary) [seperated by a space]: ");
    scanf("%f %f", &z2_r, &z2_i);
    printf("Press A for +\nPress S for -\nPress M for x\nPress D for %%\n");
    scanf(" %c", &operation);
    printf("\n");
    
    switch(operation){  //  Chooses operation the user wants to perform
            case 'A':
            case 'a':
            symbol = '+';
            add_complex(z1_r, z1_i, z2_r, z2_i, &z3_r, &z3_i);
            print_complex(z1_r, z1_i, z2_r, z2_i, z3_r, z3_i, symbol);
            break;
            case 'S':
            case 's':
            symbol = '-';
            subtract_complex(z1_r, z1_i, z2_r, z2_i, &z3_r, &z3_i);
            print_complex(z1_r, z1_i, z2_r, z2_i, z3_r, z3_i, symbol);
            break;
            case 'M':
            case 'm':
            symbol = '*';
            mul_complex(z1_r, z1_i, z2_r, z2_i, &z3_r, &z3_i);
            print_complex(z1_r, z1_i, z2_r, z2_i, z3_r, z3_i, symbol);
            break;
            case 'D':
            case 'd':
            div_complex(z1_r, z1_i, z2_r, z2_i);
            break;
            default:
            printf("This is not a valid operator.\n");
    }
    
        printf("Press any key to continue, press Q to quit: ");
        scanf(" %c", &repeat);  //  Sets up program loop
        repeat = toupper(repeat);  //  Changes case of user input to upper
    }
    
    printf("Thank you come again.\n");
    return 0;
}

void print_complex(float z1_r, float z1_i, float z2_r, float z2_i, float z3_r, float z3_i, char symbol) {
    
    //  Builds printout
    char sign = ' ';
    
    printf("(%.2f + %.2fi) %c (%.2f + %.2fi) = ", z1_r, z1_i, symbol, z2_r, z2_i);
    
    if(z3_r == 0) {
        printf("(%.2fi)\n", z3_i);
    }
    if(z3_i == 0) {
        printf("(%.2f)\n", z3_r);
    }
    if(z3_i != 0 && z3_r != 0){
        if (z3_i > 0) {
            sign = '+';
        printf("(%.2f %c %.2fi)\n", z3_r, sign, fabs(z3_i));
        }
        else {
            sign = '-';
        printf("(%.2f %c %.2fi)\n", z3_r, sign, fabs(z3_i));
        }
    }
    printf("\n");
    
    return;
}

void add_complex(float z1_r, float z1_i, float z2_r, float z2_i, float *z3_r, float *z3_i) {
    
    //  Inputs users complex numbers and passes them to z3 to be taken by print statement in main()
    
    *z3_r = z1_r + z2_r;
    *z3_i = z1_i + z2_i;
    
    return;
}

void subtract_complex(float z1_r, float z1_i, float z2_r, float z2_i, float *z3_r, float *z3_i) {
    
    *z3_r = z1_r - z2_r;
    *z3_i = z1_i - z2_i;
    
    return;
}

void mul_complex(float z1_r, float z1_i, float z2_r, float z2_i, float *z3_r, float *z3_i) {
    
    *z3_r = (z1_r * z2_r) - (z1_i * z2_i);
    *z3_i = (z1_r * z2_i) + (z1_i * z2_r);
    
    return;
}

void div_complex(float z1_r, float z1_i, float z2_r, float z2_i) {
    
    //  Inputs user complex number and uses z3 to build print statement
    
    float z3_r = 0;
    float z3_i = 0;
    
    
    z3_r = (z1_r * z2_r) + (z1_i * z2_i);
    z3_i = (z1_i * z2_r) - (z1_r * z2_i);
    
    if(z3_i == 0) {
        printf("(%.2f + %.2fi)/(%.2f + %.2fi) = (%.2f)\n", z1_r, z1_i, z2_r, z2_i, z3_r / (pow(z2_r, 2) + pow(z2_i, 2)));
    }
    if(z3_r == 0) {
        printf("(%.2f + %.2fi)/(%.2f + %.2fi) = (%.2fi)\n", z1_r, z1_i, z2_r, z2_i, z3_i / (pow(z2_r, 2) + pow(z2_i, 2)));
    }
    if(z3_r != 0 && z3_i != 0) {
        printf("(%.2f + %.2fi)/(%.2f + %.2fi) = (%.2f  %.2fi)", z1_r, z1_i, z2_r, z2_i, z3_r / (pow(z2_r, 2) + pow(z2_i, 2)), z3_i / (pow(z2_r, 2) + pow(z2_i, 2)));
       
    }
    
    return;
}

