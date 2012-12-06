#ifndef __person_H__
#define __person_H__

#include <stdbool.h>

#ifdef __cplusplus
extern "C" {
#endif


#define IMC_LOW 		18.5
#define IMC_GOOD		25.
#define IMC_LITLE_HIGH	30.
#define IMC_OBESITY_1	35.
#define IMC_OBESITY_2	40.

#define IMC_LOW_MESSAGE 		"Abaixo do peso"
#define IMC_GOOD_MESSAGE 		"Peso normal"
#define IMC_LITLE_HIGH_MESSAGE 	"Sobrepeso"
#define IMC_OBESITY_1_MESSAGE	"Obesidade grau 1"
#define IMC_OBESITY_2_MESSAGE	"Obesidade grau 2"
#define IMC_OBESITY_3_MESSAGE	"Obesidade grau 3"


/* define IMCCalculator type */
typedef struct imc_calculator_s IMCCalculator;


/* define constructor */
IMCCalculator* imc_calculator_new();

/* reference counting */
void imc_calculator_ref(IMCCalculator *obj);
void imc_calculator_unref(IMCCalculator *obj);

/* weight */
bool imc_calculator_get_weight(IMCCalculator* obj, double* value);
bool imc_calculator_set_weight(IMCCalculator* obj, double value);

/* height */
bool imc_calculator_get_height(IMCCalculator* obj, double* value);
bool imc_calculator_set_height(IMCCalculator* obj, double value);

double imc_calculator_calculate_imc(IMCCalculator* obj);

char* imc_calculator_get_text_result(IMCCalculator* obj);


#ifdef __cplusplus
}
#endif

#endif /* __person_H__ */
