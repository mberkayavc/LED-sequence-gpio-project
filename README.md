# LED-sequence-gpio-project
 Sequential LED lighting project

"gpioConfig" function: This function is used to configure the GPIO pins
In this example, pins 0, 1, and 2 of the GPIOB port are utilized.
These pins are configured in output mode (GPIO_Mode_Out_PP) and at a speed of 50 MHz (GPIO_Speed_50MHz)

void gpioConfig(){
    GPIO_InitTypeDef GPIOInitStructure;
    
    RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOB, ENABLE);
    
    GPIOInitStructure.GPIO_Mode = GPIO_Mode_Out_PP;
    GPIOInitStructure.GPIO_Pin = GPIO_Pin_0 | GPIO_Pin_1 | GPIO_Pin_2;
    GPIOInitStructure.GPIO_Speed = GPIO_Speed_50MHz;
    
    GPIO_Init(GPIOB, &GPIOInitStructure);
}

"delay" function: This function creates a delay by waiting in a loop for a specific duration
It is used to ensure that the LEDs remain on or off for a certain period

In this way, the three LEDs on the microcontroller are controlled to blink sequentially