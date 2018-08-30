##
## EPITECH PROJECT, 2018
## Makefile
## File description:
## Makefile
##

CC = gcc

RM = rm -f

CFLAGS += -W -Wextra -Wall -Werror -g3 -fpic

CFLAGS += -Iproject/clang_core/ -Iproject/.

FILE = clang_core

MAIN_HEADER = clang.h

PATH_USR = /usr/

PATH_LIB = $(PATH_USR)lib/

PATH_INCLUDE = $(PATH_USR)include/

PATH_INCLUDE_CORE = $(PATH_INCLUDE)$(FILE)/

PATH_PROJECT = project/

PATH_CORE = $(PATH_PROJECT)$(FILE)/

MAKE_FILE = $(PATH_PROJECT).install/Makefile

COMPILER = $(PATH_PROJECT).install/clang_compile

COMPILER_BIN = /bin/

NAME = libclang.so

SRCS = $(PATH_PROJECT)main.c

OBJS = $(SRCS:.c=.o)

all: $(NAME) install

install: transfer fclean

remove_if_exist:
	if test -d $(PATH_INCLUDE_CORE); \
	 then rm -Rf $(PATH_INCLUDE_CORE) && mkdir $(PATH_INCLUDE_CORE); \
	 else mkdir $(PATH_INCLUDE_CORE); \
	fi

transfer: remove_if_exist
	cp $(NAME) $(PATH_LIB).
	cp $(MAKE_FILE) $(PATH_INCLUDE_CORE)
	cp $(COMPILER) $(COMPILER_BIN)
	chmod 665 $(COMPILER_BIN)clang_compile
	cp -R $(PATH_CORE)* $(PATH_INCLUDE_CORE).
	cp $(PATH_PROJECT)$(MAIN_HEADER) $(PATH_INCLUDE).

$(NAME): $(OBJS)
	$(CC) -shared -o $(NAME) $(OBJS)

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

.PHONY: all clean fclean re
