# package tests

import file test_true

create test(test2_false)
{
	Unknown unknown = use unknown;
	$get(char, test1, alpha)

	return !equals(test1, "hell0");
}

create test(test3_false)
{
	Unknown unknown = use unknown;
	$get(char, test1, beta)

	return !equals(test1, "World");
}

create initialisator
{
	create define("true", test1_true)
	create define("false", test2_false)
	create define("false", test3_false)
}
