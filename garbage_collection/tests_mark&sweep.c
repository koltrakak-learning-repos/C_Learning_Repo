#include <stdio.h>

#include "vm.h"
#include "vm_object.h"
#include "vm_object_creation.h"

void simple_test() {
    vm_t *vm = vm_new();
    frame_t *f1 = vm_new_frame(vm);

    vm_object_t *s = new_vm_string(vm, "I wish I knew how to read.");
    frame_reference_object(f1, s);
    
    // nothing should be collected because
    // we haven't freed the frame
    printf("gc 1\n");
    vm_collect_garbage(vm);

    frame_free(vm_frame_pop(vm)); // libero il frame e la sua reference a s
    printf("gc 2\n");
    vm_collect_garbage(vm);

    vm_free(vm);
}

void complicated_test() {
    vm_t *vm = vm_new();
    frame_t *f1 = vm_new_frame(vm);
    frame_t *f2 = vm_new_frame(vm);
    frame_t *f3 = vm_new_frame(vm);

    vm_object_t *s1 = new_vm_string(vm, "This string is going into frame 1");
    frame_reference_object(f1, s1);
    vm_object_t *s2 = new_vm_string(vm, "This string is going into frame 2");
    frame_reference_object(f2, s2);
    vm_object_t *s3 = new_vm_string(vm, "This string is going into frame 3");
    frame_reference_object(f3, s3);

    vm_object_t *i1 = new_vm_integer(vm, 69);
    vm_object_t *i2 = new_vm_integer(vm, 420);
    vm_object_t *i3 = new_vm_integer(vm, 1337);
    vm_object_t *v = new_vm_vector3(
        vm,
        i1,
        i2,
        i3
    );
    frame_reference_object(f1, i1);
    frame_reference_object(f2, v); 
    frame_reference_object(f3, v); 


    // only free the top frame (f3)
    frame_free(vm_frame_pop(vm));
    printf("gc 1\n");
    vm_collect_garbage(vm); // dovrebbe liberarsi solo s3
    
    // VM pass should free the vector, but not i1
    // because its final frame hasn't been freed
    frame_free(vm_frame_pop(vm));
    // frame_free(vm_frame_pop(vm));
    printf("gc 2\n");
    vm_collect_garbage(vm);

    vm_free(vm);
}