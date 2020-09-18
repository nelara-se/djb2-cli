#include <stdio.h>
#include <stdlib.h>

unsigned long
hash(const char *str)
{
    unsigned long hash = 5381;
    int c;

    while ((c = *str++))
        hash = ((hash << 5) + hash) + c; /* hash * 33 + c */

    return hash;
}

int
main(int argc, char *argv[])
{
    char *buffer = NULL;
    ssize_t nread;
    size_t len;
    
    while ((nread = getline(&buffer, &len, stdin)) != -1)
    {
        fprintf(stdout, "%lu\n", hash(buffer));
    }

    free(buffer);
    return EXIT_SUCCESS;
}
