#include <stdlib.h>

#include "exercise.h"

int *allocate_scalar_list(int size, int multiplier) {
	int* scalar_list = (int*)malloc(size * sizeof(int));
	if (scalar_list == 0) {
		return 0;
	}
	for (int i = 0; i < size; i++) {
		scalar_list[i] = i * multiplier;
	}
	return scalar_list;
}
