
/*
  Arduino Automatic Hand Sanitizer Dispenser

  Controller : Arduino Uno
  Sensor     : HC-SR04 Ultrasonic Sensor
  Actuator   : 5V Relay Module + DC Pump

  Developed by: Rajan Robotics
  Vision to Reality
*/

#define TRIG_PIN 9
#define ECHO_PIN 10
#define RELAY_PIN 7

// Most relay modules are active LOW
#define RELAY_ON LOW
#define RELAY_OFF HIGH

const float DETECTION_DISTANCE = 10.0;

const unsigned long PUMP_TIME = 700;
const unsigned long RELEASE_TIME = 500;

bool pumpRunning = false;
bool readyToDispense = true;

unsigned long pumpStartTime = 0;
unsigned long handRemovedTime = 0;

float measureDistance() {

  digitalWrite(TRIG_PIN, LOW);
  delayMicroseconds(2);

  digitalWrite(TRIG_PIN, HIGH);
  delayMicroseconds(10);

  digitalWrite(TRIG_PIN, LOW);

  unsigned long duration =
      pulseIn(ECHO_PIN, HIGH, 30000UL);

  if (duration == 0) {
    return -1;
  }

  return (duration * 0.0343) / 2.0;
}

void startPump() {

  digitalWrite(RELAY_PIN, RELAY_ON);

  pumpRunning = true;
  readyToDispense = false;

  pumpStartTime = millis();

  Serial.println("Hand Detected!");
  Serial.println("Sanitizer Dispensing...");
}

void stopPump() {

  digitalWrite(RELAY_PIN, RELAY_OFF);

  pumpRunning = false;

  Serial.println("Dispensing Completed");
}

void setup() {

  pinMode(TRIG_PIN, OUTPUT);
  pinMode(ECHO_PIN, INPUT);
  pinMode(RELAY_PIN, OUTPUT);

  digitalWrite(TRIG_PIN, LOW);
  digitalWrite(RELAY_PIN, RELAY_OFF);

  Serial.begin(9600);

  Serial.println("RAJAN ROBOTICS");
  Serial.println("Automatic Hand Sanitizer Dispenser");
  Serial.println("System Ready!");
}

void loop() {

  float distance = measureDistance();

  // Stop pump after the dispensing duration
  if (pumpRunning &&
      millis() - pumpStartTime >= PUMP_TIME) {

    stopPump();
  }

  // Check for hand detection
  if (distance > 0 &&
      distance <= DETECTION_DISTANCE) {

    handRemovedTime = 0;

    if (readyToDispense && !pumpRunning) {
      startPump();
    }
  }

  // Rearm only after the hand is removed
  else if (distance > DETECTION_DISTANCE) {

    if (handRemovedTime == 0) {
      handRemovedTime = millis();
    }

    if (!pumpRunning &&
        !readyToDispense &&
        millis() - handRemovedTime >= RELEASE_TIME) {

      readyToDispense = true;
      Serial.println("Ready for Next Dispensing");
    }
  }

  delay(100);
}
