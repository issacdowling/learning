
#include "http.h"
#include <stdio.h>
#include <string.h>

int main() {
    // I won't bother comparing the rest
    if (strcmp(http_to_str(HTTP_BAD_REQUEST), "400 Bad Request") == 0) {
        printf("Success");
    } else {
        printf("No success");
    }
}
