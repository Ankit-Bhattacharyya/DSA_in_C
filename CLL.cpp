// Circular SLL

#include<stdio.h>
#include<stdlib.h>

typedef struct node{
	int data;
	node *next;
}node;

node *head = NULL;

//Insert at beginning
void insert_at_beginning(int item)
{
	node *newNode;
	newNode = (node *)malloc(sizeof(node));
	newNode->data = item;
	if(head==NULL)
	{
		newNode->next = newNode;
	}
	else
	{
		node *temp;
		temp = head;
		newNode->next = temp;
		while(temp->next!=head)
		{
			temp = temp->next;
		}
		temp->next = newNode;	
	}
	head = newNode;
}

//Insert after a node
void insert_after_node(int item, int value)
{
	node *newNode, *temp, *after;
	temp = head;
	newNode = (node *)malloc(sizeof(node));
	while(temp->data != item)
	{
		temp = temp->next;
	}
	newNode->data = value;
	after = temp->next;
	temp->next = newNode;
	newNode->next = after;
}

//Insert before a node
void insert_before_node(int item, int value)
{
	node *newNode, *temp, *before;
	temp = head;
	newNode = (node *)malloc(sizeof(node));
	while(temp->data != item)
	{
		before = temp;
		temp = temp->next;
	}
	newNode->data = value;
	before->next = newNode;
	newNode->next = temp;
}

//Insert at end
void insert_at_end(int item)
{
	node *newNode, *temp;
	temp = head;
	newNode = (node *)malloc(sizeof(node));
	while(temp->next != head)
	{
		temp = temp->next;
	}
	newNode->data = item;
	temp->next = newNode;
	newNode->next = head;
}

//Delete first node
void delete_first_node()
{
	node *temp;
	if(head->next == head)
	{
		head = NULL;
	}
	else
	{
		temp = head;
		while(temp->next != head)
		{
			temp = temp->next;
		}
		head = head->next;
		temp->next = head;
	}
}

//Delete Specific Node
void delete_specific_node(int item)
{
	node *temp, *before;
	temp = head;
	while(temp->data != item)
	{
		before = temp;
		temp = temp->next;
	}
	before->next = temp->next;
}

//Delete Last node
void delete_last_node()
{
	node *temp, *before;
	temp = head;
	while(temp->next != head)
	{
		before = temp;
		temp = temp->next;
	}
	before->next = head;
}

//Searching
void searching(int item)
{
	node *temp;
	temp = head;
	while(temp->next != head)
	{
		if(temp->data == item)
		{
			break;
		}
		temp = temp->next;
	}
	if(temp->data == item)
		printf("Present\n");
	else
		printf("Not Present\n");
}

//Delete Linked List
void delete_linked_list()
{
	head = NULL;
}

//Display Linked List
void print()
{
	node *temp;
	temp = head;
	if(head == NULL)
	{
		printf("No node is there\n");
	}
	else
	{
		do
		{
			printf("->%d->",temp->data);
			temp = temp->next;
		}while(temp!=head);
		printf("\n");
	}
}

int main()
{
	int x,v,value;
	while(1)
	{
		printf("1. Crate first node\n");
		printf("2. Insert node after a node\n");
		printf("3. Insert node before a node\n");
		printf("4. Insert node at end\n");
		printf("5. Delete first node\n");
		printf("6. Delete specific node\n");
		printf("7. Delete last node\n");
		printf("8. Search Value in Linked List\n");
		printf("9. Delete Linked list\n");
		printf("10. Display Linked List\n");
		printf("11. Exit\n");
		scanf("%d",&x);
		switch(x)
		{
			case 1:
				printf("Enter value: ");
				scanf("%d",&v);
				insert_at_beginning(v);
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
				printf("Enter value: ");
				scanf("%d",&v);
				insert_at_end(v);
				break;
			case 5:
				delete_first_node();
				printf("Deleted First Node\n");
				break;
			case 6:
				printf("Enter value of node: ");
				scanf("%d",&v);
				delete_specific_node(v);
				printf("Deleted Specific Node\n");
				break;
			case 7:
				delete_last_node();
				printf("Deleted Last Node\n");
				break;
			case 8:
				printf("Enter value: ");
				scanf("%d",&v);
				searching(v);
				break;
			case 9:
				delete_linked_list();
				printf("Deleted Linked List\n");
				break;
			case 10:
				print();
				break;
			case 11:
				exit(0);
			default:
				printf("Wrong Choice!\n");
		}
	}
}
