#include "main.h"

/**
 * _remove - adds \0 to replace \n
 * @user_command: command
 * Return: nothing
 */

void _remove(char *user_command)
{
	int i = 0;

	for (i = 0; user_command[i] != '\n' && user_command[i] != '\0'; i++)
		;
	user_command[i] = '\0';
}
