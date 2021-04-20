typedef struct{
	int a[10];
	int top;
}Stack ;


void push(Stack *,int);
int pop(Stack *);
void display(Stack *);