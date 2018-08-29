/*
** EPITECH PROJECT, 2018
** connection
** File description:
** connection
*/

# ifndef ERROR_HANDLER_HH
	# define ERROR_HANDLER_HH

# include "clang.h"

enum s_status
{
	LOW,
	NORMAL,
	HIGH,
	CRITICAL
};

OBJECT_CREATOR
(
	Error,

	int code;
	Status status;
)

# define setError(b, c) (Error) {\
				.code = b,\
				.status = c\
			}

# define __(a, b, c) \
	!a ? call(error, setError(b, c)) : 0

# define _N_(a, b, c) \
	a < 0 ? call(error, setError(b, c)) : 0

# define _NQ_(a, b, c) \
		a <= 0 ? call(error, setError(b, c)) : 0

public String function(getErrorAsString, Error error)
{
	__UNUSED__;
	switch (error.status)
	{
		case LOW:
			return "LOW";
		case HIGH:
			return "HIGH";
		default:
			return "CRITICAL";
	}
	return "NONE";
}

public void function(error, Error error)
{
	__UNUSED__;
	printf("[%s] Unexpected error happened : %d\n",
		call(getErrorAsString, error),
		error.code);
	perror("Stack:");
	call(__EXIT);
}

# endif
