#include<msp430.h>
/*
 * TimeA0_PWM_Init.c
 *
 *  Created on: 2023年7月8日
 *      Author: 31770
 */

void TimeB0__PWM_Init(void)
{
    P7SEL |= BIT4; //IO口复用
    P7DIR |= BIT4;

    TB0CTL = TBSSEL__SMCLK  + MC_3; //SMCLK，增减模式,计数到CCR0处
    TB0CCR0 = 1000;   //都设置为00ffH，则初始占空比为0

    //TB0CCR2 = 800; //占空比(TACCR0 - TACCR2) / TACCR0,频率 = SMCLK / (TACCR0 + 1) / 2
    TB0CCTL2 = OUTMOD_6; //选择比较模式，模式6：Toggle/set
}
void TimeA1__PWM_Init(void)
{
    P1SEL |= BIT2; //IO口复用
    P1DIR |= BIT2;

    TA0CTL = TASSEL__SMCLK  + MC_3; //SMCLK，增减模式,计数到CCR0处
    TA0CCR0 = 1000;   //都设置为00ffH，则初始占空比为0

    //TA1CCR1 = 800; //占空比(TACCR0 - TACCR2) / TACCR0,频率 = SMCLK / (TACCR0 + 1) / 2
    TA0CCTL1 = OUTMOD_6; //选择比较模式，模式6：Toggle/set
}


