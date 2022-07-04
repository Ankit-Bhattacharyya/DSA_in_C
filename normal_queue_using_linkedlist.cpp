#include<stdio.h>
#include<stdlib.h>

typedef struct node{
	int data;
	node *next;
}node;

node *front = NULL;
node *back = NULL;

void enQueue(int item)
{
	node *temp, *newNode;
	newNode = (node *)malloc(sizeof(node));
	if(newNode==NULL)
	{
		printf("Overflow\n");
		exit(1);
	}
	else
	{	
		newNode->data = item;
		if(front==NULL)
		{
			front = newNode;
			back = newNode;
			newNode->next = NULL;
		}
		else
		{
			back->next = newNode;
			back = newNode;
			newNode->next = NULL;
		}
	}
}

void deQueue()
{
	if(front == NULL)
		printf("Queue is NULL\n");
	else
	{
		node *temp;
		temp = front;	
		front = front->next;
		free(temp);
	}
}

void print_items()
{
	if(front==NULL || back==NULL)
		printf("Queue is Empty\n");
	else
	{
		node *temp;
		temp = front;
		while(temp)
		{
			printf("%d->",temp->data);
			temp = temp->next;
		}
		printf("\n");
	}
}

int peek()
{
	return front->data;
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
