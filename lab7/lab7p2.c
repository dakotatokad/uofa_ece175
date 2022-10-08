//
//  main.c
//  lab7p2
//
//  Created by dakotatokad on 3/12/15.
//

#include <stdio.h>
#define SIZE 100

void encryption(char sentence[SIZE], char *encrypt_sentence);
void counting_alphabet(char sentence[SIZE], int *upper, int *lower);

int main(void){
    
    char sentence[SIZE], encrypt_sentence[SIZE];
    int upper, lower;
    
    printf("Enter a sentence for encryption\n");
    fgets(sentence, SIZE, stdin);
    //see section 5.12 in Zyante book
    //Suggestions: use Debug feature to see how sentence array keep
    //each character
    //Q: what are the last two characters in the sentence array?
    encryption(sentence, encrypt_sentence); // receives a string
    //"sentence" and return the encrypted string "encrypt_sentence"
    counting_alphabet(sentence, &lower, &upper);  //lower and upper –
                                                   //keep total numbers of a-z and A-Z, respectively in the sentence
    //Complete the program below so that it displays information
    //shown in sample code executions
    return 0; }

void encryption(char sentence[SIZE], char *encrypt_sentence){
    
    int i, j;
    
    for(i = 97; i <= 122; ++i){
        
  (      
)        if(i == 122) {
            i = 97;
        }
    }
    
    for(i = 65; i <= 90; ++i) {
        
     
        if(i == 90) {
            i = 65;
        }
    }
    
    
    
    return;
}

void counting_alphabet(char sentence[SIZE], int *upper, int *lower) {
    
    return;
}