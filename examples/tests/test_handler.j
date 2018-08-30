# package tests

import file test_true

$new test(test2_false)
{
	return false;
}

$new test(test3_false)
{
	return false;
}

$new initialisator
{
	$new define("true", test1_true)
	$new define("false", test2_false)
	$new define("false", test3_false)
}
