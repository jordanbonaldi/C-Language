# package tests

import file test_true

create test(test2_false)
{
	return false;
}

create test(test3_false)
{
	return false;
}

create initialisator
{
	create define("true", test1_true)
	create define("false", test2_false)
	create define("false", test3_false)
}
