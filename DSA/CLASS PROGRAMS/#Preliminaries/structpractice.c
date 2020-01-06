#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct student
{
    int *regno;
    char *name[20];
    float *cgpa;
} s1[10], s2, *s3;

void main()
{
    int reg = 20;
    s1[1].regno = &reg;

    strcpy(s2.name, "ABCD");

    s3 = (struct student *)malloc(sizeof(struct student));
    s3->regno = &reg;

    printf("%d \n", *(s1[1].regno));
    printf("%s \n", s2.name);
    printf("%d \n", *s3->regno);
}