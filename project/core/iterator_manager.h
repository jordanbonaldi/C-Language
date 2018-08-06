/*
** EPITECH PROJECT, 2018
** IT
** File description:
** IT
*/

# ifndef ITERATOR_HANDLER_HH
	# define ITERATOR_HANDLER_HH

# define GLOBAL_ITERATOR_NAME ev

# define IT GLOBAL_ITERATOR_NAME

# define EXEC_FUNC(ret, func)\
		({ ret __fn__ func __fn__; })

# define ARRAY_LEN(arr) (sizeof(arr) / sizeof(*arr))

# define FOREACH_LENGTH_FUNCTION(type, obj, length, func) {\
		void (*__action)(type GLOBAL_ITERATOR_NAME, \
				__attribute__((unused)) int index) = func;\
		for (int index = 0; index < (int)length; index++)\
			__action(obj[index], index);\
	}

# define FOREACH_FUNCTION(type, obj, func)\
		FOREACH_LENGTH_FUNCTION(type, obj, \
			ARRAY_LEN(obj), func)

# define FOREACH_LENGTH(type, obj, length, func)\
		FOREACH_LENGTH_FUNCTION(type, obj, length, \
		EXEC_FUNC(void, (type GLOBAL_ITERATOR_NAME, int index) func))

# define FOREACH(a, b, func)\
		FOREACH_LENGTH(a, b, ARRAY_LEN(b), func)

# define FOREACH_IT(max, func) {\
		void (*__action)(int index) = \
		EXEC_FUNC(void, (int index) func);\
		for (int index = 0; index < max; index++) \
			__action(index);\
	}

# define FOREACH_LIST(type, obj, func) {\
	type tmp = obj; \
	void (*__action)(type GLOBAL_ITERATOR_NAME) = \
	EXEC_FUNC(void, (type GLOBAL_ITERATOR_NAME) func);\
	while (tmp) {\
		__action(tmp);\
		tmp = tmp->next;\
	}\
}
#endif
