#include<msp430.h>
/*
 * Motor.c
 *
 *  Created on: 2023年7月8日
 *      Author: 31770
 */

void Motor_Move(int motor, int direction)
{
    //IN1->P6.0 IN2->P6.1 IN3->P6.2 IN4->P6.3
    P6DIR |= BIT0 + BIT1+ BIT2 + BIT3;
    switch (motor)
    {
        case 1:                                         //左电机
            if (direction == 1)                         //前进
            {
                P6OUT |= BIT0;
                P6OUT &= ~BIT1;
            }
            else if (direction == -1)                //后退
            {
                P6OUT &= ~BIT0;
                P6OUT |= BIT1;
            }
            else                                      //停车
            {
                P6OUT &= ~BIT0;
                P6OUT &= ~BIT1;
            }
            break;
        case 2:                                      //右电机
            if (direction == 1)                      //前进
            {
                P6OUT |= BIT2;
                P6OUT &= ~BIT3;
            }
            else if (direction == -1)                //后退
            {
                P6OUT &= ~BIT2;
                P6OUT |= BIT3;
            }
            else                                     //停车
            {
                P6OUT &= ~BIT2;
                P6OUT &= ~BIT3;
            }
            break;
    }
}

void moveForward()
{
    Motor_Move(1,1);// Turn on left motor
    Motor_Move(2,1);// Turn on right motor
}

void moveBackward()
{
    Motor_Move(1,-1);// Turn on left motor
    Motor_Move(2,-1);// Turn on right motor
}

void turnLeft()
{
    Motor_Move(1,-1);// Turn off left motor
    Motor_Move(2,1);// Turn on right motor
}

void turnRight()
{
    Motor_Move(1,1);// Turn on left motor
    Motor_Move(2,-1);// Turn off right motor
}

void stop()
{
    Motor_Move(1,0);// Turn off left motor
    Motor_Move(2,0);// Turn off right motor
}
void speed(int left,int right)
{
    TA0CCR1 = 1000 - right;
    TB0CCR2 = 1000 - left;
}
