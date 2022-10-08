//
//  main.c
//  hw4p1
//
//  Created by dakotatokad on 2/11/15.
//

//  Program reads time in seconds from "time.txt", converts numbers to seconds => number in hours, mins, seconds.  Writes each conversion into "output.txt"
//  Input Number in seconds from "time.txt"
//  Output Number in hours, mins, seconds

#include <stdio.h>
#include <stdlib.h>

int main(void) {
    
    int fileSeconds = 0;
    int hours       = 0;
    int premin      = 0;
    int minutes     = 0;
    int presec      = 0;
    int seconds     = 0;
    FILE *time;
    FILE *output;
    
    printf("Opening file\n");
    time = fopen("time.txt", "r");  // Opens file to read and append file "time.txt"
    
    if(time == NULL) {  // If file DNE will return NULL
        printf("Could not open file\n");
        return -1;
    }
    
    printf("Writing to file\n");
    
    output = fopen("output.txt", "w");  // Opens output.txt for writing
    
    while(fscanf(time, "%d", &fileSeconds) != EOF) {  // Scans file until EOF for values
        if(fileSeconds == 0) {
            fprintf(output, "Seconds: %7d\t Time: Is time even real?\n", fileSeconds);
        }
        else {
        hours = fileSeconds / (60 * 60);  // Whole # of hours
        premin = fileSeconds % (60 * 60); // Remainder from hours
        minutes = premin / 60;  // Whole # of minutes
        presec = premin % 60;  // Remainder of minutes
        seconds = presec;  // Remainder Seconds
            
            fprintf(output, "Seconds: %7d\t Time: ", fileSeconds);  // Leading print statement
            
            if(hours == 0) {
            }
            else {
                fprintf(output, "%d hours ", hours);
            }
            if(minutes == 0) {
            }
            else {
                fprintf(output, "%d minutes ", minutes);
            }
            if(seconds == 0) {
                fprintf(output, "\n");
            }
            else {
                fprintf(output, "%d seconds\n", seconds);
            }  // Print commands, if number is zero the unit and number will be disregarded
        }
    }
    
    printf("Closing file\n");
    fclose(time);  // Closes file  "time.txt."
    
 
    return 0;
}
