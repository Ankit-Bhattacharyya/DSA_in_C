#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

#define capacity 10

int arr[10];
int top = -1;

bool isEmpty()
{
	if(top==-1)
	{
		return true;
	}
	else
	{
		return false;
	}
}

void push(int item)
{
	if(top==capacity-1)
	{
		printf("Stack Overflow");
		return;
	}
	
	else
	{
		arr[top+1]=item;
		top = top+1;
	}
}

int pop()
{
	if(isEmpty()==true)
	{
		printf("Stack Underflow");
	}
	else
	{
		top=top-1;
		return arr[top];
	}
}

int peek()
{
	if(isEmpty()==true)
	{
		printf("Stack is Empty");
		return -1;
	}
	else
	{
		return arr[top];
	}
}

void display(int arr[])
{
	int i,size;
	size=sizeof(arr)/sizeof(arr[0]);
	if(top==-1)
	{
		printf("Stack is Empty\n");
	}
	else
	{
		for(i=top;i>=0;i--)
		{
			printf("\n %d",arr[i]);
		}
	}
}

int main(){
	int x,v;
	while(1){
		printf("\nPress 1 to push an element\n");
		printf("Press 2 to pop an element\n");
		printf("Press 3 to check top element\n");
		printf("Press 4 to display the stack\n");
		printf("Press 5 to exit\n");
		scanf("%d",&x);
		switch(x){
			case 1:
					printf("\nEnter a number:");
					scanf("%d",&v);
					push(v);
					break;
			case 2:
					v = pop();
					printf("The top element is popped");
					break;
			case 3: 
					v = peek();
					printf("\n The top element is %d",v);
					break;
			case 4:
					display(arr);
					break;
			case 5:		
					exit(0);
			default:
					printf("\n Wrong choice");
		}
	}
}
