#include "circularsinglylinkedlistADT.h"
#include <stdio.h>
#include <stdlib.h>

void main()
{
    NODE first = NULL;
    int choice, ele;

    printf("1. Insert Front \n");
    printf("2. Insert Rear \n");
    printf("3. Delete Front \n");
    printf("4. Delete Rear \n");
    printf("5. Display. \n");
    // printf("6. Delete Duplicates. \n");

    do
    {
        printf("Enter your choice \n");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            printf("Enter the element \n");
            scanf("%d", &ele);

            first = insert_frontCSL(first, ele);
            break;
        case 2:
            printf("Enter the element \n");
            scanf("%d", &ele);

            first = insert_rearCSL(first, ele);
            break;

        case 3:
            first = delete_frontCSL(first);
            break;

        case 4:
            first = delete_rearCSL(first);
            break;

        case 5:
            printf("The elements in the list are:\n");
            display_CSL(first);
            break;
        }

    } while (choice < 6);
}
