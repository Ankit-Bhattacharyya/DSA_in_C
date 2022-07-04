#include<stdio.h>
#include<stdlib.h>

typedef struct node{
	node *prev;
	int val;
	node *next;
}node;

node *head = NULL;

//Insert at beginning
void insert_at_front(int item)
{
	node *newNode;
	newNode = (node *)malloc(sizeof(node));
	newNode->prev = NULL;
	newNode->val = item;
	newNode->next = NULL;
	newNode->next = head;
	if(head != NULL)
		head->prev = newNode;
	head =  newNode;
}

//Insert after a node
void insert_after_node(int item, int value)
{
	node *newNode,*temp,*after;
	temp = head;
	newNode = (node *)malloc(sizeof(node));
	while(temp->val != item)
	{
		temp = temp->next;
	}
	newNode->val = value;
	after = temp->next;
	temp->next = newNode;
	newNode->next = after;
}

//Insert before a node
void insert_before_node(int item, int value)
{
	node *newNode,*temp,*before;
	temp = head;
	newNode = (node *)malloc(sizeof(node));
	while(temp->val!=item)
	{
		temp=temp->next;
	}
	newNode->val = value;
	before = temp->prev;
	before->next = newNode;
	newNode->next = temp;
}

//Insert at end
void insert_at_end(int item)
{
	node *newNode, *temp;
	temp = head;
	newNode = (node *)malloc(sizeof(node));
	while(temp->next!=NULL)
	{
		temp = temp->next;
	}
	newNode->val = item;
	temp->next = newNode;
	newNode->next = NULL;
}

//Delete node at beginning
void delete_first_node()
{
	head = head->next;
}
//Delete specific node
void delete_specific_node(int item)
{
	node *temp, *before, *after;
	temp = head;
	while(temp->val!=item)
	{
		temp = temp->next;
	}
	before = temp->prev;
	after = temp->next;
	before->next = after;
	after->prev = before;
}
//Delete last node
void delete_last_node()
{
	node *temp, *before;
	temp = head;
	while(temp->next != NULL)
	{
		temp = temp->next;
	}
	before = temp->prev;
	before->next = NULL;
}

//Searching
void searching(int item)
{
	node *temp;
	temp = head;
	while(temp->next!=NULL)
	{
		if(temp->val==item)
		{
			printf("Present\n");
			break;
		}
		else
		{
			temp = temp->next;
		}
	}
	if(temp->val!=item)
	{
		printf("Not Present\n");
	}
	
}

//Delete Linked List
void delete_linked_list()
{
	head = NULL;
}

//Print
void print()
{
	node *temp;
	temp = head;
	if(head==NULL)
	{
		printf("No Node there\n");
	}
	else
	{
		while(temp)
		{
			printf("<-%d->",temp->val);
			temp = temp->next;
		}
	}
	printf("\n");
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
		printf("6. Delete specific node\n");
		printf("7. Delete node at end\n");
		printf("8. Search value\n");
		printf("9. Delete Linked List\n");
		printf("10. Display Linked List\n");
		printf("11. To exit program\n");
		scanf("%d",&x);
		switch(x)
		{
			case 1:
				printf("Enter value of node: ");
				scanf("%d",&v);
				insert_at_front(v);
				break;
			case 2:
				printf("Enter position: ");
				scanf("%d",&v);
				printf("Enter value: ");
				scanf("%d",&value);
				insert_after_node(v,value);
				break;
			case 3:
				printf("Enter position: ");
				scanf("%d",&v);
				printf("Enter value: ");
				scanf("%d",&value);
				insert_before_node(v,value);
				break;
			case 4:
				printf("Enter value of node: ");
				scanf("%d",&v);
				insert_at_end(v);
				break;
			case 5:
				delete_first_node();
				printf("Deleted first node\n");
				break;
			case 6:
				printf("Enter position: ");
				scanf("%d",&v);
				delete_specific_node(v);
				printf("Node Deleted\n");
				break;
			case 7:
				delete_last_node();
				printf("Deleted Last Node\n");
				break;
			case 8:
				printf("Enter value: ");
				scanf("%d",&v);
				searching(v);
			case 9:
				delete_linked_list();
				break;
			case 10:
				print();
				break;
			case 11:
				exit(0);
			default:
				printf("Wrong Choice!\n");
				break;
		}
	}
}
