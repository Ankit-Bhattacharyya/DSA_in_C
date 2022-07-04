#include<stdio.h>
#include<stdlib.h>

typedef struct node{
	int val;
	node *next;
}node;

node *top = NULL;

void push(int item)
{
	node *newNode;
	newNode = (node *)malloc(sizeof(newNode));
	if(newNode==NULL)
	{
		printf("Stack Overflow");
		exit(1);
	}
	newNode->val = item;
	newNode->next = NULL;
	newNode->next = top;
	top = newNode;
}

void pop()
{
	if(top==NULL)
	{
		printf("stack is empty\n");
	}
	else
	{
		printf("\nTop element is poped\n");
		top = top->next;
	}
}

int peek()
{
	if(top==NULL)
	{
		return -1;
	}
	else
	{
		return top->val;
	}
}

void display()
{
	node *temp;
	temp = top;
	if(temp==NULL)
	{
		printf("stack is empty\n");
	}
	else
	{
		while(temp)
		{
			printf("%d\n",temp->val);
			temp = temp->next;
		}
	}
}

int main()
{
	int x,v;
	while(1){
		printf("Choose 1 to push element\n");
		printf("Choose 2 to pop element\n");
		printf("Choose 3 to peek element\n");
		printf("Choose 4 to display stack\n");
		printf("Choose 5 to exit\n");
		scanf("%d",&x);
		switch(x){
			case 1:
				printf("\nEnter element to push: ");
				scanf("%d",&v);
				push(v);
				break;
			case 2:
				pop();
				break;
			case 3:
				v = peek();
				if(v==-1)
				{
					printf("stack is empty\n");
				}
				else
				{
					printf("\nTop element is: %d\n",v);	
				}
				break;
			case 4:
				display();
				break;
			case 5:
				exit(0);
			default:
				printf("Wrong choice\n");
				break;
		}
	}
	return 0;
}
