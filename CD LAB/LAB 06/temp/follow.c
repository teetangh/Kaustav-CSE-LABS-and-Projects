#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(int argc, char const *argv[])
{

    char a[100][100], b;
    int n;

    printf("Enter the number of productions\n");
    scanf("%d", &n);
    printf("Enter the production rules\n");

    for (int i = 0; i < n; i++)
        scanf("%s", a[i]);

    printf("Follow of (%c) =  {$} \n", a[0][0]);

    for (int i = 1; i < n; i++)
    {
        printf("Follow (%c) = {", a[i][0]);

        for (int j = 0; j < n; j++)
            for (int k = 3; k < strlen(a[j]); k++)
                if (a[j][k] == a[i][0])
                    printf("%c", a[j][k + 1]);

        printf("}\n");
    }

    return 0;
}
