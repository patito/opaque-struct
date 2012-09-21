#include <stdio.h>
#include <stdbool.h>

#include "calculator.h"

int main()
{
	int first_value;
	int second_value;
	int sum_result;
	int sub_result;
	int div_result;
	int mult_result;

	Calculator *calc = calculator_new();

	calculator_set_first_value(calc, 10);
	calculator_set_second_value(calc, 15);

	calculator_get_first_value(calc, &first_value);
	calculator_get_second_value(calc, &second_value);

	/* calc->first_value = 0; ERROR */

	printf("First Value = %d\n", first_value);
	printf("Second Value = %d\n", second_value);

	calculator_sum(calc, &sum_result);
	calculator_sub(calc, &sub_result);
	calculator_div(calc, &div_result);
	calculator_mult(calc, &mult_result);

	printf("Sum  = %d\n", sum_result);
	printf("Sub  = %d\n", sub_result);
	printf("Div  = %d\n", div_result);
	printf("Mult = %d\n", mult_result);

	calculator_unref(calc);
	

	return 0;
}
