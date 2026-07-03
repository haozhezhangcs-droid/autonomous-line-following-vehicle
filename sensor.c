#include <msp430.h>
#include <sensor.h>

#define LEFT_SENSOR_1_BIT   BIT0   // Left sensor connected to P1.4左1边的传感器
#define RIGHT_SENSOR_1_BIT  BIT3   // Left sensor 2 connected to P1.2左2的传感器
#define RIGHT_SENSOR_2_BIT  BIT2  // Right sensor connected to P1.5右1边的传感器
#define LEFT_SENSOR_2_BIT   BIT1  /// Right sensor 2 connected to P1.3右2的传感器

void sensor_Init()
{
    P4DIR &= ~(LEFT_SENSOR_1_BIT + RIGHT_SENSOR_1_BIT +  LEFT_SENSOR_2_BIT +  RIGHT_SENSOR_2_BIT); // Set sensor pins as input
    P4REN |= LEFT_SENSOR_1_BIT + RIGHT_SENSOR_1_BIT +  LEFT_SENSOR_2_BIT +  RIGHT_SENSOR_2_BIT; // Enable pullup resistors
    P4OUT |= LEFT_SENSOR_1_BIT + RIGHT_SENSOR_1_BIT +  LEFT_SENSOR_2_BIT +  RIGHT_SENSOR_2_BIT; // Pullup

}
// 获取传感器状态
int getSensorState()
{
    int state = 0;

    if ((P4IN & LEFT_SENSOR_1_BIT) == 0)
    {
        state = -2;    // 左外传感器检测到黑线
    }
    if ((P4IN & LEFT_SENSOR_2_BIT) == 0)
    {
        state = -1;    // 左内传感器检测到黑线
    }
    if ((P4IN & RIGHT_SENSOR_1_BIT) == 0)
    {
        state = 2;    // 右外传感器检测到黑线
    }
    if ((P4IN & RIGHT_SENSOR_2_BIT) == 0)
    {
        state = 1;    // 右内传感器检测到黑线
    }
    return state;
}


