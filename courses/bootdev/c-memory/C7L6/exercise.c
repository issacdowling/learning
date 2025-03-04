#include <stdlib.h>
#include <string.h>

void swap(void *vp1, void *vp2, size_t size) {
    // "Allocate memory for a temporary buffer to store the data using malloc."
    void* tmp = malloc(size);
    // "If the allocation fails (returns NULL) return immediately."
    if (tmp == 0) {
        return;
    }

    // "Use memcpy to shuffle the data around."
    memcpy(tmp, vp2, size);

    memcpy(vp2, vp1, size);

    mempcpy(vp1, tmp, size);

    // "Don't forget to free the temporary buffer."
    free(tmp);
}
