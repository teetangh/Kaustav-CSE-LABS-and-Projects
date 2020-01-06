#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct node
{
    char data;
    struct node *next;
} * app;

app addfirst(char o)
{
    app x = (app)malloc(sizeof(struct node));
    x->data = o;
    x->next = NULL;
    return x;
}
void add(app s, char o)
{
    app x = (app)malloc(sizeof(struct node));
    app y;
    x->data = o;
    x->next = NULL;
    y = s;
    while (y->next != NULL)
    {
        y = y->next;
    }
    y->next = x;
}
void print(app s)
{
    app q = s;
    if (q == NULL)
    {
        printf("List empty\n");
        return;
    }
    while (q != NULL)
    {
        printf("%c", q->data);
        q = q->next;
    }
}
int main()
{
    app p = NULL;
    int i, n;
    char a[100];
    printf("Enter number\n");
    scanf("%s", a);
    i = strlen(a);
    p = addfirst(a[0]);
    for (n = 1; n < i; n++)
        add(p, a[n]);
    print(p);
}