#include <stdio.h>
#include <stdlib.h>
#include "doublylinkedlistADT.h"

void main()
{
    NODE first = NULL;
    int choice, ele;

    printf("1. Insert Front \n");
    printf("2. Insert Rear \n");
    printf("3. Delete Front \n");
    printf("4. Delete Rear \n");
    printf("5. Display. \n");

    do
    {
        printf("Enter your choice \n");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            printf("Enter the element \n");
            scanf("%d", &ele);

            first = insert_frontDL(first, ele);
            break;
        case 2:
            printf("Enter the element \n");
            scanf("%d", &ele);

            first = insert_rearDL(first, ele);
            break;

        case 3:
            first = delete_frontDL(first);
            break;

        case 4:
            first = delete_rearDL(first);
            break;

        case 5:
            printf("The elements in the list are:\n");
            display(first);
            break;
        }

    } while (choice < 6);
}