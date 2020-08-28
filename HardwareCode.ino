#include <Servo.h>.
// Defines Tirg and Echo pins of the Ultrasonic Sensor
const int trigPin = 9;
const int echoPin = 8;
// Variables for the duration and the distance
long duration;
int distance;
boolean tar = false;
Servo myServo; // Creates a servo object for controlling the servo motor
Servo trig;
Servo launch;
void setup() {
  pinMode(trigPin, OUTPUT); // Sets the trigPin as an Output
  pinMode(echoPin, INPUT); // Sets the echoPin as an Input
  Serial.begin(9600);
  myServo.attach(11); // Defines on which pin is the servo motor attached
  trig.attach(12);
  launch.attach(10);
}
void loop() {
  // rotates the servo motor from 15 to 165 degrees
  for(int i=15;i<=165;i++){  
  myServo.write(i);
  launch.write(i);
  trig.write(90);
  delay(30);
  distance = calculateDistance();
  // Calls a function for calculating the distance measured by the Ultrasonic sensor for each degree
  if(distance <=15&& distance >5)
  { delay(500);
    trig.write(180);
    delay(1000);
    
  }
  Serial.print(i); // Sends the current degree into the Serial Port
  Serial.print(","); // Sends addition character right next to the previous value needed later in the Processing IDE for indexing
  Serial.print(distance); // Sends the distance value into the Serial Port
  Serial.print("."); // Sends addition character right next to the previous value needed later in the Processing IDE for indexing
  }
  // Repeats the previous lines from 165 to 15 degrees
  for(int i=165;i>15;i--){  
   myServo.write(i);
  launch.write(i);
  trig.write(90);
  delay(30);
  distance = calculateDistance();// Calls a function for calculating the distance measured by the Ultrasonic sensor for each degree
  if(distance <=15 && distance >5)
  { delay(500);
    trig.write(180);
    delay(1000);
    
  }
  Serial.print(i);
  Serial.print(",");
  Serial.print(distance);
  Serial.print(".");
  }
}
// Function for calculating the distance measured by the Ultrasonic sensor
int calculateDistance(){ 
  
  digitalWrite(trigPin, LOW); 
  delayMicroseconds(2);
  // Sets the trigPin on HIGH state for 10 micro seconds
  digitalWrite(trigPin, HIGH); 
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  duration = pulseIn(echoPin, HIGH); // Reads the echoPin, returns the sound wave travel time in microseconds
  distance= duration*0.034/2;
  return distance;
}
