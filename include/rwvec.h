#ifndef RWVEC_H
#define RWVEC_H
#include <stddef.h>

#define DEFINE_VEC(name, type) \
    typedef struct name { \
        type* data; \
        size_t capacity; \
        size_t length; \
    } name##_t; \
    struct name name##_new(void); \
    void name##_del(struct name* vec); \
    void name##_push(struct name* vec, type element); \
    void name##_pop(struct name* vec); \
    void name##_remove(struct name* vec, size_t index); \
    void name##_insert(struct name* vec, size_t index, type element)

#define IMPL_VEC_NEW(name, type) \
    struct name name##_new(void) { \
        struct name inst = {NULL, 0, 0}; \
        return inst; \
    }
#define IMPL_VEC_DEL(name, type) \
    void name##_del(struct name* vec) { \
        if (vec->data) \
            free(vec->data); \
    }
#define IMPL_VEC_PUSH(name, type) \
    void name##_push(struct name* vec, type element) { \
        vec->data = realloc(vec->data, vec->capacity + sizeof(type)); \
        vec->data[vec->length] = element; \
        vec->length += 1; \
        vec->capacity = vec->length * sizeof(type); \
    }
#define IMPL_VEC_POP(name, type) \
    void name##_pop(struct name* vec) { \
        if (vec->length == 0) \
            return; \
        vec->data = realloc(vec->data, vec->capacity - sizeof(type)); \
        vec->length -= 1; \
        vec->capacity = vec->length * sizeof(type); \
        if (vec->length == 0) \
            vec->data = NULL; \
    }
#define IMPL_VEC_REMOVE(name, type) \
    void name##_remove(struct name* vec, size_t index) { \
        if (index >= vec->length) \
            return; \
        memmove( \
            vec->data + index, \
            vec->data + index + 1, \
            vec->capacity - (index + 1) * sizeof(type) \
        ); \
        name##_pop(vec); \
    }
#define IMPL_VEC_INSERT(name, type) \
    void name##_insert(struct name* vec, size_t index, type element) { \
        if (index > vec->length) \
            return; \
        if (index == vec->length) { \
            name##_push(vec, element); \
            return; \
        } \
        vec->data = realloc(vec->data, vec->capacity + sizeof(type)); \
        memmove( \
            vec->data + index + 1, \
            vec->data + index, \
            vec->capacity - (index) * sizeof(type) \
        ); \
        vec->data[index] = element; \
        vec->length++; \
        vec->capacity = vec->length * sizeof(type); \
    }

#define IMPLEMENT_VEC_FUNCS(name, type) \
    IMPL_VEC_NEW(name, type) \
    IMPL_VEC_DEL(name, type) \
    IMPL_VEC_PUSH(name, type) \
    IMPL_VEC_POP(name, type) \
    IMPL_VEC_REMOVE(name, type) \
    IMPL_VEC_INSERT(name, type)

#ifdef __cplusplus
    #define IMPLEMENT_VEC(name, type) \
        extern "C" { \
        IMPLEMENT_VEC_FUNCS(name, type) \
        }
#else
    #define IMPLEMENT_VEC(name, type) IMPLEMENT_VEC_FUNCS(name, type)
#endif

#endif
