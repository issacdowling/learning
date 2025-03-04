#include "../munit/munit.h"
#include "exercise.h"

#include <stdio.h>

// Trying to use munit so I need to modify the original tests less.

int main() {
	{
		snek_int_t integer;
		integer.value = 42;
		snek_zero_out(&integer, INTEGER);
		munit_assert_int(integer.value, ==, 0);
	}

	{
		snek_float_t float_num;
		float_num.value = 3.14;
		snek_zero_out(&float_num, FLOAT);
		munit_assert_float(float_num.value, ==, 0.0);
	}

	{
		snek_bool_t boolean;
		boolean.value = 1;
		snek_zero_out(&boolean, BOOL);
		munit_assert_int(boolean.value, ==, 0);
	}

	{
		snek_int_t integer;
		snek_float_t float_num;
		snek_bool_t boolean;

		integer.value = -100;
		float_num.value = -99.99;
		boolean.value = 255;

		snek_zero_out(&integer, INTEGER);
		snek_zero_out(&float_num, FLOAT);
		snek_zero_out(&boolean, BOOL);

		munit_assert_int(integer.value, ==, 0);
		munit_assert_float(float_num.value, ==, 0.0);
		munit_assert_int(boolean.value, ==, 0);

	}

	printf("All asserts passed\n");

}
