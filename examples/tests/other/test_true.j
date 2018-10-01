# package tests/other

create test(test1_true)
{
	Unknown unknown = use unknown;
	$get(char, test1, alpha)
	return equals(test1, "hello");
}
