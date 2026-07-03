#include <msp430.h>

//对射式红外传感器初始化
void Infrared_Sensor_Init(void)
{
    P2DIR &= ~BIT0;          //设置P2.3口为输入
    P2REN |= BIT0;          //配置P2.3下拉电阻
    P2IN &= ~BIT0;
    P2IE |= BIT0;           //P2.3中断使能
    P2IES &= ~BIT0;          //P2.3上升沿触发中断
    P2IFG &= ~BIT0;        //清除中断标志位

}
