
#ifndef ADC_H_
#define ADC_H_

#include "std_types.h"
#include "common_macros.h"


#define ADC_MAX_BITS 1023
#define INTERNAL_VOLTAGE 2.56

/*
 The ADC reference voltage has 3 options in the Atmega32:
 AREF, AVCC and Internal VREF its value 2.56 voltage
 */

typedef enum{
	AREF,AVCC,INTERNAL=3
}ADC_ReferenceVolatge;


/*
 The ADC Prescaler should adjust the ADC Frequency as it must be 50KHz---->200KHz
 and it has 8 options, the First two options give the same prescaler -->FCPU/2 the same as in the data sheet
 */
typedef enum{
F_CPU_CLOCK_2,F_CPU_CLOCK_2_2,F_CPU_CLOCK_4,F_CPU_CLOCK_8,F_CPU_CLOCK_16,
F_CPU_CLOCK_32,F_CPU_CLOCK_64,F_CPU_CLOCK_128
}ADC_Prescaler;


/*
 The structure ADC_configType is used for dynamic configuration of the ADC to send it to the Init function
  */

typedef struct{
	ADC_ReferenceVolatge ref_voltage;
	ADC_Prescaler prescaler;
}ADC_configType;


void ADC_init(const ADC_configType *adc_config);

uint16 ADC_readChannel(uint8 channel_num);



#endif /* ADC_H_ */
