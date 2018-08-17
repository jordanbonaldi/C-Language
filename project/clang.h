/*
** EPITECH PROJECT, 2018
** IT
** File description:
** IT
*/

# ifndef PROJECT_HH
	# define PROJECT_HH

# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <sys/types.h>
# include <sys/socket.h>
# include <sys/select.h>
# include <netinet/in.h>
# include <netdb.h>
# include <arpa/inet.h>
# include <unistd.h>
# include <signal.h>
# include <stdbool.h>
# include <sys/time.h>
# include <errno.h>
# include <stdarg.h>
# include <fcntl.h>
# include <ctype.h>
# include <time.h>
# include <assert.h>

// PROJECT'S INCLUDES

# include "clang_core/definition.h"

# include "clang_core/function_manager.h"

# define MAIN_STRUCT DefaultObj

# include "clang_core/anticipator.h"

CREATE_FUNCTION(void, __EXIT)
{
	exit(EXIT_SUCCESS);
}

# include "clang_core/error_manager.h"

# include "clang_core/iterator_manager.h"

# include "clang_core/socket_manager.h"

# include "clang_core/timeutils.h"

# include "clang_core/callback.h"

# include "clang_core/test_manager.h"

# include "clang_core/socket_manager.h"

# include "clang_core/buffer.h"

# include "clang_core/commands_queue.h"

#endif
