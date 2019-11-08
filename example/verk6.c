#pragma config(Sensor, dgtl1,  rightEncoder,        sensorQuadEncoder)
#pragma config(Sensor, dgtl3,  leftEncoder,         sensorQuadEncoder)
#pragma config(Motor,  port2,           rightMotor,    tmotorNormal, openLoop, reversed)
#pragma config(Motor,  port3,           leftMotor,     tmotorNormal, openLoop)

#include "verk6.h"

My_verk6 *array_function(){
	My_verk6 verk6_array[5];
		verk6_array[0].first_turn=false;
		verk6_array[0].second_turn=true;
		verk6_array[0].dist=BASEDIST*3;
		verk6_array[0].doing="first glas";
		verk6_array[1].first_turn=false;
		verk6_array[1].second_turn=false;
		verk6_array[1].dist=BASEDIST*2;
		verk6_array[1].doing="second glas";
		verk6_array[2].first_turn=false;
		verk6_array[2].second_turn=true;
		verk6_array[2].dist=BASEDIST;
		verk6_array[2].doing="third glas";
		verk6_array[3].first_turn=true;
		verk6_array[3].second_turn=false;
		verk6_array[3].dist=BASEDIST;
		verk6_array[3].doing="forth glas";
	return &verk6_array;
}
//+++++++++++++++++++++++++++++++++++++++++++++| MAIN |+++++++++++++++++++++++++++++++++++++++++++++++
task main()
{
	wait1Msec(2000);
	My_verk6 *ptr =array_function();
	for(int i=0;i<4;i++){
    //displayLCDString(0, 0, ptr->doing);
    writeDebugStreamLine("Working in %s\n", ptr->doing);
    //displayLCDString(1, 0, "Distance = ");
    writeDebugStreamLine("Distance = %d\n", ptr->dist);
    //displayLCDNumber(1, 10, ptr->dist);
    wait1Msec(1000);
		ptr++;
}
}
//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
