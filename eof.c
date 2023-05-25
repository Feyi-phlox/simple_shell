#include "main.h"

/**
 * _eof - response/action after eof check
 * Return: void
 */

void _eof(void)
{
	write(STDOUT_FILENO, "\nBye...see you later\n", 21);
	break;
}
