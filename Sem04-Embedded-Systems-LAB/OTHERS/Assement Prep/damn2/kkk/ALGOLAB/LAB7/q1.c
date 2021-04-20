#include <stdio.h>
#include <stdlib.h>

typedef struct node{
	int info;
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

NODE* create(NODE *bnode, int x){
	// NODE *getnode;
	if(bnode == NULL){
		bnode = (NODE*)malloc(sizeof(NODE));
		bnode-> info = x;
		bnode->left = bnode->right = NULL;
		bnode->height = 1;
	}
	else if(x>bnode->info){
		bnode->right=create(bnode->right, x);
		bnode->height = 1 + max(height(bnode->left), height(bnode->right));
	}
	else if(x<bnode->info){
		bnode->left=create(bnode->left, x);
		bnode->height = 1 + max(height(bnode->left), height(bnode->right));
	}
	else{
		printf("Duplicate Node \n");
		printf("Insertion Failed\n\n\n");
	}
	return(bnode);
}

void postorder(NODE *ptr){
	if(ptr!=NULL){
		postorder(ptr->left);
		postorder(ptr->right);
		int balance = height(ptr->left)-height(ptr->right);
		printf("Node:%5d has Height: %5d and balance factor = %d\n", ptr->info, ptr->height, balance);
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
	printf("Postorder Traversal: \n");
	postorder(root);				
}