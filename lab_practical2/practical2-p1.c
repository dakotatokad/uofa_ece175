//
//  main.c
//  Midterm2P1
//
//  Created by dakotatokad on 4/2/15.
//

#include <stdio.h>
#define ROW 6
#define COL 7

int main(void) {
 
    FILE *input;
    int elevations[6][7];
    int row, col, valley;
    int rowprint, colprint;
    
    input = fopen("input.txt", "r");
    if(input == NULL)
        printf("Error, File not found.\n");
    
    printf("Scanning Files\n");
    for(row = 0; row < ROW; row++) {
        for(col = 0; col < COL; col++) {
            fscanf(input, "%d", &elevations[row][col]);
        }
    }
    
    printf("Analyzing Files\n");
    
    printf("Terrain Data:\n");
    for(row = 0; row < ROW; row++) {
        for(col = 0; col < COL; col++) {
            printf("%d ", elevations[row][col]);
        }
        printf("\n");
    }
    printf("\n");
    for(row = 1; row < ROW - 1; row++){
        for(col = 1; col < COL - 1; col++) {
            if(elevations[row][col] < elevations[row - 1][col - 1] && elevations[row][col] < elevations[row - 1][col] && elevations[row][col] < elevations[row][col - 1] && elevations[row][col] < elevations[row - 1][col + 1] && elevations[row][col] < elevations[row + 1][col + 1] && elevations[row][col] < elevations[row + 1][col] && elevations[row][col] < elevations[row + 1][col - 1] && elevations[row][col] < elevations[row][col + 1]) {
                
                valley = elevations[row][col];
                rowprint = row;
                colprint = col;
                printf("Valley %d at row %d and column %d.\n", valley, rowprint, colprint);
            }
            else {}
        }
    }
    printf("\nData Analysis Complete.\n");
    
    return 0;
}
