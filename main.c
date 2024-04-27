#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <avr/io.h>
#include <avr/interrupt.h>
#include <util/delay.h>
#include <math.h>
#include "adc.h"
#include "lcd.h"
#include "relay.h"

uint8 CalbCond = TRUE;

float32 CalbValue = 1.97;
float32 FACTOR = 1;

float32 get_current()
{
	uint16 adc_value=0;
	float32 RMS_value=0;
	float32 voltage=0;
	float32 MeanSquareSum=0;
	float32 current=0;
	uint16 i=0;
	uint16 counter=0;
	for (i=0;i<1000;i++)
	{
		adc_value = ADC_readChannel(7);
		voltage = (adc_value/1024.0)*5.0;

		current = (((float)adc_value / 1024.0) * 5.0 )/0.033;
		MeanSquareSum=MeanSquareSum+current*current;
		counter=counter+1;
	}

	RMS_value = sqrt(MeanSquareSum/counter);

	if((CalbCond== TRUE) && (RMS_value>0))
	{
		CalbCond=FALSE;
	   FACTOR = CalbValue/RMS_value;

	}
	return (RMS_value*FACTOR);

}

int main(void) {


	LCD_init();

	ADC_configType config = {AVCC,F_CPU_CLOCK_128};

	ADC_init(&config);
	
	relay_init();
    relay_ON();


	float32 current=0;


	while(1)
	{

		 LCD_displayStringRowColumn(0,0,"Current= ");

		current=get_current();

		LCD_DispFloat(current);

		LCD_displayCharacter('A');

		 LCD_displayStringRowColumn(1,0,"Factor ");

			LCD_DispFloat(FACTOR);


		_delay_ms(500);

		LCD_clearScreen();
		
		/* turn off circuit if current bigger than 5 amperes */
		if(current>2.2)
		{
			relay_OFF();
			_delay_ms(5000);
		}
		else
		{
			relay_ON();
		}
	}

	return 0;
}
