# 🚗 Arduino Ultrasonic Parking Sensor

A simple, beginner-friendly Arduino project that mimics a real-world car parking sensor. It uses an ultrasonic sensor to measure distance and provides escalating visual and audio feedback using three LEDs (green, yellow, red) and an active buzzer.

This project is an excellent introduction to using sensors, processing real-time data, and controlling multiple outputs based on conditional logic.

## 🚀 In Action

This project provides real-time feedback based on an object's proximity. The system has three distinct states:

### 🟢 State 1: Safe
* **Trigger:** Object is > 50cm away.
* **Feedback:** The **Green LED** is on, indicating the path is clear.
* **Sound:** None.

![green](https://github.com/user-attachments/assets/eec02da1-8f18-4020-be85-fe0bcd1025b1)

### 🟡 State 2: Warning
* **Trigger:** Object is between 20cm and 50cm.
* **Feedback:** The **Yellow LED** turns on.
* **Sound:** The buzzer emits a **slow, "warning" beep**.

![yellow](https://github.com/user-attachments/assets/e25cbf93-b703-4b18-a5d3-eaff3bb7c7cd)


### 🔴 State 3: Danger
* **Trigger:** Object is < 20cm away.
* **Feedback:** The **Red LED** turns on.
* **Sound:** The buzzer emits a **fast, "danger" beep** to signal an immediate stop.

![red](https://github.com/user-attachments/assets/d471e523-da49-4dbb-bcc2-76191fba8869)

## ✨ Features

* **Real-time Distance Measurement:** Uses the HC-SR04 ultrasonic sensor to get live distance readings.
* **Visual Feedback System:** A simple "traffic light" (Green, Yellow, Red) to provide at-a-glance status.
* **Audio Feedback System:** An active buzzer that changes its beeping pattern based on the urgency level.

## 🛠️ Components Used

* 1x Arduino UNO R3
* 1x HC-SR04 Ultrasonic Sensor
* 1x Active Buzzer
* 1x Red LED
* 1x Yellow LED
* 1x Green LED
* 3x 220Ω Resistors (for the LEDs)
* 1x Breadboard
* Jumper Wires
* 1x 9V Battery & Snap-on Connector (for portable power)

## 🧠 How It Works

1.  The Arduino triggers the sensor's **`Trig`** pin, sending out a short ultrasonic pulse.
2.  The Arduino listens on the **`Echo`** pin for the pulse to bounce off an object and return.
3.  The time taken for this round trip (`duration`) is measured.
4.  The `duration` is converted to a `distance` in centimeters using the formula: `distance = (duration * 0.034) / 2`.
5.  A series of `if-else` statements checks the `distance` variable and activates the correct LED and buzzer pattern corresponding to the "Safe", "Warning", or "Danger" state.

## 🔌 How to Use

1.  Assemble the circuit (a wiring diagram can be added here).
2.  Upload the `.ino` code file from this repository to your Arduino board using the Arduino IDE.
3.  Power the board via USB or the 9V battery.
4.  Move your hand or an object towards the sensor to see the feedback change!

## Here is a video demonstration!

https://github.com/user-attachments/assets/c54991fa-6a5f-4cc5-9e54-6bdcc9cd37ad

