#include <stdio.h>

int main(int argc, char const *argv[])
{
    char c = 'a';
    printf("%c\n", c);

    int i = 14;
    printf("%d\n", i);

    long int li = 18;
    long long int lli = 501ll;
    printf("%ld\n", li);
    printf("%lld\n", lli);

    unsigned long int ui = 10u;
    unsigned long long int ulli = 10ull;
    printf("%lu\n", ui);
    printf("%llu\n", ulli);

    float f = 12.30f;
    double d = 3.1415;
    printf("%f\n", f);
    printf("%f\n", d);

    long double ld = 3.5;
    printf("%Lf\n", ld);

    return 0;
}
