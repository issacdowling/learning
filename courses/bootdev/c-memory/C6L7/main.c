#include "exercise.h"
#include <stdio.h>
#include <stdlib.h>

int main() {
	// Much higher number than the default 500 so it _actually_ runs out of memory on real systems
	const int num_lists = 5000000;
	for (int i = 0; i < num_lists; i++) {
		int *lst = allocate_scalar_list(50000, 2);
		if (lst == NULL) {
			printf("Failed to allocate list\n");
		return 1;
		} else {
			printf("Allocated list %d\n", i);
		}
		free(lst);
	}
	return 0;
}
