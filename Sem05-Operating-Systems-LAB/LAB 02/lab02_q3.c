#include <unistd.h>
#include <stdio.h>
#include <dirent.h>
#include <string.h>

#include <sys/stat.h>
#include <sys/types.h>

void print_installed_files(char *dir, int depth)
{
    DIR *dp;
    struct dirent *entry;
    struct stat statbuf;

    if ((dp = opendir(dir)) == NULL)
    {
        fprintf(stderr, "Cannot open Directory %s \n", dir);
        return;
    }
    chdir(dir);
    while ((entry = readdir(dp)) != NULL)
    {
        lstat(entry->d_name, &statbuf);

        if (S_ISDIR(statbuf.st_mode))
        {
            if ((strcmp(".", entry->d_name) == 0) || (strcmp("..", entry->d_name) == 0))
                continue;
            printf(" %*s %s/ \n", depth, "", entry->d_name);

            // Recur at a new indent level
            print_installed_files(entry->d_name, depth + 4);
        }

        else
            printf(" %*s  %s \n", depth, "", entry->d_name);
    }

    chdir("..");
    closedir(dp);
}

int main(int argc, char const *argv[])
{
    print_installed_files("/usr/bin", 1);
    return 0;
}
