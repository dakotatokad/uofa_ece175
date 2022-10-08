//
//  main.c
//  hw4p2
//
//  Created by dakotatokad on 2/11/15.
//

// Creates a Mandelbrot Fractal based off of the Mandelbrot Algorithm in a new text file.
// Inputs: X1, X2, Delta Value
// Outputs:  * and spaces, fractal design in txt file

#include <stdio.h>
#include <math.h>


int main(void) {
    double x1, x, xtemp, Xc         = 0;
    double y1, y, ytemp, Yc         = 0;
    double z                        = 0;
    double delta                    = 0;
    int i, j, k                     = 0;
    const int MaxCount              = 500;
    const int MaxZ                  = 10;  
    FILE *Mandelbrot;
    
    printf("Enter an X coordinate: ");
    scanf("%lf", &x1);
    printf("Enter a Y coordinate: ");
    scanf("%lf", &y1);
    printf("Enter a Delta: ");
    scanf("%lf", &delta);
    printf("\n");
    
    
    printf("Opening Mandelbrot.txt\n");
    Mandelbrot = fopen("Mandelbrot.txt", "w");  // Creates/Opens file named Mandelbrot.txt
    
    if(Mandelbrot == NULL) {
        printf("Error.  File could not be found.");
        return -1;
    }
    
    printf("File has been found.  Commencing algorithm.\n");
    
    y = y1;
    
    while(k <= 75) {  // Loop if lines are < 75
        
    x = x1;
        
        for(j = 0; j <= 75; ++j) {  // Loop if characters is < 75
            
            Xc = x;
            Yc = y;
            i = 0;
        
            while(i <= MaxCount) {  // Begin Madelbrot Calc
                xtemp = pow(Xc, 2) - pow(Yc, 2) + x;
                ytemp = (2.0 * Xc * Yc) + y;
                Xc = xtemp;
                Yc = ytemp;
                i++;
            }
            
            z = sqrt(pow(Xc, 2) + pow(Yc, 2));
            
                if(z <= MaxZ) {
                    fprintf(Mandelbrot, "*");  //  Data in algorithm prints "*"
                    x = x + delta;  // Increments X coordinate
                }
                else {
                    fprintf(Mandelbrot, " ");  // Data not in algorithm prints " "
                    x = x + delta;
                }
                
                // End Mandelbrot Calc
        
        } // Characters While Loop
            
            fprintf(Mandelbrot, "\n");
            
            y = y - delta;  // Decrements y coordinate
        
            k++;

    } // Lines While Loop
    
    printf("Closing Mandelbot.txt\n");
    fclose(Mandelbrot);
    
    return 0;
}
