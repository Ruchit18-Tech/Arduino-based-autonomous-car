#include <HCSR04.h>

float dist;
UltraSonicDistanceSensor ultrasonic(A0,A1);

int right_Forward_Pin = 2;
int right_Backward_Pin = 3;
int left_Forward_Pin = 4;
int left_Backward_Pin = 7;

void setup() {
    pinMode(right_Backward_Pin, OUTPUT);
    pinMode(right_Forward_Pin, OUTPUT);
    pinMode(left_Backward_Pin, OUTPUT);
    pinMode(left_Forward_Pin, OUTPUT);
    Serial.begin(9600);
}

void loop() {

  dist = ultrasonic.measureDistanceCm();
  Serial.println(dist);

  if (dist > -1 && dist < 25) {
    stop();
    delay(1500);
    backward();
    delay(500);
    stop();
    delay(1500);
    
    if(random(0, 2) == 0) {
      left();
    } else {
      right();
    }
    delay(500);
    stop();
    delay(1000);
  } else {
    forward();
  }


}

void stop() {
  digitalWrite(right_Backward_Pin, LOW);
  digitalWrite(right_Forward_Pin, LOW);
  digitalWrite(left_Backward_Pin, LOW);
  digitalWrite(left_Forward_Pin, LOW);  
}

void left() {
  digitalWrite(right_Backward_Pin, LOW);
  digitalWrite(right_Forward_Pin, HIGH);
  digitalWrite(left_Backward_Pin, LOW);
  digitalWrite(left_Forward_Pin, LOW);
}

void right() {
  digitalWrite(right_Forward_Pin, LOW);
  digitalWrite(right_Backward_Pin, LOW);
  digitalWrite(left_Forward_Pin, HIGH);
  digitalWrite(left_Backward_Pin, LOW);
}

void backward() {
  digitalWrite(left_Forward_Pin, LOW);
  digitalWrite(left_Backward_Pin, HIGH);
  digitalWrite(right_Forward_Pin, LOW);
  digitalWrite(right_Backward_Pin, HIGH);
}

void forward() {
  digitalWrite(right_Forward_Pin, HIGH);
  digitalWrite(right_Backward_Pin, LOW);
  digitalWrite(left_Forward_Pin, HIGH);
  digitalWrite(left_Backward_Pin, LOW);
}