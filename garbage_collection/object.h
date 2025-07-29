#pragma once

#include <stdbool.h>
#include <stddef.h>

typedef struct Object object_t; // forward declaration

typedef struct Vector {
    object_t *x;
    object_t *y;
    object_t *z;
} vector_t;

typedef struct Array {
    size_t size;
    object_t **elements; // array di puntatori ad oggetti
} array_t;

typedef enum ObjectKind {
    INTEGER,
    FLOAT,
    STRING,
    VECTOR3,
    ARRAY,
} object_kind_t;

typedef union ObjectData {
    int v_int;
    float v_float;
    char* v_string;
    vector_t v_vector3;
    array_t v_array;
} object_data_t;

typedef struct Object {
    object_kind_t kind;
    object_data_t data;
    int ref_count;
} object_t;


extern int obj_len(object_t *obj);
extern object_t *obj_sum(object_t *a, object_t *b);
extern object_t *_new_obj();
extern void refcount_inc(object_t *obj);
extern void refcount_dec(object_t *obj);
extern void refcount_free(object_t *obj);

extern object_t *new_integer(int value);
extern object_t *new_float(float value);
extern object_t *new_string(char* value);
extern object_t *new_vector3(
    object_t *x,
    object_t *y,
    object_t *z
); 
extern object_t *new_array(size_t size);
extern bool array_set(object_t *array, size_t index, object_t *value);
extern object_t *array_get(object_t *array, size_t index);