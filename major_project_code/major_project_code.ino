const int sensorDigital = 3;
const int LED = 6;
const int blinkPin = 2;
const int motorPin = 13;
const int buzzerPin = 12;
long lastBlinkTime;
void setup() {
  pinMode(motorPin, OUTPUT);
  pinMode(buzzerPin, OUTPUT);
  pinMode(blinkPin, INPUT);
  pinMode(sensorDigital, INPUT);
  pinMode(LED, OUTPUT);
  digitalWrite(LED, LOW); // Ensure LED is initially OFF
  digitalWrite(motorPin, HIGH);
}
void loop() {
  int digital = digitalRead(sensorDigital);
  if (digital == 0) {
    digitalWrite(LED, HIGH);    
  }
  if (digital == 1) {
    digitalWrite(LED, LOW);  
  }
  if (!digitalRead(blinkPin)) {
    lastBlinkTime = millis(); // Reset the last blink time
    digitalWrite(buzzerPin, LOW);
    digitalWrite(motorPin, LOW);
  }
  if (TimeDelay() >= 3 ) digitalWrite(buzzerPin, HIGH);
  if (TimeDelay() >= 4 ) digitalWrite(motorPin, HIGH);
}
int TimeDelay() {
  long t = millis() - lastBlinkTime;
  t = t / 1000;
  return t;
}