#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <fcntl.h>

int main(){
  
    int filePointer = open("temp.txt", O_RDONLY);
    char buffer[256];
    read(filePointer, buffer, sizeof(buffer));
    int i = 0;
    char ch;
    int characters, words, lines;

    characters = words = lines = 0;

    while(buffer[i] != '\0'){
        ch = buffer[i];
        characters++;
        printf("%c", ch);

        if (ch == '\n' || ch == '\0'){
            lines++;
            // characters--;
        }

        if (ch == ' ' || ch == '\t' || ch == '\n' || ch == '\0'){
            words++;
            characters--;
        }

        i++;
    }

    printf("\n");
    printf("Total characters: %d\n", characters);
    printf("Total words: %d\n", words);
    printf("Total lines: %d\n", lines);
}