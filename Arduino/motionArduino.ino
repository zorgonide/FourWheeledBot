#include "CytronMotorDriver.h"


// Configure the motor driver.
CytronMD motor1(PWM_PWM, 4, 5);  // PWM 1A = Pin 4, PWM 1B = Pin 5.
CytronMD motor2(PWM_PWM, 7, 6);  // PWM 2A = Pin 6, PWM 2B = Pin 7.
CytronMD motor3(PWM_PWM, 9, 8);  // PWM 3A = Pin 8, PWM 3B = Pin 9.
CytronMD motor4(PWM_PWM, 11, 10);  // PWM 4A = Pin 10, PWM 4B = Pin 11.

const int trigPin = 47;
const int echoPin = 49;
// defines variables
long duration;
int distance;

int inp;

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


void backward()
{
  Serial.println("Backward\n");
  motor1.setSpeed(205);
  motor2.setSpeed(205);
  motor3.setSpeed(205);
  motor4.setSpeed(205);
}
void right()
{
  Serial.println("Right \n");
  motor1.setSpeed(255);
  motor2.setSpeed(-255);
  motor3.setSpeed(255);
  motor4.setSpeed(-255);
}
void left()
{
  Serial.println("Left\n");
  motor1.setSpeed(-255);
  motor2.setSpeed(255);
  motor3.setSpeed(-255);
  motor4.setSpeed(255); 
}
void forward()
{
  motor1.setSpeed(-255);
  motor2.setSpeed(-255);
  motor3.setSpeed(-255);
  motor4.setSpeed(-255);
  //delay(30);
  
}
void forwardleft()
{
  motor1.setSpeed(-100);
  motor2.setSpeed(-200);
  motor3.setSpeed(-100);
  motor4.setSpeed(-200);
}
void forwardright()
{
  Serial.print("Forward Right\n");
  motor1.setSpeed(-200);
  motor2.setSpeed(-100);
  motor3.setSpeed(-200);
  motor4.setSpeed(-100);
}
void backwardleft()
{
  Serial.println("Backward Left\n");
  motor4.setSpeed(-100);
  motor3.setSpeed(-200);
  motor2.setSpeed(-125);
  motor1.setSpeed(-255);
}
void backwardright()
{
  Serial.print("Backward Right\n");
  motor4.setSpeed(-200);
  motor3.setSpeed(-100);
  motor2.setSpeed(-255);
  motor1.setSpeed(-125);
}
void Brake()
{
  Serial.print("Breaks\n");
  motor1.setSpeed(0);
  motor2.setSpeed(0);
  motor3.setSpeed(0);
  motor4.setSpeed(0);
}
void loop()
{
  if(Serial.available() > 0)
  {
    inp = Serial.read();
    
    switch(inp)
    {
      case 'w' : 
                  forward();
                  delay(500);
                  Brake();
                  break;
      case 's' : 
                  backward();
                  delay(500);
                  Brake();
                  break;
      case 'd' : 
                  right();
                  delay(250);
                  Brake();
                  break;
      case 'a' : 
                  left();
                  delay(250);
                  Brake();
                  break;
      case 'l' : 
                  forwardright();
                  delay(40);
                  Brake();
                  break;
      case 'j' : 
                  forwardleft();
                  delay(40);
                  Brake();
                  break;
      /*case 'l' : 
                  backwardright();
                  delay(40);
                  Brake();
                  break;
      case 'k' : 
                  backwardleft();
                  delay(40);
                  Brake();
                  break;
      */
      case 'b' :
      default : 
                  Brake();
    }
  }
}
