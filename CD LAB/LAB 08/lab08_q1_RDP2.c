#include "/home/kaustav/Desktop/KaustavLABS3/CD LAB/LAB 04/lab04_q1_symbol_table_header.h"

int curr = 0;
// char str[100];
static char str[700000000];

// FILE *fp = fopen("lab04_q1_input.c", "r");
FILE *fp;
struct token *currentToken;
bool isBacktracking = false;
////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// LAB 07
void Program();
void declarations();
void data_type();
void identifier_list();
void identifier_list_factors();
void assign_stat();
void assign_stat_factors();
// LAB 08
void statement_list();
void statement();
void expn();
void eprime();
void simple_expn();
void seprime();
void term();
void tprime();
void factor();
void relop();
void addop();
void mulop();

////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void success()
{
    ;
    printf("SUCCESS\n");
    exit(0);
}

void invalid()
{
    printf("Error at Row %d : Column %d ::", currentToken->row, currentToken->column);
    exit(0);
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void tokenDebug()
{
    printf("Token Scanned < %s , %s > \n ", currentToken->lexeme, currentToken->type);
}

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
                    statement_list();

                    // currentToken = getNextToken(fp), tokenDebug();
                    if (strcmp(currentToken->lexeme, "}") == 0)
                        return;
                    else
                    {
                        printf(" } expected\n");
                        invalid();
                    }
                }
                else
                {
                    printf("{ Expected\n");
                    invalid();
                }
            }
            else
            {
                printf(") Expected\n");
                invalid();
            }
        }
        else
        {
            printf("( Expected\n");
            invalid();
        }
    }
    else
    {
        printf("Main Expected\n");
        invalid();
    }
};
void declarations()
{
    char *first_of_declarations[2] = {"int", "char"};
    int flag = 0;
    for (int i = 0; i < sizeof(first_of_declarations) / sizeof(first_of_declarations[0]); i++)
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
            printf("; expected\n");
            invalid();
        }
    }
}
void data_type()
{
    // currentToken = getNextToken(fp), tokenDebug();
    if ((strcmp(currentToken->lexeme, "int") == 0) || (strcmp(currentToken->lexeme, "char") == 0))
    {
        currentToken = getNextToken(fp);
    }

    else
    {
        printf("Backtrack please\n");
        // invalid();
        return;
    }
};
void identifier_list()
{
    currentToken = getNextToken(fp), tokenDebug();
    if (strcmp(currentToken->type, "identifier") == 0)
        identifier_list_factors();
    else
    {
        printf("identifier expected\n");
    }
};
void identifier_list_factors()
{
    currentToken = getNextToken(fp), tokenDebug();
    if (strcmp(currentToken->lexeme, ",") == 0)
        identifier_list();
}
void assign_stat()
{
    // currentToken = getNextToken(fp), tokenDebug();
    if ((strcmp(currentToken->type, "identifier") == 0))
    {
        currentToken = getNextToken(fp), tokenDebug();
        if (strcmp(currentToken->lexeme, "=") == 0)
        {
            // assign_stat_factors();
            currentToken = getNextToken(fp), tokenDebug();
            expn();
        }
        else
        {
            printf("= expected\n");
            invalid();
        }
    }
    else
    {
        printf("hi identifier expected\n");
        invalid();
    }
}
// void assign_stat_factors()
// {
//     currentToken = getNextToken(fp), tokenDebug();

//     if ((strcmp(currentToken->type, "identifier") == 0) || (strcmp(currentToken->type, "constant") == 0))
//     {
//         currentToken = getNextToken(fp), tokenDebug();
//         if (strcmp(currentToken->lexeme, ";") == 0)
//             return;
//         else
//         {
//             printf("; expected\n");
//             invalid();
//         }
//     }
//     else
//     {
//         printf("identifier or constant expected\n");
//         invalid();
//     }
// }

void statement_list()
{
    currentToken = getNextToken(fp), tokenDebug();

    char *first_of_statement_list[1] = {"identifier"};
    int flag = 0;
    for (int i = 0; i < sizeof(first_of_statement_list) / sizeof(first_of_statement_list[0]); i++)
    {
        if (strcmp(currentToken->lexeme, first_of_statement_list[i]) == 0)
            flag++;
    }

    if (flag)
    {
        statement();
        statement_list();
    }
}

void statement()
{
    assign_stat();
    currentToken = getNextToken(fp);
    if (strcmp(currentToken->lexeme, ";") == 0)
        return;
    else
    {
        invalid();
        printf("; expected");
    }
}
void expn()
{
    simple_expn();
    eprime();
}
void eprime()
{
    int flag = 0;
    if (strcmp(currentToken->type, "relational_operators") == 0)
        flag++;

    if (flag)
    {
        relop();
        simple_expn();
    }
}
void simple_expn()
{
    term();
    seprime();
}
void seprime()
{
    int flag = 0;
    char *first_of_seprime[2] = {"+", "-"};
    for (int i = 0; i < (sizeof(first_of_seprime) / sizeof(first_of_seprime[0])); i++)
        flag++;

    if (flag)
    {
        addop();
        term();
        seprime();
    }
}

void term()
{
    factor();
    tprime();
}
void tprime()
{

    int flag = 0;
    char *first_of_tprime[3] = {"*", "/", "%"};
    for (int i = 0; i < (sizeof(first_of_tprime) / sizeof(first_of_tprime[0])); i++)
        flag++;

    if (flag)
    {
        mulop();
        term();
        tprime();
    }
}

void factor()
{
    currentToken = getNextToken(fp), tokenDebug();
    if ((strcmp(currentToken->type, "identifier") == 0 || (strcmp(currentToken->type, "constant") == 0)))
        return;
    else
    {
        printf("identifier or constant expected\n");
        invalid();
    }
}
void relop()
{
    // currentToken = getNextToken(fp);
    if (strcmp(currentToken->type, "relational_operators") == 0)
        return;
    else
    {
        printf("Relational operator epxected \n");
        invalid();
    }
}
void addop()
{
    if ((strcmp(currentToken->lexeme, "+") == 0 || strcmp(currentToken->lexeme, "-") == 0))
        return;
    else
    {
        printf("+ or - expected \n");
        invalid();
    }
}
void mulop()
{
    if ((strcmp(currentToken->lexeme, "*") == 0 || strcmp(currentToken->lexeme, "/") == 0 || strcmp(currentToken->lexeme, "%")))
        return;
    else
    {
        printf("* / or mod expected \n");
        invalid();
    }
}

int main(int argc, char const *argv[])

{

    fp = fopen("lab08_RDP_input.c", "r");
    // freopen("lab08_RDP_output.txt", "w", stdout);
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
