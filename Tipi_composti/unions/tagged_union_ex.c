#include <stdio.h>

typedef enum SnekObjectKind {
    INTEGER,
    STRING,
} snek_object_kind_t;


typedef union SnekObjectData {
  int v_int;
  char *v_string;
} snek_object_data_t;

// tagged union:
// unisce insieme una struct con un enumerativo per il tipo
typedef struct SnekObject {
  snek_object_kind_t kind;
  snek_object_data_t data;
} snek_object_t;



snek_object_t new_integer(int i) {
  return (snek_object_t){
    .kind = INTEGER,
    .data = {.v_int = i}
  };
}

snek_object_t new_string(char *str) {
  return (snek_object_t){
    .kind = STRING,
    .data = {.v_string = str}
  };
}


void format_object(snek_object_t obj, char *buffer) {
    switch (obj.kind) {
        case INTEGER:
            sprintf(buffer, "int:%d\n", obj.data.v_int);
            break;
            
        case STRING:
            sprintf(buffer, "string:%s\n", obj.data.v_string);
            break;
        
        default:
            printf("Unknown type\n");
            break;
    }
}

int main() {
    char buffer[100];
    snek_object_t i = new_integer(5);
    format_object(i, buffer);
    printf("%s\n", buffer);
    
    snek_object_t s = new_string("Hello!");
    format_object(s, (buffer+10));
    printf("%s\n", buffer+10);
  
    return 0;
}