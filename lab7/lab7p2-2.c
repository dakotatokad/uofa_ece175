//
//  main.c
//  lab7p2.2
//
//  Created by dakotatokad on 3/12/15.
//

#include <stdio.h>
#include <math.h>
#include <ctype.h>
#define SIZE 10000

void encryption(char sentence[SIZE], char *encrypt_sentence);
void decryption(char encrypt_sentence[SIZE], char *sentence);
void counting_alphabet(char sentence[SIZE], int *upper, int *lower);

int main(void) {
    
    char sentence[SIZE] = {0}, encrypt_sentence[SIZE] = {0};
    int upper = 0, lower = 0;
    char selection[3];
    int i = 0;
    
    printf("A) Encryption\nB) Decryption\n");
    printf("Selection: ");
    
    
    fgets(selection, 3, stdin);
    printf("\n");
    
    switch(selection[i]) {
            case 'A':
            
                printf("Enter a sentence for encryption: \n");
                fgets(sentence, SIZE, stdin);
                
                encryption(sentence, encrypt_sentence);
                counting_alphabet(sentence, &lower, &upper);
                
                printf("\nUpper: %d\nLower: %d\n", upper, lower);
                printf("%s\n", encrypt_sentence);
            
            break;
            
            case 'B':
            
                printf("Enter a sentence for decryption: \n");
                fgets(encrypt_sentence, SIZE, stdin);
                
                decryption(encrypt_sentence, sentence);
                counting_alphabet(encrypt_sentence, &lower, &upper);
                
                printf("\nUpper: %d\nLower: %d\n", upper, lower);
                printf("%s\n", sentence);
            
            break;
            
        default:
            printf("Error\n");
    }
    
    return 0;
}

void encryption(char sentence[SIZE], char *encrpyt_sentence) {
    
    int i;
    
    for(i = 0; i < SIZE; ++i) {
        if(sentence[i] >= 97 && sentence[i] <= 122) {
            encrpyt_sentence[i] = 219 - sentence[i];
        }
        else if(sentence[i] >= 65 && sentence[i] <= 90) {
            encrpyt_sentence[i] = 155 - sentence[i];
        }
        else {
            encrpyt_sentence[i] = sentence[i];
        }
        
    }

    
    return;
}

void decryption(char encrypt_sentence[SIZE], char *sentence) {
    
    int i;
    
    for(i = 0; i < SIZE; ++i) {
        if(encrypt_sentence[i] >= 97 && encrypt_sentence[i] <= 122) {
            sentence[i] = 219 - encrypt_sentence[i];
        }
        else if(encrypt_sentence[i] >= 65 && encrypt_sentence[i] <= 90) {
            sentence[i] = 155 - encrypt_sentence[i];
        }
        else {
            sentence[i] = encrypt_sentence[i];
        }
        
    }
    
    
    return;
}

void counting_alphabet(char sentence[SIZE], int *lower, int *upper) {
    
    int i = 0;
    int sumlower = 0, sumupper = 0;
    
    for(i = 0; i < SIZE; i++) {
        if(sentence[i] >= 96 && sentence[i] <= 122) {
            sumlower += 1;
        }
        if(sentence[i] >= 65 && sentence[i] <= 90) {
            sumupper += 1;
        }
    }
    
    *lower = sumlower;
    *upper = sumupper;
    
    return;
}  // GOOD