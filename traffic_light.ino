// Traffic Light Controller matching 555 Timer Schematic

const int redPin = 8;
const int yellowPin = 9;
const int greenPin = 10;

// Calculated delay durations from RC values in schematic
const unsigned long redYellowDuration = 6900; // 6.9s (100k + 100uF)
const unsigned long greenDuration     = 3300; // 3.3s (47k + 100uF)

void setup() {
  pinMode(redPin, OUTPUT);
  pinMode(yellowPin, OUTPUT);
  pinMode(greenPin, OUTPUT);
}

void loop() {
  // --- Phase 1: First 555 Timer ON (Red & Yellow Active) ---
  digitalWrite(redPin, HIGH);
  digitalWrite(yellowPin, HIGH);
  digitalWrite(greenPin, LOW);
  delay(redYellowDuration);

  // --- Phase 2: Second 555 Timer Triggered (Green Active) ---
  digitalWrite(redPin, LOW);
  digitalWrite(yellowPin, LOW);
  digitalWrite(greenPin, HIGH);
  delay(greenDuration);
}