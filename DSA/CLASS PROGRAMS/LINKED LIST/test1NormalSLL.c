#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int data;
    struct node *next;
} * NODE;
NODE insertFront(NODE first, int data)
{
    NODE newNode = (NODE)malloc(sizeof(struct node));
    newNode->data = data;
    newNode->next = NULL;

    if (first == NULL)
        first = newNode;

    else
    {
        newNode->next = first;
        first = newNode;
    }
    return first;
}

NODE insertRear(NODE first, int data)
{
    NODE newNode = (NODE)malloc(sizeof(struct node));
    newNode->data = data;
    newNode->next = NULL;

    if (first == NULL)
        first = newNode;
    else
    {
        NODE temp = first;
        while (temp->next != NULL)
            temp = temp->next;

        temp->next = newNode;
    }
    return first;
}

NODE deleteFront(NODE first)
{
    NODE temp = first;
    if (first == NULL)
    {
        printf("Linked List is Empty from deleteFront func. \n");
        return NULL;
    }
    else
    {
        first = first->next;
        printf("The element deleted by deleteFront func was %d ", temp->data);
        free(temp);
        return first;
    }
}

NODE deleteRear(NODE first)
{
    NODE curr = first;
    NODE prev = NULL;
    if (first == NULL)
    {
        printf("Linked List is Empty from deleteRear func. \n");
        return NULL;
    }
    else
    {
        while (curr->next != NULL)
        {
            prev = curr;
            curr = curr->next;
        }
        prev->next = NULL;
        printf("The element deleted by deleteRear func was %d ", curr->data);
        free(curr);
    }
    return first;
}

void displaySLL(NODE head)
{
    NODE temp = head;
    if (head == NULL)
    {
        printf("Empty List \n");
        return;
    }

    while (temp != NULL)
    {
        printf("%d->", temp->data);
        temp = temp->next;
    }

    printf("\n");
}
void main()
{
    NODE head = NULL;

    printf("1.insertFront\n");
    printf("2.insertRear\n");
    printf("3.deleteFront\n");
    printf("4.deleteRear\n");
    printf("5.displaySLL\n");
    printf("6.Exit\n");
    int choice;

    int value;
    while (1)
    {
        printf("Enter your choice \n ");
        scanf(" %d", &choice);
        switch (choice)
        {
        case 1:
            printf("Enter element to be inserted at Front ");
            scanf(" %d", &value);
            head = insertFront(head, value);
            break;
        case 2:
            printf("Enter element to be inserted at Rear ");
            scanf(" %d", &value);
            head = insertRear(head, value);
            break;
        case 3:
            head = deleteFront(head);
            break;
        case 4:
            head = deleteRear(head);
            break;
        case 5:
            displaySLL(head);
            break;
        case 6:
            exit(0);
            break;
        }
    }
}