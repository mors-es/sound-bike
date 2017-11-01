// Based on File > Examples > Servo > Knob
// Controlling a servo position using a potentiometer (variable resistor)
// by Michal Rinott <http://people.interaction-ivrea.it/m.rinott>


int potpin = 0;       // analog pin used to connect the speedometer
int val;              // variable to read the value from the analog pin
int perimeter = 0.120 // perimeter of the weel of the bike in meter
int totalTime = 0;    // total time just before printing the speed in milliseconds
int time;             // time between two speedometer 'closed'
int speed = 0;        // speed in m/s

void setup()
{
  Serial.begin(9600);
}

void loop()

{
  val = analogRead(potpin);        // reads the value of the potentiometer (value between 0 and 1023)

  val = map(val, 0, 1023, 0, 255); // map value to 8 bit
  Serial.println(val);
  
  // check if the speedometer is 'closed' 
  if(val > 200) 
  {
    time = millis() - totalTime;       // set time between the the last passage in the 'if'
    speed = perimeter / (time / 1000); // set speed in m/s
    Serial.println(speed);             // print the speed
    totalTime = millis();              // set new time since the begining of the program
  };

  if(val < 20)
  {
    time++;
  }

  // check is the time since the speedometer is 'closed' is not too long
  if(time > 2000)
  {
    speed = 0;               // set the speed to zero
    Serial.println(speed);   // print the speed (zero)
    time=0;                  // set interval to zero.
  }
  // wait a bit to not send massive amounts of data but have to be enough quick to not miss the speedometer 'closed'
  delay(20);
}
