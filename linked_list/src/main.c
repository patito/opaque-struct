#include <stdio.h>

#include "list.h"


int
main()
{
	int i = 0;
	int element = 0;

	List* list = list_new();

	list_add_element(list, 5);
	list_add_element(list, 4);
	list_add_element(list, 3);
	list_add_element(list, 2);
	list_add_element(list, 1);
	list_add_element(list, 0);

	printf("size = %d\n", list_get_size(list));
	
	for (i = 0; i < list_get_size(list); i++) {
		list_get_element(list, i, &element);
		printf("Element %d = %d\n", i, element);
	}

	printf("empty list = %d\n", list_is_empty(list));
	
	list_unref(list);

	printf("empty list = %d\n", list_is_empty(list));
	
	return 0;
}
