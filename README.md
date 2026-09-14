# Ultrasonic Proximity Alert System

A real-time, configurable proximity detection and alert system developed using an Arduino Uno and HC-SR04 ultrasonic sensor.

## 📌 Overview

This project detects objects in front of an ultrasonic sensor and determines their proximity based on configurable distance thresholds.

The Arduino continuously measures the distance of an object using the HC-SR04 ultrasonic sensor. Based on the measured distance, the system classifies the object into one of three states:

- 🟢 SAFE
- 🟡 WARNING
- 🔴 CRITICAL

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
- Three-level proximity classification
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

## 🧠 Working Principle

The HC-SR04 ultrasonic sensor emits an ultrasonic pulse and measures the time taken for the reflected pulse to return.

The Arduino uses this time to calculate the distance between the sensor and the detected object.

The distance is calculated using:

**Distance = (Time × Speed of Sound) / 2**

The division by 2 accounts for the ultrasonic wave travelling from the sensor to the object and back.

The calculated distance is then compared with predefined thresholds.

---

## 🚦 Detection States

| Distance | Status | LED | Buzzer |
|---|---|---|---|
| > 30 cm | 🟢 SAFE | Green | OFF |
| 15–30 cm | 🟡 WARNING | Yellow | Intermittent |
| ≤ 15 cm | 🔴 CRITICAL | Red | Rapid |

The main warning threshold can be modified directly in the Arduino code:

```cpp
const float ALERT_DISTANCE = 30.0;
