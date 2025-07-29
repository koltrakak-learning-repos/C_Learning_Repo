#pragma once
#include <stdbool.h>
#include <stddef.h>

#include "stack.h"

typedef struct VmObject vm_object_t;

typedef struct {
  size_t size;
  vm_object_t **elements;
} vm_array_t;

typedef struct {
  vm_object_t *x;
  vm_object_t *y;
  vm_object_t *z;
} vm_vector_t;

typedef enum VmObjectKind {
  INTEGER,
  FLOAT,
  STRING,
  VECTOR3,
  ARRAY,
} vm_object_kind_t;

typedef union SnekObjectData {
  int v_int;
  float v_float;
  char *v_string;
  vm_vector_t v_vector3;
  vm_array_t v_array;
} vm_object_data_t;

typedef struct VmObject {
  bool is_marked;
  vm_object_kind_t kind;
  vm_object_data_t data;
} vm_object_t;

void vm_object_free(vm_object_t *obj);