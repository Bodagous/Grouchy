int IRIN0 = A0;  // detector inupt


int IRINVAL0 = 0; // ir value
int IROUT = 3;  // irled out

byte IR0; // serial output value
int loop_cnt = 0;

void setup()
{
  Serial.begin(9600);  //give it a chance to talk
  pinMode(IRIN0, INPUT); //analogread a0

  pinMode(IROUT, OUTPUT); //out ir led
}

/* this is crap but it gets the job done commenting edits for others*/

void loop()
{

    if ( loop_cnt > 50 ) { //analogeRead every 100 msecs get new data
        loop_cnt = 0;
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
  loop_cnt++;
  delay(1);
}

void allon()
{
  Serial.println("tx and rx on"); 
  digitalWrite(IROUT, HIGH);
  IRINVAL0 = digitalRead(IRIN0);
  IR0 = IRINVAL0;
  Serial.print(" "); Serial.println((byte)IR0, DEC);
  digitalWrite(IROUT, LOW);
}

void rxonly()
{
  Serial.print("rx on : "); 
  IRINVAL0 = digitalRead(IRIN0);
  IR0 = IRINVAL0;
  Serial.print(" "); Serial.println((byte)IR0, DEC);
}
