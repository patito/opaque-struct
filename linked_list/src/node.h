#ifndef __NODE_H__
#define __NODE_H__

#include <stdbool.h>

#ifdef __cplusplus
extern "C" {
#endif


/* define node type */
typedef struct node_s Node;


/* define constructor */
Node* node_new();


/* reference counting */
void node_ref(Node *obj);
void node_unref(Node *obj);


/* value */
bool node_get_value(Node* obj, int* value);
bool node_set_value(Node* obj, int value);


/* next */
Node* node_get_next(Node* obj);
bool node_set_next(Node* obj, Node* next);


#ifdef __cplusplus
}
#endif

#endif /* __NODE_H__ */
