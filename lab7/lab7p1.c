//
//  main.c
//  lab7p1
//
//  Created by dakotatokad on 3/12/15.
//

#include <stdio.h>
#include <math.h>

void get_corners(double *x, double *y);
double polygon_area(double x[7], double y[7], int size);

int main(void) {
    
    double x[7];
    double y[7];
    double area;
    double size = 7;
    int i;
    
    get_corners(x, y);

    area = polygon_area(x, y, size);
    
    for(i = 0; i < 7; ++i) {
        printf("%.2lf %.2lf\n", x[i], y[i]);
    }
    
    printf("\nIts area is %.2lf\n", area);
  
    return 0;
}

void get_corners(double *x, double *y) {
    
    FILE *polygon;
    
    polygon = fopen("polygon.txt", "r");
    
    if(polygon == NULL) {
        printf("The file could not be found.\n");
    }

    int i = 0;
    
    
    while(fscanf(polygon, "%lf %lf", &x[i], &y[i])!= EOF) {
        ++i;
    }
    
    return;
}  // GOOD

double polygon_area(double x[7], double y[7], int size) {
    
    double area;
    int i = 0;
    double sum = 0;
    
    for(i = 0; i <= size - 2; ++i) {
        sum += ((x[i+1] + x[i]) * (y[i+1] - y[i]));
    }
    
    
    area = (1.0 / 2.0) * fabs(sum);
    
    return area;
}