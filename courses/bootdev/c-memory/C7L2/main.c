#include <stdio.h>
#include "exercise.h"
#include <stdlib.h>
#include <string.h>

int main() {
	{
		token_t token = {"hello", 1, 1};
		token_t** result = create_token_pointer_array(&token, 1);
		if (result != 0) {
			printf("Success 1, result array not null\n");
		} else {
			printf("Fail 1, result array null\n");
		}

		if (result[0] != 0) {
			printf("Success 2, result array[0] token pointer not null\n");
		} else {
			printf("Fail 1, result array[0] token pointer null\n");
		}

		if (strcmp(result[0]->literal, "hello") == 0) {
			printf("Success 3, result array[0] token literal is hello\n");
		} else {
			printf("Fail 3, result array[0] token literal not hello\n");
		}

		if (result[0]->line == 1) {
			printf("Success 4, result array[0]->line is 1\n");
		} else {
			printf("Fail 4, result array[0]->line not 1\n");
		}

		if (result[0]->column == 1) {
			printf("Success 5, result array[0]->column is 1\n");
		} else {
			printf("Fail 5, result array[0]->column not 1\n");
		}

		// Until here runs with the unmodified code, but these pointers end up being equal.
		if (result[0] != &token) {
			printf("Success 6, result[0] pointer != token pointer\n");
		} else {
			printf("Fail 6, result[0] pointer == token pointer\n");
		}

		free(result[0]);
		free(result);
	}

	{
		token_t tokens[3] = {
			{"foo", 1, 1},
			{"bar", 2, 5},
			{"baz", 3, 10}
		};
		token_t** result = create_token_pointer_array(tokens, 3);

		if (result != 0) {
			printf("Success 7, result pointer not null\n");
		} else {
			printf("Fail 7, result pointer is null\n");
		}

		for (int i = 0; i < 3; i++) {
			if (result != 0) {
				printf("Success %d, result pointer not null\n", 8 + i);
			} else {
				printf("Fail %d, result pointer is null\n", 8 + i);
			}

			if (strcmp(result[i]->literal, tokens[i].literal) == 0) {
				printf("Success %d, literal matches\n", 9 + i);
			} else {
				printf("Fail %d, literal not matches\n", 9 + i);
			}

			if (result[i]->line == tokens[i].line) {
				printf("Success %d, line number match\n", 10 + i);
			} else {
				printf("Fail %d, line number no match\n", 10 + i);
			}

			if (result[i]->column == tokens[i].column) {
				printf("Success %d, column number match\n", 11 + i);
			} else {
				printf("Fail %d, column number no match\n", 11 + i);
			}

			if (result[i] != &tokens[i]) {
				printf("Success %d, result[i] pointer != token pointer\n", 12 + i);
			} else {
				printf("Fail %d, result[i] pointer == token pointer\n", 12 + i);
			}
		}
		for (int i = 0; i < 3; i++) {
			free(result[i]);
		}
		free(result);
	}

	{
		token_t tokens[2] = {
			{"test1", 1, 1},
			{"test2", 2, 2}
		};
		token_t** result = create_token_pointer_array(tokens, 2);

		if (result != 0) {
			printf("Success 15, array not null\n");
		} else {
			printf("Fail 15, array is null\n");
		}

		if (result[0] != 0) {
			printf("Success 16, first in array not null\n");
		} else {
			printf("Fail 16, first in array is null\n");
		}

		if (result[1] != 0) {
			printf("Success 17, second in array not null\n");
		} else {
			printf("Fail 17, second in array is null\n");
		}

		if (result[0] != result[1]) {
			printf("Success 18, first and second in array different\n");
		} else {
			printf("Fail 18, first and second in array not different\n");
		}

		if (result[0] != &tokens[0]) {
			printf("Success 19, first token pointer doesn't point to original\n");
		} else {
			printf("Fail 19, first token pointer points to original\n");
		}

		if (result[1] != &tokens[1]) {
			printf("Success 20, second token pointer doesn't point to original\n");
		} else {
			printf("Fail 20, second token pointer points to original\n");
		}

		free(result[0]);
		free(result[1]);
		free(result);
	}
}
