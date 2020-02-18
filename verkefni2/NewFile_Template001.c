#pragma config(Sensor, in1,    LightSensor,    sensorReflection)
#pragma config(Sensor, in2,    LineFollower1,  sensorLineFollower)
#pragma config(Sensor, in3,    LineFollower2,  sensorLineFollower)
#pragma config(Sensor, in4,    Linefollower3,  sensorLineFollower)
#pragma config(Sensor, in5,    Potentiometer,  sensorPotentiometer)
#pragma config(Sensor, in6,    Gyro,           sensorGyro)
#pragma config(Sensor, dgtl1,  Encoder1,       sensorQuadEncoder)
#pragma config(Sensor, dgtl3,  Encoder2,       sensorQuadEncoder)
#pragma config(Sensor, dgtl5,  Sonar,          sensorSONAR_cm)
#pragma config(Sensor, dgtl7,  limmitSW,       sensorTouch)
#pragma config(Sensor, dgtl8,  button,         sensorTouch)
#pragma config(Motor,  port2,           motorR,        tmotorVex269, openLoop)
#pragma config(Motor,  port3,           motorL,        tmotorVex269, openLoop, reversed)
#pragma config(Motor,  port4,           arm,           tmotorVex269, openLoop)
#pragma config(Motor,  port5,           speedC,        tmotorVex269, openLoop)
//*!!Code automatically generated by 'ROBOTC' configuration wizard               !!*//

#define basetime 900
int power = 127;

void drive(int time,int b_or_f) {
	motor[motorR] = power*b_or_f;
	motor[motorL]  = power*b_or_f;
	wait1Msec(time);
}

void stop(int stoptime) {
	motor[motorR] = 0;
	motor[motorL]  = 0;
	wait1Msec(stoptime);

}

task main()
{
	for(int i=1;i<=5;i++){
		drive(i*basetime,1);
		stop(700);
		drive(i*basetime,-1);
		stop(700);
	}
}
