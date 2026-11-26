# 🧴 Arduino Automatic Hand Sanitizer Dispenser

**Developed by Rajan Robotics**  
*Vision to Reality*

## 📌 Project Overview

The Arduino Automatic Hand Sanitizer Dispenser is a touchless dispensing system designed to dispense sanitizer when a hand is detected near the outlet.

An HC-SR04 ultrasonic sensor detects the presence of a hand. Arduino processes the measured distance and activates a relay module to operate a small DC pump for a predefined duration.

This project demonstrates ultrasonic sensor interfacing, relay control and basic automation.

## 🎯 Objectives

- Detect hand presence without physical contact.
- Interface an HC-SR04 sensor with Arduino Uno.
- Control a DC pump using a relay module.
- Dispense sanitizer automatically.
- Understand sensor-based automation.

## 🧰 Components Required

| S.No. | Component | Quantity |
|---|---|---:|
| 1 | Arduino Uno | 1 |
| 2 | HC-SR04 Ultrasonic Sensor | 1 |
| 3 | 5V Relay Module | 1 |
| 4 | Mini DC Pump (compatible with sanitizer) | 1 |
| 5 | Sanitizer Container | 1 |
| 6 | External DC Power Supply | 1 |
| 7 | Connecting Tubes | As required |
| 8 | Jumper Wires | As required |

## 🔌 Circuit Connections

### HC-SR04 – Arduino Uno

| HC-SR04 Pin | Arduino Pin |
|---|---|
| VCC | 5V |
| TRIG | D9 |
| ECHO | D10 |
| GND | GND |

### Relay Module – Arduino Uno

| Relay Pin | Arduino Pin |
|---|---|
| VCC | 5V |
| GND | GND |
| IN | D7 |

### DC Pump – External Supply

| Pump Connection | Connection |
|---|---|
| Supply Positive | Relay COM |
| Relay NO | Pump Positive |
| Pump Negative | Supply Negative |

Use a relay module rated for the pump's voltage and current. The pump supply must be suitable for the pump.

## ⚙️ Working Principle

1. The HC-SR04 sensor continuously measures the distance in front of the dispenser.
2. When a hand is detected within the configured distance, Arduino identifies the hand.
3. Arduino activates the relay module.
4. The relay switches ON the DC pump for a short duration.
5. Sanitizer is dispensed through the outlet.
6. The pump switches OFF automatically.
7. The system waits for the hand to be removed before accepting another dispensing request.

## 💻 Software Requirements

- Arduino IDE
- Arduino Uno board package
- USB cable

No external Arduino library is required.

## ✨ Features

- Touchless sanitizer dispensing.
- Ultrasonic hand detection.
- Automatic pump control.
- Adjustable detection distance.
- Timed dispensing operation.
- Simple and low-cost educational design.

## 🧪 Testing Procedure

1. Connect the ultrasonic sensor and relay module.
2. Connect the DC pump through the relay contacts.
3. Upload the Arduino program.
4. Power the Arduino and pump using suitable supplies.
5. Place your hand near the ultrasonic sensor.
6. Observe the pump activating briefly.
7. Remove your hand and test again.

## 🏠 Applications

- Touchless sanitizer dispensers.
- Schools and colleges.
- Laboratories.
- Offices.
- Public hygiene demonstrations.
- Robotics and automation projects.

## 🚀 Future Improvements

- Add an LCD to display dispensing status.
- Add an IR sensor for hand detection.
- Add a sanitizer-level monitoring sensor.
- Add an ESP32 for usage monitoring.
- Add an adjustable dispensing duration.

## ⚠️ Safety Note

This is an educational prototype, not a certified hygiene device. Use a pump and tubing compatible with the sanitizer liquid. Keep the Arduino and electrical connections away from liquid spills. Never operate the pump without suitable protection and supervision.

## 📁 Repository Structure

```text
Arduino-Automatic-Hand-Sanitizer-Dispenser/
│
├── Code/
│   └── Automatic_Hand_Sanitizer.ino
│
├── Circuit/
│   └── circuit_diagram.png
│
├── Images/
│   └── working_prototype.jpg
│
├── Videos/
│   └── demo_video_link.txt
│
├── README.md
└── LICENSE
```

## 👨‍💻 Developed By

**Rajan Robotics**  
*Vision to Reality*

Government Recognised Enterprise  
UDYAM Registration: UDYAM-TN-27-0023934

**Learn | Build | Innovate | Inspire**

---

⭐ If you find this project useful, consider starring this repository!
