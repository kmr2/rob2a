#pragma config(UART_Usage, UART2, uartVEXLCD, baudRate19200, IOPins, None, None)
#pragma config(Motor,	 port2,						rightMotor,		 tmotorNormal, openLoop, reversed)
#pragma config(Motor,	 port3,						leftMotor,		 tmotorNormal, openLoop)

#include "../../includes/headers/myheader.h"
#include "../../includes/tasks/menutask.c"

task main()
{
	StartTask(menu);
}
