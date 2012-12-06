#ifndef __person_H__
#define __person_H__

#include <stdbool.h>

#ifdef __cplusplus
extern "C" {
#endif

#define MAX_NAME_SIZE 30


/* define person type */
typedef struct person_s IMCCalculator;


/* define constructor */
IMCCalculator* person_new();

/* reference counting */
void person_ref(IMCCalculator *obj);
void person_unref(IMCCalculator *obj);


/* value */
bool person_get_weight(IMCCalculator* obj, char* value);
bool person_set_weight(IMCCalculator* obj, char* value);


/* next */
bool person_get_height(IMCCalculator* obj, int* value);
bool person_set_height(IMCCalculator* obj, int value);


#ifdef __cplusplus
}
#endif

#endif /* __person_H__ */
