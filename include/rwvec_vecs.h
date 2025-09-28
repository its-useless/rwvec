#ifndef RWVEC_VECS_H
#define RWVEC_VECS_H
#include <stdlib.h>
#include <string.h>

#include "rwvec.h"

#ifdef RWVEC_VECS_IMPL
    #define VECTOR(name, type) \
        DEFINE_VEC(name, type); \
        IMPLEMENT_VEC(name, type)
#else
    #define VECTOR(name, type) DEFINE_VEC(name, type);
#endif

#define VECTOR_WITH_POINTER(name, type) \
    VECTOR(name, type) \
    VECTOR(name##_p, type*)

/* default vectors */
VECTOR_WITH_POINTER(rwvec_int, int)
VECTOR_WITH_POINTER(rwvec_uint, unsigned int)
VECTOR_WITH_POINTER(rwvec_long, long)
VECTOR_WITH_POINTER(rwvec_ulong, unsigned long)
VECTOR_WITH_POINTER(rwvec_char, char)
VECTOR_WITH_POINTER(rwvec_uchar, unsigned char)
VECTOR_WITH_POINTER(rwvec_short, short)
VECTOR_WITH_POINTER(rwvec_ushort, unsigned short)
VECTOR_WITH_POINTER(rwvec_float, float)
VECTOR_WITH_POINTER(rwvec_double, double)

VECTOR(rwvec_void_p, void*)

/* your custom implementations go here */

#endif