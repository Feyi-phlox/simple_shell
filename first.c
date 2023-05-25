#include "main.h"

/**
 * _first - returns input command
 * @user_command: first input
 * @command_length: second input
 * Return: -1 || 0
 */

ssize_t  _first(char *user_command, size_t command_length)
{
	ssize_t command_input;

	if(!isatty(STDIN_FILENO))
	write(STDOUT_FILENO, "Cisfun$ ", 8);
	return command_input = getline(&user_command, &command_length, stdin);
}
