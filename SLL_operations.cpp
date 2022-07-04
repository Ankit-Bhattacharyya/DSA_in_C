#include<stdio.h>
#include<stdlib.h>

typedef struct node{
	int data;
	node *link;
}node;

node *head = NULL;

//Insert at the beginning
void insert_at_begining(int item)
{
	node *newNode;
	newNode = (node *)malloc(sizeof(node));
	newNode->data = item;
	newNode->link = NULL;
	newNode->link = head;
	head = newNode;
}

//Insert after a node
void insert_after_a_node(int item,int after_val)
{
	node *newNode,*temp,*after;
	temp = head;
	newNode = (node *)malloc(sizeof(node));
	while(temp->data!=after_val)
	{
		temp = temp->link;
	}
	newNode->data = item;
	after = temp->link;
	temp->link = newNode;
	newNode->link = after;
	
}

//Insert before a node
void insert_before_a_node(int item, int before_val)
{
	node *newNode, *temp, *before;
	temp = head;
	newNode = (node *)malloc(sizeof(node));
	while(temp->data!=before_val)
	{
		before = temp;
		temp = temp->link;
	}
	newNode->data = item;
	before->link = newNode;
	newNode->link = temp;
}

//Insert at the end
void insert_at_end(int item)
{
	node *newNode, *temp;
	temp = head;
	newNode = (node *)malloc(sizeof(node));
	while(temp->link)
	{
		temp = temp->link;
	}
	newNode->data = item;
	newNode->link = NULL;
	temp->link = newNode;
}

//Delete Starting Node
void delete_first_node()
{
	head = head->link;
}

//Delete after a Node
void delete_after_node(int value)
{
	node *temp, *after;
	temp = head;
	after = temp->link;
	while(temp->data != value)
	{
		temp = temp->link;
		after = after->link;
	}
	temp->link = after->link;
}
/*
//Delete before a Node
void delete_before_node(int value)
{
	node *temp, *before;
	temp = head;
	while(temp->data != value)
	{
		before = temp;
		temp = temp->link;
	}
	before->link = temp->link;
}
*/
//Delete Specific Node
void delete_specific_node(int value)
{
	node *temp, *position;
	temp = head;
	while(temp->data != value)
	{
		position = temp;
		temp = temp->link;
	}
	position->link = temp->link;
}

//Delete Last Node
void delete_last_node()
{
	node *temp, *before;
	temp = head;
	while(temp->link != NULL)
	{
		before = temp;
		temp = temp->link;
	}
	before->link = NULL;
}

//Searching
void search(int v)
{
	node *temp;
	temp = head;
	while(temp->link != NULL)
	{
		if(temp->data == v)
		{
			break;
		}
		temp = temp->link;
	}
	if(temp->data == v)
	{
		printf("Present\n");
	}
	else
	{
		printf("Not present\n");
	}
}
//Delete Linked list
void delete_linkedlist()
{
	head = NULL;
}

//Display Linked List
void print()
{
	node *temp;
	temp = head;
	if(temp==NULL)
	{
		printf("No node is there.\n");
	}
	else
	{
		while(temp)
		{
			printf("%d->",temp->data);
			temp = temp->link;
		}
		printf("\n");
	}
}

int main()
{
	int x,v,value;
	while(1)
	{
		printf("1. Insert node at begining\n");
		printf("2. Insert node after a node\n");
		printf("3. Insert node before a node\n");
		printf("4. Insert node at the end\n");
		printf("5. Delete node at begining\n");
		printf("6. Delete node after a node\n");
	//	printf("7. Delete node before a node\n");
		printf("7. Delete specific node\n");
		printf("8. Delete node at end\n");
		printf("9. Search value\n");
		printf("10. Delete Linked List\n");
		printf("11. Display Linked List\n");
		printf("12. To exit program\n");
		scanf("%d",&x);
		switch(x)
		{
			case 1:
				printf("Enter value to insert at begining: ");
				scanf("%d",&v);
				insert_at_begining(v);
				break;
			case 2:
				printf("Enter value to insert after a node: ");
				scanf("%d",&v);
				printf("Enter value of node after which want to fix position: ");
				scanf("%d",&value);
				insert_after_a_node(v,value);
				break;
			case 3:
				printf("Enter value to insert before a node: ");
				scanf("%d",&v);
				printf("Enter value of node before which want to fix position: ");
				scanf("%d",&value);
				insert_before_a_node(v,value);
				break;
			case 4:
				printf("Enter value to insert at the end: ");
				scanf("%d",&v);
				insert_at_end(v);
				break;
			case 5:
				printf("Deleted First Node\n");
				delete_first_node();
				break;
			case 6:
				printf("Enter the value of node after want delete: ");
				scanf("%d",&value);
				delete_after_node(value);
				break;
			case 7:
				printf("Enter the value of node want delete: ");
				scanf("%d",&value);
				delete_specific_node(value);
				break;
			case 8:
				printf("Deleted Last Node\n");
				delete_last_node();
				break;
			case 9:
				printf("Enter value to search: ");
				scanf("%d",&v);
				search(v);	
				break;
			case 10:
				delete_linkedlist();
				break;	
			case 11:
				print();
				break;
			case 12:
				exit(0);
			default:
				printf("Wrong choice!\n");
				break;
		}
	}
	return 0;
}
