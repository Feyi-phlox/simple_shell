#include "main.h"

/**
 * path - function to get the path
 * @user_command: user input
 * @directories: get command location
 * @numdirs: directory numbers
 * Return: path || NULL;
 */

char *path(char *user_command, char **directories, int numdirs)
{
	char *executable_path = NULL;
	int i, j, k, dir_length, command_length, sum;

	if (access(user_command, X_OK) == 0)
		return (_strdup(user_command));
	for (i = 0; i < numdirs; i++)
	{
		dir_length = _strlen(directories[i]);
		command_length = _strlen(user_command);
		sum = dir_length + command_length + 2;
		executable_path = (char *)malloc((sum) * sizeof(char));
		if (executable_path == NULL)
		{
			perror("Issue with malloc");
			exit(1);
		}
		j = 0;
		if (user_command[0] != '/')
		{
			for (k = 0; k < dir_length; k++)
				executable_path[j++] = directories[i][k];
			executable_path[j++] = '/';
		}
		for (k = 0; k < command_length; k++)
			executable_path[j++] = user_command[k];
		executable_path[j] = '\0';
		if (access(executable_path, X_OK) == 0)
			return (executable_path);
		free(executable_path);
	}
	return (NULL);
}
