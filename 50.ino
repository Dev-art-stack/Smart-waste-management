#include <NewPing.h>

#include <Servo.h>	
Servo servo1;

const int trigPin = 8; const int echoPin = 9;

long duration;

int distance=0; int potPin = A0; int soil=0;
int fsoil;
int maxDryValue=10;	//this value decides how much humidity require to treat waste as wet object
 
int Ultra_Distance=15;	//set Distance between Ultrasonic and moisture(soil) sensor in cm

#include <Wire.h> 
#include <NewPing.h> 
#define trigPin1 11
#define echoPin1 12
#define buzzer 2
const int maxTankDepth = 10; 
const int buzzerThreshold = 80;
NewPing sonar(trigPin1, echoPin1, maxTankDepth);

void setup()
{
Serial.begin(9600); 
pinMode(trigPin, OUTPUT); 
pinMode(echoPin, INPUT); 
servo1.attach(7);
Serial.println("Soil Sensor	Ultrasonic	Servo"); 
pinMode(buzzer, OUTPUT);
digitalWrite(buzzer, LOW);
}

void loop()
{
int sensorValue=analogRead(A1); int soil=0;
for(int i=0;i<2;i++)
{
digitalWrite(trigPin, LOW);
delayMicroseconds(7); 
digitalWrite(trigPin, HIGH); 
delayMicroseconds(10); 
digitalWrite(trigPin, LOW); 
delayMicroseconds(10);
duration = pulseIn(echoPin, HIGH); 
distance= duration*0.034/2+distance; 
delay(10);

}
distance=distance/2;
int distance1 = sonar.ping_cm();
int wasteLevel = map(distance1, 0, maxTankDepth, 100, 0);
wasteLevel = constrain(wasteLevel, 0, 100);

if (distance <Ultra_Distance && distance>1)
{
delay(1000);
 
for(int i=0;i<3;i++)
{
soil = analogRead(potPin) ;
soil = constrain(soil, 485, 1023);
fsoil = (map(soil, 485, 1023, 100, 0))+fsoil; delay(75);
}
fsoil=fsoil/3;

Serial.print("Humidity: "); Serial.print(fsoil);
Serial.print("%"); Serial.print("	Distance: ");Serial.print(distance);Serial.print(" cm"); Serial.print("	Rotten Value: ");Serial.print(sensorValue);
if (sensorValue>100){ 
digitalWrite(13,HIGH); 
delay(1000);
}
else{
digitalWrite(13,LOW);
}
if(fsoil>maxDryValue)
{delay(1000);
Serial.println("	==>WET Waste "); servo1.write(10);
delay(3000);} else{ delay(1000);
Serial.println("	==>Dry Waste "); servo1.write(170);
delay(3000);} Serial.print("Distance: "); Serial.print(distance1); Serial.print(" cm, Fill Level: "); Serial.print(wasteLevel); Serial.println(" %");
if (wasteLevel >= (buzzerThreshold)) { 
  digitalWrite(buzzer, HIGH);
}
else{
digitalWrite(buzzer, LOW);
}

servo1.write(90);} distance=0; fsoil=0;delay(1000);
delay(1000);
}
