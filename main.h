#ifndef MAIN_H
#define MAIN_H

#include <stdio.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>

/* Function prototypes */

char *path(char *user_command, char **directories, int numdirs);
int _strcmp(char *s1, char *s2);
int _strlen(char *s);
char *_strstr(char *haystack, char *needle);
char *_strdup(char *str);
void _myexecv(char *path_return, char **args);
char *pa(char *user_command, char *args[], int argc, char *directories[], int numdirs);
void _remove(char *user_command);

#endif
