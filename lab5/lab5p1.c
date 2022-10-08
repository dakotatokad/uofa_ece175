//
//  main.c
//  Lab5p1
//
//  Created by dakotatokad on 2/19/15.
//

#include <stdio.h>
#include <math.h>

const float R       = 0.08206;
void printchoice(void);
double pressure_cal(int gas, double T, double Vh);



int main() {
    
    int gastype         = 0;
    float temp          = 0;
    float volume        = 0;
    float pressure      = 0;
    char cont           = 'A';
    
    printf("Van Der Walls Calculator.\n");
    
    do {
        
        printchoice();
        
        printf("\nPlease Select the gas you would like to use by selecting the corresponding number: ");
        scanf("%d", &gastype);
        
        printf("Please enter a temperature in Kelvin: ");
        scanf("%f", &temp);
        
        printf("Please enter a gas vaolume in Liters/mol (Negative values will be converted to positive): ");
        scanf("%f", &volume);
        if(volume < 0) {
            volume = fabs(volume);
            printf("The volume has been converted to a positive number: %.4f\n", volume);
        } // IF
        
        
        pressure = pressure_cal(gastype, temp, volume);
        
        if( pressure != -1.00) {
        printf("\nThe Pressure is: %.4f atm\n", pressure);
        }
        else {
        }
        
        printf("Do you want to continue?  Y(es) or N(o).\n");	
        scanf(" %c", &cont);
        
        printf("\n");
        
    } while(cont == 'Y');
    
    printf("Goodbye.\n");
    
    
    return 0;
}


void printchoice(void) {
    printf("Number\tGas Type\n");
    printf("1\tHelium\n2\tHydrogen\n3\tOxygen\n4\tChlorine\n5\tCarbon Dioxide\n");
    return;
}

double pressure_cal(int gas, double T, double Vh) {
    double a = 0.0;
    double b = 0.0;
    double P = 0.0;
    
    switch(gas){
        case 1:
            a = 0.0341;
            b = 0.0237;
            break;
            
        case 2:
            a = 0.244;
            b = 0.0266;
            break;
            
        case 3:
            a = 1.36;
            b = 0.0318;
            break;
            
        case 4:
            a = 6.49;
            b = 0.0562;
            break;
            
        case 5:
            a = 3.59;
            b = 0.0427;
            break;
            
        default:
            printf("This is not a usable gas type.  Please restart the program.\n\n");
            a = 0.0;
            b = 0.0;
    }// Switch
    
    P = -1.0;
    if((a != 0) && (b != 0)) {
        P = R * T/(Vh - b) - a/(Vh * Vh);
    }
    return P;
    
}
