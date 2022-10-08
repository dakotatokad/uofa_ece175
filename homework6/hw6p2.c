//
//  main.c
//  hw6p2
//
//  Created by dakotatokad on 3/6/15.
//
// Inputs: IMEI number
// Outputs: Sum of 14 digits, check digit, validity
// Outputs calculated from formulas based on IMEI number

#include <stdio.h>

// Declare functions
int summation14(int IMEI[15]);
int checkdigit(int sum);

int main(void) {
  
    int IMEI[15] = {0};  // IMEI array with 15 values
    int sum = 0, i, check;
    
    printf("Enter a 15-digit barcode seperated by spaces: ");
    for(i = 0; i < 15; ++i) {
        scanf("%d", &IMEI[i]);  // inputs user value to array elements
    }
    
    sum = summation14(IMEI);  // calls summation14
    
    check = checkdigit(sum);  // calls checkdigit

    printf("Total Sum of 14 digits: %d\n", sum);
    printf("Check Digit: %d\nLuhn Digit: %2d\n", check, IMEI[14]);
    
    if(check == IMEI[14]) {  // if check digit = luhn, IMEI is valid
        printf("IMEI is valid.\n");
    }
    else {
        printf("IMEI is not valid.\n");
    }
    
    return 0;
}

int summation14 (int IMEI[15]) {
    int sum1 = 0, sum2 = 0, sum = 0, i, ones, tens;
    
    for(i = 0; i < 14; i += 2) {  // sum of odd digit places
        sum1 += IMEI[i];
    }
    for(i = 1; i < 14; i += 2) {  // sum of even digit places * 2
        if((IMEI[i] * 2) >= 10) {
            ones = (IMEI[i] * 2) % 10;  // if >= 10 finds 1s place
            tens = (IMEI[i] * 2) / 10;  // if >= 10 finds 10s place
            sum2 += (ones + tens);  // adds the two
            }
        else {
            sum2 += (IMEI[i] * 2);  // if <= 10 just 2x element
        }
    }
    
    sum = sum1 + sum2;  // Adds sums
    
    return sum;
}

int checkdigit(int sum) {
    int check;
    
    check = sum % 10;  // Finds 1s place of sum as check digit
    
    if(check != 0) {  // if check != 0 subtract from 10
        check = 10 - check;
    }
    
    return check;
}


//3 5 7 6 8 3 0 3 6 2 5 7 3 7 8

//The check digit is calculated as follows:
//1) First, we calculate the SUM of the first IMEI’s 14 digits by adding
//a) the digits in the odd positions
//b) the double of the digits in the even positions. But if the double of the digit is a two-digit number, we add each digit separately. For example, suppose that the value of the digit is 8, its double is 16. We therefore add to the SUM the result of 1+6 = 7 (and not 16).
//2) If the last digit of the calculated SUM is 0, that is the check digit. If not, we subtract the last digit of the calculated SUM from 10 and that is the check digit.
