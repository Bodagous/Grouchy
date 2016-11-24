/*  laser tag gun repurposing.  small dome with 5 IR sensor/ readers.
 2 wires 1 gpio and 1 out.  testing possibility of repurpose.
*/
int irSensorDigital[6] = {0,0,0,0,0,0};
int READER = A1;
int READER2 = 4;
int REFERENCE = 0;
int PWMOUT = 250;

void setup()
{
	pinMode(READER2, INPUT);
	pinMode(READER, INPUT);
}

void loop()
{
 	digitalWrite(READER2, LOW);
 	delay(200);
 	if (REFERENCE != analogRead(READER)){
 		READER2 = digitalRead(READER);
    else {irSensorDigital[i] = 0;}
    Serial.print(REFERENCE[i]);
    Serial.print("|");
    count = count + irSensorDigital[i];
    int b = 5-i;
    READER2 = READER + (irSensorDigital[i]<<b);
 	delay(200);

 	}
}