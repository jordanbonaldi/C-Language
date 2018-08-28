# ifndef toto_HH
	# define toto_HH

# include <clang.h>

# define Object tar

OBJECT_CREATOR
(
	tar,

	String a;

	String b;
)

private function(tar *, init)
{
	new(tar, toto, sizeof(tar));

	toto->a = "toto";
	toto->b = "titi";

	return toto;
}

import main(int, init)

public function(void, test, String string)
{
	printf("%s\n", string);
}

private function(void, toto)
{
	printf("test1\n");
}

default(int)
{
	call(toto);
	call(test, use a);

	call(test, use b);

	return 0;
}

# endif
