
/*Help of this program we are learning how to
Reverse words without reversing the individual words.
Using Stack. 
Time complexity : O(n).
*/

/* Include header file*/
#include <stdio.h>
#include <stdlib.h>

struct Stack
{
    /*Data field*/
    char data;
    /*Pointer field*/
    struct Stack *next;
};

/*Function declaration section*/
void pop(struct Stack **);
void push(char, struct Stack **);
void reverse_word(char *, struct Stack **);

/*Insert Stack element*/
void push(char value, struct Stack **top)
{
    struct Stack *new_node = (struct Stack *)malloc(sizeof(struct Stack));
    if (new_node != NULL)
    {
        new_node->data = value;
        new_node->next = *top;
        *top = new_node;
    }
    else
    {
        printf("\n Memory overflow.");
        return;
    }
}

/*Remove stack top element*/
void pop(struct Stack **top)
{
    if (*top != NULL)
    {
        struct Stack *remove = *top;
        *top = (*top)->next;
        remove->next = NULL;
        free(remove);
        remove = NULL;
    }
}

/*assign given word of string into stack*/
void fill_data(char *temp, struct Stack **top, int start, int end)
{
    for (end; end >= start; end--)
    {
        push(temp[end], top);
    }
}

/*Reverse word*/
void reverse_word(char *temp, struct Stack **top)
{

    if (temp[0] == '\n')
    {
        printf("\n Empty expression ");
        return;
    }
    printf("\n Input String: %s", temp);
    int index = 0, counter = 0;
    for (index = 0; temp[index] != '\0'; index++)
    {

        if (temp[index] == ' ')
        {
            fill_data(temp, top, index - counter, index);
            counter = 0;
        }
        else if (temp[index + 1] == '\0')
        {
            /*add space to last word*/
            push(' ', top);
            fill_data(temp, top, (index - counter), index);
        }
        else
        {
            counter++;
        }
    }
    counter = index;
    index = 0;
    /*assign stack element to original string */
    while (*top && index < counter)
    {
        temp[index] = (*top)->data;
        pop(top);
        index++;
    }

    printf("\nOutput String: %s", temp);
}

/*Main function*/
int main()
{
    /*start execution*/
    // char array[] = "code to like you Are";
    printf("Enter String");
    char array[50];
    gets(array);
    struct Stack *top = NULL;
    reverse_word(array, &top);
    printf("\n");

    return 0;
    /* End execution of program */
}
