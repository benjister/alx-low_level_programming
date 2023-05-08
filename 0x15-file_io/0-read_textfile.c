#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>

/**
 * read_textfile - reads a text file and prints it to the POSIX standard output
 * @filename: the name of the file to read
 * @letters: the number of letters to read and print
 *
 * Return: the number of letters read and printed, or 0 if an error occurred
 */
ssize_t read_textfile(const char *filename, size_t letters)
{
    int fd, ret;
    char *buf;

    if (filename == NULL)
        return (0);

    fd = open(filename, O_RDONLY);
    if (fd == -1)
        return (0);

    buf = malloc(letters * sizeof(char));
    if (buf == NULL)
        return (0);

    ret = read(fd, buf, letters);
    if (ret == -1)
    {
        free(buf);
        return (0);
    }

    ret = write(STDOUT_FILENO, buf, ret);
    if (ret == -1 || ret != letters)
    {
        free(buf);
        return (0);
    }

    free(buf);
    close(fd);

    return (ret);
}
