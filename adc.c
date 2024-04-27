#include "adc.h"
#include <avr/io.h>

/*
 Description
 The Init function takes the structure of ADC_configType type which contains the configurations of the ADC of reference voltage and prescaler
 It takes the structure by Address
 */

void ADC_init(const ADC_configType *adc_config)
{
ADMUX=((adc_config->ref_voltage)<<6);

ADCSRA= (ADCSRA & 0x78) | (1<<ADEN) | (adc_config->prescaler);

}


/*
 Descritpion
 The ADC_readChannel function takes the channel number and convert the analog value to digital,
 it's using the Polling technique.
  */
uint16 ADC_readChannel(uint8 channel_num)
{
	ADMUX= (ADMUX & 0xE0) | (channel_num & 0x1F);
	SET_BIT(ADCSRA,ADSC); //start conversion
	while(BIT_IS_CLEAR(ADCSRA,ADIF)); //Wait till the flag of the ADC be set
	SET_BIT(ADCSRA,ADIF); //Clear the ADC Flag
	return ADC;

}
