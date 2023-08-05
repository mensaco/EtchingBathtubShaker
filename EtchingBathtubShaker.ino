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
  Serial.begin(115200);

  // minA = 0; 
  // maxA = 180;
  // myservo.attach(SERVO_PIN, minA,maxA);

  read_min = true;
} 
 
 
void loop() 
{ 
  // if (Serial.available() > 0) 
  // {
  //    // get incoming byte:
  //    inByte = Serial.read(); 
  //    switch(inByte)
  //    {
  //      case ':':
  //      read_min = false;
  //      maxA = 0;
  //      break;
  //      case '0':
  //      case '1':
  //      case '2':
  //      case '3':
  //      case '4':
  //      case '5':
  //      case '6':
  //      case '7':
  //      case '8':
  //      case '9':
  //      if(read_min)
  //      {
  //        minA = minA * 10 + inByte - '0';
  //      }
  //      else
  //      {
  //        maxA = maxA * 10 + inByte - '0';
  //      }
  //      break;
  //      case ';':
  //      myservo.detach();
  //      Serial.print(minA);
  //      Serial.print(":");
  //      Serial.println(maxA);
  //      myservo.attach(SERVO_PIN, minA,maxA);  // attaches the servo on pin 9 to the servo object 
  //      read_min = true;
  //      minA = 0;
  //      maxA = 0;
  //      break;
  //      default:
  //      break;
  //    }
  // }
  // else 
  // {
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
  //}
}