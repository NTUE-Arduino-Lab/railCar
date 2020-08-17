int counter1, counter2;
int pin1 = 8;
int pin2 = 13;
int status1 = 0;
int status2 = 0;
int result[2];
char r[8];
void setup()
{
	Serial.begin(9600);
	pinMode(pin1,INPUT);
	pinMode(pin2,INPUT);
	result[0] = 0;
	result[1] = 0;

}
void loop()
{
	counter1 = digitalRead(pin1);
	counter2 = digitalRead(pin2);
	// Serial.println(r);
	
	switch (status1)
	{
	case 0:
		if(counter1 == HIGH)
		{
			result[0] = 1; 
			status1 = 1;
		}
		break;
	
	case 1:
		sprintf(r,"%d %d",result[0],result[1]);
		Serial.println(r);
		status1 = 2;
		break;
	case 2:
		if(counter1 == LOW)
		{
			result[0] = 0; 
			sprintf(r,"%d %d",result[0],result[1]);
			Serial.println(r);
			status1 = 0;
		}
		break;
	}

	switch (status2)
	{
	case 0:
		if(counter2 == HIGH)
		{
			result[1] = 1;
			status2 = 1;
		}

		break;
	
	case 1:
		sprintf(r,"%d %d",result[0],result[1]);
		Serial.println(r);
		status2 = 2;
		break;
	case 2:
		if(counter2 == LOW)
		{
			result[1] = 0; 
			sprintf(r,"%d %d",result[0],result[1]);
			Serial.println(r);
			status2 = 0;
		}
		break;
	}
}