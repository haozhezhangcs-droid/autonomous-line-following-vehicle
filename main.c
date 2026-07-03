#include <msp430.h>
#include "Motor.h"
#include <OLED.h>
#include <TimeB0.h>

#define LEFT_SENSOR_1_BIT   BIT0   // Left sensor connected to P1.4左1边的传感器
#define RIGHT_SENSOR_1_BIT  BIT3   // Left sensor 2 connected to P1.2左2的传感器
#define RIGHT_SENSOR_2_BIT  BIT2  // Right sensor connected to P1.5右1边的传感器
#define LEFT_SENSOR_2_BIT   BIT1  /// Right sensor 2 connected to P1.3右2的传感器

void set_up()
{
    P4DIR &= ~(LEFT_SENSOR_1_BIT + RIGHT_SENSOR_1_BIT +  LEFT_SENSOR_2_BIT +  RIGHT_SENSOR_2_BIT); // Set sensor pins as input
    P4REN |= LEFT_SENSOR_1_BIT + RIGHT_SENSOR_1_BIT +  LEFT_SENSOR_2_BIT +  RIGHT_SENSOR_2_BIT; // Enable pullup resistors
    P4OUT |= LEFT_SENSOR_1_BIT + RIGHT_SENSOR_1_BIT +  LEFT_SENSOR_2_BIT +  RIGHT_SENSOR_2_BIT; // Pullup

}
void loop() {
    int left_sensor_1 = (P4IN & LEFT_SENSOR_1_BIT) == 0; // Read left sensor (1=black, 0=white)读左侧的传感器，白的话就是高电平
    int right_sensor_1= (P4IN & RIGHT_SENSOR_1_BIT) == 0; // Read right sensor (1=black, 0=white)读右侧的传感器，白的话就是高电平
    int left_sensor_2 = (P4IN & LEFT_SENSOR_2_BIT) == 0;
    int right_sensor_2 = (P4IN & RIGHT_SENSOR_2_BIT) == 0;
//这取决于传感器是检测到了黑线（0）还是白线（1）
    //uint8_t sensorState = P1IN & (LEFT_SENSOR_1_BIT | RIGHT_SENSOR_1_BIT);
     if(!(left_sensor_2) && right_sensor_2)
     {
         speed(500,800);
         turnLeft();
         __delay_cycles(200000);
     }
     else if(left_sensor_2 && !(right_sensor_2))
     {
         speed(800,500);
         turnRight();
         __delay_cycles(200000);
     }

     else if(!(left_sensor_1) && right_sensor_1)
      {
          speed(800,1000);
          turnLeft();
          __delay_cycles(400000);
      }
      else if(left_sensor_1 && !(right_sensor_1))
      {
          speed(1000,800);
          turnRight();
          __delay_cycles(40000);
      }
      else if(right_sensor_1 && right_sensor_2 && left_sensor_1 && left_sensor_2)
      {
          speed(500,500);
          moveForward();
      }
      else
      {
          stop();
      }
//    if(!(left_sensor_2) && right_sensor_2)
//    {
//        int s = 300;
//        do
//        {
//            speed(0,s);
//            turnLeft();
//            s += 5;
//            if(s >= 1000)
//            {
//                s = 1000;
//            }
//        }while(left_sensor_2 == 0);
//    }
//    else if(left_sensor_2 && !(right_sensor_2))
//    {
//        int s = 300;
//        do
//        {
//            speed(s,0);
//            turnRight();
//            s += 5;
//            if(s >= 1000)
//            {
//                s = 1000;
//            }
//        }while(right_sensor_2 == 0);
//    }
//
//    else if(!(left_sensor_1) && right_sensor_1)
//    {
//        int s = 300;
//        do
//        {
//            speed(0,s);
//            turnLeft();
//            s += 10;
//            if(s >= 1000)
//            {
//                s = 1000;
//            }
//        }while(left_sensor_1 == 0);
//    }
//    else if(left_sensor_1 && !(right_sensor_1))
//    {
//        int s = 300;
//        do
//        {
//            speed(s,0);
//            turnRight();
//            s += 10;
//            if(s >= 1000)
//            {
//                s = 1000;
//            }
//        }while(right_sensor_1 == 0);
//    }
//    else if(right_sensor_1 && right_sensor_2 && left_sensor_1 && left_sensor_2)
//    {
//      speed(1000,1000);
//      moveForward();
//    }
//    else
//    {
//      stop();
//    }
}
void main(void)
{
	WDTCTL = WDTPW | WDTHOLD;	// stop watchdog timer
	//初始化PWM和按键
	TimeB0__PWM_Init();
	TimeA1__PWM_Init();
	_EINT();
	set_up();

	while(1)
	{
        loop();
	}
}


