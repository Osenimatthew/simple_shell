 #include "shell.h"

/**
 * interactive - Checks if the shell is in interactive mode
 * @info: Pointer to a struct containing relevant information
 *
 * Return: 1 if the shell is in interactive mode, 0 otherwise
 */
int interactive(info_t *info)
{
        return (isatty(STDIN_FILENO) && info->readfd <= 2);
}

/**
 * is_delim - Check if a character is a delimiter
 * @e: The character to be checked
 * @delim: The delimiter string
 *
 * Return: 1 if true, 0 if false
 */
int is_delim(char e, char *delim)
{
        while (*delim)
                if (*delim++ == e)
                        return (1);
        return (0);
}

/**
 * _isalpha - Check if a character is alphabetic.
 * @e: The character to check.
 *
 * Return: 1 if 'e' is an alphabetic character, 0 otherwise.
 */
int _isalpha(int e)
{
        if ((e >= 'a' && e <= 'z') || (e >= 'A' && e <= 'Z'))
                return (1);
        else
                return (0);
}

/**
 * _atoi - converts a string to an integer
 * @s: the string to be converted
 * Return: 0 if no numbers in string, converted number otherwise
 */
int _atoi(char *s)
{
        int j, sign = 1, flag = 0, output;
        unsigned int result = 0;

        for (j = 0;  s[j] != '\0' && flag != 2; j++)
        {
                if (s[j] == '-')
                        sign *= -1;

                if (s[j] >= '0' && s[j] <= '9')
                {
                        flag = 1;
                        result *= 10;
                        result += (s[j] - '0');
                }
                else if (flag == 1)
                        flag = 2;
        }

        if (sign == -1)
                output = -result;
        else
                output = result;

        return (output);
}

