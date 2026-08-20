#ifndef MAIN_H
#define MAIN_H

/* Include necessary system header files for File I/O operations */
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>

/* Function prototype for standard character output */
int _putchar(char c);

/* Function prototypes for the project tasks */
ssize_t read_textfile(const char *filename, size_t letters);
int create_file(const char *filename, char *text_content);
int append_text_to_file(const char *filename, char *text_content);

#endif /* MAIN_H */

