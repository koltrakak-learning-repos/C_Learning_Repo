#include <stdlib.h>
#include <string.h>

#include "object.h"

int obj_len(object_t *obj) {
    if (obj == NULL) {
        return -1;
    }

    switch (obj->kind) {
        case INTEGER:
            return 1;
        
        case FLOAT:
            return 1;

        case STRING:
            return strlen(obj->data.v_string);

        case VECTOR3:
            return 3;
    
        case ARRAY:
            return obj->data.v_array.size;
        
        default:
            return -1;
    }
}


object_t *new_integer(int value) {
    object_t *new_int_obj = (object_t *)malloc(sizeof(object_t));
    if (new_int_obj == NULL) {
        return NULL;
    }

    new_int_obj->kind = INTEGER;
    new_int_obj->data.v_int = value;

    return new_int_obj;    
}

object_t *new_float(float value) {
    object_t *new_float_obj = (object_t *)malloc(sizeof(object_t));
    if (new_float_obj == NULL) {
        return NULL;
    }

    new_float_obj->kind = FLOAT;
    new_float_obj->data.v_float = value;

    return new_float_obj;    
}


// Small data types like integers and floats are stored directly in the object, so there's no need for additional memory allocation.
// Strings, however, are a different story. Strings in C are just arrays of characters, and because they can be any length, we need 
// to dynamically allocate memory for the string data separately from the object itself.
object_t *new_string(char *value) {
    object_t *new_string_obj = (object_t *)malloc(sizeof(object_t));
    if (new_string_obj == NULL) {
        return NULL;
    }

    int size = strlen(value) + 1;
    char* new_string_value = (char *)malloc(size);
    if (new_string_obj == NULL) {
        free(new_string_obj);
        return NULL;
    }
    memcpy(new_string_value, value, size);
    
    new_string_obj->kind = STRING;
    new_string_obj->data.v_string = new_string_value;

    return new_string_obj;    
}


object_t *new_vector3(
    object_t *x,
    object_t *y,
    object_t *z
) {
    if (x == NULL || y == NULL || z == NULL) {
        return NULL;
    }

    object_t *new_vec3_obj = (object_t *)malloc(sizeof(object_t));
    if (new_vec3_obj == NULL) {
        return NULL;
    }
    
    new_vec3_obj->kind = VECTOR3;
    new_vec3_obj->data.v_vector3 = (vector_t){
        .x = x,
        .y = y,
        .z = z,
    };

    return new_vec3_obj;    
}

object_t *new_array(size_t size) {
    object_t *new_array_obj = (object_t *)malloc(sizeof(object_t));
    if (new_array_obj == NULL) {
        return NULL;
    }
    
    object_t **elements = (object_t **)calloc(size, sizeof(object_t *));
    if (elements == NULL) {
        free(new_array_obj);
        return NULL;
    }

    new_array_obj->kind = ARRAY;
    new_array_obj->data.v_array.size     = size;
    new_array_obj->data.v_array.elements = elements;

    return new_array_obj;
}

bool array_set(object_t *arr_obj, size_t index, object_t *value) {
    if (arr_obj == NULL || value == NULL) {
        return false;
    }
    if(arr_obj->kind != ARRAY) {
        return false;
    }
    if (index < 0 || arr_obj->data.v_array.size <= index) {
        return false;
    }

    arr_obj->data.v_array.elements[index] = value;
    return true;
}

object_t *array_get(object_t *arr_obj, size_t index) {
    if (arr_obj == NULL) {
        return NULL;
    }
    if(arr_obj->kind != ARRAY) {
        return NULL;
    }
    if (index < 0 || arr_obj->data.v_array.size <= index) {
        return NULL;
    }

    return arr_obj->data.v_array.elements[index];
}




object_t *obj_sum(object_t *a, object_t *b) {
    if (a == NULL || b == NULL) {
        return NULL;
    }

    switch (a->kind) {
        case INTEGER:
            switch (b->kind) {
                case INTEGER:
                    return new_integer(a->data.v_int + b->data.v_int);
                case FLOAT:
                    return new_float(a->data.v_int + b->data.v_float);
                default:
                    return NULL;
            }

        case FLOAT:
            switch (b->kind) {
                case INTEGER:
                    return new_integer(a->data.v_float + b->data.v_int);
                case FLOAT:
                    return new_float(a->data.v_float + b->data.v_float);
                default:
                    return NULL;
            }

        case STRING:
            switch (b->kind) {
                case STRING:
                    int new_size = obj_len(a) + obj_len(b) + 1;
                    char *sum_string = (char *)calloc(new_size, sizeof(char));
                    strcat(sum_string, a->data.v_string);
                    strcat(sum_string, b->data.v_string);
                    object_t *res = new_string(sum_string);
                    free(sum_string);
                    return res;
                default:
                    return NULL;
            }
        
        case VECTOR3:
            switch (b->kind) {
                case VECTOR3:
                    return new_vector3(
                        obj_sum(a->data.v_vector3.x, b->data.v_vector3.x),
                        obj_sum(a->data.v_vector3.y, b->data.v_vector3.y),
                        obj_sum(a->data.v_vector3.z, b->data.v_vector3.z)
                    );
                default:
                    return NULL;
            }

        case ARRAY:
            switch (b->kind) {
                case ARRAY:
                    int new_size = obj_len(a) + obj_len(b);
                    object_t *res = new_array(new_size);

                    for(int i=0; i<a->data.v_array.size; i++) {
                        array_set(res, i, array_get(a, i));
                    }
                    for(int i=0; i<b->data.v_array.size; i++) {
                        array_set(res, i, array_get(b, i));
                    }

                    return res;                    

                default:
                    return NULL;
            }

        default:
            return NULL;
    }
}