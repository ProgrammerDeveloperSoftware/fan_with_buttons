#include <Servo.h>

Servo servo;

int motore=9;
int pulsante1=13;   //per spegnere il ventilatore
int pulsante2=12;   //per avviare il motore a 85 pwm
int pulsante3=11;   //per avviare il motore a 170 pwm
int pulsante4=10;   //per avviare il motore a 255 pwm
int statopuls1=LOW;
int statopuls2=LOW;
int statopuls3=LOW;
int statopuls4=LOW;

void setup() {
  pinMode(motore,OUTPUT);
  pinMode(pulsante1,INPUT);
  pinMode(pulsante2,INPUT);
  pinMode(pulsante3,INPUT);
  pinMode(pulsante4,INPUT);
  servo.attach(8);
 }

void loop() {
    statopuls1=digitalRead(pulsante1);
    statopuls2=digitalRead(pulsante2);
    statopuls3=digitalRead(pulsante3);
    statopuls4=digitalRead(pulsante4);


    if(statopuls1==HIGH){
      analogWrite(motore,0);
    }

    if(statopuls2==HIGH){
      analogWrite(motore,85);
    }


    if(statopuls3==HIGH){
      analogWrite(motore,170);
    }


    if(statopuls4==HIGH){
      analogWrite(motore,255);
    }

for(int pos=0; pos<170; pos++){
  servo.write(pos);
}


for(int pos=170; pos>0; pos--){
  servo.write(pos);
 }
}
