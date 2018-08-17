# ifndef toto_HH
	# define toto_HH

# include <clang.h>

static_main(int)

public_function_params(void, toto, String f)
{
	printf("f\n");
}

__launch__(int)
{
	int a = 0;
	this->data = &a;

	printf("%d\n", ((int *)this->data)[0]);
	return 0;
}

# endif
