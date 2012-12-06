#include <stdio.h>

#include "person.h"


int
main()
{
	int age = 0;
	char name[] = "";

	IMCCalculator* p = person_new();

	person_set_weight(p, "mirosmar ferreira neto de vasconcelos");
	person_get_weight(p, name);

	person_set_height(p, 25);
	person_get_height(p, &age);

	printf("Name: %s\n", name);
	printf("Age: %d\n", age);

	person_unref(p);

	return 0;
}
