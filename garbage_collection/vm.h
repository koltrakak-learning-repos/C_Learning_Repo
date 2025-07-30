#pragma once
#include "vm_object.h"
#include "stack.h"

// vm immaginaria che tiene traccia degli oggetti e degli stack frame creati
typedef struct VirtualMachine {
  stack_t *frames;   // questi frames tengono traccia di tutti gli oggetti attivi
  stack_t *objects;  // questo tiene traccia di tutti gli oggetti allocati
} vm_t;

typedef struct StackFrame {
  stack_t *references; // references to object_t
} frame_t;

vm_t *vm_new();
void vm_free(vm_t *vm);
void vm_track_object(vm_t *vm, vm_object_t *obj);  // wrapper method for type-safety

void vm_frame_push(vm_t *vm, frame_t *frame);   // wrapper method for type-safety
frame_t *vm_frame_pop(vm_t *vm);
frame_t *vm_new_frame(vm_t *vm);
void frame_free(frame_t *frame);
void frame_reference_object(frame_t *frame, vm_object_t *obj); // wrapper method for type-safety

/// Our main functions for garbage collection.
void mark(vm_t *vm);
void trace(vm_t *vm);
void sweep(vm_t *vm);
/// Helper functions for `trace`
void trace_blacken_object(stack_t *gray_objects, vm_object_t *obj);
void trace_mark_object(stack_t *gray_objects, vm_object_t *obj);

void vm_collect_garbage(vm_t *vm);