const int LED=3;

bool started = false;
bool ended = false;
char incoming ;
char data[4];
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
    started = true;
    digi=0;
    data[digi] = '\0';
  }
  else if (incoming == '>')
  {
    ended = true;
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
if (started && ended)
{
  int value = atoi(data);

  analogWrite(LED, value);
  digi=0;
  data[digi] = '\0';
  started=false;
  ended =false;
  
}
}
