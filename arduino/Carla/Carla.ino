#define trigPin1 8
#define echoPin1 9

#define trigPin2 10
#define echoPin2 11

#define trigPin3 52
#define echoPin3 51

int duration, distance, Sensor1,BackSensor,Sensor2,Sensor3;
char buf[6];

void setup() {
  Serial.begin(9600);
  pinMode(trigPin1, OUTPUT);
  pinMode(echoPin1, INPUT);
  pinMode(trigPin2, OUTPUT);
  pinMode(echoPin2, INPUT);
}

void loop() {
  SonarSensor(trigPin1, echoPin1);
  Sensor1 = distance;
  SonarSensor(trigPin2, echoPin2);
  Sensor2 = distance;
  SonarSensor(trigPin3, echoPin3);
  Sensor3 = distance;

  buf[0] = Sensor1;
  buf[2] = Sensor2;
  buf[4] = Sensor3;
  if (Serial.available()){
    Serial.read();
    Serial.write(buf, 6);
  }
}

void SonarSensor(int trigPin,int echoPin)
{
digitalWrite(trigPin, LOW);
delayMicroseconds(2);
digitalWrite(trigPin, HIGH);
delayMicroseconds(10);
digitalWrite(trigPin, LOW);
duration = pulseIn(echoPin, HIGH);
distance = (duration/2) / 29.1;

}
