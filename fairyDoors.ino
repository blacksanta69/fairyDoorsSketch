//Fairy Doors Sketch
//by Christopher Lewis
//Creative Commons License
//Fairy Doors Sketch by Christopher Lewis
//is licensed under a Creative Commons Attribution-NonCommercial-ShareAlike 
//4.0 International License.

int pinDoor = 2;
int lastDoorVal = LOW;
long lastActivation = 0;
long timeSpan = 25*60*1000L; //Minutes*seconds*ms
void setup(){
  Serial.begin(115200);
  pinMode(pinDoor, INPUT_PULLUP);
  pinMode(13, OUTPUT);
  resetTimer();
}

void loop(){
  int doorVal = digitalRead(pinDoor);
  long timeElapsed = millis()- lastActivation;
  if (timeElapsed > timeSpan){
    resetTimer();
    delay(10);
    doorVal = HIGH;
    Serial.print("1");
    digitalWrite(13, LOW);
    delay(100);
    Serial.print("0");
    digitalWrite(13, HIGH);
  }
  /**/
  
  if (doorVal == HIGH && lastDoorVal != doorVal) {
    digitalWrite(13, LOW);
    //Door opend
    //Serial.println("Door opened");
    Serial.print("1");
    resetTimer();
  }  else if (doorVal == LOW && lastDoorVal != doorVal) {
    digitalWrite(13, HIGH);
    //Door closed
    //Serial.println("Door closed");
    Serial.print("0");
    resetTimer();
  }
  lastDoorVal = doorVal;
}

void resetTimer(){
    lastActivation = millis(); 
}
