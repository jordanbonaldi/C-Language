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
	$new define("true", test1_true)
	$new define("false", test2_false)
	$new define("false", test3_false)
}
