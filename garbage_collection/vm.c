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

frame_t *vm_frame_pop(vm_t *vm) {
    return stack_pop(vm->frames);
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

void frame_reference_object(frame_t *frame, vm_object_t *obj) {
    stack_push(frame->references, obj);
}

/* main functions for garbage collection. */

// marks every object that's DIRECTLY referenced by a stack frame
void mark(vm_t *vm) {
    for(int i=0; i<vm->frames->count; i++) {
        frame_t *cur_frame = (frame_t *)vm->frames->data[i];
        for(int j=0; j<cur_frame->references->count; j++) {
            vm_object_t *cur_obj = (vm_object_t *)cur_frame->references->data[j];
            cur_obj->is_marked = true;
        }
    }
}

// marchio un oggetto e lo pusho in uno stack per esplorare il grafo 
void trace_mark_object(stack_t *gray_objects, vm_object_t *obj) {
    if (obj == NULL || obj->is_marked) {
        return;
    }

    obj->is_marked = true;
    stack_push(gray_objects, obj);
}

// black objects -> nodo esplorato
// gray objects  -> nodo da esplorare
// container objects sicuramente hanno qualcosa da esplorare
void trace_blacken_object(stack_t *gray_objects, vm_object_t *obj) {
    // Mentalmente, segno l'oggetto corrente come
    // black object indipendentemente dal tipo

    switch (obj->kind) {
        case INTEGER:
        case FLOAT:
        case STRING:
            // faccio nulla in quanto non sono container objects.
            break;
        
        case VECTOR3:
            // segno gli oggetti figli come gray object
            trace_mark_object(gray_objects, obj->data.v_vector3.x);
            trace_mark_object(gray_objects, obj->data.v_vector3.y);
            trace_mark_object(gray_objects, obj->data.v_vector3.z);
            break;

        case ARRAY:
            // segno gli oggetti figli come gray object
            for (int i=0; i<obj->data.v_array.size; i++) {
                trace_mark_object(gray_objects, obj->data.v_array.elements[i]);
            }
            break;

        default:
            // panico
    }
}

void trace(vm_t *vm) {
    stack_t *gray_objects = stack_new(8);
    if (gray_objects == NULL) {
        return;
    }

    // aggiungo allo stack d'esplorazione i root objects marchiati  
    for (int i=0; i<vm->objects->count; i++) {
        vm_object_t *cur_obj = (vm_object_t *)vm->objects->data[i]; 
        if (cur_obj->is_marked) {
            stack_push(gray_objects, cur_obj);
        } 
    }

    // esploro il grafo degli oggetti
    // - se l'oggetto poppato non è un container object, non ha riferimenti ad altri 
    //   oggetti da esplorare ed è quindi una foglia del grafo
    // - altrimenti, gli oggetti figli diventano altri gray object da esplorare
    while(gray_objects->count != 0) {
        vm_object_t *o = (vm_object_t *)stack_pop(gray_objects);
        trace_blacken_object(gray_objects, o);
    }

    stack_free(gray_objects);
}

void sweep(vm_t *vm) {
    // itero su tutti gli oggetti e libero quelli non marchiati
    for (int i=0; i<vm->objects->count; i++) {
        vm_object_t *cur_obj = (vm_object_t *)vm->objects->data[i]; 
        if (cur_obj->is_marked) {
            cur_obj->is_marked = false; // mi devo ricordare di resettare altrimenti rimane anche al prossimo ciclo di gc
        } 
        else {
            vm_object_free(cur_obj);
            vm->objects->data[i] == NULL; // tolgo anche il dangling pointer dallo stack
        }
    }

    stack_remove_nulls(vm->objects); // ricompatto lo stack
}

void vm_collect_garbage(vm_t *vm) {
    mark(vm);
    trace(vm);
    sweep(vm);
}