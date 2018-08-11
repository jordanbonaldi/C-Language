/*
** EPITECH PROJECT, 2018
** client
** File description:
** client
*/

# ifndef DEFINITION_HH
	# define DEFINITION_HH

# define OBJECT_CREATOR(x, ...) typedef struct s_##x { \
				__VA_ARGS__; \
			} x;

# define OBJECT_DEFINE(x) typedef struct s_##x x;

/*
	Defining struct to allocating pre processing memory
*/

	OBJECT_DEFINE(SockFile);
	OBJECT_DEFINE(Socket);
	OBJECT_DEFINE(CallBack);
	OBJECT_DEFINE(Unknown);
	OBJECT_DEFINE(Times);
	OBJECT_DEFINE(TimeManager);
	OBJECT_DEFINE(Tests);
	OBJECT_DEFINE(DefaultObj);
	OBJECT_DEFINE(Buffer);
	OBJECT_DEFINE(Container);

/*
	End pre processing definition
*/

OBJECT_CREATOR
(
	DefaultObj,

	void *data;

	Socket *socket;
	TimeManager *time;
	Buffer *buffer;
	Container *queue;
	Tests *tests;
)

OBJECT_CREATOR
(
	Unknown,

	void *alpha;
	void *beta;
)

# define setUnknown(a, b) (Unknown) {\
				.alpha = a,\
				.beta = b\
			}

# define Status enum s_status

# define Direction enum s_Direction

# define String char *

# define _sendToUser(x, s) dprintf(x, s)

# define __sendToUser(user, s, ...) dprintf(user->index, s, __VA_ARGS__)

#endif
