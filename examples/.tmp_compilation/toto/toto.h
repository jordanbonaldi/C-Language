#ifndef sync_toto
#define sync_toto

#include <clang.h>

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

public void function(test, String string)
{
	printf("%s\n", string);
}
#endif
