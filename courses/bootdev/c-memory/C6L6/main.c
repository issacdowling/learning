
#include "exercise.h"
#include <stdio.h>
#include <stdlib.h>

int main() {
	{
	int size = 5;
	int multiplier = 2;
	int *result = allocate_scalar_list(size, multiplier);
	if (result != 0) {
		printf("Success 1, non-null pointer\n");
	} else {
		printf("Fail 1, null pointer\n");
	}
	free(result);
	}

	{
	  int size = 5;
	  int multiplier = 2;
	  int *result = allocate_scalar_list(size, multiplier);
	  int expected[5];
	  expected[0] = 0;
	  expected[1] = 2;
	  expected[2] = 4;
	  expected[3] = 6;
	  expected[4] = 8;
	  for (int i = 0; i < size; i++) {
		if (result[i] == expected[i]) {
			printf("Success 2, expected values\n");
		} else {
			printf("Fail 2, not expected values\n");
		}
	  }
	  free(result);
	}

	{
	  int size = 3;
	  int multiplier = 0;
	  int *result = allocate_scalar_list(size, multiplier);
	  for (int i = 0; i < size; i++) {
				if (result[i] == 0) {
					printf("Success 3, 0\n");
				} else {
					printf("Fail 3, not 0\n");
				}	  }
	  free(result);
	}

	{
	  int size = 1024 * 1024 * 100;
	  int multiplier = 1;
	  int *result = allocate_scalar_list(size, multiplier);
 		if (result != 0) {
				printf("Success 4, expected null\n");
			} else {
				printf("Fail 4, not null\n");
			}
	}
}
