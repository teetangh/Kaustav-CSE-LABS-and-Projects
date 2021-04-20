#include <stdio.h>
#include <stdlib.h>
#include "singlylinkedlistADT.h"

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
        }

    } while (choice < 7);
}
