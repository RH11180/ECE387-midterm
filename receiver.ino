int LED=3;
int started = 0;
int ended = 0;
char incoming ;
char data[4];  // array stored 4 bytes
byte digi;    


void setup() {
Serial.begin(9600);
pinMode(LED, OUTPUT);


}

void loop() {
while (Serial.available()>0)
{
  incoming = Serial.read();
  if (incoming == '<')
  {
    started = 1;
    digi=0;
    data[digi] = '\0';
  }
  else if (incoming == '>')
  {
    ended = 1;
    break;
   
  }
else
{
  if (digi<5)
  {
    data[digi] = incoming;
    digi++;
    data[digi] = '\0';
  }
}
}
if (started==1 && ended==1)  //finish transmition
{
  int value = atoi(data); //all data send by Xbee are char

  analogWrite(LED, value);
  digi=0;
  data[digi] = '\0';
  started=0;
  ended =0;
  
}
}
