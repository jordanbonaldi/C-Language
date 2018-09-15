# package main

import file test_handler

import file player

default Object is Test

create Object
(
	Test,

	String test1;
	String test2;

	Player player;
)

private Test * function(init)
{
	new(Test)
	alloc(_test, sizeof(Test))

	_test->test1 = "hello";
	_test->test2 = "world";
	_test->player = setObject(Player, { .id = 90 });

	return _test;
}

import main(int, { call(init) })

default(int)
{
	$>"%s %s" use test1, use test2

	$>"Player id : %d" use player.id

	return 0;
}
