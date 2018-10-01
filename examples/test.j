# package main

default Object is Test

future(Player)

create Object
(
	Test,

	Unknown unknown;

	Player * player;
)

import file player

import file test_handler

private Test * function(init)
{
	new(Test)
	alloc(_test, sizeof(Test))

	_test->unknown = setUnknown("hello", "world");
	_test->player = call(initPlayer, 90);
	return _test;
}

import main(int, { call(init) })

default(int)
{
	Unknown unknown = use unknown;
	$get(char, test1, alpha)
	$get(char, test2, beta)

	$>"%s %s" test1, test2

	use player->setId(this, 9);

	int id = use player->id;

	$>"Player id : %d" id

	free(use player);

	return 0;
}
