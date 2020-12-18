#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
typedef struct ste
{
    char lexeme[30];
    int index;
    char type[15];
    int size;
} ste;

typedef struct token
{
    char token_name[100];
    unsigned int row, col;
} token;

typedef struct localTableData
{
    char fn_name[30];
    int size;
} localTableData;

FILE *file;
int row = 1, col = 0;
ste table[10][100];
localTableData tableData[10];
int st_index = 0;
int st_num = -1;
int scope = 0;
char dbuf[15] = "";

int prev, ca, cb;

int isKeyword(char *word)
{
    char *keylist[4] = {"class", "string", "int", "char"};

    for (int i = 0; i < 4; ++i)
    {
        if (strcmp(word, keylist[i]) == 0)
        {
            return 1;
        }
    }
    return 0;
}

int isSpecialSymbol(char ch)
{
    return (strchr("[]{}(),;:.#", ch) != NULL);
}

int isOperator(char ch)
{
    return (strchr("+-*/%<>^=!", ch) != NULL);
}

token newToken(char name[50], int r, int c)
{
    token t;
    strcpy(t.token_name, name);
    t.row = r;
    t.col = c;
    return t;
}

void insertSt(char lexeme[100], char type[15], int size)
{
    ste t;
    strcpy(t.lexeme, lexeme);
    strcpy(t.type, type);
    t.size = size;
    t.index = st_index + 1;
    for (int i = 0; i < st_index; i++)
    {
        if (strcmp(table[st_num][i].lexeme, lexeme) == 0)
        {
            return;
        }
    }
    table[st_num][st_index++] = t;
    tableData[st_num].size += 1;
}

void printSt()
{
    for (int j = 0; j <= st_num; j++)
    {
        printf("\n------------------------------------\n");
        printf("\nSymbol table for %s\n\n", tableData[j].fn_name);
        printf("Index\tLexeme\tType\tSize\n");
        for (int i = 0; i < tableData[j].size; i++)
        {
            printf("%d\t%s\t%s\t%d\n", table[j][i].index, table[j][i].lexeme,
                   table[j][i].type, table[j][i].size);
        }
    }
}

token getNextToken()
{
    char buf[30];
    int idx = 0;
    int ca = getc(file);
    col++;
    token t;
    while (ca == '\n')
    {
        strcpy(dbuf, "");
        ca = getc(file);
        col = 1;
        row += 1;
    }
    if (ca == EOF)
    {
        return newToken("EOF", row, col);
    }
    if (ca == ' ')
    {
        ca = getc(file);
        col += 1;
    }
    if (isalpha(ca))
    {
        while (isalpha(ca) || isdigit(ca) || ca == '_')
        {
            buf[idx++] = ca;
            ca = getc(file);
            col++;
        }
        ungetc(ca, file);
        col--;
        buf[idx] = '\0';
        if (isKeyword(buf))
        {
            strcpy(dbuf, buf);
            t = newToken(buf, row, col - strlen(buf) + 1);
        }
        else
        {
            int num = 1;
            t = newToken("id", row, col - strlen(buf) + 1);
            ca = getc(file);
            if (ca == '(')
            {
                if (scope != 0)
                {
                    insertSt(buf, "func", -1);
                }
                else
                {
                    //printf("New function %s\n\n", buf);
                    st_num++;
                    strcpy(tableData[st_num].fn_name, buf);
                    st_index = 0;
                }
                ungetc(ca, file);
                return t;
            }

            if (ca == '[')
            {
                int pos = ftell(file);
                int cb;
                num = 0;
                while ((cb = getc(file)) != ']')
                {
                    num = num * 10 + (cb - '0');
                }
                fseek(file, pos, SEEK_SET);
            }
            ungetc(ca, file);
            int sz = 0;
            if (strcmp(dbuf, "int") == 0 || strcmp(dbuf, "float") == 0)
                sz = 4;

            insertSt(buf, dbuf, sz * num);
        }
    }
    else if (ca == '"')
    {
        t = newToken("string", row, col);
        do
        {
            ca = getc(file);
            col++;
        } while (ca != '"');
    }
    else if (isSpecialSymbol(ca))
    {
        if (ca == '{')
            scope++;
        if (ca == '}')
            scope--;
        buf[idx++] = ca;
        buf[idx] = '\0';
        t = newToken(buf, row, col);
    }
    else if (isOperator(ca))
    {
        buf[idx++] = ca;
        ca = getc(file);
        cb = getc(file);
        col++;
        if (strcmp(ca, "<") == 0 && strcmp(cb, '-') == 0)
        {
            buf[idx++] = ca;
            buf[idx++] = cb;
        }

        else
        {
            ungetc(ca, file);
            ungetc(cb, file);
            col--;
        }
        buf[idx] = '\0';
        t = newToken(buf, row, col - strlen(buf) + 1);
    }

    return t;
}

int main()
{
    FILE *fa, *fb;

    fa = fopen("input.c", "r");
    if (fa == NULL)
    {
        printf("Cannot open file \n");
        exit(0);
    }
    fb = fopen("output.c", "w+");
    ca = getc(fa);
    while (ca != EOF)
    {
        if (ca == ' ' || ca == '\t')
        {
            putc(' ', fb);
            while (ca == ' ' || ca == '\t')
                ca = getc(fa);
            ungetc(ca, fa);
        }
        else if (ca == '-')
        {
            cb = getc(fa);
            if (cb == '-')
            {
                while (ca != '\n')
                    ca = getc(fa);
            }
            else
            {
                putc(ca, fb);
                putc(cb, fb);
            }
        }
        else
            putc(ca, fb);
        ca = getc(fa);
    }
    fclose(fa);
    fclose(fb);

    file = fopen("output.c", "r");
    printf("Tokens:\n\n");
    while (1)
    {
        token t = getNextToken();
        if (strcmp(t.token_name, "EOF") == 0)
            break;
        printf("<%s, %d, %d>\n", t.token_name, t.row, t.col);
    };
    fclose(file);
    printSt();
    return 0;
}

//////////////////////////////////////////////////////////////////////////////////END////////////////////////////////////////////////////