#define TRIG_PIN 9
#define ECHO_PIN 10

#define GREEN_LED 4
#define YELLOW_LED 5
#define RED_LED 7

#define BUZZER_PIN 6

// Main configurable warning threshold
const float ALERT_DISTANCE = 30.0;

// Critical distance threshold
const float CRITICAL_DISTANCE = 15.0;


float measureDistance() {

  // Send ultrasonic trigger pulse
  digitalWrite(TRIG_PIN, LOW);
  delayMicroseconds(2);

  digitalWrite(TRIG_PIN, HIGH);
  delayMicroseconds(10);

  digitalWrite(TRIG_PIN, LOW);

  // Measure echo duration
  long duration = pulseIn(ECHO_PIN, HIGH);

  // Convert time to distance in cm
  float distance = duration * 0.0343 / 2;

  return distance;
}


void setLEDs(bool green, bool yellow, bool red) {

  digitalWrite(GREEN_LED, green);
  digitalWrite(YELLOW_LED, yellow);
  digitalWrite(RED_LED, red);
}


void setup() {

  pinMode(TRIG_PIN, OUTPUT);
  pinMode(ECHO_PIN, INPUT);

  pinMode(GREEN_LED, OUTPUT);
  pinMode(YELLOW_LED, OUTPUT);
  pinMode(RED_LED, OUTPUT);

  pinMode(BUZZER_PIN, OUTPUT);

  Serial.begin(9600);

  Serial.println("-----------------------------------");
  Serial.println("  ULTRASONIC PROXIMITY ALERT SYSTEM");
  Serial.println("-----------------------------------");

  Serial.print("Warning threshold : ");
  Serial.print(ALERT_DISTANCE);
  Serial.println(" cm");

  Serial.print("Critical threshold: ");
  Serial.print(CRITICAL_DISTANCE);
  Serial.println(" cm");

  Serial.println("-----------------------------------");
}


void loop() {

  float distance = measureDistance();

  Serial.print("Distance : ");
  Serial.print(distance, 1);
  Serial.println(" cm");


  // =========================
  // SAFE STATE
  // =========================

  if (distance > ALERT_DISTANCE) {

    setLEDs(HIGH, LOW, LOW);

    noTone(BUZZER_PIN);

    Serial.println("Status   : SAFE");
  }


  // =========================
  // WARNING STATE
  // =========================

  else if (distance > CRITICAL_DISTANCE) {

    setLEDs(LOW, HIGH, LOW);

    Serial.println("Status   : WARNING");

    // Slow intermittent beep
    tone(BUZZER_PIN, 1000);
    delay(100);

    noTone(BUZZER_PIN);
    delay(400);
  }


  // =========================
  // CRITICAL STATE
  // =========================

  else {

    setLEDs(LOW, LOW, HIGH);

    Serial.println("Status   : CRITICAL");

    // Fast warning tone
    tone(BUZZER_PIN, 1500);
    delay(150);

    noTone(BUZZER_PIN);
    delay(100);
  }

  Serial.println("-----------------------------------");

  delay(100);
}
