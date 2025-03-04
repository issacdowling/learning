#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>

#include "exercise.h"
#include "../munit/munit.h"

int main() {
	{
		char *a = "Hello";
		char *b = "Goodbye";

		swap_strings(&a, &b);

		munit_assert_string_equal(a, "Goodbye");
		munit_assert_string_equal(b, "Hello");
	}

	{
		char *a = "terminal.shop";
		char *b = "ssh";

		swap_strings(&a, &b);

		munit_assert_string_equal(a, "ssh");
		munit_assert_string_equal(b, "terminal.shop");
	}
}
