// Working of arithmetic operators
#include <stdio.h>
int main()
{
    // Example 1: Arithmetic Operators
    int a = 9, b = 4, c;

    c = a + b;
    printf("a+b = %d \n", c);
    c = a - b;
    printf("a-b = %d \n", c);
    c = a * b;
    printf("a*b = %d \n", c);
    c = a / b;
    printf("a/b = %d \n", c);
    c = a % b;
    printf("Remainder when a divided by b = %d \n", c);

    // Example 2: Increment and Decrement Operators

    int a = 10, b = 100;
    float c = 10.5, d = 100.5;

    printf("++a = %d \n", ++a);
    printf("--b = %d \n", --b);
    printf("++c = %f \n", ++c);
    printf("--d = %f \n", --d);

    // Example 3: Assignment Operators

    int a = 5, c;

    c = a; // c is 5
    printf("c = %d\n", c);
    c += a; // c is 10
    printf("c = %d\n", c);
    c -= a; // c is 5
    printf("c = %d\n", c);
    c *= a; // c is 25
    printf("c = %d\n", c);
    c /= a; // c is 5
    printf("c = %d\n", c);
    c %= a; // c = 0
    printf("c = %d\n", c);

    // Example 4: Relational Operators

    int a = 5, b = 5, c = 10;

    printf("%d == %d is %d \n", a, b, a == b);
    printf("%d == %d is %d \n", a, c, a == c);
    printf("%d > %d is %d \n", a, b, a > b);
    printf("%d > %d is %d \n", a, c, a > c);
    printf("%d < %d is %d \n", a, b, a < b);
    printf("%d < %d is %d \n", a, c, a < c);
    printf("%d != %d is %d \n", a, b, a != b);
    printf("%d != %d is %d \n", a, c, a != c);
    printf("%d >= %d is %d \n", a, b, a >= b);
    printf("%d >= %d is %d \n", a, c, a >= c);
    printf("%d <= %d is %d \n", a, b, a <= b);
    printf("%d <= %d is %d \n", a, c, a <= c);

    // Example 5: Logical Operators

    int a = 5, b = 5, c = 10, result;

    result = (a == b) && (c > b);
    printf("(a == b) && (c > b) is %d \n", result);

    result = (a == b) && (c < b);
    printf("(a == b) && (c < b) is %d \n", result);

    result = (a == b) || (c < b);
    printf("(a == b) || (c < b) is %d \n", result);

    result = (a != b) || (c < b);
    printf("(a != b) || (c < b) is %d \n", result);

    result = !(a != b);
    printf("!(a != b) is %d \n", result);

    result = !(a == b);
    printf("!(a == b) is %d \n", result);

    // Example 6: sizeof Operator
    int a;
    float b;
    double c;
    char d;
    printf("Size of int=%lu bytes\n", sizeof(a));
    printf("Size of float=%lu bytes\n", sizeof(b));
    printf("Size of double=%lu bytes\n", sizeof(c));
    printf("Size of char=%lu byte\n", sizeof(d));

    return 0;
}