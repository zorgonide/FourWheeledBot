 #include "CytronMotorDriver.h"


// Configure the motor driver.
CytronMD motor1(PWM_PWM, 5, 4);  // PWM 1A = Pin 2, PWM 1B = Pin   3.
CytronMD motor2(PWM_PWM, 6, 7);  // PWM 2A = Pin 4, PWM 2B = Pin 5.
CytronMD motor3(PWM_PWM, 8, 9);  // PWM 3A = Pin 6, PWM 3B = Pin 7.
CytronMD motor4(PWM_PWM, 10, 11);  // PWM 4A = Pin 8, PWM 4B = Pin 9.

int inp;
const int trigPin = 47;
const int echoPin = 49;
// defines variables
long duration;
int distance;

// The setup routine runs once when you press reset.
void setup() 
{
  Serial.begin(19200);
  motor1.setSpeed(0); 
  motor2.setSpeed(0);
  motor3.setSpeed(0);
  motor4.setSpeed(0);
  pinMode(trigPin, OUTPUT); // Sets the trigPin as an Output
  pinMode(echoPin, INPUT); // Sets the echoPin as an Input
}

boolean dist()
{
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  // Sets the trigPin on HIGH state for 10 micro seconds
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  // Reads the echoPin, returns the sound wave travel time in microseconds
  duration = pulseIn(echoPin, HIGH);
  // Calculating the distance
  distance= duration*0.034/2;
  if (distance <6)
  {
    return false;
  }
  else return true;
}

void trot()
// Reduce change in momentum of bot
{
  motor1.setSpeed(100);
  motor2.setSpeed(100);
  motor3.setSpeed(100);
  motor4.setSpeed(100);
}

void backward()
{
  motor1.setSpeed(-150);
  motor2.setSpeed(-150);
  motor3.setSpeed(-150);
  motor4.setSpeed(-150);
}
void right()
{
  motor1.setSpeed(210);
  motor2.setSpeed(-210);
  motor3.setSpeed(210);
  motor4.setSpeed(-210);
}
void left()
{
  motor1.setSpeed(-210);
  motor2.setSpeed(210);
  motor3.setSpeed(-210);
  motor4.setSpeed(210); 
}
void forward()
{
  motor1.setSpeed(200);
  motor2.setSpeed(200);
  motor3.setSpeed(200);
  motor4.setSpeed(200);
}
void forwardleft()
{
  motor1.setSpeed(255);
  motor2.setSpeed(100);
  motor3.setSpeed(255);
  motor4.setSpeed(100);
}
void forwardright()
{
  motor1.setSpeed(100);
  motor2.setSpeed(255);
  motor3.setSpeed(100);
  motor4.setSpeed(255);
}
/*
void backwardleft()
{
  motor4.setSpeed(-100);
  motor3.setSpeed(-200);
  motor2.setSpeed(-125);
  motor1.setSpeed(-255);
}
void backwardright()
{
  motor4.setSpeed(-200);
  motor3.setSpeed(-100);
  motor2.setSpeed(-255);
  motor1.setSpeed(-125);
}
*/
void Brakes()
{
  motor1.setSpeed(0);
  motor2.setSpeed(0);
  motor3.setSpeed(0);
  motor4.setSpeed(0);
}

void loop()
{
  // To use HC SR04 distance sensor
  // if (Serial.available() > 0 && dist())
  
  if(Serial.available() > 0)
  {
    inp = Serial.read();
    
    switch(inp)
    {
      case 'w' : 
                  forward();
                  delay(500);
                  Brakes();
                  break;
      case 's' : 
                  backward();
                  delay(500);
                  Brakes();
                  break;
      case 'd' : 
                  forwardright();
                  delay(250);
                  Brakes();
                  break;
      case 'a' : 
                  forwardleft();
                  delay(250);
                  Brakes();
                  break;
      case 'p' :  
                  right();
                  delay(250);
                  Brakes();
                  break;
      case 'i' : 
                  left();
                  delay(250);
                  Brakes();
                  break;
      case 'l' : //Yet to implement
                  //backwardright();
                  delay(40);
                  Brakes();
                  break;
      case 'k' : //Yet to implement
                  //backwardleft();
                  delay(40);
                  Brakes();
                  break;
      case 't' : 
                  trot();
                  delay(500);
                  Brakes();
                  break;
      case 'b' :
      default : 
                  Brakes();
    }
  }
}
