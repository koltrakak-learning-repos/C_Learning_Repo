#pragma once
#include "vm_object.h"
#include "stack.h"

// vm immaginaria che tiene traccia degli oggetti e degli stack frame creati
typedef struct VirtualMachine {
  stack_t *frames;
  stack_t *objects;
} vm_t;

typedef struct StackFrame {
  stack_t *references; // references to object_t
} frame_t;

vm_t *vm_new();
void vm_free(vm_t *vm);
void vm_track_object(vm_t *vm, vm_object_t *obj);  // wrapper method for type-safety

void vm_frame_push(vm_t *vm, frame_t *frame);   // wrapper method for type-safety
frame_t *vm_new_frame(vm_t *vm);
void frame_free(frame_t *frame);