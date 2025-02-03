#include <stdlib.h>

#include "exercise.h"

int main() {
	{
		int *pointer = NULL;
		allocate_int(&pointer, 10);

		if (pointer != 0) {
			printf("Success 1, pointer not null\n");
		} else {
			printf("Fail 1, pointer is null\n");
		}

		if (*pointer == 10) {
			printf("Success 2, pointer points to 10\n");
		} else {
			printf("Fail 2, pointer points not to 10\n");
		}

		free(pointer);
	}

	{
		int value = 5;
		int *pointer = &value;

		allocate_int(&pointer, 20);

		if (value == 5) {
			printf("Success 3, value has original (non-overwritten) value\n");
		} else {
			printf("Fail 3, value overwritten\n");
		}
		if (pointer != 0) {
			printf("Success 4, pointer not null\n");
		} else {
			printf("Fail 5, pointer is null\n");
		}

		if (*pointer == 20) {
			printf("Success 5, pointer has overwritten value\n");
		} else {
			printf("Fail 5, pointer not changed value\n");
		}

		free(pointer);
	}
}
