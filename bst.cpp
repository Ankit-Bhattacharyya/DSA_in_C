//BST

#include<stdio.h>
#include<stdbool.h>
#include<stdlib.h>

typedef struct node{
	node *left_child;
	int data;
	node *right_child;
}node;

node *ROOT = NULL;

bool searchElement(int item, node *root)
{
	if(root==NULL)
	{
		return false;
	}
	
	else if(root->data==item)
	{
		return true;
	}
	
	else
	{
		if(item<root->data)
		{
			searchElement(item,root->left_child);
		}
		if(item>root->data)
		{
			searchElement(item,root->right_child);
		}
	}
}

void createTree(int item, node *root)
{
	if(root == NULL)
	{
		node *newNode;
		newNode = (node *)malloc(sizeof(node));
		newNode->data = item;
		newNode->left_child = NULL;
		newNode->right_child = NULL;
		ROOT = newNode;
		return;
	}
	else
	{
		if(root->data>item)
		{
			if(root->left_child == NULL)
			{
				node *newNode;
				newNode = (node *)malloc(sizeof(node));
				newNode->data = item;
				root->left_child = newNode;
				newNode->left_child = NULL;
				newNode->right_child = NULL;
				return;
			}
			createTree(item,root->left_child);
		}
		if(root->data<item)
		{
			if(root->right_child == NULL)
			{
				node *newNode;
				newNode = (node *)malloc(sizeof(node));
				newNode->data = item;
				root->right_child = newNode;
				newNode->left_child = NULL;
				newNode->right_child = NULL;
				return;
			}
			createTree(item,root->right_child);
		}
	}
}

struct node* minValueNode(struct node* node)
{
    struct node* current = node;
    while (current && current->left_child != NULL)
        current = current->left_child;
 
    return current;
}

node* deleteSpecificNode(int item, node *root)
{
	node *temp;	
	if(root == NULL)
	{
		return root;
	}
	
	else if(item<root->data && item!=root->data)
	{
		temp = root;
		root->left_child = deleteSpecificNode(item, root->left_child);
		root = root->left_child;
	}
	
	else if(item>root->data && item!=root->data)
	{
		temp = root;
		root->right_child= deleteSpecificNode(item, root->right_child);
		root = root->right_child;
	}
	
	else
	{
		if(ROOT->left_child==NULL && ROOT->right_child==NULL)
		{
			ROOT = NULL;
		}
	 	if(root->left_child == NULL)
		{
            temp = root->right_child;
            return temp;
        }
        if(root->right_child == NULL) 
		{
            temp = root->left_child;
            return temp;
        }
        temp = minValueNode(root->right_child);
        root->data = temp->data;
        
        root->right_child = deleteSpecificNode(temp->data,root->right_child);
    }
    return root;
}

void inOrder(node *root)
{
	if(root!=NULL)
    {
        inOrder(root->left_child);
        printf("->%d->", root->data);
        inOrder(root->right_child);
    }
}

void preOrder(node *root)
{
	if(root!=NULL)
    {
    	printf("->%d->", root->data);
        preOrder(root->left_child);
        preOrder(root->right_child);
    }
}

void postOrder(node *root)
{
	if(root!=NULL)
    {
    	postOrder(root->left_child);
        postOrder(root->right_child);
        printf("->%d->", root->data);
    }
}

int main()
{
	int x,v;
	bool c;
	while(1)
	{
		printf("1. New Element:\n");
		printf("2. Delete Element:\n");
		printf("3. Inorder Traversal:\n");
		printf("4. Preorder Traversal:\n");
		printf("5. Postorder Traversal:\n");
		printf("6. Search Element:\n");
		printf("7. Exit:\n");
		scanf("%d",&x);
		
		switch(x)
		{
			case 1:
				printf("Enter value of new node: ");
				scanf("%d",&v);
				createTree(v,ROOT);
				break;
			case 2:
				printf("Enter value:");
				scanf("%d",&v);
				deleteSpecificNode(v,ROOT);
				break;
			case 3:
				printf("Inorder Sequence is:\n");
				inOrder(ROOT);
				printf("\n");
				break;
			case 4:
				printf("Preorder Sequence is:\n");
				preOrder(ROOT);
				printf("\n");
				break;
			case 5:
				printf("Postorder Sequence is:\n");
				postOrder(ROOT);
				printf("\n");
				break;
			case 6:
				printf("Enter value for search:");
				scanf("%d",&v);
				c = searchElement(v,ROOT);
				if(c==true)
					printf("FOUND\n");
				else
					printf("NOT FOUND\n");
				break;
			case 7:
				exit(0);
			default:
				printf("Wrong Choice\n");
				break;
		}
	}
	return 0;
}
