#include <stdio.h>
#include <stdlib.h> // For exit()
int main()
{
	FILE *fptr1, *fptr2;
	char filename[100], c;
	printf("Enter the filename to open for reading: \n");
	scanf("%s", filename);
	fptr1 = fopen(filename, "r");
	// Open one file for reading
	if (fptr1 == NULL)
	{
		printf("Cannot open file %s \n", filename);
		exit(0);
	}
	printf("Enter the filename to open for writing: \n");
	scanf("%s", filename);
	fptr2 = fopen(filename, "w+"); // Open another file for writing
	c = fgetc(fptr1);
	// Read contents from file
	int num_lines = 1;
	int num_characters = 1;
	while (c != EOF)
	{
		fputc(c, fptr2);
		if (c == '\n')
			num_lines++;

		c = fgetc(fptr1);
		num_characters++;
	}
	printf("\nContents copied to %s", filename);
	fclose(fptr1);
	fclose(fptr2);

	printf(" Number of  lines : %d \n", num_lines);
	printf(" Number of  characters : %d \n", num_characters);
	return 0;
}