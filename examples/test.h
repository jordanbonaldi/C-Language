# ifndef toto_HH
	# define toto_HH

# include <clang.h>

static_main(int)

function(private, void, test, String string)
{
	printf("%s\n", string);
}

function(private, void, toto)
{
	printf("test1\n");
}

__launch__(int)
{
	int a = 0;
	this->data = &a;

	call(toto);
	call(test, "toto");

	printf("%d\n", ((int *)this->data)[0]);

	return 0;
}

# endif
