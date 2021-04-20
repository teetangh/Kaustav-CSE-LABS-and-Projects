//AVL TREE
//Take previous question and rotate whenever balance factor is not satisfied#include <stdio.h>
#include <stdlib.h>
#include <stdio.h>

typedef struct node{
	int key;
	struct node *left, *right;
	int height;
}NODE;

int height(NODE *n){
	if(n==NULL)
		return 0;
	return n->height;
}

int max(int a, int b){
	return (a>b)?a:b;
}

NODE* rightRotate(NODE *y)
{
	NODE *x = y->left;
	NODE *T2 = x->right;

	x->right = y;
	y->left = T2;

	x->height = max(height(x->left), height(x->right)) + 1;
	y->height = max(height(y->left), height(y->right)) + 1;

	return x;
}

NODE* leftRotate(NODE *x)
{
	NODE *y = x->right;
	NODE *T2 = y->left;

	y->left = x;
	x->right = T2;

	x->height = max(height(x->left), height(x->right)) + 1;
	y->height = max(height(y->left), height(y->right)) + 1;

	return y;
}

int getBalance(NODE *N)
{
	if(N==NULL)
		return 0;
	return height(N->left)-height(N->right);
}

NODE* create(NODE *node, int x){
	// NODE *getnode;
	if(node == NULL){
		node = (NODE*)malloc(sizeof(NODE));
		node->key = x;
		node->left = node->right = NULL;
		node->height = 1;
	}
	else if(x>node->key){
		node->right=create(node->right, x);
		node->height = 1 + max(height(node->left), height(node->right));
	}
	else if(x<node->key){
		node->left=create(node->left, x);
		node->height = 1 + max(height(node->left), height(node->right));
	}
	else{
		printf("Duplicate Node \n");
		printf("Insertion Failed\n\n\n");
	}

	int balance = getBalance(node);

	//Left Left
	if (balance > 1 && x < node->left->key) 
        return rightRotate(node); 
  
    // Right Right 
    if (balance < -1 && x > node->right->key) 
        return leftRotate(node); 
  
    // Left Right 
    if (balance > 1 && x > node->left->key) { 
        node->left =  leftRotate(node->left); 
        return rightRotate(node); 
    } 
  
    // Right Left 
    if (balance < -1 && x < node->right->key) { 
        node->right = rightRotate(node->right); 
        return leftRotate(node); 
    }
	return(node);
}

void inorder(NODE *ptr){
	if(ptr!=NULL){
		inorder(ptr->left);
		printf("%d\t",ptr->key);
		inorder(ptr->right);
	}
}


void main(){
	int n,x,ch,i;
	NODE *root;
	root = NULL;
	while(1){
		printf("Enter Node or -1 to stop:\n");
		scanf("%d", &x);
		if(x==-1)
			break;
		root = create(root, x);
	}				
	printf("Inorder Traversal: \n");
	inorder(root);				
}