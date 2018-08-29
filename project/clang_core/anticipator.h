/*
** EPITECH PROJECT, 2018
** connection
** File description:
** connection
*/

# ifndef ANTICIPATOR_HH
	# define ANTICIPATOR_HH

# include "clang.h"

# define $s(a, b) a ?: a = b;

# define setNULL(setter) this->setter = NULL

# define $reset(a, size) memset(a, 0, size)

# define $attr(attr, name) attr name

# define $a(a, b) a += b;

# define $d(a, b) a -= b;

# define $equals(a, b) !strcmp(a, b)

# define $return(value) return (value);

# define _(a) a;

# define _time_attr unsigned long long int

# define $get(type, name, index) type *name = (type *)unknown.index;

# define new(name) name *

# define alloc(attr, size) attr = malloc(size);\
				{\
					_(__(attr, CRITICAL, 1));\
				}

#define GET_MACRO(_1,_2,_3,_4,NAME,...) NAME

# endif
