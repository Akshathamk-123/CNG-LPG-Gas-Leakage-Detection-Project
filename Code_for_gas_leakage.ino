const int gasSensorPin = A0; // Gas sensor input pin
const int redLedPin = 2;     // Red LED pin
const int greenLedPin = 3;   // Green LED pin
const int buzzerPin = 4;     // Buzzer pin

const int MAX_THRESHOLD = 400; // Gas leakage threshold value

int sensorValue; // Variable to store sensor reading

void setup() {
  Serial.begin(9600);
  pinMode(gasSensorPin, INPUT);
  pinMode(redLedPin, OUTPUT);
  pinMode(greenLedPin, OUTPUT);
  pinMode(buzzerPin, OUTPUT);
}

void loop() {
  sensorValue = analogRead(gasSensorPin); // Read the gas sensor value

  if (sensorValue >= MAX_THRESHOLD) { // Check if the sensor value exceeds the threshold
    digitalWrite(redLedPin, HIGH);    // Turn on the red LED
    digitalWrite(buzzerPin, HIGH);    // Turn on the buzzer
    digitalWrite(greenLedPin, LOW);   // Turn off the green LED
    Serial.println("GAS LEAKING");    // Print gas leaking warning
  } else {
    digitalWrite(redLedPin, LOW);     // Turn off the red LED
    digitalWrite(buzzerPin, LOW);     // Turn off the buzzer
    digitalWrite(greenLedPin, HIGH);  // Turn on the green LED
    Serial.println("NORMAL");         // Print normal status
  }

  delay(1000); // Delay for a second before the next reading
}
