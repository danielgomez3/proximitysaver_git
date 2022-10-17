// ---------------------------------------------------------------- //
// Arduino Ultrasoninc Sensor HC-SR04
// Re-writed by Arbi Abdul Jabbaar
// Using Arduino IDE 1.8.7
// Using HC-SR04 Module
// Tested on 17 September 2019
// ---------------------------------------------------------------- //

#define echoPin01 22 // attach pin D2 Arduino to pin Echo of HC-SR04
#define trigPin01 24 //attach pin D3 Arduino to pin Trig of HC-SR04
#define vibrationOne 2

#define echoPin02 26
#define trigPin02 28
#define vibrationTwo 3

// defines variables
long duration01; // variable for the duration of sound wave travel
long duration02;
int distance01; // variable for the distance measurement
int distance02;
int threshold = 280;
int strength01;
int strength02;

void setup() {
  pinMode(trigPin01, OUTPUT); // Sets the trigPin as an OUTPUT
  pinMode(trigPin02, OUTPUT);
  pinMode(echoPin01, INPUT); // Sets the echoPin as an INPUT
  pinMode(echoPin02, INPUT);
  pinMode(vibrationOne, OUTPUT);
  pinMode(vibrationTwo, OUTPUT);
  Serial.begin(9600); // // Serial Communication is starting with 9600 of baudrate speed
  Serial.println("Ultrasonic Sensor HC-SR04 Test"); // print some text in Serial Monitor
  Serial.println("with Arduino UNO R3");
}
void loop() {
  // Clears the trigPin01 condition
  digitalWrite(trigPin01, LOW);
  digitalWrite(trigPin02, LOW);
  delayMicroseconds(2);
  // Sets the trigPin HIGH (ACTIVE) for 10 microseconds
  digitalWrite(trigPin01, HIGH);
  digitalWrite(trigPin02, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin01, LOW);
  digitalWrite(trigPin02, LOW);
  // Reads the echoPin, returns the sound wave travel time in microseconds
  duration01 = pulseIn(echoPin01, HIGH);
  duration02 = pulseIn(echoPin02, HIGH);
  // Calculating the distance
  distance01 = duration01 * 0.034 / 2; // Speed of sound wave divided by 2 (go and back)
  distance02 = duration02 * 0.034 / 2;
  // Displays the distance on the Serial Monitor
  Serial.print("Distance01: ");
  Serial.print(distance01);
  Serial.println(" cm");
  Serial.print("Distance02: ");
  Serial.print(distance02);
  Serial.println(" cm");
  
  if(distance01 < 200){
    strength01 = distance01 - threshold;
    analogWrite(vibrationOne, strength01);
  }
  else{
    digitalWrite(vibrationOne, LOW);
  }
  
  if(distance02 < 200){
    strength02 = distance02 - threshold;
    analogWrite(vibrationTwo, strength02);
  }
  else{
    digitalWrite(vibrationTwo, LOW);
  }

  
}
