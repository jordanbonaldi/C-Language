/*
** EPITECH PROJECT, 2018
** client
** File description:
** client
*/

# ifndef DEFINITION_HH
	# define DEFINITION_HH

# define Object(x, ...) typedef struct s_##x { \
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
	OBJECT_DEFINE(DefaultObj);

/*
	End pre processing definition
*/

# define $new

# define create

$new Object
(
	DefaultObj,

	void 		*data;

	Socket 		*socket;
	TimeManager 	*time;
	Buffer 		*buffer;
	Container 	*queue;
	Tests 		*tests;
)

# define setObject(Obj, ...) (Obj) __VA_ARGS__

# define setDefault(object) this->data = object;

# define use ((OBJ*)this->data)->

# define null NULL

$new Object
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

#endif
