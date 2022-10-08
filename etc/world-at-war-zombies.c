//
//  main.c
//  zambies
//
//  Created by dakotatokad on 2/20/15.
//

#include <stdio.h>

void zombie_health(int userrounds);
void zombie_count(int userrounds, int players);

int main(void) {
    
    int userrounds = 0;
    int players = 0;
    
    printf("Enter the amount of rounds to calculate [Health is calculated by 10's & Zombies are calculated by 5's]: ");
    scanf("%d", &userrounds);
    
    printf("Enter the amount of players (1-4): ");
    scanf("%d", &players);
    
    zombie_health(userrounds);
    printf("\n");
    zombie_count(userrounds, players); // FIX Counting
 
  
    return 0;
}

void zombie_health(int userrounds) {
    double health = 150;
    int rounds = 2;
    
    printf("On round 1 the zombies health is 150\n");
    
    while (rounds <= userrounds) {
        
        if(rounds <= 9) {
            health = health + 100;
            
            printf("On round %d the zombies health is %.0lf\n", rounds, health);
            
            rounds = rounds + 1;
        }
  
        else if (rounds <= 20) {
            health = health * 1.1;
            
            printf("On round %d the zombie health is %.3lf\n", rounds, health);
            
            rounds = rounds + 1;
        }
        
        else {
            health = (18234/7030.0) * health;
            printf("On round %d the zombie health is %.3lf\n", rounds + 9, health);
            rounds = rounds + 10;
        }
    }
    
    return;
}  // GOOD

void zombie_count(int userrounds, int players) {
    double zombies = 0;
    const double zombies1player = 24;
    const double zombies2player = 30;
    const double zombies3player = 36;
    const double zombies4player = 42;
    double i = .2;
    int rounds = 0.0;
    int test = 0;
    
    if(players == 1) {
        while(rounds <= userrounds) {
            if(rounds <= 4){
                zombies = zombies1player * i;
                rounds = rounds + 1;
                printf("On round %.0d the total zombies are %.0lf\n", rounds, zombies);
                i = i + .2;
            } //If
            else if (rounds >= 5 && rounds < 10) {
                printf("On rounds 5 - 9 there will be %.0lf zombies\n", zombies1player);
                rounds = rounds + 5;
            }
            else {
                zombies = 24;
                zombies = zombies * (rounds * 0.15);
                test = rounds % 5;
                if(test == 0) {
                printf("On round %.0d the total zombies are %.0f\n", rounds, zombies);
                }
                
                rounds = rounds + 1;
            }
        } //While
        
    } //IF
    
    if(players == 2) {
        while(rounds <= userrounds) {
            if(rounds <= 4){
                zombies = zombies2player * i;
                rounds = rounds + 1;
                printf("On round %.0d the total zombies are %.0lf\n", rounds, zombies);
                i = i + .2;
            } //If
            else if (rounds >= 5 && rounds < 10) {
                printf("On rounds 5 - 9 there will be %.0lf zombies\n", zombies2player);
                rounds = rounds + 5;
            }
            else {
                zombies = 30;
                zombies = zombies * (rounds * 0.15);
                test = rounds % 5;
                if(test == 0) {
                    printf("On round %.0d the total zombies are %.0f\n", rounds, zombies);
                }
                rounds = rounds + 1;
            }
        } //While
        
    } //IF
    
    if(players == 3) {
        while(rounds <= userrounds) {
            if(rounds <= 4){
                zombies = zombies3player * i;
                rounds = rounds + 1;
                printf("On round %.0d the total zombies are %.0lf\n", rounds, zombies);
                i = i + .2;
            } //If
            else if (rounds >= 5 && rounds < 10) {
                printf("On rounds 5 - 9 there will be %.0lf zombies\n", zombies3player);
                rounds = rounds + 5;
            }
            else {
                zombies = 36;
                zombies = zombies * (rounds * 0.15);
                test = rounds % 5;
                if(test == 0) {
                    printf("On round %.0d the total zombies are %.0f\n", rounds, zombies);
                }
                rounds = rounds + 1;
            }
        } //While
        
    } //IF
    
    if(players == 4) {
        while(rounds <= userrounds) {
            if(rounds <= 4){
                zombies = zombies4player * i;
                rounds = rounds + 1;
                printf("On round %.0d the total zombies are %.0lf\n", rounds, zombies);
                i = i + .2;
            } //If
            else if (rounds >= 5 && rounds < 10) {
                printf("On rounds 5 - 9 there will be %.0lf zombies\n", zombies4player);
                rounds = rounds + 5;
            }
            else {
                zombies = 42;
                zombies = zombies * (rounds * 0.15);
                test = rounds % 5;
                if(test == 0) {
                    printf("On round %.0d the total zombies are %.0f\n", rounds, zombies);
                }
                rounds = rounds + 1;
            }
        } //While
        
    } //IF
    
    return;
}
