#include <unistd.h>
#include <stdio.h>
#include <dirent.h>
#include <string.h>

#include <sys/stat.h>
#include <sys/types.h>

void exec_ls_l(char *dir, int depth)
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
            if ((strcmp(".", entry->d_name) != 0) && (strcmp("..", entry->d_name) != 0))
                printf(" %*s %s/ \t\t\t", 1, "", entry->d_name);
            else
                continue;
        }
        else
            printf("%*s  %s \t\t\t", depth, "", entry->d_name);

        printf(S_ISDIR(statbuf.st_mode) ? "d" : "_");
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

    chdir("..");
    closedir(dp);
}

int main(int argc, char const *argv[])
{

    exec_ls_l("/home/kaustav/Desktop/KaustavLABS3/OS LAB/LAB 02", 1);
    return 0;
}
