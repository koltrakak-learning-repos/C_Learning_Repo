#include <stdlib.h>
#include <stdio.h>

#include "object.h"
#include "stack.h"
#include "vm.h"

void test_obj_creation() {
  printf("----------------- test_object_creation -----------------\n");

  object_t *obj = new_integer(10);
  printf("tipo: %d\n", obj->kind);
  printf("data: %d\n", obj->data.v_int);
  free(obj);

  obj = new_float(3.14);
  printf("tipo: %d\n", obj->kind);
  printf("data: %f\n", obj->data.v_float);
  free(obj);

  obj = new_string("ciao, mi chiamo Kevin!");
  printf("tipo: %d\n", obj->kind);
  printf("data: %s\n", obj->data.v_string);
  free(obj->data.v_string);
  free(obj);

  object_t *x = new_integer(1);
  object_t *y = new_integer(2);
  object_t *z = new_integer(3);
  obj = new_vector3(x, y, z);  
  printf("tipo: %d\n", obj->kind);
  printf("data: (%d, %d, %d)\n", obj->data.v_vector3.x->data.v_int, obj->data.v_vector3.y->data.v_int, obj->data.v_vector3.z->data.v_int);
  free(x);
  free(y);
  free(z);
  free(obj);

  object_t *arr = new_array(5);
  object_t *i = new_integer(10);
  object_t *f = new_float(10.5);
  object_t *s = new_string("ciao");
  array_set(arr, 0, i);
  array_set(arr, 1, f);
  array_set(arr, 2, s);

  printf("tipo: %d\n", arr->kind);  
  printf("data: %d\n", array_get(arr, 0)->data.v_int);
  printf("data: %f\n", array_get(arr, 1)->data.v_float);
  printf("data: %s\n", array_get(arr, 2)->data.v_string);
  // non ho voglia di liberare la memoria
}

void test_obj_len() {
  printf("----------------- test_object_len -----------------\n");

  object_t *obj = new_integer(10);
  printf("tipo: %d; len: %d\n", obj->kind, obj_len(obj));
  free(obj);

  obj = new_float(3.14);
  printf("tipo: %d; len: %d\n", obj->kind, obj_len(obj));
  free(obj);

  obj = new_string("ciao, mi chiamo Kevin!");
  printf("tipo: %d; len: %d\n", obj->kind, obj_len(obj));
  free(obj->data.v_string);
  free(obj);

  object_t *x = new_integer(1);
  object_t *y = new_integer(2);
  object_t *z = new_integer(3);
  obj = new_vector3(x, y, z);  
  printf("tipo: %d; len: %d\n", obj->kind, obj_len(obj));
  free(x);
  free(y);
  free(z);
  free(obj);

  object_t *arr = new_array(5);
  printf("tipo: %d; len: %d\n", obj->kind, obj_len(obj));
  free(arr->data.v_array.elements);
  free(arr);
}

void test_obj_sum() {
  printf("----------------- test_object_sum -----------------\n");

  object_t *obj = new_integer(10);
  object_t *obj2 = new_float(3.14);
  printf("%d, %f\n", obj_sum(obj, obj)->data.v_int, obj_sum(obj, obj2)->data.v_float);
  free(obj);
  free(obj2);

  obj = new_string("ciao, mi chiamo Kevin!");
  printf("%s\n", obj_sum(obj, obj)->data.v_string);
  free(obj);

  object_t *x = new_integer(1);
  object_t *y = new_integer(2);
  object_t *z = new_integer(3);
  obj = new_vector3(x, y, z);  
  vector_t sum = obj_sum(obj, obj)->data.v_vector3;
  printf("(%d, %d, %d)\n", sum.x->data.v_int, sum.y->data.v_int, sum.z->data.v_int);
  free(x);
  free(y);
  free(z);
  free(obj);

  // dovrei anche liberare le somme ma non mi va
}