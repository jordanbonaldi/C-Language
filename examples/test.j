# package main

import file test_handler

# define $Object test

$new Object
(
	test,

	String test1;
	String test2;
)

private test * function(init)
{
	new(test)
	alloc(_test, sizeof(test))

	_test->test1 = "hello";
	_test->test2 = "world";

	return _test;
}

import main(int, { call(init)})

default(int)
{
	printf("%s %s\n", use test1, use test2);
	return 0;
}
