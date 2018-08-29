/*
** EPITECH PROJECT, 2018
** connection
** File description:
** connection
*/

# ifndef QUEUE_HH
	# define QUEUE_HH

# include "clang.h"

$new Class
(
	Container,

	void *contained;
)

$new Class
(
	Queue,

	String name;

	struct s_Queue *next;
)

# define addQueue(name, queue) \
		call(addQueue, \
				setUnknown(queue, name))

# define sizeQueue(size) call(QueueSize, size)


public void function(removeFirst, Container *container)
{
	_(Queue *actual = container->contained)
	_(Queue *tmp = ((Queue *)container->contained)->next)

	_(free(actual->name))
	_(free(actual))

	_(container->contained = tmp)
}


public int function(QueueSize, Queue *queue)
{
	_(int $i = 0)

	foreach
	(
		Queue *,
		queue,

		{
			_($i++)
		}
	)

	$return($i)
}


public void function(addQueue, Unknown unknown)
{
	$get(Container, _queue, alpha)
	$get(char, __name, beta)

	if (sizeQueue(_queue->contained) >= 10)
		return;

	new (Queue)
	alloc(__cmd, sizeof(Queue))

	Queue *tmp;

	__cmd->name = __name;
	__cmd->next = NULL;
	if (!_queue->contained)
		_queue->contained = __cmd;
	else {
		tmp = _queue->contained;
		while (tmp->next)
			tmp = tmp->next;
		tmp->next = __cmd;
	}
}


public void function(destroyQueue, Container *container)
{
	Queue *queue = container->contained;

	Queue *tmp = NULL;

	while (queue) {
		tmp = queue->next;
		free(queue->name);
		free(queue);
		queue = tmp;
	}
	free(container);
}

# endif
