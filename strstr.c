#include "main.h"

/**
 * _strstr - finds the first occurrence of the substring needle
 * in the string haystack
 * @needle: substring
 * @haystack: string
 * Return: a pointer to the beginning of the located substring,
 * or NULL if the substring is not found
 */

char *_strstr(char *haystack, char *needle)
{
	int j, k;

	for (j = 0; haystack[j] != '\0'; j++)
	{
		for (k = 0; needle[k] != '\0'; k++)
		{
			if (haystack[j + k] != needle[k])
				break;
		}
		if (needle[k] == '\0')
		return (haystack + j);
	}
	return (0);
}
