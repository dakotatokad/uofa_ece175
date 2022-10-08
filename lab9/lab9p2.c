//
//  main.c
//  lab9P2
//
//  Created by dakotatokad on 4/9/15.
//

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

int rollDice(void);

int main(void) {
    
    srand((int)time(NULL));
   
    int point = 0;
    int sum = 0;
    char cont;
    int betting;
    int playagain = 1;
    char temp;
    int bettingwalk = 0;
    int addiction = 0;
    
    int i;
    
    printf("================================================\n");
    printf("the shizzwack fiddle that happens in craps\n");
    printf("================================================\n");
    printf("Enter bets: ");
    scanf("%d", &betting);
    scanf("%c", &temp);
    bettingwalk = betting;
    if(betting > 5000) {
    printf("================================================\n");
    printf("ITS A BOLD MOVE COTTON LETS SEE IF IT PAYS OFF\n");
    printf("================================================\n");
    }
    
    do {
    
    do {
        printf("\n");
        i = 0;
        sum = rollDice();
    
    if(i == 1 && (sum == 7 || sum == 11)) {
       printf("You win!\n");
        betting = betting - (betting * .25);
        printf("Current $$: %d\n", betting);
        printf("Do you want to play again? (2 to quit): ");
        scanf("%d", &playagain);
        scanf("%c", &temp);
       break;
    }
    else if((sum == 2 || sum == 3 || sum == 12) && i == 1) {
        printf("CRAP!\n");
        betting = betting - (betting * .15);
        printf("Current $$: %d\n", betting);
        printf("Do you want to play again? (2 to quit): ");
        scanf("%d", &playagain);
        scanf("%c", &temp);
        
        break;
    }
    else if(sum == 7) {
        printf("You Lose!\n");
        betting = betting - (betting * .08);
        printf("Current $$: %d\n", betting);
        printf("Do you want to play again? (2 to quit): ");
        scanf("%d", &playagain);
        scanf("%c", &temp);
        addiction += 1;
        break;
    }
    else if((point == 0) && (sum == 4 || sum == 5 || sum == 6 || sum == 8 || sum == 9 || sum == 10)) {
        point = sum;
        printf("Point: %d\nGet a sum equal to %d to win!\n", point, point);
    }
    else if(sum == point) {
        printf("You win!\nSum = %d = %d = Point!\n", sum, point);
        betting = betting + (betting * .20);
        printf("Current $$: %d\n", betting);
        printf("Do you want to play again? (2 to quit): ");
        scanf("%d", &playagain);
        scanf("%c", &temp);
        break;
    }
    else {
        printf("Off by %.0lf!  Try Again!\n", fabs(point - sum));
    }
    
        if(betting == 0) {
            printf("You have no money!\n");
            break;
        }
    
    printf("Press Enter to Continue");
    fgets(&cont, 3, stdin);
    } while(cont == '\n');
    
    
    } while (playagain == 1);
    
    printf("===================================\n");
    printf("You walk home with $%.d!\n", betting);
    if(betting <= bettingwalk) {
        printf("Your net loss was $%d\n", bettingwalk - betting);
        if(addiction > 5) {
        printf("Maybe gambling is not your thing.\nPlease call 1-800-522-4700\n");
        }
    }
    else {
        printf("Your net gain was $%d\n", betting - bettingwalk);
    }
    printf("===================================\n");
    
    return 0;
}

int rollDice(void) {
    
    int diceone = 0;
    int dicetwo = 0;
    int throw = 0;
    int sum = 0;
    
    diceone = (rand() % 6) + 1;
    dicetwo = (rand() % 6) + 1;
    throw += 1;
    
    sum = dicetwo + diceone;
    
    printf("Die 1: %d\nDie 2: %d\nSum: %d\n", diceone, dicetwo, sum);
    
    
    return sum;
}