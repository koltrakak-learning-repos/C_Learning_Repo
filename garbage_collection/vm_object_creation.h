#pragma once
#include "vm_object.h"
#include "vm.h"

vm_object_t *new_vm_integer(vm_t *vm, int value);
vm_object_t *new_vm_float(vm_t *vm, float value);
vm_object_t *new_vm_string(vm_t *vm, char *value);
vm_object_t *new_vm_vector3(
    vm_t *vm,
    vm_object_t *x,
    vm_object_t *y,
    vm_object_t *z
);
vm_object_t *new_vm_array(vm_t *vm, size_t size);
