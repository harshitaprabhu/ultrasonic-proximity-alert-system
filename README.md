# Ultrasonic Proximity Alert System

A real-time, configurable proximity detection and alert system developed using an Arduino Uno and HC-SR04 ultrasonic sensor.

## 📌 Overview

This project detects objects in front of an ultrasonic sensor and determines their proximity based on configurable distance thresholds.

The Arduino continuously measures the distance of an object using the HC-SR04 ultrasonic sensor. Based on the measured distance, the system classifies the object into one of four states:

- 🟢 SAFE
- 🟡 WARNING
- 🔴 CRITICAL
- ⚪ OUT OF RANGE

Each state is indicated using a dedicated LED, while an audible buzzer provides an additional warning. The measured distance and current system status are also displayed through the Serial Monitor.

The project is currently implemented and tested as a simulation using Wokwi.

---

## 🎯 Objectives

- Measure object distance using an ultrasonic sensor.
- Implement real-time proximity detection.
- Create configurable distance thresholds.
- Provide visual alerts using LEDs.
- Provide audible alerts using a buzzer.
- Display real-time distance and system status through the Serial Monitor.
- Develop and test the system using an online simulation environment.

---

## ⚙️ Features

- Real-time distance measurement
- Configurable warning threshold
- Four-level proximity classification
- Green, yellow and red LED indicators
- Distance-dependent buzzer alerts
- Serial Monitor output
- Arduino-based control logic
- Wokwi simulation

---

## 🔌 Components Used

| Component | Quantity |
|---|---:|
| Arduino Uno | 1 |
| HC-SR04 Ultrasonic Sensor | 1 |
| Green LED | 1 |
| Yellow LED | 1 |
| Red LED | 1 |
| 220 Ω Resistor | 3 |
| Buzzer | 1 |

---

## 🔗 Pin Connections

| Component | Arduino Pin |
|---|---|
| HC-SR04 TRIG | D9 |
| HC-SR04 ECHO | D10 |
| Green LED | D4 |
| Yellow LED | D5 |
| Buzzer | D6 |
| Red LED | D7 |

---

## ⚙️ Working Principle

The HC-SR04 ultrasonic sensor sends a short ultrasonic pulse through its TRIG pin. When the pulse encounters an object, it is reflected back toward the sensor and received through the ECHO pin.

The Arduino measures the time taken for the echo to return and calculates the distance using:

```text
Distance = (Time × Speed of Sound) / 2
```

The division by 2 is required because the ultrasonic wave travels from the sensor to the object and back.

The measured distance is then compared with predefined thresholds:

1. If the distance is greater than 30 cm, the system enters the SAFE state.
2. If the distance is between 15 cm and 30 cm, the system enters the WARNING state.
3. If the distance is 15 cm or less, the system enters the CRITICAL state.
4. If no echo is received or the reading is beyond the sensor's reliable range, the system reports NO OBJECT DETECTED.

The current warning and critical thresholds are configurable in the Arduino code.

---

## 🚦 Detection States

The system classifies the detected object into four states based on its distance from the ultrasonic sensor.

| Distance / Condition | LED | Buzzer | Status |
|---|---|---|---|
| > 30 cm and ≤ 400 cm | 🟢 Green | OFF | SAFE |
| 15–30 cm | 🟡 Yellow | Slow intermittent beep | WARNING |
| ≤ 15 cm | 🔴 Red | Fast beep | CRITICAL |
| No echo / out of range | All OFF | OFF | NO OBJECT DETECTED |

The main warning threshold can be modified directly in the Arduino code:

```cpp
const float ALERT_DISTANCE = 30.0;
```

The critical threshold can also be modified:

```cpp
const float CRITICAL_DISTANCE = 15.0;
```

The system also handles situations where the ultrasonic sensor receives no echo. Instead of incorrectly interpreting a missing echo as zero distance, the system reports **NO OBJECT DETECTED**.

---

## 💻 Serial Monitor

The system continuously reports the measured distance and current status through the Serial Monitor.

### Example Output

```text
-----------------------------------
Distance : 48.2 cm
Status   : SAFE
-----------------------------------

Distance : 19.4 cm
Status   : WARNING
-----------------------------------

Distance : 7.3 cm
Status   : CRITICAL
-----------------------------------

Distance : OUT OF RANGE
Status   : NO OBJECT DETECTED
-----------------------------------
```
---

## 🧪 Simulation Results

The system was tested under different object-distance conditions using the Wokwi simulation environment.

### Circuit

![Circuit](images/Alarm%20Circuit.png)

### 🟢 Safe State

Object detected at approximately 48 cm.
The green LED remains ON, indicating that the object is outside the warning threshold.

![Safe State](images/Safe%2048%20cm.png)

### 🟡 Warning State

Object detected at approximately 19 cm.
The yellow LED turns ON and the buzzer produces intermittent warning beeps.

![Warning State](images/Warning%2019%20cm.png)

### 🔴 Critical State

Object detected at approximately 7 cm.
The red LED turns ON and the buzzer produces rapid warning beeps.

![Critical State](images/Critical%207%20cm.png)

### ⚪ No Object Detected / Out of Range

When the sensor does not receive a valid echo, the system does not interpret the reading as zero distance. Instead, it reports **NO OBJECT DETECTED**.
All LEDs and the buzzer remain OFF.

![Out of Range](images/Out%20of%20range.png)

---

## ▶️ Simulation

The project can be simulated online using Wokwi.

**[Open Wokwi Simulation](https://wokwi.com/projects/475127192526231553)**

The simulated sensor distance can be changed to observe the system transition between SAFE, WARNING, CRITICAL, and OUT OF RANGE states.

---

## 📂 Project Structure

```text
ultrasonic-proximity-alert-system/
│
├── README.md
├── proximity_alert.ino
├── diagram.json
│
└── images/
    ├── Alarm Circuit.png
    ├── Safe 48 cm.png
    ├── Warning 19 cm.png
    ├── Critical 7 cm.png
    └── Out of range.png
```
---

## 🚀 Future Improvements

Possible extensions to the project include:

- OLED/LCD display for standalone distance visualization
- Adjustable threshold using physical buttons or a potentiometer
- Wireless transmission of proximity alerts
- Integration with a robotic obstacle-avoidance system
- Multiple ultrasonic sensors for wider detection coverage

---

## 🛠️ Technologies Used

- Arduino Uno
- C/C++
- HC-SR04 Ultrasonic Sensor
- Wokwi
- GitHub

---

## 👩‍💻 Author

**Harshita Prabhu Thiagarajan**

Student Project | Embedded Systems & Robotics

