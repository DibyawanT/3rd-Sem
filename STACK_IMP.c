/*
 * C Program to Implement a Stack using Linked List
 */
#include <stdio.h>
#include <stdlib.h>
 
struct node
{
    int info;
    struct node *ptr;
}*top,*top1,*temp;
 
int topelement();
void push(int data);
void pop();
void display();
void empty();
void stack_count();
void destroy();
void create();
 
int count = 0;
 
void main()
{
    int element, choice, top_element;
 
    create();
    
    for(;;)
    {
    printf("1. Insert element into the Stack (Push Operation).\n");
    printf("2. Delete element from the Stack (Pop Operation).\n");
    printf("3. Print/Display the Top Element of the Stack.\n");
    printf("4. Check whether the Stack is empty or not.\n");
    printf("5. Print/Display all the elements in the Stack.\n");
    printf("6. Count the number of elements in the Stack.\n");
    printf("7. Destroy the entire Stack.\n");
    printf("8. Exit.\n");
 
        printf("\nEnter your Choice: ");
        scanf("%d", &choice);
 
        switch (choice)
        {
        case 1:
            printf("\nEnter a value to insert: ");
            scanf("%d", &element);
    printf("\n\n");
            push(element);
            break;
            
        case 2:
            pop();
            break;
            
        case 3:
            if (top == NULL)
                printf("\nNo elements in Stack.\n");
            else
            {
                top_element = topelement();
                printf("\nTop Element of the Stack: %d\n\n", top_element);
            }
            break;
            
        case 4:
            empty();
            break;
            
        case 5:
            display();
            break;
            
        case 6:
            stack_count();
            break;
            
        case 7:
            destroy();
            break;
            
        case 8:
            exit(0); 
            
        default :
            printf("Wrong choice entered.\n\n");
            break;
        }
    }
}
 
/* Create empty Stack */
void create()
{
    top = NULL;
}
 

/* Insert element into the Stack (Push Operation) */
void push(int data)
{
    if (top == NULL)
    {
        top =(struct node *)malloc(1*sizeof(struct node));
        top->ptr = NULL;
        top->info = data;
    }
    else
    {
        temp =(struct node *)malloc(1*sizeof(struct node));
        temp->ptr = top;
        temp->info = data;
        top = temp;
    }
    count++;
}


/* Delete element from the Stack (Pop Operation) */
void pop()
{
    top1 = top;
 
    if (top1 == NULL)
    {
        printf("\nError : Trying to pop from Empty Stack.");
        return;
    }
    else
        top1 = top1->ptr;
      printf("\nPopped value is: %d", top->info);
      printf("\n\n");
    free(top);
    top = top1;
    count--;
}


/* Print/Display the Top Element of the Stack */
int topelement()
{
    return(top->info);
}
 

/* Check whether the Stack is empty or not */
void empty()
{
    if (top == NULL)
        printf("\nStack is Empty.\n\n");
    else
        printf("\nStack is not Empty. It contains %d elements.\n\n", count);
}


/* Print/Display all the elements in the Stack */
void display()
{
    top1 = top;
 
    if (top1 == NULL)
    {
        printf("Stack is Empty.\n");
        return;
    }
 
    printf("Stack elements are:\n");
   while (top1 != NULL)
    {
        printf("\n%d\n", top1->info);
        top1 = top1->ptr;
        printf ("\n\n");
    }
 }

 
/* Count the number of elements in the Stack */
void stack_count()
{
    printf("\nNumber of elements in Stack : %d", count);
    printf("\n\n");
}


/* Destroy the entire Stack */
void destroy()
{
    top1 = top;
 
    while (top1 != NULL)
    {
        top1 = top->ptr;
        free(top);
        top = top1;
        top1 = top1->ptr;
    }
    free(top1);
    top = NULL;
 
    printf("\nAll Stack elements are destroyed.");
    count = 0;
    printf("\n\n");
}
