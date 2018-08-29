/*
** EPITECH PROJECT, 2018
** connection
** File description:
** connection
*/

# ifndef CALLBACK_HH
	# define CALLBACK_HH

# include "clang.h"

$new Class
(
	CallBack,

	String str;
	void (*action)(void *);
)

# define setCallBack(s, func) (CallBack) { \
			.str = s,\
			.action = func \
		}

# endif
