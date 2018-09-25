/*
** EPITECH PROJECT, 2018
** connection
** File description:
** connection
*/

# ifndef QUEUE_HH
	# define QUEUE_HH

# include "clang.h"

create Object
(
	Container,

	void *contained;
)

create Object
(
	List,

	void *data;

	struct s_List *next;
)

# define addList(name, list) \
		call(addList, list, name)

# define sizeList(s) call(size, s)

# define get(a, b) call(getList, a, b)

# define set(a, b, c) call(setList, a, b, c)

# define insert(a, b) call(insertList, a, b)

# define copyList(b) call(copyList, b)


public void function(removeFirst, List *list)
{
	_(List *actual = list)
	_(List *tmp = list->next)

	_(free(actual->data))
	_(free(actual))

	_(list = tmp)
}


public int function(size, List *list)
{
	_(int $i = 0)

	foreach
	(
		List *,
		list,

		{
			_($i++)
		}
	)

	$return($i)
}


public void function(addList, List **list, void *name)
{
	new (List)
	alloc(__cmd, sizeof(List))

	List *tmp;

	__cmd->data = name;
	__cmd->next = NULL;
	if (!*list)
		*list = __cmd;
	else {
		tmp = *list;
		while (tmp->next)
			tmp = tmp->next;
		tmp->next = __cmd;
	}
}

public List * function(getList, List **list, int a)
{
	int b = 0;
	List *tmp = *list;

	if (!a)
		return tmp;

	while (tmp->next) {
		if (a == b)
			break;
		b++;
		tmp = tmp->next;
	}
	return tmp;
}

public List * function(insertList, List *iterator, float a)
{
	new (List)
	alloc(__cmd, sizeof(List))

	__cmd->data = &a;
	__cmd->data = iterator->next;
	iterator->next = __cmd;
	return iterator;
}

public void function(setList, List **list, int a, void *t)
{
	get(list, a)->data = t;
}

public List * function(copyList, List *list)
{
	List *l2 = NULL;
	List *tmp = list;

	while (tmp->next) {
		addList(tmp->data, &l2);
		tmp = tmp->next;
	}
	return l2;
}

public void function(destroyList, List *_list)
{
	List *list = _list;

	List *tmp = NULL;

	while (list) {
		tmp = list->next;
		free(list->data);
		free(list);
		list = tmp;
	}
}

# endif
