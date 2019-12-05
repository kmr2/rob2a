//Wait for Press--------------------------------------------------
void waitForPress()
{
	while(nLCDButtons == 0){}
	wait1Msec(5);
}
//----------------------------------------------------------------

//Wait for Release------------------------------------------------
void waitForRelease()
{
	while(nLCDButtons != 0){}
	wait1Msec(5);
}
//----------------------------------------------------------------

task menu()
{
	//Declare count variable to keep track of our choice
	int count = 0;

	//------------- Beginning of User Interface Code ---------------
	//Clear LCD
	clearLCDLine(0);
	clearLCDLine(1);
	//Loop while center button is not pressed
	while(nLCDButtons != centerButton)
	{
		//Switch case that allows the user to choose from 4 different options
		switch(count){
		case 0:
			//Display first choice
			displayLCDCenteredString(0, "Autonomous 1");
			displayLCDCenteredString(1, "<		 Enter		>");
			waitForPress();
			//Increment or decrement "count" based on button press
			if(nLCDButtons == leftButton)
			{
				waitForRelease();
				count = 3;
			}
			else if(nLCDButtons == rightButton)
			{
				waitForRelease();
				count++;
			}
			break;
		case 1:
			//Display second choice
			displayLCDCenteredString(0, "Autonomous 2");
			displayLCDCenteredString(1, "<		 Enter		>");
			waitForPress();
			//Increment or decrement "count" based on button press
			if(nLCDButtons == leftButton)
			{
				waitForRelease();
				count--;
			}
			else if(nLCDButtons == rightButton)
			{
				waitForRelease();
				count++;
			}
			break;
		case 2:
			//Display third choice
			displayLCDCenteredString(0, "Autonomous 3");
			displayLCDCenteredString(1, "<		 Enter		>");
			waitForPress();
			//Increment or decrement "count" based on button press
			if(nLCDButtons == leftButton)
			{
				waitForRelease();
				count--;
			}
			else if(nLCDButtons == rightButton)
			{
				waitForRelease();
				count++;
			}
			break;
		case 3:
			//Display fourth choice
			displayLCDCenteredString(0, "Autonomous 4");
			displayLCDCenteredString(1, "<		 Enter		>");
			waitForPress();
			//Increment or decrement "count" based on button press
			if(nLCDButtons == leftButton)
			{
				waitForRelease();
				count--;
			}
			else if(nLCDButtons == rightButton)
			{
				waitForRelease();
				count = 0;
			}
			break;
		default:
			count = 0;
			break;
		}
	}
	//------------- End of User Interface Code ---------------------

	//------------- Beginning of Robot Movement Code ---------------
	//Clear LCD
	clearLCDLine(0);
	clearLCDLine(1);
	//Switch Case that actually runs the user choice
	switch(count){
	case 0:
		//If count = 0, run the code correspoinding with choice 1
		displayLCDCenteredString(0, "Autonomous 1");
		displayLCDCenteredString(1, "is running!");
		wait1Msec(2000);						// Robot waits for 2000 milliseconds

		// Move forward at full power for 3 seconds
		motor[rightMotor] = 127;			// Motor on port2 is run at full (127) power forward
		motor[leftMotor]	= 127;			// Motor on port3 is run at full (127) power forward
		wait1Msec(3000);							// Robot runs previous code for 3000 milliseconds before moving on
		break;
	case 1:
		//If count = 1, run the code correspoinding with choice 2
		displayLCDCenteredString(0, "Autonomous 2");
		displayLCDCenteredString(1, "is running!");
		wait1Msec(2000);						// Robot waits for 2000 milliseconds

		// Move reverse at full power for 3 seconds
		motor[rightMotor] = -127;			// Motor on port2 is run at full (-127) power reverse
		motor[leftMotor]	= -127;			// Motor on port3 is run at full (-127) power reverse
		wait1Msec(3000);							// Robot runs previous code for 3000 milliseconds before moving on
		break;
	case 2:
		//If count = 2, run the code correspoinding with choice 3
		displayLCDCenteredString(0, "Autonomous 3");
		displayLCDCenteredString(1, "is running!");
		wait1Msec(2000);						// Robot waits for 2000 milliseconds

		//Turn right for 3 seconds
		motor[rightMotor] = -63;			// Motor on port2 is run at half power reverse
		motor[leftMotor]	= 63;				// Motor on port3 is run at half power forward
		wait1Msec(3000);							// Robot runs previous code for 3000 milliseconds before moving on
		break;
	case 3:
		//If count = 3, run the code correspoinding with choice 4
		displayLCDCenteredString(0, "Autonomous 4");
		displayLCDCenteredString(1, "is running!");
		wait1Msec(2000);						// Robot waits for 2000 milliseconds

		//Turn left for 3 seconds
		motor[rightMotor] = 63;				// Motor on port2 is run at half power forward
		motor[leftMotor]	= -63;			// Motor on port3 is run at half power reverse
		wait1Msec(3000);							// Robot runs previous code for 3000 milliseconds before moving on
		break;
	default:
		displayLCDCenteredString(0, "No valid choice");
		displayLCDCenteredString(1, "was made!");
		break;
	}
	//------------- End of Robot Movement Code -----------------------
}
