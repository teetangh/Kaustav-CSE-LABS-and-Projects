#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int data;
    struct node *next;
} * NODE;

NODE insert_sort(NODE first, int ele)
{
    NODE n = (NODE)malloc(sizeof(struct node));
    n->data = ele;
    n->next = NULL;

    if (first == NULL)
        return n;

    if (ele <= first->data)
    {
        n->next = first;
        return n;
    }

    NODE prev, curr;
    prev = NULL;
    curr = first;

    while (curr != NULL && (curr->data) < ele)
    {
        prev = curr;
        curr = curr->next;
    }

    prev->next = n;
    n->next = curr;
    return first;
}

void display(NODE first)
{
    if (first == NULL)
    {
        printf("List Empty \n");
        return;
    }

    while (first != NULL)
    {
        /* code */
        printf("%d ->", first->data);
        first = first->next;
    }
}

NODE insertFront(NODE first, int ele)
{
    NODE n;
    n = (NODE)malloc(sizeof(struct node));

    n->data = ele;
    n->next = NULL;

    if (first == NULL)
        return n;

    n->next = first;
    return n;
}

NODE insertRear(NODE first, int ele)
{
    NODE n;
    n = (NODE)malloc(sizeof(struct node));

    if (n == NULL)
    {
        printf("Memory not found \n");
        exit(0);
    }

    n->data = ele;
    n->next = NULL;

    if (first == NULL)
        return n;

    NODE last = first;

    while (last->next != NULL)
        last = last->next;

    last->next = n;
    return first;
}

NODE deleteFront(NODE first)
{
    if (first == NULL)
    {
        printf("List is empty");
        return first;
    }

    NODE temp = first;
    first = first->next;

    printf("The element deleted is %d ", temp->data);
    free(temp);

    return first;
}
NODE deleteRear(NODE first)
{
    if (first == NULL)
    {
        printf("List is empty");
        return first;
    }

    NODE prev = NULL, last = first;

    while (last->next != NULL)
    {
        prev = last;
        last = last->next;
    }

    if (prev == NULL)
        return NULL;

    else
    {
        free(last);
        prev->next = NULL;
        return first;
    }
}

void remove_duplicates(NODE first)
{
    if (first == NULL)
    {
        printf("List is empty \n");
        return;
    }

    NODE curr = first, dup;

    while (curr != NULL && curr->next != NULL)
    {
        if (curr->data == curr->next->data)
        {
            dup = curr->next;
            curr->next = dup->next;
            free(dup);
        }

        else
        {
            curr = curr->next;
        }
    }
}

NODE removeduplicatesunsort(NODE first)
{
    NODE temp1 = first;
    NODE temp2 = first->next;

    while (temp1->next->next != NULL)
    {
        while (temp2->next != NULL)
        {
            /* code */
            if (temp1->data == temp2->data)
            {
                temp1->next = temp2->next;
                temp2 = temp2->next;
            }

            else if (temp1->data != temp2->data)
                temp2 = temp2->next;
        }

        temp1 = temp1->next;
        temp2 = temp1->next;
    }

    return first;
}

void main()
{
    NODE first = NULL;
    int choice, ele;

    printf("1. Insert Front \n");
    printf("2. Insert Rear \n");
    printf("3. Delete Front \n");
    printf("4. Delete Rear \n");
    printf("5. Display. \n");
    printf("6. Delete Duplicates. \n");
    printf("7. Delete Duplicates. test \n");

    do
    {
        printf("Enter your choice \n");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            printf("Enter the element \n");
            scanf("%d", &ele);

            first = insertFront(first, ele);
            break;
        case 2:
            printf("Enter the element \n");
            scanf("%d", &ele);

            first = insertRear(first, ele);
            break;

        case 3:
            first = deleteFront(first);
            break;

        case 4:
            first = deleteRear(first);
            break;

        case 5:
            printf("The elements in the list are:\n");
            display(first);
            break;
        case 6:
            remove_duplicates(first);
            break;

        case 7:
            first = removeduplicatesunsort(first);
            break;
        }

    } while (choice < 8);
}