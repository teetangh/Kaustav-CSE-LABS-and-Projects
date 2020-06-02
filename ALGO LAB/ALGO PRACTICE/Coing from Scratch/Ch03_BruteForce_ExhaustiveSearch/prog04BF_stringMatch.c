#include <stdio.h>
#include <string.h>

int BruteForceStringMatch(char *T, char *P)
{
    int n = strlen(T);
    int m = strlen(P);
    for (int i = 0; i <= (n - m); i++)
    {
        int j = 0;
        while (j < m && P[j] == T[i + j])
            j++;

        if (j == m)
            return i;
    }
    return -1;
}

int main()
{
    char T[100];
    char P[100];

    printf("Enter the text \n");
    scanf(" %s", &T);

    printf("Enter the pattern\n");
    scanf(" %s", &P);

    int answer = BruteForceStringMatch(T, P);

    if (answer == -1)
        printf("Pattern NOT FOUND\n");
    else
        printf("Pattern FOUND at index %d", answer);
    return 0;
}
// // SampleIO
//  Enter the text
// bess_knew_about_baoba
// Enter the pattern
// oba
// Pattern FOUND at index 18