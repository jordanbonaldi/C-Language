# ifndef toto_HH
	# define toto_HH

# include <clang.h>

# define Object tar

$new Class
(
	michel,

	int ui;
)

$new Class
(
	tar,

	String a;
	michel mich;
	String b;
)

private tar * function(init)
{
	new(tar)
	alloc(toto, sizeof(tar));

	toto->a = "toto";
	toto->b = "titi";
	toto->mich = setObject(michel, {
		.ui = 90
	});

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

$new test(toto1)
{
	return false;
}

$new test(toto2)
{
	return true;
}

$new initialisator
{
	$new define("t1", toto1)
	$new define("t2", toto2)
}

import main(int, { call(init) })

default(int)
{
	new(String)
	alloc(name, 19)

	name[0] = "tot";

	call(test, *name);

	call(test, use a);

	printf("%d\n", use mich.ui);

	return 0;
}

# endif
