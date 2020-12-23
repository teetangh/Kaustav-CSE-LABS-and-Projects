// Copyright (c) 17 December 2020 Kaustav Ghosh

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

// #include "lab04_q1_symbol_table_header.h"

int main(int argc, char const *argv[])
{
    // FILE *fp = fopen("input_file1.c", "r");
    FILE *fp = fopen("input_file2_multi_function.c", "r");

    freopen("lab04_symbol_table_output.txt", "w", stdout);

    if (fp == NULL)
    {
        printf("Cannot open file \n Exiting.. \n");
        exit(0);
    }

    struct token *retToken;
    while ((retToken = getNextToken(fp)) != NULL)
    {
        printf("FNO %d FSCOPE %d\t\t", function_number, function_scope);
        printf("< %d,%d,'%s',%s >\n", retToken->row, retToken->column, retToken->lexeme, retToken->type);

        insert_into_local_symbol_table_helper(retToken);
    }

    printf("\n*******************Finished Lexical analysis*******************\n");
    display_local_symbol_tables();
    printf("\n*******************Finished Symbol Table Entries*******************\n");

    return 0;
}