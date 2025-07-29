#include "vm.h"
#include "stack.h"
#include "vm_object.h"

vm_t *vm_new() {
    vm_t *new_vm = (vm_t *)malloc(sizeof(vm_t));
    if (new_vm == NULL) {
        return NULL;
    }

    new_vm->frames  = stack_new(8);
    new_vm->objects = stack_new(8);
    return new_vm;
}

void vm_free(vm_t *vm) {
    for (int i = 0; i < vm->frames->count; i++) {
        frame_free(vm->frames->data[i]);
    }
    stack_free(vm->frames);
    for (int i = 0; i < vm->objects->count; i++) {
        vm_object_free(vm->objects->data[i]);
    }
    stack_free(vm->objects);

    free(vm);
}

void vm_track_object(vm_t *vm, vm_object_t *obj) {
    stack_push(vm->objects, obj);
}


void vm_frame_push(vm_t *vm, frame_t *frame) {
    stack_push(vm->frames, frame);
}

frame_t *vm_new_frame(vm_t *vm) {
    frame_t *new_frame = malloc(sizeof(frame_t));
    if (new_frame == NULL) {
        return NULL;
    }

    new_frame->references = stack_new(8);
    stack_push(vm->frames, new_frame);
    
    return new_frame;
}

void frame_free(frame_t *frame) {
    stack_free(frame->references);
    free(frame);
}