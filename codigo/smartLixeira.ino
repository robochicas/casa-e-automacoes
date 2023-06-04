//Lixeira automatizada
#include <Servo.h>   //Importando a biblioteca do motor servo
Servo servo;     
int trigPin = 11;    
int echoPin = 10;   
int servoPin = 12;

long duracao, distancia, average;   
long aver[3];   //array for average


void setup() {       
  servo.attach(servoPin);  
  pinMode(trigPin, OUTPUT);  
  pinMode(echoPin, INPUT);  
  servo.write(0);        
  delay(1000);
  servo.detach();
} 

void measure() {  
digitalWrite(trigPin, LOW);
delayMicroseconds(5);
digitalWrite(trigPin, HIGH);
delayMicroseconds(15);
digitalWrite(trigPin, LOW);
pinMode(echoPin, INPUT);
duracao = pulseIn(echoPin, HIGH);
distancia = (duracao/2) / 29.1;
}
void loop() { 
  for (int i=0;i<=2;i++) {   
    measure();               
   aver[i]=distancia;            
    delay(50);           
  }
 distancia=(aver[0]+aver[1]+aver[2])/3;    
if ( distancia<50 ) {
 servo.attach(servoPin);
  delay(1);
 servo.write(90);  
 delay(5000);  
 servo.write(0);    
 delay(1000);
 servo.detach();      
}
}
