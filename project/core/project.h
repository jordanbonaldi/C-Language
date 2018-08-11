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

# include "anticipator.h"

# include "function_manager.h"

# define MAIN_STRUCT DefaultObj

# include "definition.h"

CREATE_FUNCTION(void, __EXIT)
{
	exit(EXIT_SUCCESS);
}

# include "error_manager.h"

# include "iterator_manager.h"

# include "socket_manager.h"

# include "timeutils.h"

# include "callback.h"

# include "test_manager.h"

# include "socket_manager.h"

# include "buffer.h"

# include "commands_queue.h"

__LAUNCH__(int)
{
	printf("toto\n");
	return 0;
}

#endif
