#include "shell.h"

/**
 * Myhistory - Displays the history list with line numbers.
 * @info: Structure containing potential arguments. Maintains
 *	a consistent function prototype.
 *
 * Return: Always returns 0.
 */
int _myhistory(info_t *info)
{
	print_list(info->history);
	return (0);
}

int unset_alias(info_t *info, char *str)
{
	char *p, f;
	int ret;

	p = _strchr(str, '=');
	if (!p)
		return (1);
	f = *p;
	*p = 0;
	ret = delete_node_at_index(&(info->alias),
		get_node_index(info->alias, node_starts_with(info->alias, str, -1)));
	*p = f;
	return (ret);
}

int set_alias(info_t *info, char *str)
{
	char *p;

	p = _strchr(str, '=');
	if (!p)
		return (1);
	if (!*++p)
		return (unset_alias(info, str));

	unset_alias(info, str);
	return (add_node_end(&(info->alias), str, 0) == NULL);
}

/**
 * print_alias - prints an alias to string
 * @node: the alias node
 *
 * Return: Always 0 on success, 1 on error
 */
int print_alias(list_t *node)
{
	char *p = NULL, *a = NULL;

	if (node)
	{
		p = _strchr(node->str, '=');
		for (a = node->str; a <= p; a++)
			_putchar(*a);
		_putchar('\'');
		_puts(p + 1);
		_puts("'\n");
		return (0);
	}
	return (1);
}

int _myalias(info_t *info)
{
	int g = 0;
	char *p = NULL;
	list_t *node = NULL;

	if (info->argc == 1)
	{
		node = info->alias;
		while (node)
		{
			print_alias(node);
			node = node->next;
		}
		return (0);
	}
	for (g = 1; info->argv[g]; g++)
	{
		p = _strchr(info->argv[g], '=');
		if (p)
			set_alias(info, info->argv[i]);
		else
			print_alias(node_starts_with(info->alias, info->argv[g], '='));
	}

	return (0);
}
