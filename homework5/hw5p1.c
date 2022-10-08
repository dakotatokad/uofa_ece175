//
//  main.c
//  hw5p1
//
//  Created by dakotatokad on 2/24/15.
//
//
//  This program converts either an equation from Two - Point or Point - Slope form into Slope - Intercept form.
//  Inputs: Slope, 2 (x,y) coordinates
//  Outputs: Slope - Intercept equation



#include <stdio.h>
#include <ctype.h>
#include <math.h>

//  Declare functions

int get_choice(void);
void SlopeInt_from_2Pt (double X1, double Y1, double X2, double Y2);
void Display_2Pt(double X1, double Y1, double X2, double Y2);
void Display_SlopeInt(double m, double b);
void SlopeInt_from_PtSlope(double slope, double X1, double Y1);
void Display_PtSlope(double m, double X1, double Y1);
void clearscreen();

int main(void) {
    
    int choice;
    char repeat = 'Y';
    int i = 0;
    double X1 = 0; double X2 = 0; 
    double Y1 = 0; double Y2 = 0;
    double m = 0;
    
    while(repeat == 'Y') {  //  Program Repeat Loop
        
        i = 0;  // Initialize Sass
        
    do {  //  Gets users choice of either Pt-Slope or Two-Pt
        
    choice = get_choice();      //  Calls function user choice and returns a number value
        if(choice != 1 && choice != 2) {
                if(i >= 0 && i < 2) {
                    printf("\nYou're royal heighness needs to choose between 1 or 2, no more no less.");
                    clearscreen();
                }
                else if(i >= 2 && i <= 5) {
                    printf("\nReally, its just the number 1 or 2...");
                    clearscreen();
                }
                else if(i > 5 && i <= 9) {
                    printf("\nMaybe you should just stop...");
                    clearscreen();
                }
                else if(i > 9) {
                    printf("\nYou've had %d tries.\nYou're doing point slope.", i);
                    choice = 2;
                    clearscreen();
                }
        } // IF
      ++i;
        
    } while(choice != 1 && choice != 2);  //  If get_choice() returns other than 1 or 2  will repeat loop
    
    switch(choice) {
        case 1:     //  Case 1 inputs coordinates and calls SlopeInt_from_2Pt
            printf("Enter the point (X1, Y1) seperated by a comma: ");
            scanf("%lf, %lf", &X1, &Y1);
            printf("Enter the point (X2, Y2) seperated by a comma: ");
            scanf(" %lf, %lf", &X2, &Y2);
            
            SlopeInt_from_2Pt(X1,  Y1,  X2,  Y2);
            
            break;
            
        case 2:     //  Case 2 inputs slope and coordinate and calls SlopeInt_from_PtSlope
            printf("Enter a slope: ");
            scanf("%lf", &m);
            printf("Enter the point (X1, Y1) seperated by a comma: ");
            scanf(" %lf, %lf", &X1, &Y1);
            
            SlopeInt_from_PtSlope(m, X1, Y1);
            
            break;
    } // Switch End
        
        printf("\nDo another conversion (Y/y or N/n)?  ");
        scanf(" %c", &repeat);      // Sets up program loop
        repeat = toupper(repeat);  //  Converts value to uppercase
        printf("\n\n");
        
    } // repeat loop
    
    printf("Goodbye.\n");
    
    return 0;
}

int get_choice(void) {
    
    //  Displays menu and returns user choice to main()
    
    int choice;
  
    printf("Mode\t\t\tEquation\t\tGiven\n");
    printf("--------------------------------------------------------------\n");
    printf("Two - Point form\t\tm=(y1-y1)/(x2-x1)\t(x1,y1),(x2,y2)\n\n");
    printf("Point - Slope form\t\ty-y1 = m(x-x1)\t\tm, (x1,y1)\n\n");
    printf("Slope - Intercept form\ty = mx+b\t\t\tm, b\n\n");
    printf("Select the form that you would like to convert to Slope - Intercept Form\n1) for Two - Point form\n2) for Point - Slope form\n");
    printf("\nThy majesty chooses: ");
    scanf("%d", &choice);
    
    return(choice);

}

void clearscreen() {
    
    //  Prints 3 newlines
    
    int i;
    for(i = 0; i <= 3; ++i) {
        printf("\n");
    }
    return;
}

void SlopeInt_from_2Pt (double X1, double Y1, double X2, double Y2) {
    
    //Input: x1, y1, x2, y2
    //Output: slope (m) and intercept (b)
    
    double m;
    double b;
    
    m = (Y2 - Y1)/(X2 - X1);
    b = (Y1 - (m * X1));
    
    Display_2Pt(X1, Y1, X2, Y2);
    
    Display_SlopeInt(m, b);
    
    return;
}

void SlopeInt_from_PtSlope(double m, double X1, double Y1) {
    
    //Input: x1, y1, slope (m)
    //Output: intercept (b)
    
    double b;
    
    b = Y1 - (m * X1);
    
    Display_PtSlope(m, X1, Y1);
    
    Display_SlopeInt(m, b);
    
    return;
}

void Display_2Pt(double X1, double Y1, double X2, double Y2){
    
    //Input: x1, y1, x2, y2
    //Output: None (No return output BUT this function displays the
    //two-point line equation)
    
    printf("\nTwo-Point Form:\n");
    printf("m = (%.2lf - %.2lf)/(%.2lf - %.2lf)\n", Y2, Y1, X2, X1);
    
    return;
}

void Display_PtSlope(double m, double X1, double Y1) {
    
    //Input: x1, y1, and slope (m)
    //Output: None (No return output BUT this function displays the
    //point-slope line equation)
    
    printf("\nPoint-Slope Form:\n");
    printf("y - %.2lf = %.2lf ( x - %.2lf)\n", Y1, m, X1);
    
    return;
    
}

void Display_SlopeInt(double m, double b){
    
    //Input: slope (m) and intercept (b)
    //Output: None (No return output BUT this function displays the
    //slope-intercept line equation)
    char symbol = ' ';
    
    if (b > 0) {
        symbol = '+';
        printf("\nSlope-Intercept Form:\n");
        printf("y = %.2lfx %c %.2lf\n", m, symbol, fabs(b));
    }
    else if ( b == 0) {
        printf("\nSlope-Intercept Form:\n");
        printf("y = %.2lfx\n", m);
    }
    else {
        symbol = '-';
        printf("\nSlope-Intercept Form:\n");
        printf("y = %.2lfx %c %.2lf\n", m, symbol, fabs(b));
    }
    
    
    
    return;
}
