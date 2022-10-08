//
//  main.c
//  hw2p1
//
//  Created by dakotatokad on 1/27/15.
//
//  Calculates the cost of a passengers luggage based on preset prices based on weight and class of travel.
//  Inputs: Users Class, Weight of luggage
//  Outputs: Price of luggage
//  Price of luggage is based upon the weight and class of travel user takes

#include <stdio.h>
#include <math.h>

int main(void) {
    
    char class              = 'A';
    float lugWeight         = 0.00;
    float totalCost         = 0.00;

    while(class != 'Z' && class != 'z') {  //  Loops program until user exits
    
    printf("Please enter the Passenger Class.\n");
    printf("E - Economy\nB - Buisness\nV - VIP\nZ - Exit\n\n");
    scanf(" %c", &class);  //  User enters preferred class of travel
    
    
        switch(class) {  //  Based on class determines price
            case 'e':
            case 'E':
            printf("You have selected economy.\nPlease enter the luggage weight in pounds.\n");
            scanf(" %f", &lugWeight);  //  User enters weight of luggage
                //  If statements determine the cost based on user entered weight of luggage
            if(lugWeight < 25.00) {
                totalCost = fabs((lugWeight - 25.00) * 0);  //  fabs() stops weight 0 = -0.00
                printf("Total cost is $%.2f.\n\n", totalCost);
            }
            else if(lugWeight >= 25 && lugWeight <= 40) {
                totalCost = (lugWeight - 25) * 1.50;
                printf("Total cost is $%.2f.\n\n", totalCost);
            }
            else {
                totalCost = ((lugWeight - 40) * 2.00) + (15 * 1.50);
                printf("Total cost is $%.2f.\n\n", totalCost);
            }
            break; //E
            //
            case 'b':
            case 'B':
            printf("You have selected buisness.\nPlease enter the luggage weight in pounds.\n");
            scanf(" %f", &lugWeight);
            if(lugWeight < 35){
                totalCost = fabs((lugWeight - 35) * 0);
                printf("Total cost is $%.2f.\n\n", totalCost);
            }
            else if(lugWeight >= 35 && lugWeight <= 50) {
                totalCost = (lugWeight - 35) * 1.25;
                printf("Total cost is $%.2f.\n\n", totalCost);
            }
            else {
                totalCost = ((lugWeight - 50) * 1.50) + (15 * 1.25);
                printf("Total cost is $%.2f.\n\n", totalCost);
            }
            break; //B
            //
            case 'v':
            case 'V':
                printf("You have selected VIP.\nPlease enter the luggage weight in pounds.\n");
                scanf(" %f", &lugWeight);
                if(lugWeight < 60) {
                totalCost = fabs(0);
                printf("Total cost is $%.2f.\n\n", totalCost);
            }
            else {
                totalCost = 30;
                printf("Total cost is $%.2f.\n\n", totalCost);
            }
            break; //V
            //
            case 'z':
            case 'Z':  //  Occupies 'Z' command to avoid default command
            break;
                //
            default:
            printf("This is not a class.\n\n");  //  If user enters and unregistered class program responds.
                
    }  //switch class
        
    } //while loop end
    
    printf("Thank you, goodbye.\n");  //  Prints before termination
    
    
        return 0;
}
