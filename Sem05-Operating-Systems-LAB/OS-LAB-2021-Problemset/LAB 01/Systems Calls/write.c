// // Syntax
// size_t write(int fildes, const void *buf, size_t nbytes);

#include <unistd.h>
#include <stdlib.h>


int main(int argc, char const *argv[])
{
    if ((write(1, "Here is some data\n", 18)) != 18)
        write(2, "A write error has occured on the file descriptor 1 \n", 46);

    exit(0);
}
