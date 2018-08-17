#include <SoftwareSerial.h>
SoftwareSerial ESPserial(12, 13); // RX | TX

//right side motor control
int ctrl_IN1 = 7;
int ctrl_IN2 = 6;
int ctrl_ENABLE1 = 3; //enable right
//left side motor control
int ctrl_IN3 = 5;
int ctrl_IN4 = 4;
int ctrl_ENABLE2 = 2; //enable left

void setup(){
  Serial.begin(9600);
  ESPserial.begin(9600);

  pinMode(ctrl_IN1, OUTPUT);
  pinMode(ctrl_IN2, OUTPUT);
  pinMode(ctrl_IN3, OUTPUT);
  pinMode(ctrl_IN4, OUTPUT);
}

void loop(){
  //startCar();
  //delay(1000);
  //stopCar();
  //delay(1000);
  //leftTurn();
  //delay(1000);
  //rightTurn();
  //delay(1000);

  if ( ESPserial.available() ) {
    char msg = ESPserial.read();

    if (msg == 'e') {
      leftTurn();
    }

    if (msg == 'd') {
      rightTurn();
    }

    if (msg == 'f') {
      startCar();
    }

    if (msg == 'p') {
      stopCar();
    }
  }
}

void startCar(){
  digitalWrite(ctrl_IN1, HIGH); //7,6,5,4
  digitalWrite(ctrl_IN2, LOW);
  digitalWrite(ctrl_IN3, HIGH);
  digitalWrite(ctrl_IN4, LOW);
}
void stopCar(){
  digitalWrite(ctrl_IN1, LOW);
  digitalWrite(ctrl_IN2, LOW);
  digitalWrite(ctrl_IN3, LOW);
  digitalWrite(ctrl_IN4, LOW);
}
void leftTurn(){
  digitalWrite(ctrl_IN1, LOW);
  digitalWrite(ctrl_IN2, HIGH);
  digitalWrite(ctrl_IN3, HIGH);
  digitalWrite(ctrl_IN4, LOW);
}
void rightTurn(){
  digitalWrite(ctrl_IN1, HIGH);
  digitalWrite(ctrl_IN2, LOW);
  digitalWrite(ctrl_IN3, LOW);
  digitalWrite(ctrl_IN4, HIGH);
}
