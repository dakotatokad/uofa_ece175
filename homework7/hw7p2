//
//  main.c
//  hw7p2
//
//  Created by dakotatokad on 3/12/15.
//
// Program calculates the number of words in a sentence and reversed the word order
// Inputs: Sentence
// Outputs: Number of words, reversed sentence

#include <stdio.h>
#include <string.h>

void wordCount(char sentence[100]);
void sentenceReversed(char sentence[100]);

int main(void) {
    
    char sentence[100];
    
    printf("Enter a statement: ");
    fgets(sentence, 3000, stdin);       // Gets an entire users string
    
    wordCount(sentence);                // Calls wordCount of sentence to find number of words
    
    sentenceReversed(sentence);         // Calls sentenceReversed of sentence to print reversal
 
    return 0;
}

void wordCount(char sentence[100]) {
    
    int wordcount= 0;
    int i;
    
    i = 0;
    while(sentence[i] != '\0') {    // Reads through string positions till it finds null character
        if(sentence[i] == ' ') {    // If a space is found increase the word count by 1
            wordcount += 1;
        }
        if(sentence[i] == '\n') {   // If a newline is found increase the word count by 1 because input is from console
            wordcount += 1;
        }
        ++i;                        // Changes i through array
    }
    
    printf("\nThere are %d words in the sentence: %s\n", wordcount, sentence);
    
    return;
}

void sentenceReversed(char sentence[100]) {
    
    char reversed[100];
    int L;
    int i = 0, j = 0;
    
    strlcpy(reversed, sentence, 100);                   // copies string sentence from main into string reversed to help debug
    
    L = strlen(reversed) - 1.00;                        // Finds length of string, -1 because stdin reads '\n'
    
    for(i = L - 1; i >= 0; --i) {                       // Goes through array backwords from end
        if(reversed[i - 1] == ' ' || i == 0) {          // When a space is found or the array is at i=0
            for (j = i; j <= L - 1; ++j) {              // Print from i to end of array [ last position]
                printf("%c", reversed[j]);
            }
            L = i;                                      // Resets L to the last position for retyping at next word
            printf(" ");                                // Prints space between words
        }
        
    }
    
    printf("\n");
    
    return;
}
