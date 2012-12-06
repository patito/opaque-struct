#include <stdio.h>
#include <stdlib.h>
#include <strings.h>
#include <string.h>

#include "person.h"


struct person_s {
	char name[MAX_NAME_SIZE];
	int  age;
	int ref;
};



/* constructor */
IMCCalculator*
person_new()
{
	IMCCalculator* obj = (IMCCalculator*) malloc(sizeof(IMCCalculator));

	if (NULL == obj) {
		printf("%s out of memory\n", __FUNCTION__);
		return NULL;
	}

	bzero((void*) obj, sizeof(IMCCalculator));
	obj->ref = 1;

	return obj;
}


/* destructor */
static void
person_destroy(IMCCalculator* obj)
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
person_ref(IMCCalculator *obj)
{
	if (NULL == obj) {
		printf("%s null object\n", __FUNCTION__);
		return;
	}

	obj->ref++;
}


void 
person_unref(IMCCalculator *obj)
{
	if (NULL == obj) {
		printf("%s null object\n", __FUNCTION__);
		return;
	}

	obj->ref--;

	if (0 == obj->ref) {
		person_destroy(obj);
	}
}


/* name */
bool 
person_get_weight(IMCCalculator* obj, char* value)
{
	if (NULL == obj) {
		printf("%s null object\n", __FUNCTION__);
		return false;
	}

	if (NULL == value) {
		printf("%s second value is null object\n", __FUNCTION__);
		return false;
	}

	strcpy(value, obj->name);

	return true;
}


bool 
person_set_weight(IMCCalculator* obj, char* value)
{
	if (NULL == obj) {
		printf("%s null object\n", __FUNCTION__);
		return false;
	}

	strncpy(obj->name, value, MAX_NAME_SIZE);
	obj->name[MAX_NAME_SIZE] = '\0';

	return true;
}


/* age */
bool
person_get_height(IMCCalculator* obj, int* value)
{
	if (NULL == obj) {
		printf("%s null object\n", __FUNCTION__);
		return false;
	}

	if (NULL == value) {
		printf("%s second value is null object\n", __FUNCTION__);
		return false;
	}

	*value = obj->age;

	return true;
}


bool
person_set_height(IMCCalculator* obj, int value)
{
	if (NULL == obj) {
		printf("%s null object\n", __FUNCTION__);
		return false;
	}

	obj->age = value;

	return true;
}
