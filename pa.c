#include "main.h"

/**
 * pa - basic work
 * @user_command: input 1
 * @args: input 2
 * @argc: input 3
 * @directories: input 4
 * @numdirs: input 5
 * Return: path
 */

char *pa(char *user_command, char *args[],
		int argc, char *directories[], int numdirs)
{
	char *pa_return, *tokens;

	tokens = strtok(user_command, " ");
	argc = 0;
	while (tokens != NULL && argc < 10)
	{
		args[argc++] = tokens;
		tokens = strtok(NULL, " ");
	}
	args[argc] = NULL;
	pa_return = path(args[0], directories, numdirs);
	return (pa_return);
}
