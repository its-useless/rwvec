#define RWVEC_VECS_IMPL
#include <rwvec_vecs.h>
#include <stdio.h>

void print(rwvec_int_t* vec) {
    size_t i;
    for (i = 0; i < vec->length; i++) {
        printf("%d ", vec->data[i]);
    }
    printf("\n");
}

int main() {
    rwvec_int_t vec = rwvec_int_new();

    rwvec_int_push(&vec, 123);
    rwvec_int_push(&vec, 69);
    rwvec_int_push(&vec, 256);

    rwvec_int_insert(&vec, 3, 42);

    print(&vec);

    rwvec_int_del(&vec);
    return 0;
}