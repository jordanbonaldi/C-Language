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

# define __ITERATE__(type, obj, length, func) {\
		void (*__action)(__attribute__((unused))type GLOBAL_ITERATOR_NAME, \
				__attribute__((unused)) int index) = func;\
		for (int index = 0; index < (int)length; index++)\
			__action(obj[index], index);\
	}

# define length_iterate(type, obj, length, func)\
		__ITERATE__(type, obj, length, \
		EXEC_FUNC(void, (__attribute__((unused))type GLOBAL_ITERATOR_NAME,\
		 __attribute__((unused))int index) func))

# define number_iterate(max, func) {\
		void (*__action)(int index) = \
		EXEC_FUNC(void, (__attribute__((unused))int index) func);\
		for (int index = 0; index < max; index++) \
			__action(index);\
	}

# define list_iterate(type, obj, func) {\
	type tmp = obj; \
	void (*__action)(type GLOBAL_ITERATOR_NAME) = \
	EXEC_FUNC(void, (__attribute__((unused))type GLOBAL_ITERATOR_NAME) func);\
	while (tmp) {\
		__action(tmp);\
		tmp = tmp->next;\
	}\
}

#define foreach(...) GET_MACRO(__VA_ARGS__, length_iterate, list_iterate, number_iterate)(__VA_ARGS__)

#endif
