/********************************** (C) COPYRIGHT *******************************
 * File Name          : main.c
 * Author             : WCH
 * Version            : V1.0.0
 * Date               : 2022/08/08
 * Description        : Main program body.
*********************************************************************************
* Copyright (c) 2021 Nanjing Qinheng Microelectronics Co., Ltd.
* Attention: This software (modified or not) and binary are used for 
* microcontroller manufactured by Nanjing Qinheng Microelectronics.
*******************************************************************************/

/*
 *@Note
USART Print debugging routine:
 USART1_Tx(PD5).
 This example demonstrates the use of USART1(PD5) as a print debug port output.

*/
#include <stdbool.h>
#include "debug.h"

/* Global typedef */

/* Global define */

/* Global Variable */

void gpio_toggle_init(void){
    GPIO_InitTypeDef gpio={0};

    RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOC, ENABLE);
    gpio.GPIO_Pin = GPIO_Pin_1;
    gpio.GPIO_Mode = GPIO_Mode_Out_PP;
    gpio.GPIO_Speed = GPIO_Speed_50MHz;
    GPIO_Init(GPIOC, &gpio);
    gpio.GPIO_Pin = GPIO_Pin_2;
    gpio.GPIO_Mode = GPIO_Mode_Out_PP;
    gpio.GPIO_Speed = GPIO_Speed_50MHz;
    GPIO_Init(GPIOC, &gpio);
}


/*********************************************************************
 * @fn      main
 *
 * @brief   Main program.
 *
 * @return  none
 */
int main(void)
{
    NVIC_PriorityGroupConfig(NVIC_PriorityGroup_2);
    Delay_Init();
    USART_Printf_Init(115200);
    printf("SystemClk:%ld\r\n", SystemCoreClock);

    printf("This is printf example\r\n");
    gpio_toggle_init();

    bool level = 0;
    while(1)
    {
        Delay_Ms(1000);
        GPIO_WriteBit(GPIOC, GPIO_Pin_1, level ? Bit_SET : Bit_RESET);
        Delay_Ms(50);
        GPIO_WriteBit(GPIOC, GPIO_Pin_2, level ? Bit_RESET : Bit_SET);
        printf("level: %d\r\n", level);
        level = !level;
    }
}
