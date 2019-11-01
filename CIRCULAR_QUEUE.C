# include<stdio.h>
# define MAX 50

void insert(int);
void del();
void display();

int cqueue_arr[MAX];
int front = -1;
int rear = -1;

/* Beginning of main() */
int main()
{
	int choice, item;
	do
	{
		printf("1. Insert element into the rear of the Circular Queue.\n");
		printf("2. Delete element from the front of the Circular Queue.\n");
		printf("3. Display all elements of the Circular Queue.\n");
		printf("4. Quit.\n");

		printf("\nEnter your choice: ");
		scanf("%d",&choice);

		switch(choice)
		{
			case 1 :
				printf("\nInsert the following element in Circular Queue: ");
				scanf("%d", &item);

				insert(item);
				printf("\n");
				break;
			case 2 :
				del();
				break;
			case 3:
				display();
				break;
			case 4:
				break;
				default:
				printf("Wrong choice!\n");
				printf("\n");
		}  /* End of switch */
	}while(choice!=4);  /* End of do-while */
}
/* End of main() */


/* Beginning of insert() */
void insert(int item)
{
	if((front == 0 && rear == MAX-1) || (front == rear+1))
	{
		printf("\nQueue Overflow!\n");
		return;
	}
	if (front == -1)  /* If Circular Queue is initially empty */
	{
		front = 0;
		rear = 0;
	}
	else
	{
		if(rear == MAX-1)	/* If rear is at last position of queue */
			rear = 0;
		else
			rear = rear+1;
	}
	cqueue_arr[rear] = item ;
}
/* End of insert() */


/* Beginning of del() */
void del()
{
	if (front == -1)
	{
		printf("\nQueue Underflow!\n");
		printf("\n");
		return;
	}
	printf("\nElement deleted from Circular Queue is: %d\n",cqueue_arr[front]);
	printf("\n");
	if(front == rear) /* Circular Queue has only one element */
	{
		front = -1;
		rear=-1;
	}
	else
	{	
		if(front == MAX-1)
			front = 0;
		else
			front = front+1;
	}
}
/* End of del() */


/* Beginning of display() */
void display()
{
	int front_pos = front, rear_pos = rear;
	if(front == -1)
	{
		printf("\nQueue is empty!\n");
		printf("\n");
		return;
	}
	printf("\nThe element(s) in the Queue is/are: \n");
	if( front_pos <= rear_pos )
		while(front_pos <= rear_pos)
		{
			printf("%d ",cqueue_arr[front_pos]);
			front_pos++;
		}
	else
	{
		while(front_pos <= MAX-1)
		{
			printf("%d ",cqueue_arr[front_pos]);
			front_pos++;
		}
		front_pos = 0;
		while(front_pos <= rear_pos)
		{
			printf("%d ",cqueue_arr[front_pos]);
			front_pos++;
		}
	}
	printf("\n\n");
}
