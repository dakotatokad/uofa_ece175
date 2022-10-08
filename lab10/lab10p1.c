//
//  main.c
//  lab10
//
//  Created by dakotatokad on 4/16/15.
//

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define SWAP 1
#define NO_SWAP 0

typedef struct coord {
    double x; // name of person
    double y; // age of person
    struct coord *listp; // pointer to a node_t
} coordinate_T;

void  scan_fun(coordinate_T *pt, FILE *in);  // reads a member's data from a file
void  print_fun(coordinate_T *pt); // prints a list node
void print_list(coordinate_T *pt); // prints the entire list
coordinate_T *find_name(coordinate_T *pt, int *query); // finds a person's name in the list. returns the address of the node where there was a match
void find_age(coordinate_T *pt, int min, int max); // finds all list members with ages between min and max
void swap(coordinate_T *x, coordinate_T *y); // swaps the contents of two nodes
void sort_list(coordinate_T *pt); // sorts the list by name
void add_member(coordinate_T **h, coordinate_T **c); // adds a new member to the list
void delete_member(coordinate_T **h, coordinate_T **c); // deletes the list
void pause(void); // pauses the program execution until Enter is pressed

int main(void)
{
    int i=0;
    coordinate_T *headp=NULL, *temp, *current=NULL;
    FILE *inp;
    
    inp=fopen("database.txt", "r");
    
    while(!feof(inp)) // while the end of file has not been reached
    {
        temp=(coordinate_T *)malloc(sizeof (coordinate_T)); // creation of memory
        scan_fun(temp, inp); // initialization of element of list
        if (current==NULL)
            headp=temp; // setting the head of the list
        else
            current->listp=temp; // else connecting to previous element
        i++;   // count number of elements added
        current=temp; // updating the current element
        temp->listp=NULL; // setting pointer to null.
    }
    
    print_list(headp); // print the list
    
    pause(); //wait for user input
    
    printf("\nFind node with name 'Jack'\n");
    temp=find_name(headp,"Jack");  // find element
    
    if (temp==NULL) // if element not found
        printf("this name does not exist in the database");
    else
        print_fun(temp); // print element
    
    pause(); //wait for user input
    
    printf("\nFind node with age between 22-28\n");
    find_age(headp, 22, 28);   //find elements with age between 22 and 28
    pause();
    
    printf("\nAdd a new member to the list (at the end of the list)\n");
    add_member(&headp, &current); // add a new member to the list
    print_list(headp); // print the list
    pause(); // wait for user input
    
    printf("\nSort the list by alphabetical order\n");
    sort_list(headp); // sort the list
    print_list(headp); // print the list
    pause();
    
    printf("\nDeleting a member\n");
    delete_member(&headp, &current); // delete a member
    print_list(headp); // print the list
    
    fclose(inp);
    return(0);
}


void  scan_fun(coordinate_T *pt, FILE *in)
{ //scans file and stores input on a node_t structure
    fscanf(in, "%s%d", pt->x, &pt->y);
}

void  print_fun(coordinate_T *pt)
{ //prints a node_t structure
    printf("%s, %d\n", pt->x, pt->y);
}

void print_list(coordinate_T *pt)
{
    if (pt==NULL)
        printf("The list is empty\n");
    else
    {
        while (pt!=NULL)
        { // traversing the list
            print_fun(pt);
            pt=pt->listp;
        }
    }
}


coordinate_T *find_name(coordinate_T *pt, char *query)
{   // finds the name query in the database
    // returns pointer to structure matched or null
    while(strcmp(pt->x, query)!=0 && pt!=NULL)
        pt=pt->listp;
    return pt;
}


void find_age(coordinate_T *pt, int min, int max)
{ // finds elements within a range of ages
    while(pt!=NULL)
    { if (pt->y >= min && pt->y <=max)
        print_fun(pt);
        pt=pt->listp;}
}

void swap(coordinate_T *x, coordinate_T *y)
{ // swaps two elements on the list
    coordinate_T t;
    strcpy(&t.x, &x->x);
    t.y=x->y;
    strcpy(x->x, y->x);
    x->y=y->y;
    strcpy(y->x,t.x);
    y->y=t.y;
}

void sort_list(coordinate_T *pt)
{  // sorts the list alphabetically
    
    coordinate_T *temp, *min;
    while (pt!=NULL)
    {	temp=pt;
        min=pt;
        while(temp!=NULL)
        {
            if (strcmp(min->x, temp->x)>0)
            {
                min=temp;
            }
            temp=temp->listp;
        }
        swap(pt, min);
        pt=pt->listp;
    }
}


void add_member(coordinate_T **h, coordinate_T **c)
{   // adds an element at the end of the  list
    coordinate_T *temp;
    temp=(coordinate_T *)malloc(sizeof (coordinate_T)); // memory allocation
    printf("Enter the x of the new number:");
    scanf("%lf",&temp->y); //scan for the age
    printf("Enter the y of the new number:");
    scanf("%lf", &temp->x); // scan for the name
    if (*h==NULL) // if list is empty
        *h=temp; // point the head to temp
    else
    {
        (*c)->listp=temp; // point previous last element to temp
        *c=temp; // update the current last element
    }
    temp->listp=NULL; // point temp->listp to NULL
}

void delete_member(coordinate_T **h, coordinate_T **c)
{
    coordinate_T *target; // pointer to string to be deleted
    coordinate_T **temp=h; // pointer to the head of the list
    char s[20];
    
    printf("Enter the name of the entry you want to delete:");
    fflush(stdin);
    scanf("%s",s);
    target=find_name(*h, s); // finding the element to be deleted
    if (target==NULL)
        printf("This entry does not exist\n");
    else
    {
        while ((*temp)!=target)
        {
            temp=&(*temp)->listp; // locating the address of the previous element
        }
        if (target==*h) // if first element must be deleted
            *h=target->listp; // make head point to the next element
        if (target==*c) // if last element is to be deleted
            *c=*temp; // update the position of the last element
        *temp=target->listp;  // skip element to be deleted
        free(target); // free the memory
    }
}


void pause(void)
{
    fflush(stdin);
    printf("Press Enter to continue");
    getchar();

}