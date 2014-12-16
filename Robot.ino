/*
David Tsenter
Mr Wong
07/07/2014
This program will control our robot to manoeuvre through any maze 
by hugging the left wall.
*/
// motor 1
const int motor1pin = 6;
const int motor2pin = 5;
// motor 2
const int motor3pin = 11;
const int motor4pin = 10;
// LED Pin
const int led = 13;
// LDR Pin
const int ldr = 0;
// Integer used to store the LDR readings
int ldr_val;

/*
This method enables the motors, ldr ,and the LED. 
*/
void setup ()
{
  Serial.begin (9600);
  pinMode (motor1pin, OUTPUT); 
  pinMode (motor2pin, OUTPUT);
  pinMode (motor3pin, OUTPUT); 
  pinMode (motor4pin, OUTPUT);
  pinMode (led, OUTPUT);
}
/*
This method handles the logic of the robot. The LED is turned on, and the LDR readings are read in.
If the reading on the LDR is less than 200 meaning that it is on white, the robot rotates to the right.
If the reading on the LDR is over 200 meaning that it is on black, the robot rotates to the right.

This whole process is looped, and the result being that the robot always hugs the left wall, solving the maze,
and continually cycling through it.
*/
void loop ()
{
  digitalWrite (led, HIGH);
  ldr_val = analogRead (0);
  Serial.println (ldr_val);
  if (ldr_val< 200)
  {
  analogWrite (motor1pin, 0);
  analogWrite (motor2pin, 90);
  analogWrite (motor3pin, 120);
  analogWrite (motor4pin, 0);
  delay (70);
  }
  if (ldr_val>200)
{
  analogWrite (motor1pin,120);
  analogWrite (motor2pin, 0);
  analogWrite (motor3pin, 0);
  analogWrite (motor4pin, 90);
  delay (70);
}
}


