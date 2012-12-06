#include <stdio.h>

#include "imc_calculator.h"


int
main()
{
	double weight = 0.;
	double height = 0.;
	double imc = 0.;
	char* textResult = "";

	IMCCalculator* imcCalc = imc_calculator_new();

	imc_calculator_set_height(imcCalc, 1.87);
	imc_calculator_set_weight(imcCalc, 93.);

	imc_calculator_get_height(imcCalc, &height);
	imc_calculator_get_weight(imcCalc, &weight);

	imc = imc_calculator_calculate_imc(imcCalc);

	textResult = imc_calculator_get_text_result(imcCalc);

	printf("Altura: %.2f m\n", height);
	printf("Peso  : %.2f kg\n", weight);
	printf("IMC   : %.2f\n", imc);
	printf("%s\n", textResult);

	imc_calculator_unref(imcCalc);

	return 0;
}
