#include <stdio.h>
#include <stdlib.h>
#include "exercise.h"

char *get_full_greeting(char *greeting, char *name, int size) {
	// No longer need to assume 100, since it's being dynamically allocated
	char* full_greeting = (char*)malloc(size * sizeof(char));
	snprintf(full_greeting, size, "%s %s", greeting, name);
	return full_greeting;
}
