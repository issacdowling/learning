#include "exercise.h"
#include <string.h>
#include <stdio.h>

int main() {

    char str_buffer[100];
    snek_object_t str_object = new_string("Hello");
    format_object(str_object, str_buffer);
    if (strcmp("string:Hello", str_buffer) == 0) {
        printf("Str1Success\n");
    } else {
        printf("Str1Fail\n");
    }

    snek_object_t str2_object = new_string("good evening");
    format_object(str2_object, str_buffer);
    if (strcmp("string:good evening", str_buffer) == 0) {
        printf("Str2Success\n");
    } else {
        printf("Str2Fail\n");
    }


    char int_buffer[100];
    snek_object_t int_object = new_integer(10);
    format_object(int_object, int_buffer);
    if (strcmp("int:10", int_buffer) == 0) {
        printf("IntSuccess\n");
    } else {
        printf("IntFail\n");
    }

    snek_object_t int2_object = new_integer(20004);
    format_object(int2_object, int_buffer);
    if (strcmp("int:20004", int_buffer) == 0) {
        printf("Int2Success\n");
    } else {
        printf("Int2Fail\n");
    }
}
