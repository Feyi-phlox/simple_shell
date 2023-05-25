#include "main.h"

/**
 * _myexecv - exev operation
 * @path_return: path to exe file
 * @args: list of arguments
 * Return: void
 */

void _myexecv(char *path_return, char **args)
{
	execv(path_return, args);
	write(STDOUT_FILENO, "No such file or directory\n", 26);
	exit(1);
}
