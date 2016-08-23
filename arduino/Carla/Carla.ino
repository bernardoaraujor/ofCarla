#define portSensor1 9
#define portSensor2 11
#define portSensor3 50

bool sensores[3];

void setup() {
  Serial.begin(9600);
  pinMode(portSensor1, INPUT);
  pinMode(portSensor2, INPUT);
  pinMode(portSensor3, INPUT);
}

void loop() {
  sensores[0] = digitalRead(portSensor1);
  sensores[1] = digitalRead(portSensor2);
  sensores[2] = digitalRead(portSensor3);

  //Serial.print(sensores[0]); 

 if (Serial.available()){
    Serial.read();
      
    if (sensores[0]){
      Serial.print(1);
    }else{
      Serial.print(0);
    }
      
    if (sensores[1]){
      Serial.print(1);
    }else{
      Serial.print(0);
    }  

    if (sensores[2]){
      Serial.print(1);
    }else{
      Serial.print(0);
    }  
  } 
}
