#include<stdio.h>
void create(int []);
void down_adjust(int [],int);

int main()
{
	int heap[30],n,i,last,temp;

	printf("Enter Number of Elements in the Array:\n");
	scanf("%d",&n);

	printf("\nEnter %d Elements in the Array:\n",n);
	for(i=1;i<=n;i++)
		scanf("%d",&heap[i]);

	/* Create a Heap */
	heap[0]=n;
	create(heap);

	/* Sorting */
	while(heap[0] > 1)
	{
		/* Swap heap[1] and heap[last] */
		last=heap[0];
		temp=heap[1];
		heap[1]=heap[last];
		heap[last]=temp;
		heap[0]--;
		down_adjust(heap,1);
	}

	/* Print Sorted Array */
	printf("\nThe Sorted Array is:");
	for(i=1;i<=n;i++)
		printf("\n%d",heap[i]);

	return 0;
}


void create(int heap[])
{
	int i,n;
	n=heap[0]; /* Number of Elements */

	for(i=n/2;i>=1;i--)
		down_adjust(heap,i);
}


void down_adjust(int heap[],int i)
{
	int j,temp,n,flag=1;
	n=heap[0];

	while(2*i<=n && flag==1)
	{
		j=2*i;    /* j points to the Left Child */
		if(j+1<=n && heap[j+1] > heap[j])
			j=j+1;
		if(heap[i] > heap[j])
			flag=0;
		else
		{
			temp=heap[i];
			heap[i]=heap[j];
			heap[j]=temp;
			i=j;
		}
	}
}
