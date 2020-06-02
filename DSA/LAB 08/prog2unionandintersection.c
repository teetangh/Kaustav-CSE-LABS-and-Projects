#include <stdio.h>
#include <stdlib.h>
#include "singlylinkedlistADT.h"

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

NODE union_L1L2(NODE L1, NODE L2)
{
    NODE L3 = NULL;

    if (L1 == NULL && L2 != NULL)
        return L2;

    if (L1 != NULL && L2 == NULL)
        return L1;

    if (L1 == NULL && L2 == NULL)
        return L1;

    while (L1 != NULL && L2 != NULL)
    {
        if (L1->data == L2->data)
        {
            L3 = insert_sort(L3, L1->data);
            L1 = L1->next;
            L2 = L2->next;
        }

        else if (L1->data < L2->data)
        {
            L3 = insert_sort(L3, L1->data);
            L1 = L1->next;
        }

        else
        {
            L3 = insert_sort(L3, L2->data);
            L2 = L2->next;
        }
    }
    while (L1 != NULL)
    {
        L3 = insert_sort(L3, L1->data);
        L1 = L1->next;
    }

    while (L2 != NULL)
    {
        L3 = insert_sort(L3, L2->data);
        L2 = L2->next;
    }
    return L3;
}

NODE intersection_L1L2(NODE L1, NODE L2)
{
    NODE L5 = NULL;

    if (L1 == NULL || L2 == NULL)
        return L5;

    // if (L1 != NULL && L2 == NULL)
    //     return L3;

    // if (L1 == NULL && L2 == NULL)
    //     return L3;

    while (L1 != NULL && L2 != NULL)
    {
        if (L1->data == L2->data)
        {
            L5 = insert_sort(L5, L1->data);
            L1 = L1->next;
            L2 = L2->next;
        }

        else if (L1->data < L2->data)
        {
            // L3 = insert_sort(L3, L1->data);
            L1 = L1->next;
        }

        else
        {
            // L3 = insert_sort(L3, L2->data);
            L2 = L2->next;
        }

        // while (L1 != NULL)
        // {
        //     L3 = insert_sort(L3, L1->data);
        //     L1 = L1->next;
        // }

        // while (L2 != NULL)
        // {
        //     L3 = insert_sort(L3, L2->data);
        //     L2 = L2->next;
        // }
    }

    return L5;
}
void main()
{
    int ele, ele2;
    NODE L1 = NULL;
    NODE L2 = NULL;

    do
    {
        printf("Create the list 1 \n");
        printf("Enter the elements for L1 ");
        scanf("%d", &ele);

        if (ele != -9999)
            L1 = insert_sort(L1, ele);

    } while (ele != -9999);

    do
    {
        printf("Create the list 2 \n");
        printf("Enter the elements for L2 ");
        scanf("%d", &ele2);

        if (ele2 != -9999)
            L2 = insert_sort(L2, ele2);
    } while (ele2 != -9999);

    remove_duplicates(L1);
    remove_duplicates(L2);

    printf("Displaying List 1 after removing duplicates \n");
    display(L1);
    printf("\n");
    printf("Displaying List 2 after removing duplicates \n");
    display(L2);
    printf("\n");

    NODE L4 = NULL;
    L4 = union_L1L2(L1, L2);

    printf("Displaying Union of List 1 and 2 \n");
    display(L4);

    NODE L6 = NULL;
    L6 = intersection_L1L2(L1, L2);

    printf("\n");

    printf("Displaying Intersection of List 1 and 2 \n");
    display(L6);
}
