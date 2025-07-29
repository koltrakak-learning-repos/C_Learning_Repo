#include <stdlib.h>
#include <string.h>

#include "vm_object.h"
#include "vm_object_creation.h"
#include "vm.h"

vm_object_t *_new_vm_object(vm_t *vm) {
  vm_object_t *obj = calloc(1, sizeof(vm_object_t));
  if (obj == NULL) {
    return NULL;
  }

  vm_track_object(vm, obj);

  return obj;
}

vm_object_t *new_vm_array(vm_t *vm, size_t size) {
  vm_object_t *obj = _new_vm_object(vm);
  if (obj == NULL) {
    return NULL;
  }

  vm_object_t **elements = calloc(size, sizeof(vm_object_t *));
  if (elements == NULL) {
    free(obj);
    return NULL;
  }

  obj->kind = ARRAY;
  obj->data.v_array = (vm_array_t){.size = size, .elements = elements};

  return obj;
}

vm_object_t *new_vm_vector3(
    vm_t *vm, vm_object_t *x, vm_object_t *y, vm_object_t *z
) {
  if (x == NULL || y == NULL || z == NULL) {
    return NULL;
  }

  vm_object_t *obj = _new_vm_object(vm);
  if (obj == NULL) {
    return NULL;
  }

  obj->kind = VECTOR3;
  obj->data.v_vector3 = (vm_vector_t){.x = x, .y = y, .z = z};

  return obj;
}

vm_object_t *new_vm_integer(vm_t *vm, int value) {
  vm_object_t *obj = _new_vm_object(vm);
  if (obj == NULL) {
    return NULL;
  }

  obj->kind = INTEGER;
  obj->data.v_int = value;

  return obj;
}

vm_object_t *new_vm_float(vm_t *vm, float value) {
  vm_object_t *obj = _new_vm_object(vm);
  if (obj == NULL) {
    return NULL;
  }

  obj->kind = FLOAT;
  obj->data.v_float = value;
  return obj;
}

vm_object_t *new_vm_string(vm_t *vm, char *value) {
  vm_object_t *obj = _new_vm_object(vm);
  if (obj == NULL) {
    return NULL;
  }

  int len = strlen(value);
  char *dst = malloc(len + 1);
  if (dst == NULL) {
    free(obj);
    return NULL;
  }

  strcpy(dst, value);

  obj->kind = STRING;
  obj->data.v_string = dst;
  return obj;
}
