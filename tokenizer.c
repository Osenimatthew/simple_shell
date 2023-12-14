#include "shell.h"

/**
 * **strtow - splits a string into words. Repeat delimiters are ignored
 * @str: the input string
 * @d: the delimeter string
 * Return: a pointer to an array of strings, or NULL on failure
 */

char **strtow(char *str, char *d)
{
	int r, h, k, m, numwords = 0;
	char **s;

	if (str == NULL || str[0] == 0)
		return (NULL);
	if (!d)
		d = " ";
	for (r = 0; str[r] != '\0'; r++)
		if (!is_delim(str[r], d) && (is_delim(str[r + 1], d) || !str[r + 1]))
			numwords++;

	if (numwords == 0)
		return (NULL);
	s = malloc((1 + numwords) * sizeof(char *));
	if (!s)
		return (NULL);
	for (r = 0, h = 0; h < numwords; h++)
	{
		while (is_delim(str[r], d))
			r++;
		k = 0;
		while (!is_delim(str[r + k], d) && str[r + k])
			k++;
		s[h] = malloc((k + 1) * sizeof(char));
		if (!s[h])
		{
			for (k = 0; k < h; k++)
				free(s[k]);
			free(s);
			return (NULL);
		}
		for (m = 0; m < k; m++)
			s[h][m] = str[r++];
		s[h][m] = 0;
	}
	s[h] = NULL;
	return (s);
}
/**
 * **strtow2 - splits a string into different words
 * @str: the inputed string
 * @d: the delimeter
 * Return: a pointer to an array of strings, or NULL on failure
 */
char **strtow2(char *str, char d)
{
	int r, h, k, m, numwords = 0;
	char **s;

	if (str == NULL || str[0] == 0)
		return (NULL);
	for (r = 0; str[r] != '\0'; r++)
		if ((str[r] != d && str[r + 1] == d) ||
		    (str[r] != d && !str[r + 1]) || str[r + 1] == d)
			numwords++;
	if (numwords == 0)
		return (NULL);
	s = malloc((1 + numwords) * sizeof(char *));
	if (!s)
		return (NULL);
	for (r = 0, h = 0; h < numwords; h++)
	{
		while (str[r] == d && str[r] != d)
			r++;
		k = 0;
		while (str[r + k] != d && str[r + k] && str[r + k] != d)
			k++;
		s[h] = malloc((k + 1) * sizeof(char));
		if (!s[h])
		{
			for (k = 0; k < h; k++)
				free(s[k]);
			free(s);
			return (NULL);
		}
		for (m = 0; m < k; m++)
			s[h][m] = str[r++];
		s[h][m] = 0;
	}
	s[h] = NULL;
	return (s);
}
