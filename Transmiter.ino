#define trig 2 
#define echo 3 
int cm; //distance 
float temp; //   
const int aRead = A0; 
int value, threshold; 

void setup() {
  
	Serial.begin(9600); 
  pinMode(trig, OUTPUT);  
  pinMode(echo, INPUT);  
}

void loop() {
  //trigger the distance mesurement 
  digitalWrite(trig, LOW); // send low to trig
  delayMicroseconds(2);    //wait more than 10us aka 2 ms
  digitalWrite(trig,HIGH); //send high to trig 
  delayMicroseconds(10);    //wait 10 ms
  digitalWrite(trig, LOW); //send low and end trigger
    
  temp = float(pulseIn(echo, HIGH)); //save the time of echo
  //pulse return time from high to low


  /* Math part:(
   *  sound speed 340m/s 340000cm/1000000 us
   *  round trip divide by 2
   *  temp*((34/1000))/2
   */
//  Serial.print(cm);//  
   cm = (temp * 17 )/1000; //time to distance
  	value = cm;
  	//Map the analog value to pwm value
  	value = map (value, 0, 90, 0, 511);
    threshold=200-value;
    if (threshold>40)
    {value=200;}
    else
    {value=0; }
    
	//Send the message:
	//Serial.print(vav);
	Serial.print('<'); 	//Start
 	Serial.print(value);
	Serial.println('>');//End
}


  
