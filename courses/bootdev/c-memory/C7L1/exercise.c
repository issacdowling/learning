#include "stdlib.h"

#include "exercise.h"

void allocate_int(int **pointer_pointer, int value) {
	int* single_int = (int*)malloc(sizeof(int));
	// Took a while to put a * before pointer_pointer, kept getting a null pointer,
	// needed to re-think the point of this a few times to catch it.
	*pointer_pointer = single_int;
	*single_int = value;
}
