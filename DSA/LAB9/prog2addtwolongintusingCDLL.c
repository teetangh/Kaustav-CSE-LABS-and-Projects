#include <stdio.h>
#include <stdlib.h>

// It is stil not circular yet
typedef struct node
{
    int data;
    struct node *llink;
    struct node *rlink;
} * NODE;

NODE getNode()
{
    NODE temp = (NODE)malloc(sizeof(struct node));
    return temp;
}

void insertFront(int item, NODE head)
{
    NODE temp, next;
    temp = getNode();

    temp->data = item;
    next = head->rlink;
    temp->llink = head;
    head->rlink = temp;
    temp->rlink = next;
    next->llink = temp;
}

//Function creates linked list representing the long int
NODE ReadLongInteger()
{
    NODE head;
    char str[100];
    int i, n;
    printf("Enter the string representing long integer");
    fflush(stdin);
    scanf(" %s", str);

    for (int n = 0; str[n]; n++)
        head = getNode();

    head->llink = head->rlink = head;
    //Extract each digit from left
    // and insert at the front of the list

    for (int i = n - 1; i >= 0; i--)
        insertFront(str[i] - '0', head);

    return head;
}

void Display(NODE head)
{
    NODE temp;
    for (temp = head->rlink; temp != head; temp = temp->rlink)
        printf("%d->", temp->data);
}

NODE AddLongIntger(NODE A, NODE B)
{
    int digit, sum, carry;
    NODE head, r, R, a, b;

    carry = 0;
    a = A->llink;
    b = B->llink;

    head = getNode();
    head->llink = head->rlink = head;

    while (a != A && b != B)
    {
        sum = a->data + b->data + carry;
        digit = sum % 10;
        carry = sum / 10;
        insertFront(digit, head);

        a = a->llink;
        b = b->llink;

        // Identify the bigger Number
        if (a != A)
        {
            r = a;
            R = A;
        }
        else
        {
            r = b;
            R = B;
        }

        // Add Carry to remaining digits of bigger Number

        while (r != R)
        {
            sum = r->data + carry;
            digit = sum % 10;
            carry = sum / 10;
            insertFront(digit, head);
            r = r->rlink;
        }

        // Insert the last carry if present
        if (carry)
            insertFront(carry, head);
        return head;
    }
}
void main()
{
    NODE a, b, sum;
    a = ReadLongInteger();
    b = ReadLongInteger();
    printf("\n Head Integer \n");
    Display(a);
    printf("\n Second Integer \n");
    Display(b);
    sum = AddLongIntger(a, b);
    printf("\n Sum of two given ");
    Display(sum);
}
