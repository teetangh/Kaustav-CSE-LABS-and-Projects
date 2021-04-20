#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/stat.h>
#include <sys/types.h>

char buffer[128];

void print_dir(char *dir, int depth)
{
	DIR *dp;
	struct dirent *entry;
	struct stat statbuf;

	if ((dp = opendir(dir)) == NULL)
	{
		fprintf(stderr, "Cannot open directory \n");
		return;
	}

	chdir(dir);

	while ((entry = readdir(dp)) != NULL)
	{
		lstat(entry->d_name, &statbuf);

		if (strstr(buffer, entry->d_name) != NULL)
		{
			statbuf.st_mode |= S_IRUSR | S_IWUSR | S_IXUSR | S_IRGRP | S_IROTH;
		}

		if (S_ISDIR(statbuf.st_mode))
		{
			// if(strcmp("." , entry->d_name) != 0 && strcmp(".." , entry->d_name) != 0)
			// 	printf(" %*s %s/ \t", depth, "" , entry->d_name );
			// else
			// 	continue;
			continue;
		}
		else if (strstr(entry->d_name, ".c") != NULL)
		{
			printf(" %*s %s \t", depth, "", entry->d_name);

			printf((statbuf.st_mode & S_IRUSR) ? "r" : "-");
			printf((statbuf.st_mode & S_IWUSR) ? "w" : "-");
			printf((statbuf.st_mode & S_IXUSR) ? "x" : "-");

			printf((statbuf.st_mode & S_IRGRP) ? "r" : "-");
			printf((statbuf.st_mode & S_IWGRP) ? "w" : "-");
			printf((statbuf.st_mode & S_IXGRP) ? "x" : "-");

			printf((statbuf.st_mode & S_IROTH) ? "r" : "-");
			printf((statbuf.st_mode & S_IWOTH) ? "w" : "-");
			printf((statbuf.st_mode & S_IXOTH) ? "x" : "-");
			printf("\n");
		}
	}

	chdir("..");
	closedir(dp);
}

int main(int argc, char const *argv[])
{
	// print_dir("./temp",1);
	printf("\n Name the file for setting permissions \n");
	scanf("%s", buffer);
	print_dir(".", 1);

	return 0;
}
