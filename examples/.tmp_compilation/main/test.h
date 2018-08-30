#ifndef sync_main
#define sync_main

#include <clangh.h>

# define $Object tar

$new Object
(
	michel,

	int ui;
)

$new Object
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
#endif
