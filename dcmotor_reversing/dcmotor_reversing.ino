/*
Adafruit Arduino - Lesson 15. Bi-directional Motor
*/
 
int enablePin = 11;
int in1Pin = 10;
int in2Pin = 9;
int dc2enablePin = 6;
int dc2in1Pin = 5;
int dc2in2Pin = 3;
int switchPin = 7;
int potPin = 0;
 
void setup()
{
  pinMode(in1Pin, OUTPUT);
  pinMode(in2Pin, OUTPUT);
  pinMode(enablePin, OUTPUT);
  pinMode(dc2in1Pin, OUTPUT);
  pinMode(dc2in2Pin, OUTPUT);
  pinMode(dc2enablePin, OUTPUT);
  pinMode(switchPin, INPUT_PULLUP);
}
 
void loop()
{
  int speed = analogRead(potPin) / 4;
  boolean reverse = digitalRead(switchPin);
  setMotor(speed, reverse);
}
 
void setMotor(int speed, boolean reverse)
{
  analogWrite(enablePin, speed);
  analogWrite(dc2enablePin, speed);
  digitalWrite(in1Pin, ! reverse);
  digitalWrite(in2Pin, reverse);
  digitalWrite(dc2in1Pin, ! reverse);
  digitalWrite(dc2in2Pin, reverse);
}
