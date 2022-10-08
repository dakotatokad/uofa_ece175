//
//  main.c
//  lab10.1
//
//  Created by dakotatokad on 4/16/15.
//

#include <stdio.h>
#include <stdlib.h>
#include <math.h>


typedef struct coord {
    double x;
    double y;
    struct coord *listp;
} coordinate_t;

void scan_fun(coordinate_t *pt, FILE *input);
void print_list(coordinate_t *pt);
void find_2plus(coordinate_t *pt);
void print_fun(coordinate_t *pt);
void delete_member(coordinate_t **h, coordinate_t **c);
void pause_p();

coordinate_t *find_name(coordinate_t *pt, int *query) {
    int i = 0;
    while(i < *query) {
        pt = pt->listp;
        i++;
    }
    return pt;
}

int main(void) {
    
    int i = 0;
    coordinate_t *headp = NULL, *temp = NULL, *current = NULL, **temp_p;
    FILE *input;
    
    input = fopen("input.txt", "r");
    
    while(!feof(input)) {
        temp = (coordinate_t*)malloc(sizeof(coordinate_t));
        scan_fun(temp, input);
        
        if(current == NULL)
            headp = temp;
        
        else
            current->listp = temp;
        
        i++;
        current = temp;
        temp ->listp = NULL;
    }
    printf("Whole List:\n");
    print_list(headp);
    printf("\n");
    pause_p();
    
    printf("Coordinates greater than 2:\n");
    find_2plus(headp);
    printf("\n");
    pause_p();

    
    printf("Deleting 5th node.\n");
    delete_member(&headp, &current);
    print_list(headp);
    printf("\n");
    pause_p();

    
    printf("Deleting 0th node.\n");
    delete_member(&headp, &current);
    print_list(headp);
    printf("\n");
    
    
    printf("DONE");


    return 0;
}

void scan_fun(coordinate_t *pt, FILE *input) {
    fscanf(input, "%lf %lf", &pt->x, &pt->y);
}

void print_fun(coordinate_t *pt) {
    printf("(x,y) = (%.2lf, %.2lf)\n", pt->x, pt->y);
}

void print_list(coordinate_t *pt) {
    if(pt == NULL)
        printf("The list is empty\n");
    else {
        while(pt != NULL) {
            print_fun(pt);
            pt = pt->listp;
        }
    }
}

void find_2plus(coordinate_t *pt) {
    double distance;
    
    while(pt != NULL) {
        // Greater than 2
        distance = sqrt(pow(pt->x, 2) + pow(pt->y, 2));
        if(distance >= 2) {
            printf("Distance: %.2lf\t", distance);
            print_fun(pt);
        }
        pt = pt->listp;
    }
}

void delete_member(coordinate_t **h, coordinate_t **c) {
    coordinate_t *target;
    coordinate_t **temp=h;
    
    int s;
    
    printf("Enter node to delete: ");
    fpurge(stdin);
    scanf("%d", &s);
    
    target = find_name(*h, &s);
    
    if(target == NULL)
        printf("This entry does not exist.\n");
    
    else {
        while((*temp) != target) {
            temp = &(*temp)->listp;
        }
        if(target == *h)
            *h = target -> listp;
        if(target == *c)
            *c = *temp;
        
        *temp = target->listp;
        free(target);
    }
}

void pause_p() {
    fpurge(stdin);
    printf("Press Enter to Continue");
    getchar();
    return;
}

