#include "main.h"

/**
 * _strdup -  function that returns a pointer to a newly allocated space
 * in memory, which contains a copy of the string given as a parameter.
 * @str: the string that is copied
 * Return: a pointer to the duplicated string or NULL for insufficient memory
 */

char *_strdup(char *str)
{
	char *strdup;
	int len;
	int i;

	if (str == NULL)
		return (NULL);
	len = 0;
	while (str[len] != '\0')
		len++;
	strdup = malloc((len + 1) * sizeof(char));

	if (strdup == NULL)
		return (NULL);

	for (i = 0; str[i]; i++)
		strdup[i] = str[i];
	return (strdup);
}
