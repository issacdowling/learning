#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "exercise.h"

typedef unsigned int uintptr_t;

// Helper function to check if a pointer is on the stack
bool is_on_stack(void *ptr) {
  void *stack_top = __builtin_frame_address(0);
  uintptr_t stack_top_addr = (uintptr_t)stack_top;
  uintptr_t ptr_addr = (uintptr_t)ptr;

  // Check within a threshold in both directions (e.g., 1MB)
  uintptr_t threshold = 1024;

  return ptr_addr >= (stack_top_addr - threshold) && ptr_addr <= (stack_top_addr + threshold);
}

int main() {
	char *result = get_full_greeting("Hello", "Alice", 20);

	if (strcmp(result, "Hello Alice") == 0) {
		printf("Success basic greeting string\n");
	} else {
		printf("Failed basic greeting string\n");
	}

	if (!is_on_stack(result)) {
		printf("Success basic not on stack\n");
	} else {
		printf("Failed basic, is on stack!\n");
	}

	free(result);


	char *result2 = get_full_greeting("Hey", "Bob", 4);
	if (strcmp(result2, "Hey") == 0) {
		printf("Success 2, truncated to buffer\n");
	} else {
		printf("Failed 2, not truncated to buffer\n");
	}

	if (!is_on_stack(result2)) {
		printf("Success 2 not on stack\n");
	} else {
		printf("Failed 2, is on stack!\n");
	}

	free(result2);
}
