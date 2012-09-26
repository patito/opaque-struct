#ifndef __LIST_H__
#define __LIST_H__

#include <stdbool.h>

#include "node.h"

#ifdef __cplusplus
extern "C" {
#endif


/* define list type */
typedef struct list_s List;


/* constructor */
List* list_new();


/* reference counting */
void list_ref(List* obj);
void list_unref(List* obj);


/* metodos */

bool list_add_element(List* obj, int value);

Node* list_remove_first_element(List* list);

Node* list_remove_element(List* obj, int position);

bool list_get_element(List* obj, int position, int* element);

int list_get_size(List* obj);

bool list_is_empty(List* obj);



#ifdef __cplusplus
}
#endif

#endif
