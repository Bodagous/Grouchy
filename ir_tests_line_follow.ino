int IRIN0 = A0;  // detector inupt


int IRINVAL0 = 0; // ir value
int IROUT = 3;  // irled out

byte IR0; // serial output value

void setup()
{
  Serial.begin(9600);  //give it a chance to talk
  pinMode(IRIN0, INPUT); //analogread a0

  pinMode(IROUT, OUTPUT); //out ir led
}

/* this is crap but it gets the job done commenting edits for others*/

void loop()
{
  Serial.println("manual calibration testing for IR tx rx");
  Serial.print("\tyou will have 2 second windows in which the test is done");
   delay (5000);
   rxonly();
   delay (2000);
   allon();
   delay(2000);  //long pause run it back now
   rxonly();
   delay (2000);
   allon();
   delay(2000);
}

void allon()
{
  Serial.println("tx and rx on"); 
  digitalWrite(IROUT, HIGH);
  IRINVAL0 = analogRead(IRIN0);
  IR0 = IRINVAL0;
  Serial.print(" "); Serial.println((byte)IR0, DEC);
  digitalWrite(IROUT, LOW);
}

void rxonly()
{
  Serial.print("rx on : "); 
  digitalWrite(IROUT, LOW);
  IRINVAL0 = analogRead(IRIN0);
  IR0 = IRINVAL0;
  Serial.print(" "); Serial.println((byte)IR0, DEC);
  digitalWrite(IROUT, LOW);
}

