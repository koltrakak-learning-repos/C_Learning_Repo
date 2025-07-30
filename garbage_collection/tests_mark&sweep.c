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