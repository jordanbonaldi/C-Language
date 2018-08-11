/*
** EPITECH PROJECT, 2018
** connection
** File description:
** connection
*/

# ifndef QUEUE_HH
	# define QUEUE_HH

# include "project.h"

OBJECT_CREATOR
(
	Container,

	void *contained;
)

OBJECT_CREATOR
(
	Queue,

	String name;

	struct s_Queue *next;
)

# define addQueue(name, queue) \
		CALL_FUNCTION_PARAMS(addQueue, \
				setUnknown(queue, name))

# define sizeQueue(size) CALL_FUNCTION_PARAMS(QueueSize, size)

CREATE_FUNCTION_PARAMS(void, removeFirst, Container *container)
{
	_(Queue *actual = container->contained)
	_(Queue *tmp = ((Queue *)container->contained)->next)

	_(free(actual->name))
	_(free(actual))

	_(container->contained = tmp)
}

CREATE_FUNCTION_PARAMS(int, QueueSize, Queue *queue)
{
	_(int $i = 0)

	FOREACH_LIST
	(
		Queue *,
		queue,

		{
			__SETUNUSED__(index)
			__SETUNUSED__(IT)
			_($i++)
		}
	)

	__return($i)
}

CREATE_FUNCTION_PARAMS(void, addQueue, Unknown unknown)
{
	_get(Container, _queue, alpha);
	_get(char, __name, beta);

	if (sizeQueue(_queue->contained) >= 10)
		return;

	Queue *__cmd;
	Queue *tmp;

	__MALLOC__(__cmd, sizeof(Queue))

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

CREATE_FUNCTION_PARAMS(void, destroyQueue, Container *container)
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
