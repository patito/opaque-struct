#include <stdio.h>
#include <stdlib.h>

#include "node.h"
#include "list.h"


struct list_s 
{
	Node* head;
	int size;
	int ref;
};



/* constructor */
List* 
list_new()
{
	List* obj = (List*) malloc(sizeof(List));

	if (NULL == obj) {
		printf("%s out of memory\n", __FUNCTION__);
		return NULL;
	}

	obj->head = NULL;
	obj->size = 0;
	obj->ref = 1;

	return obj;
}


/* destructor */
static bool 
list_destroy(List* obj)
{
	Node* node = NULL;
	int i = 0;

	if (NULL == obj) {
		printf("%s object is null\n", __FUNCTION__);
		return false;
	}

	for (i = list_get_size(obj); i > 0; i--) {
		node = list_remove_element(obj, 0);

		if (NULL != node) {
			node_unref(node);
		}
	}

	free(obj);
	obj = NULL;

	return true;
}


/* reference counting */
void 
list_ref(List* obj)
{
	if (NULL == obj) {
		printf("%s object is null\n", __FUNCTION__);
		return;
	}

	obj->ref++;
}


void
list_unref(List* obj)
{
	if (NULL == obj) {
		printf("%s object is null\n", __FUNCTION__);
		return;
	}

	obj->ref--;

	if (0 == obj->ref) {
		list_destroy(obj);
	}
}


/* metodos */

bool 
list_add_element(List* obj, int value)
{
	Node* node = NULL;
	
	if (NULL == obj) {
		printf("%s object is null\n", __FUNCTION__);
		return false;
	}

	node = node_new();
	node_set_value(node, value);

	if (0 == obj->size) {
		obj->head = node;
	}
	else {
		node_set_next(node, obj->head);
		obj->head = node;
	}

	obj->size++;

	return true;
}


Node* 
list_remove_first_element(List* obj)
{
	Node* node = NULL;

	if (NULL == obj) {
		printf("%s: null object\n", __FUNCTION__);
		return NULL;
	}

	node = obj->head;

	obj->head = node_get_next(node);

	node_set_next(node, NULL);

	return node;
}


Node*
list_remove_element(List* obj, int position)
{
    Node* node = NULL;
	Node* prev_node = NULL;
    int i = 0;

    if (NULL == obj) {
        printf("%s object is null\n", __FUNCTION__);
        return NULL;
    }

	if (position > obj->size) {
		printf("%s index out of bound %d\n", __FUNCTION__, position);
		return NULL;
	}

	if (0 == position) {
		node = list_remove_first_element(obj);
	}
	else {
		node = obj->head;
    
		for (i = 0; i < position; i++) {
			prev_node = node;
			node = node_get_next(node);		
		}

		node_set_next(prev_node, node_get_next(node));
		node_set_next(node, NULL);
	}

	obj->size--;

	return node;
}


bool 
list_get_element(List* obj, int position, int* element)
{
	Node* node = NULL;
	int i = 0;

	if (NULL == obj) {
		printf("%s object is null\n", __FUNCTION__);
		return false;
	}

	if (position > obj->size) {
		printf("%s out of bound %d\n", __FUNCTION__, position);
		return false;
	}

	if (NULL == element) {
		printf("%s element is null\n", __FUNCTION__);
		return false;
	}

	node = obj->head;

	for (i = 0; i < position; i++) {
		node = node_get_next(node);
	}

	node_get_value(node, element);

	return true;
}


int 
list_get_size(List* obj)
{
	return obj->size;
}


bool 
list_is_empty(List* obj)
{
	return obj->size == 0 ? true : false;
}


