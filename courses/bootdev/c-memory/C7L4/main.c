#include <stddef.h>
#include <stdio.h>

#include "exercise.h"
#include "../munit/munit.h"

int main() {
	{
		int a = 5;
		int b = 6;

		swap_ints(&a, &b);

		munit_assert_int(a, ==, 6);
		munit_assert_int(b, ==, 5);
	}

	{
		int a = 5;

		swap_ints(&a, &a);

		munit_assert_int(a, ==, 5);
	}
	printf("All asserts passed\n");

}
