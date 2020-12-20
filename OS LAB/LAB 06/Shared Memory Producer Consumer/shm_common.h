#include <stdbool.h>

#define TEXT_SIZE 2048

struct shared_use_st
{
    bool written_by_you;
    char some_text[TEXT_SIZE];
};
