// Copyright (c) 21 December 2020 Kaustav Ghosh

// Permission is hereby granted, free of charge, to any person obtaining a copy
// of this software and associated documentation files (the "Software"), to deal
// in the Software without restriction, including without limitation the rights
// to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
// copies of the Software, and to permit persons to whom the Software is
// furnished to do so, subject to the following conditions:

// The above copyright notice and this permission notice shall be included in all
// copies or substantial portions of the Software.

// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
// IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
// FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
// AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
// LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
// OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
// SOFTWARE.

// #include "/home/student/Desktop/KaustavLABS3/CD LAB/LAB 04/lab04_q1_symbol_table_header.h"
#include "/home/kaustav/Desktop/KaustavLABS3/CD LAB/LAB 04/lab04_q1_symbol_table_header.h"

int curr = 0;
// char str[100];
static char str[700000000];

// FILE *fp = fopen("lab04_q1_input.c", "r");
FILE *fp;
struct token *currentToken;
bool isBacktracking = false;
////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void Program();
void declarations();
void data_type();
void identifier_list();
void identifier_list_factors();
void assign_stat();
void assign_stat_factors();

////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void success()
{
    printf("SUCCESS\n");
    exit(0);
}

void invalid()
{
    printf("Error at Row %d : Column %d ::", currentToken->row, currentToken->column);
    exit(0);
}

void tokenDebug()
{
    printf("Token Scanned < %s , %s > \n ", currentToken->lexeme, currentToken->type);
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void Program()
{
    if (strcmp(currentToken->lexeme, "main") == 0)
    {
        currentToken = getNextToken(fp), tokenDebug();
        if (strcmp(currentToken->lexeme, "(") == 0)
        {
            currentToken = getNextToken(fp), tokenDebug();
            if (strcmp(currentToken->lexeme, ")") == 0)
            {
                currentToken = getNextToken(fp), tokenDebug();
                if (strcmp(currentToken->lexeme, "{") == 0)
                {
                    currentToken = getNextToken(fp), tokenDebug();

                    declarations();
                    assign_stat();
                    if (strcmp(currentToken->lexeme, "}") == 0)
                        return;
                    else
                    {
                        printf("} expected \n");
                        invalid();
                    }
                }
                else
                {
                    printf("{ expected \n");
                    invalid();
                }
            }
            else
            {
                printf(") expected \n");
                invalid();
            }
        }
        else
        {
            printf("( expected \n");
            invalid();
        }
    }
    else
    {
        printf("main expected \n");
        invalid();
    }
}

void declarations()
{
    char first_of_declarations[2][10] = {"int", "char"};
    int flag = 0;
    for (int i = 0; i < sizeof(first_of_declarations) / sizeof(first_of_declarations[0]); ++i)
    {
        if (strcmp(currentToken->lexeme, first_of_declarations[i]) == 0)
            flag++;
    }

    if (flag)
    {
        data_type();
        identifier_list();
        if (strcmp(currentToken->lexeme, ";") == 0)
        {
            currentToken = getNextToken(fp), tokenDebug();
            declarations();
        }
        else
        {
            printf("here ; expected \n");
            invalid();
        }
    }
}

void data_type()
{
    if ((strcmp(currentToken->lexeme, "int") == 0 || strcmp(currentToken->lexeme, "char") == 0))
    {
        currentToken = getNextToken(fp), tokenDebug();
        return;
    }
}

void identifier_list()
{
    if (strcmp(currentToken->type, "identifier") == 0)
    {
        currentToken = getNextToken(fp), tokenDebug();
        identifier_list_factors();
    }
    else
    {
        printf("identifier expected\n");
        invalid();
    }
}

void identifier_list_factors()
{
    if (strcmp(currentToken->lexeme, ",") == 0)
    {
        currentToken = getNextToken(fp), tokenDebug();
        identifier_list();
    }
}

void assign_stat()
{
    if (strcmp(currentToken->type, "identifier") == 0)
    {
        currentToken = getNextToken(fp), tokenDebug();
        if (strcmp(currentToken->lexeme, "=") == 0)
        {
            currentToken = getNextToken(fp), tokenDebug();
            assign_stat_factors();
        }
        else
        {
            printf("= expected\n");
            invalid();
        }
    }
    else
    {
        printf("identifier expected\\n");
        invalid();
    }
}

void assign_stat_factors()
{
    if (strcmp(currentToken->type, "identifier") || strcmp(currentToken->type, "constant") == 0)
    {
        currentToken = getNextToken(fp), tokenDebug();
        if (strcmp(currentToken->lexeme, ";") == 0)
        {
            currentToken = getNextToken(fp), tokenDebug();
            return;
        }
        else
        {
            printf("; expected\n");
            invalid();
        }
    }
    else
    {
        printf("identifier or constant expected \n");
        invalid();
    }
}

int main(int argc, char const *argv[])
{

    fp = fopen("lab07_RDP_input.c", "r");
    freopen("lab07_RDP_output.txt", "w", stdout);

    if (fp == NULL)
    {
        printf("Cannot open file \n Exiting.. \n");
        exit(0);
    }

    currentToken = getNextToken(fp), tokenDebug();
    Program();
    success();

    printf("\n*******************Finished Recursive Decent Parsing*******************\n");

    return 0;
}
