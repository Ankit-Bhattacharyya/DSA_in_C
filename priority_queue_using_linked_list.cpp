#include<stdio.h>
#include<stdlib.h>
#include<string.h>

//#define MAX 10

typedef struct node{
	char name;
	int data;
	node *next;
}node;

node *front = NULL;
node *back = NULL;

void enQueue(char name_v, int item)
{
	node *newNode;
	newNode = (node *)malloc(sizeof(node));
	newNode->name = name_v;
	newNode->data = item;
	if(front == NULL)
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

void deQueue()
{
	if(front == NULL)
		printf("Queue is Empty\n");
	else
	{
		node *temp, *after, *before, *ptr;
		int value;
		temp = front;
		after = temp->next;
		while(temp->next)
		{
			if(temp->data<after->data)
				value = temp->data;
			else
				value = after->data;
			temp = temp->next;
		}
		if(front->next == NULL)
		{
			front = NULL;
			back = NULL;
		}
		else if(front->data == value)
		{
			front = front->next;
		}
		else
		{
			ptr = front;
			while(ptr->data!=value)
			{
				before = ptr;
				ptr = ptr->next;
			}
			ptr = ptr->next;
			before->next = ptr;
		}
	}
}

void printItems()
{
	if(front==NULL || back==NULL)
		printf("Queue is Empty\n");
	else
	{
		node *temp;
		temp = front;
		while(temp)
		{
			printf("%c-%d->",temp->name,temp->data);
			temp = temp->next;
		}
		printf("\n");
	}
}

int main()
{
	int x,v;
	char entry;
	while(1)
	{
		printf("1. Enqueue\n");
		printf("2. Dequeue\n");
		printf("3. Display\n");
		printf("4. Exit\n");
		scanf("%d",&x);
		switch(x)
		{
			case 1:
				fflush(stdin);
				printf("Enter name:");
				scanf("%s",&entry);
				printf("Enter value:");
				scanf("%d",&v);
				enQueue(entry,v);
				break;
			case 2:
				deQueue();
				printf("Deleted Items\n");
				break;
			case 3:
				printItems();
				break;
			case 4:
				exit(0);
			default:
				printf("Wrong Choice\n");
				break;
		}
	}
	return 0;
}
