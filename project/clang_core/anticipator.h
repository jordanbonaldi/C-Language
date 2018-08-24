/*
** EPITECH PROJECT, 2018
** connection
** File description:
** connection
*/

# ifndef ANTICIPATOR_HH
	# define ANTICIPATOR_HH

# include "clang.h"

# define ASSIGN(a, b) a ?: a = b;

# define setNULL(setter) this->setter = NULL

# define RESET(a, size) memset(a, 0, size)

# define __ATTR__(attr, name) attr name

# define _A_(a, b) a += b;

# define _D_(a, b) a -= b;

# define __return(value) return (value);

# define _(a) a;

# define _time_attr unsigned long long int

# define _get(type, name, index) type *name = (type *)unknown.index;

# define __MALLOC_CR__(attr, name, size) attr * name = malloc(size);\
				{\
					_(__(name, CRITICAL, 1));\
				}

# define __MALLOC__(attr, size) attr = malloc(size);\
				{\
					_(__(attr, CRITICAL, 1));\
				}

# define new(attr, name, size) attr * name = malloc(size);\
				{\
					_(__(name, CRITICAL, 1));\
				}

# define alloc(attr, size) attr = malloc(size);\
				{\
					_(__(attr, CRITICAL, 1));\
				}

# endif
