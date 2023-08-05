#include <Servo.h> 

int SERVO_PIN = D5;
int LED_PIN  = LED_BUILTIN;

Servo myservo;  
int inByte;
int minA;
int maxA;
int pos;
bool read_min;

void setup() 
{ 
  myservo.attach(SERVO_PIN, 600,2000);  
  pinMode(LED_PIN, OUTPUT);  
  read_min = true;
} 
 
 
void loop() 
{ 
  
    // up: LED is on
    digitalWrite(LED_PIN, HIGH);
    for(pos = 0; pos < 180; pos += 4)  // goes from 0 degrees to 180 degrees 
    {                                  // in steps of 1 degree 
      myservo.write(pos);              // tell servo to go to position in variable 'pos' 
      delay(10);                       // waits 15ms for the servo to reach the position 
    } 
    // down: LED is off
    digitalWrite(LED_PIN, LOW);
    for(pos = 180; pos>=1; pos-=4)     // goes from 180 degrees to 0 degrees 
    {                                
      myservo.write(pos);              // tell servo to go to position in variable 'pos' 
      delay(10);                       // waits 15ms for the servo to reach the position 
    } 
    
}