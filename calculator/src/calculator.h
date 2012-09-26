#ifndef __CALCULATOR_H__
#define __CALCULATOR_H__

#include <stdbool.h>

#ifdef __cplusplus
extern "C" {
#endif

typedef struct _Calculator Calculator;

/* Constructor */

Calculator *calculator_new ();

Calculator *calculator_with_values_new (int first_value, int second_value);

/* Reference Counting */

void calculator_ref(Calculator *obj);

void calculator_unref(Calculator *obj);

/* Getters */

bool calculator_get_first_value(Calculator *obj, int *first_value);

bool calculator_get_second_value(Calculator *obj, int *second_value);

/* Setters */

bool calculator_set_first_value(Calculator *obj, int first_value);

bool calculator_set_second_value(Calculator *obj, int second_value);

/* Methods */

bool calculator_sum(Calculator *obj, int *sum_result);

bool calculator_div(Calculator *obj, int *div_result);

bool calculator_sub(Calculator *obj, int *sub_result);

bool calculator_mult(Calculator *obj, int *mult_result);

#ifdef __cplusplus
}
#endif

#endif /*__CALCULATOR_H__ */

