#include <stdio.h>
#include <stdlib.h>

#include "node.h"


struct node_s {
	int value;
	struct node_s* next;
	int ref;
};



/* constructor */
Node* 
node_new()
{
	Node* obj = (Node*) malloc(sizeof(Node));

	if (NULL == obj) {
		printf("%s out of memory\n", __FUNCTION__);
		return NULL;
	}

	obj->value = 0;
	obj->next = NULL;
	obj->ref = 1;

	return obj;
}


/* destructor */
static void
node_destroy(Node* obj)
{
	if (NULL == obj) {
		printf("%s null object\n", __FUNCTION__);
		return;
	}

	free(obj);
	obj = NULL;
}


/* reference counting */
void 
node_ref(Node *obj)
{
	if (NULL == obj) {
		printf("%s null object\n", __FUNCTION__);
		return;
	}

	obj->ref++;
}


void 
node_unref(Node *obj)
{
	if (NULL == obj) {
		printf("%s null object\n", __FUNCTION__);
		return;
	}

	obj->ref--;

	if (0 == obj->ref) {
		node_destroy(obj);
	}
}


/* value */
bool 
node_get_value(Node* obj, int* value)
{
	if (NULL == obj) {
		printf("%s null object\n", __FUNCTION__);
		return false;
	}

	if (NULL == value) {
		printf("%s second value is null object\n", __FUNCTION__);
		return false;
	}

	*value = obj->value;
	
	return true;
}


bool 
node_set_value(Node* obj, int value)
{
	if (NULL == obj) {
		printf("%s null object\n", __FUNCTION__);
		return false;
	}

	obj->value = value;

	return true;
}


/* next */
Node* 
node_get_next(Node* obj)
{
	if (NULL == obj) {
		printf("%s null object\n", __FUNCTION__);
		return false;
	}

	return obj->next;
}


bool 
node_set_next(Node* obj, Node* next)
{
	if (NULL == obj) {
		printf("%s null object\n", __FUNCTION__);
		return false;
	}

	obj->next = next;

	return true;
}

