#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct node
{
  char data[20];
  struct node *llink;
  struct node *rlink;
}*NODE;

void display(NODE first)
{
  if(first==NULL)
  {
    printf("List empty.\n");
    return;
  }
  while(first->rlink!=NULL)
  {
    printf("%s\t", first->data);
    first = first->rlink;
  }
  printf("%s\n", first->data);
}

NODE insert_first(NODE first, char ele[])
{
  NODE n = (NODE)malloc(sizeof(struct node));
  strcpy(n->data, ele); n->llink = NULL;
  if(first==NULL)
  {
    n->rlink = NULL;
    return n;
  }
  n->rlink = first;
  first->llink = n;
  return n;
}

NODE insert_rear(NODE first, char ele[])
{
  NODE n = (NODE)malloc(sizeof(struct node));
  strcpy(n->data, ele); n->llink = n->rlink = NULL;
  if(first==NULL)
    return n;
  NODE cur = first;
  while(cur->rlink!=NULL)
    cur = cur->rlink;
  cur->rlink = n;
  n->llink = cur;
  return first;
}

void reverse(NODE *head_ref) 
{ 
     NODE temp = NULL;   
     NODE cur = *head_ref; 
     while (cur !=  NULL) 
     { 
       temp = cur->llink; 
       cur->llink = cur->rlink; 
       cur->rlink = temp;               
       cur = cur->llink; 
     }       
     if(temp != NULL ) 
        *head_ref = temp->llink; 
}      

void main()
{
  NODE first = NULL;
  int ch; char ele[20];
  printf("1.Insert from front 2.Insert from rear\n");
  do
  {
    printf("Enter choice:\n");
    scanf("%d", &ch);
    switch(ch)
    {
      case 1: printf("Enter the element:\n");
          scanf("%s", &ele);
          first = insert_first(first, ele);
          break;
      case 2: printf("Enter the element:\n");
          scanf("%s", &ele);
          first = insert_rear(first, ele);
          break;
      default: break;
    }
  }while(ch<3);
  printf("List before reversal:\n");
  display(first);
  printf("List after reversal:\n");
  reverse(&first);
  display(first);
}

