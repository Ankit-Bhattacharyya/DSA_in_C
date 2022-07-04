#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

#define capacity 10

int arr[capacity];
int back = -1;
int front = -1;

bool isEmpty()
{
	if(back == -1)
	{
		return true;
	}
	else
	{
		return false;
	}
}

void enQueue(int item)
{
	if(back == capacity-1)
	{
		printf("Over Flow!\n");
	}
	else
	{
		if(front == -1)
				front++;
		back++;
		arr[back] = item;
	}
}

void deQueue()
{
	if(isEmpty()==true)
		printf("Queue is empty!\n");
	else
	{
		front++;
		if(front > back)
			front = back = -1;
	}
}

void print_items()
{
	if(isEmpty()==true)
		printf("Queue is Empty\n");
	else
	{
		for(int i=front;i<=back;i++)
		{
			printf("%d ",arr[i]);
		}
		printf("\n");
	}
}

int peek()
{
	if(isEmpty() == true)
	{
		printf("Queue is Empty\n");
		return -1;
	}
	else
		return arr[front];
}

int main()
{
	int x,v;
	while(1)
	{
		printf("1. Enqueue Element:\n");
		printf("2. Dequeue Element:\n");
		printf("3. Display Element:\n");
		printf("4. Peek checking:\n");
		printf("5. Exit:\n");
		scanf("%d",&x);
		switch(x)
		{
			case 1:
				printf("Enter Element: ");
				scanf("%d",&v);
				enQueue(v);
				break;
			case 2:
				deQueue();
				printf("Deleted items\n");
				break;
			case 3:
				print_items();
				break;
			case 4:
				v = peek();
				printf("Peek element is:%d\n",v);
				break;
			case 5:
				exit(0);
			default:
				printf("Wrong Choice!\n");
				break;
		}
	}
	return 0;
}
