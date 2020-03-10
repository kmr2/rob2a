#pragma config(UART_Usage, UART1, uartVEXLCD, baudRate19200, IOPins, None, None)
#pragma config(Sensor, in1,    lightSensor,    sensorReflection)
#pragma config(Sensor, in2,    LineFollower1,  sensorLineFollower)
#pragma config(Sensor, in3,    LineFollower2,  sensorLineFollower)
#pragma config(Sensor, in4,    Linefollower3,  sensorLineFollower)
#pragma config(Sensor, in5,    Potentiometer,  sensorPotentiometer)
#pragma config(Sensor, in6,    Gyro,           sensorGyro)
#pragma config(Sensor, dgtl1,  encoderR,       sensorQuadEncoder)
#pragma config(Sensor, dgtl3,  encoderL,       sensorQuadEncoder)
#pragma config(Sensor, dgtl5,  Sonar,          sensorSONAR_cm)
#pragma config(Sensor, dgtl7,  limmitSW,       sensorTouch)
#pragma config(Sensor, dgtl8,  button,         sensorTouch)
#pragma config(Motor,  port2,           motorR,        tmotorVex269, openLoop)
#pragma config(Motor,  port3,           motorL,        tmotorVex269, openLoop, reversed)
#pragma config(Motor,  port4,           arm,           tmotorVex269, openLoop)
#pragma config(Motor,  port5,           speedC,        tmotorVex269, openLoop)
//*!!Code automatically generated by 'ROBOTC' configuration wizard               !!*//

/*----------------------------------------------------------------------------------------------------*\
|*																 - Moving Straight with Encoders -																	*|
|*																			ROBOTC on VEX 2.0 CORTEX																			*|
|*																																																		*|
|*	This program implements a self-straightening algorithm that provides a higher power level to the	*|
|*	motor that has traveled less, determined by comparing the values of the two encoders.							*|
|*	There is a 2 second pause at the beginning of the program.																				*|
|*																																																		*|
|*																				ROBOT CONFIGURATION																					*|
|*		NOTES:																																													*|
|*		1)	Reversing 'rightMotor' (port 2) in the "Motors and Sensors Setup" is needed with the				*|
|*				"Squarebot" model, but may not be needed for all robot configurations.											*|
|*		2)	Whichever encoder is being used for feedback should be cleared just before it starts				*|
|*				counting by using the "SensorValue(encoder) = 0;".	This helps ensure consistancy.					*|
|*																																																		*|
|*		MOTORS & SENSORS:																																								*|
|*		[I/O Port]					[Name]							[Type]								[Description]											*|
|*		Motor		- Port 2		rightMotor					VEX 3-wire module			Right side motor									*|
|*		Motor		- Port 3		leftMotor						VEX 3-wire module			Left side motor										*|
|*		Digital - Port 1,2	rightEncoder				VEX Shaft Encoder			Right side												*|
|*		Digital - Port 3,4	leftEncoder					VEX Shaft Encoder			Left side													*|
\*----------------------------------------------------------------------------------------------------*/

// light 100
// dark  400

//+++++++++++++++++++++++++++++++++++++++++++++| MAIN |+++++++++++++++++++++++++++++++++++++++++++++++

#define BASEDIST 450

const float base_turn= 3.3;

int power = 80;

task display(){
	bLCDBacklight = true;
	string mainBattery, backupBattery;

	while(true)
	{
		clearLCDLine(0);
		clearLCDLine(1);

		//Display the Primary Robot battery voltage
		displayLCDString(0, 0, "Primary: ");
		sprintf(mainBattery, "%1.2f%c", nImmediateBatteryLevel/1000.0,'V'); //Build the value to be displayed
		displayNextLCDString(mainBattery);

		//Display the Backup battery voltage
		displayLCDString(1, 0, "Backup: ");
		sprintf(backupBattery, "%1.2f%c", BackupBatteryLevel/1000.0, 'V');	//Build the value to be displayed
		displayNextLCDString(backupBattery);

		//Short delay for the LCD refresh rate
		wait1Msec(100);
	}
}

void stop(int stoptime) {
	motor[motorR] = 0;
	motor[motorL]	 = 0;
	wait1Msec(stoptime);

}

void turn(int deg, bool LeftRight)
{

	while(abs(SensorValue[encoderR]) < base_turn*deg)
	{
		if(LeftRight) {
			motor[motorR] = -power;
			motor[motorL]	 = power;
		}
		else {
			motor[motorR] = power;
			motor[motorL]	 = -power;
		}
	}
}

void correction(bool r_l) {
	if(r_l == true){
		motor[motorR] = 60;
		motor[motorL] = 0;
		wait1Msec(100);
	}
	else {
		motor[motorR] = 0;
		motor[motorL] = 60;
		wait1Msec(100);
	}
}

void resetEncoder() {
	SensorValue[encoderR] = 0;
	SensorValue[encoderL]	 = 0;
}



void drive(int b_f,int spaceBetween) {
	while(SensorValue(Sonar) > spaceBetween  || SensorValue(Sonar) == -1)
	{
		if(SensorValue[encoderR] == SensorValue[encoderL])
		{
			// Move Forward
			motor[motorR] = power*b_f;
			motor[motorL]	 = power*b_f;
		}
		else if(SensorValue[encoderR] > SensorValue[encoderL])
		{
			// Turn slightly right
			motor[motorR] = power*b_f;
			motor[motorL]	 = (power-20)*b_f;
		}
		else
		{
			// Turn slightly left
			motor[motorR] = (power-20)*b_f;
			motor[motorL]	 = power*b_f;
		}
	}
}
task stopMyTask() {
	while(vexRT[Btn8R]==0){
	}
	StopAllTasks();
}

task main()
{
	StartTask(stopMyTask);
	StartTask(display);
	resetEncoder();
	while(1==1)	{
		while(SensorValue(lightSensor) < 270) {
			drive(1,65);
			resetEncoder();
			stop(800);
			turn(70,true);
			resetEncoder();
			stop(1500);
		}
	}
}
