/*
** EPITECH PROJECT, 2018
** lol
** File description:
** lol
*/

# ifndef TEST_JORDYTERION_HH
	# define TEST_JORDYTERION_HH

# include "clang.h"

create Object
(
	Tests,

	String name;

	bool (*action)(MAIN_STRUCT *);

	struct s_Tests *next;
)

# define setTests(n, cb) (Tests) {\
					.name = n,\
					.action = cb\
				}

# define test(name) public bool function(name)

# define initialisator public void function(init_test)

# define define(n, f) {\
				call(addTest, setTests(n, getFnc(f)));\
			}

private int function(sizeTests)
{
	int $i = 0;

	foreach(Tests *, this->tests, {
		$i++;
	});

	return $i;
}

public void function(launchTests)
{
	int $failed = 0;
	int $succeed = 0;
	int $test = 0;
	int $size = call(sizeTests);

	foreach
	(
		Tests *,
		this->tests,
		{
			$test++;
			printf("\nTesting T:%d -> %s\n\n", $test, IT->name);
			if (IT->action(this)) {
				printf("\n=========== RESULTS ===========\n");
				printf("\n\tTest : %d -> succeed\n", $test);
				$succeed ++;
			} else {
				printf("\n=========== RESULTS ===========\n");
				printf("\n\tTest : %d -> failed\n", $test);
				$failed ++;
			}
		}
	)

	printf("\n\n======== GLOBAL RESULTS ========\n\n");

	printf("\t%d test(s) succeed on %d test(s)\n", $succeed, $size);

	printf("\t%d test(s) failed on %d test(s)\n", $failed, $size);

	printf("\n\tSuccess : %.1f%%\n", (double)($succeed * 100) / $size);
	if ($failed)
		printf("\tFail : %.1f%%\n", (double)($failed * 100) / $size);
}

public void function(addTest, Tests test)
{
	new(Tests)
	alloc(__test, sizeof(Tests))

	Tests *tmp;

	__test->name = test.name;
	__test->action = test.action;
	__test->next = NULL;
	if (!this->tests)
		this->tests = __test;
	else {
		tmp = this->tests;
		while (tmp->next)
			tmp = tmp->next;
		tmp->next = __test;
	}
}

public void function(destroyTests)
{
	Tests *tmp = this->tests;
	Tests *tmp2;

	while (tmp) {
		tmp2 = tmp->next;
		free(tmp);
		tmp = tmp2;
	}
}


# endif
