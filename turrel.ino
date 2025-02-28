#include <OneButton.h>

#include <Servo.h>
int X=90;
int Y=90;
bool f=false;
static void tr(){
  f=!f;
}
const int stepsPerRevolution=1024;
const int trigPin = 11;
const int echoPin = 10;
int xv;
int yv;
int valpot;
int angle;
int potenciometr;
long duration;
int distance;
Servo myServo; 
Servo avtomat;
OneButton button(2, true);
void setup() {
  pinMode(3,INPUT_PULLUP);
  pinMode(2,INPUT_PULLUP);
 pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT); 
  Serial.begin(9600); 
  myServo.attach(9); 
  avtomat.attach(10);
  avtomat.write(0);
  button.attachClick(tr);
}

void loop() {
  Serial.println(f);
  button.tick();
  if(f==false){
    if(digitalRead(3)==0){
      digitalWrite(13,1);
    }
       if(digitalRead(3)==1){
      digitalWrite(13,0);
    }
    xv=analogRead(0) - 512;
    yv=analogRead(1) - 512;

    if(xv > 64) X++;
    else if(xv < -64) X--;
    if(yv > 64) Y++;
    else if(yv < -64) Y--;
    
    delay(30);
  }
  if(f==true){
      if(Serial.available()>0){
    char a = Serial.read();
    switch(a){
      case 'r':
      if(X>0) X--;
      break;
      case 'l':
      if(X<180) X++;
      break;
      case 'd':
      if(Y<180) Y++;
      break;
      case 'u':
      if(Y>0) Y--;
      break;
    }

  }

avtomat.write(X);
      myServo.write(Y);
      
    
  Serial.println(X);}

  
  /*for (int i = 180; i >= 0; i--) {
    
    distance = calculateDistance(); 
    if(distance>30){
    myServo.write(i);
    digitalWrite(13,0); 
    delay(30);
    if(digitalRead(2)==1){
         f=false;
    }
} 
  if(distance<30){
        if(digitalRead(2)==1){
        f=false;
    }
avtomat.write(i);
digitalWrite(13,1);
i++;
if(i==0){
  i--;
}
    }}
      for (int i = 0; i < 180; i++) {
    distance = calculateDistance(); 
    if(distance>30){
          if(digitalRead(2)==1){
     f=false;
    }
    myServo.write(i);
    digitalWrite(13,0); 
    delay(30);
   } 
  if(distance<30){
        if(digitalRead(2)==1){
  f=false;
    }

    
avtomat.write(i);
digitalWrite(13,1);
 i--;
 if(i==180){
  i++;
}
    }
  }}
  }


int calculateDistance() {
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2); 
  digitalWrite(trigPin, HIGH); 
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW); 
  duration = pulseIn(echoPin, HIGH); 
  distance = duration / 58; 
  return distance; */
}
