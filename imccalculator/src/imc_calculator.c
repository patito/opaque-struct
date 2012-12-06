#include <stdio.h>
#include <stdlib.h>
#include <strings.h> 	//bzero

#include "imc_calculator.h"


struct imc_calculator_s {
	double weight;  //peso
	double height;  //altura
	int ref;
};


//used function
static char* imc_calculator_get_table_text_result(double imc);


/* constructor */
IMCCalculator*
imc_calculator_new()
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
imc_calculator_destroy(IMCCalculator* obj)
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
imc_calculator_ref(IMCCalculator *obj)
{
	if (NULL == obj) {
		printf("%s null object\n", __FUNCTION__);
		return;
	}

	obj->ref++;
}


void 
imc_calculator_unref(IMCCalculator *obj)
{
	if (NULL == obj) {
		printf("%s null object\n", __FUNCTION__);
		return;
	}

	obj->ref--;

	if (0 == obj->ref) {
		imc_calculator_destroy(obj);
	}
}


/* name */
bool 
imc_calculator_get_weight(IMCCalculator* obj, double* value)
{
	if (NULL == obj) {
		printf("%s null object\n", __FUNCTION__);
		return false;
	}

	if (NULL == value) {
		printf("%s second value is null object\n", __FUNCTION__);
		return false;
	}

	*value = obj->weight;

	return true;
}


bool 
imc_calculator_set_weight(IMCCalculator* obj, double value)
{
	if (NULL == obj) {
		printf("%s null object\n", __FUNCTION__);
		return false;
	}

	obj->weight = value;

	return true;
}


/* age */
bool
imc_calculator_get_height(IMCCalculator* obj, double* value)
{
	if (NULL == obj) {
		printf("%s null object\n", __FUNCTION__);
		return false;
	}

	if (NULL == value) {
		printf("%s second value is null object\n", __FUNCTION__);
		return false;
	}

	*value = obj->height;

	return true;
}


bool
imc_calculator_set_height(IMCCalculator* obj, double value)
{
	if (NULL == obj) {
		printf("%s null object\n", __FUNCTION__);
		return false;
	}

	obj->height = value;

	return true;
}


double
imc_calculator_calculate_imc(IMCCalculator* obj)
{
	if (NULL == obj) {
		printf("%s null object\n", __FUNCTION__);
		return -1.;
	}

	return obj->weight / (obj->height * obj->height);
}


char*
imc_calculator_get_text_result(IMCCalculator* obj)
{
	double imc = 0.;

	if (NULL == obj) {
		printf("%s null object\n", __FUNCTION__);
		return "ERROR NULL OBJECT";
	}

	imc = imc_calculator_calculate_imc(obj);

	return imc_calculator_get_table_text_result(imc);
}


static char*
imc_calculator_get_table_text_result(double imc)
{
	if (imc < IMC_LOW) {
		return IMC_LOW_MESSAGE;
	}
	else if (imc < IMC_GOOD) {
		return IMC_GOOD_MESSAGE;
	}
	else if (imc < IMC_LITLE_HIGH) {
		return IMC_LITLE_HIGH_MESSAGE;
	}
	else if (imc < IMC_OBESITY_1) {
		return IMC_OBESITY_1_MESSAGE;
	}
	else if (imc < IMC_OBESITY_2) {
		return IMC_OBESITY_2_MESSAGE;
	}
	else {
		return IMC_OBESITY_3_MESSAGE;
	}
}
