#include "vm_object.h"

void vm_object_free(vm_object_t *obj) {
    switch (obj->kind) {
        case INTEGER:
        case FLOAT:
            break;
        case STRING:
            free(obj->data.v_string);
            break;
        case VECTOR3: {
			// mark and sweep will handle the contained objects
            break;
        }
        case ARRAY: {
			// mark and sweep will handle the container objects
			free(obj->data.v_array.elements);
            break;
        }
    }

    free(obj);
}
