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

private tar * function(init)
{
	new(tar)
    alloc(toto, sizeof(tar));

	toto->a = "toto";
	toto->b = "titi";

	return toto;
}

public void function(test, String string)
{
	printf("%s\n", string);
}

private void function(toto)
{
	printf("test1\n");
}

CREATE_TEST(toto1)
{
	return false;
}

CREATE_TEST(toto2)
{
	return true;
}

INIT_TEST
{
	__ACTIVATED__("t1", toto1)
	__ACTIVATED__("t2", toto2)
}

import main(int, { call(init) })

default(int)
{
    new(String)
    alloc(name, 19)

		name[0] = "tot";

		call(test, *name);

		call(test, use a);
		return 0;
}

# endif
