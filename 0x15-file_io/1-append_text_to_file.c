#include <stdio.h>
#include <stdlib.h>
#include "main.h"

int main(int argc, char **argv)
{
    ssize_t ret;

    if (argc != 2)
    {
        fprintf(stderr, "Usage: %s filename\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    ret = read_textfile(argv[1], 114);
    printf("(printed chars: %ld)\n", ret);

    ret = read_textfile(argv[1], 1024);
    printf("(printed chars: %ld)\n", ret);

    return (EXIT_SUCCESS);
}
