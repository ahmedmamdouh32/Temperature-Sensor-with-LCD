
#include "HAL/LM35.h"
#include "MCAL/ADC.h"
#include "MCAL/DIO.h"
#include "HAL/LCD.h"


void Display_Temperature();


int main(void)
{
	
	
	PinMode(DIO_PD4,OUTPUT);
	PinMode(DIO_PD5,OUTPUT);
	PinMode(DIO_PD6,OUTPUT);
	PinMode(DIO_PD7,OUTPUT);
	PinMode(DIO_PB0,OUTPUT);
	PinMode(DIO_PB1,OUTPUT);
	PinMode(DIO_PC0,INPUT);
	
	LCD_init();
	ADC_init(ADC_PRESCALAR_128,AVCC);
	
	
	
	
    /* Replace with your application code */
    while (1) 
    {
		
		Display_Temperature();	
    }
}



void Display_Temperature(){
	LCD_SetCursor(0,0);
	LCD_WriteString("Temperature is :");
	LCD_SetCursor(1,6);
	LCD_WriteNumber(temp_read(ADC_CHANNEL_0));
	LCD_WriteString(" C ");
}


