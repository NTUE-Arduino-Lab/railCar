int sensor = 11;
int output = 13;
int status = 0;
void setup()
{
	Serial.begin(9600);
	pinMode(output, OUTPUT);
	digitalWrite(output,LOW);
	pinMode(sensor, INPUT);
}
void loop()
{
	switch (status)
	{
	case 0:
		if(digitalRead(sensor) == LOW){
			digitalWrite(output, HIGH);
			delay(1000);
			status = 1;
		}
		break;
	
	case 1:
		if(digitalRead(sensor) == HIGH){
			digitalWrite(output, LOW);
			delay(1000);
			status = 0;
		}
		break;
	}
}