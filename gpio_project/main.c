#include "stm32f10x.h"                  // Device header


uint16_t buttonState=0;

uint16_t counter=0;

void delay(uint32_t time){
while(time--);
}

void gpioConfig(){
	
	GPIO_InitTypeDef GPIOInitStructure; // Bir adet obje olusturduk
	
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOB,ENABLE); //Clock aktiflestirdik for LED
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOC,ENABLE); // for BUTTON
	
	//LED
	GPIOInitStructure.GPIO_Mode=GPIO_Mode_Out_PP; //GPIO 'yu çikis olarak belirledik
	GPIOInitStructure.GPIO_Pin=GPIO_Pin_0; //Sifirinci pin olarak belirledik
	GPIOInitStructure.GPIO_Speed=GPIO_Speed_50MHz; // Hizi belirledik
	
	GPIO_Init(GPIOB,&GPIOInitStructure); //Structure i pointer kullanarak tanitmis olduk
	
	
	//BUTTON
	GPIOInitStructure.GPIO_Mode=GPIO_Mode_IPD;
	GPIOInitStructure.GPIO_Pin=GPIO_Pin_6;
	
	GPIO_Init(GPIOC,&GPIOInitStructure); //Structure i pointer kullanarak tanitmis olduk
	

}



int main(){
	
	gpioConfig();
	
	
	while(1){
		
		buttonState=GPIO_ReadInputDataBit(GPIOC,GPIO_Pin_6);
		if(buttonState==1){
		counter++;
			delay(360000);
		}
		
		
		
	}
	
	
	
	
}