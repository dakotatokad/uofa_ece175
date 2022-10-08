//
//  main.c
//  lab4 p2
//
//  Created by dakotatokad on 2/12/15.
//

#include <stdio.h>

int main(void) {
    
    int num         = 0;
    int i           = 0;
    int j           = 0;
    FILE *pattern;
    
    pattern = fopen("pattern.txt", "w");
    
    if(pattern == NULL) {
        printf("Error: File Could Not Be Found.\n");
        return -1;
    }
    
    printf("Enter a number: ");
    scanf("%d", &num);  // 3
    
    
    for(i = 0; i <= num; ++i) {
        for(j = num + 1; j > i; --j) {
            printf("%d ", i);
            fprintf(pattern, "%d ", i);
        }
        printf("\n");
        fprintf(pattern, "\n");
    }

    for(i = num - 1; i >= 0; --i) {
        for(j = 0; j <= num - i; ++j) {
            printf("%d ", i);
            fprintf(pattern, "%d ", i);
        }
        printf("\n");
        fprintf(pattern, "\n");
            
    }

    
    fclose(pattern);
    return 0;
}
