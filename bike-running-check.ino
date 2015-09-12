// Based on File > Examples > Servo > Knob
// Controlling a servo position using a potentiometer (variable resistor)
// by Michal Rinott <http://people.interaction-ivrea.it/m.rinott>

#include <Servo.h>

Servo myservo;  // create servo object to control a servo

int potpin = 0;  // analog pin used to connect the potentiometer
int val;  // variable to read the value from the analog pin
int ts;
int vol;
int time = 0;
int timo = 0;
int i;

void setup()
{
  Serial.begin(9600);
  myservo.attach(9);  // attaches the servo on pin 9 to the servo object
}

void loop()

{
  val = analogRead(potpin);            // reads the value of the potentiometer (value between 0 and 1023)
 //Serial.println(val);
 // val = map(val, 50, 300, 0, 179);
     // scale it to use it with the servo (value between 0 and 180)
//  for(i = 0 ;   i < 100 ; i++){
  //if(val > 20) { ts = ts + 1;}
  //delay(10);
// }
if(val > 150 ) {Serial.println("A"); time=0;};


 if(val < 20)
{
   time++;
}

if(time > 1000){Serial.println("B"); time=0;}
if(time > 45){Serial.println("C"); timo=0;}// myservo.write(val);    // sets the servo position according to the scaled value
  delay(15);
    timo++;// waits for the servo to get there
}
