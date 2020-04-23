#include <stdlib.h>

const int senPin1 = 7;
const int senPin2 = 8;
const int senPin3 = 9;
const int senPin4 = 10;
const int senPin5 = 11;
const int senPin6 = 12;
const int pumpPin = 13;
char buf[128], result[64];
char * serial = "202002";

//--------------------------------------------------------------

void setup() {  
  Serial.begin(9600);
  pinMode(senPin1, OUTPUT);
  pinMode(senPin2, OUTPUT);
  pinMode(senPin3, OUTPUT);
  pinMode(senPin4, OUTPUT);
  pinMode(senPin5, OUTPUT);
  pinMode(senPin6, OUTPUT);
  pinMode(pumpPin, OUTPUT);
  digitalWrite(senPin1, HIGH);
  digitalWrite(senPin2, HIGH);
  digitalWrite(senPin3, HIGH);
  digitalWrite(senPin4, HIGH);
  digitalWrite(senPin5, HIGH);
  digitalWrite(senPin6, HIGH);
//  digitalWrite(pumpPin, HIGH);
}
void loop() {
  
  memset(result, '\0', sizeof(result));
  strcat(result, serial);
    
  for(int i=0; i<6; i++){        //result로 합치기
    sprintf(buf,"%d",analogRead(i)+1);
    strcat(result, " ");
    strcat(result, buf);
  }
  strcat(result, ".");
  
  Serial.println(result);
  delay(10000);
}
