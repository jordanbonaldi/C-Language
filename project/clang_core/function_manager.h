/*
** EPITECH PROJECT, 2018
** IT
** File description:
** IT
*/

# ifndef FUNCTION_HANDLER_HH
	# define FUNCTION_HANDLER_HH

# define PARAM_NAMED this

# define public

# define private static

# define VA_ARGS(...) , ##__VA_ARGS__

# define __UNUSED__ (void)this;

# define __SETUNUSED__(param) (void)param;

# define PRE_FUNC_NAME MAIN_PREFIX

# define CREATE_ARGS MAIN_STRUCT *PARAM_NAMED

# define CREATE_FUNCTION(type, name) type PRE_FUNC_NAME##name(\
				__attribute__((unused))CREATE_ARGS)

# define function(access, type, name, ...) access type PRE_FUNC_NAME##name(\
				__attribute__((unused))CREATE_ARGS VA_ARGS(__VA_ARGS__))

# define CREATE_FUNCTION_PARAMS(type, name, params) \
	type PRE_FUNC_NAME##name(__attribute__((unused))CREATE_ARGS,\
			__attribute__((unused))params)

# define __launch__(type) type launcher(\
					__attribute__((unused))CREATE_ARGS,\
					__attribute__((unused))const int argc,\
					__attribute__((unused))char **argv)

# define CREATE_FUNCTION_NEUTRAL(type, name) type name()

# define CREATE_FUNCTION_NEUTRAL_LINKED(type, name) type name(CREATE_ARGS)

# define CREATE_FUNCTION_VARIADIC(type, name, params, ...) \
	type PRE_FUNC_NAME##name(CREATE_ARGS, params, __VA_ARGS__)

# define call(name, ...) PRE_FUNC_NAME##name(PARAM_NAMED VA_ARGS(__VA_ARGS__))

# define CALL_FUNCTION(name) PRE_FUNC_NAME##name(PARAM_NAMED)

# define CALL_FUNCTION_LINKED(name) name(PARAM_NAMED)

# define CALL_FUNCTION_LINKED_PASSED(name) name(&PARAM_NAMED)

# define call_params(name, param)\
		PRE_FUNC_NAME##name(PARAM_NAMED, param)

# define CALL_FUNCTION_PARAMS(name, param)\
		PRE_FUNC_NAME##name(PARAM_NAMED, param)

# define CALL_FUNCTION_PARAMS_AS_PASS(name, param)\
		PRE_FUNC_NAME##name(&PARAM_NAMED, param)

# define CALL_FUNCTION_VARIADIC(name, param, ...) \
	PRE_FUNC_NAME##name(PARAM_NAMED, param, __VA_ARGS__)

# define get(name) PRE_FUNC_NAME##name

# define CALL_FUNCTION_AS_PASS(name) PRE_FUNC_NAME##name(&PARAM_NAMED);

# define CREATE_FUNCTION_WITH_REGISTER(name, strname, register, func)\
		register(strname, GET_FUNCTION(name))

# define CALL_ANY(caller, args) caller(PARAM_NAMED, args)

# define CALL_ANY_AS_PASS(caller, args) caller(&PARAM_NAMED, args)

# define FUNC(c_) ({ c_ a;})

# define EXEC_FUNC(ret, func)\
		({ ret __fn__ func __fn__; })

# define static_main(type) type main(__attribute__((unused)) const int argc,\
				     __attribute__((unused)) char **argv\
			     ) {\
					new(MAIN_STRUCT, this, sizeof(MAIN_STRUCT))\
					type t = launcher(this, argc, argc);\
					free(this);\
					return t;\
				}

#endif
