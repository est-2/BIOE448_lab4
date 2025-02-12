const int trigPin = 11;
const int echoPin = 12;
long duration;
int distanceCm, distanceInch;
const int greenPin = 3;
const int redPin = 4;

void setup() {
  // put your setup code here, to run once:
pinMode(trigPin, OUTPUT);
pinMode(echoPin, INPUT);
Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
digitalWrite(trigPin, LOW);
delayMicroseconds(2);
digitalWrite(trigPin, HIGH);
delayMicroseconds(10);

duration = pulseIn(echoPin, HIGH);

distanceCm = duration * 0.01724;
distanceInch = duration * 0.006757;
Serial.print("Distance: ");
Serial.print(distanceCm);
Serial.print(" cm/");
Serial.print(distanceInch);
Serial.println(" in");

if (distanceCm > 20) {
  digitalWrite(greenPin, LOW);
  digitalWrite(redPin, HIGH);
}
else {
  digitalWrite(greenPin, HIGH);
  digitalWrite(redPin, LOW);
}
delay(1000);

}
