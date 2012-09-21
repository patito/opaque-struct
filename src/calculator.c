#include <stdlib.h>
#include <stdio.h>

#include "calculator.h"

struct _Calculator {
	int first_value;
	int second_value;
	int ref;
};

Calculator *calculator_new ()
{
	Calculator *obj = (Calculator *)malloc(sizeof(Calculator));

	if (NULL == obj) {
		printf("%s Out of Memory!\n", __FUNCTION__);
		return NULL;
	}

	obj->first_value = 0;
	obj->second_value = 0;
	obj->ref = 1; 	/* Reference Counting */

	return obj;
}

Calculator *calculator_with_values_new (int first_value, int second_value)
{
	/* Poderia utilizar o calculator_new(); */
	Calculator *obj = (Calculator *)malloc(sizeof(Calculator));

    if (NULL == obj) {
        printf("%s Out of Memory!\n", __FUNCTION__);
		return NULL;
    }

    obj->first_value = first_value;
    obj->second_value = second_value;
    obj->ref = 1;   /* Reference Counting */

    return obj;
}

static void calculator_destroy(Calculator *obj)
{
    if (NULL == obj) {
        printf("%s Object calculator is NULL!\n", __FUNCTION__);
		return;
    }
	
	free(obj);
	obj = NULL;
}

/* Inc. reference (+1) */
void calculator_ref(Calculator *obj)
{
	if (NULL == obj) {
        printf("%s Object calculator is NULL!\n", __FUNCTION__);
		return;
	}

    obj->ref++;
}

/* Dec. reference (-1) */
void calculator_unref(Calculator *obj)
{
	if (NULL == obj) {
        printf("%s Object calculator is NULL!\n", __FUNCTION__);
		return;
	}

	obj->ref--;
	if (0 == obj->ref) {
        calculator_destroy(obj);
    }
}

bool calculator_get_first_value(Calculator *obj, int *first_value)
{
	if (NULL == obj) {
        printf("%s Object calculator is NULL!\n", __FUNCTION__);
		return false;
	}

	if (NULL == first_value) {
        printf("%s first_value is NULL!\n", __FUNCTION__);
		return false;
	}

	*first_value = obj->first_value;
	return true;
}

bool calculator_get_second_value(Calculator *obj, int *second_value)
{
    if (NULL == obj) {
        printf("%s Object calculator is NULL!\n", __FUNCTION__);
        return false;
    }

    if (NULL == second_value) {
        printf("%s second_value is NULL!\n", __FUNCTION__);
        return false;
    }

    *second_value = obj->second_value;

    return true;
}

bool calculator_set_first_value(Calculator *obj, int first_value)
{
    if (NULL == obj) {
        printf("%s Object calculator is NULL!\n", __FUNCTION__);
        return false;
    }

    obj->first_value = first_value;

	return true;
}

bool calculator_set_second_value(Calculator *obj, int second_value)
{
    if (NULL == obj) {
        printf("%s Object calculator is NULL!\n", __FUNCTION__);
        return false;
    }

    obj->second_value = second_value;

	return true;
}

bool calculator_sum (Calculator *obj, int *sum)
{
    if (NULL == obj) {
        printf("%s Object calculator is NULL!\n", __FUNCTION__);
        return false;
    }

	*sum = obj->first_value + obj->second_value;

	return true;
}

bool calculator_sub (Calculator *obj, int *sub)
{
    if (NULL == obj) {
        printf("%s Object calculator is NULL!\n", __FUNCTION__);
        return false;
    }

    *sub = obj->first_value - obj->second_value;

    return true;
}

bool calculator_div (Calculator *obj, int *div)
{
    if (NULL == obj) {
        printf("%s Object calculator is NULL!\n", __FUNCTION__);
        return false;
    }

    *div = obj->first_value / obj->second_value;

    return true;
}

bool calculator_mult (Calculator *obj, int *mult)
{
    if (NULL == obj) {
        printf("%s Object calculator is NULL!\n", __FUNCTION__);
        return false;
    }

    *mult = obj->first_value * obj->second_value;

    return true;
}

