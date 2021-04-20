#include <stdio.h>

void randomNumberGEnerator(int *r, int n, int m, int seed, int a, int b)
{
    r[0] = 0;
    for (int i = 1; i <= n; i++)
        r[i] = (a * r[i - 1] + b) % m;
}

int main()
{
    int n;
    int r[100];
    printf("Please enter the number of random numers you need");
    scanf(" %d", &n);
    int seed, a, b, m;
    printf("Please enter the values of seed, a b,m");
    scanf(" %d %d %d %d", &seed, &a, &b, &m);

    randomNumberGEnerator(r, n, m, seed, a, b);
    for (int i = 0; i <= n; i++)
        printf(" %d", r[i]);
}
// // Sample IO
// Please enter the number of random numers you need10
// Please enter the values of seed, a b,m6 7 8 9
//  0 8 1 6 5 7 3 2 4 0 8