#include "main.h"

/**
 * main - Putting all the shell functions together
 * Return: 0 on success
 */

int main(void)
{
	char *user_command = NULL, *args[10], *path_return;
	char *directories[] = {"/usr/bin", "/bin"};
	size_t command_length = 100;
	ssize_t command_input;
	int argc = 0, numdirs, run_status = 0;

	numdirs = sizeof(directories) / sizeof(directories[0]);
	while (1 && !run_status)
	{
		if (!isatty(STDIN_FILENO))
			run_status = 1;
		else
			write(STDOUT_FILENO, "Cisfun$ ", 8);
		command_input = getline(&user_command, &command_length, stdin);
		if (command_input == -1)
		{
			write(STDOUT_FILENO, "#exit\n\n[Disconnected...]\n", 25);
			break;
		}
		_remove(user_command);
		if (_strcmp(user_command, "exit") == 0 || _strcmp(user_command, "quit") == 0)
		{
			write(STDOUT_FILENO, "#exit\n\n[Disconnected...]\n", 25);
			break;
		}
		path_return = pa(user_command, args, argc, directories, numdirs);
		if (path_return == NULL)
		{
			write(STDOUT_FILENO, "No such file or directory\n", 26);
			continue;
		}
		if (fork() == 0)
			_myexecv(path_return, args);
		else
			wait(NULL);
		free(path_return);
	}
	free(user_command);
	return (0);
}
