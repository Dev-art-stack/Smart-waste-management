# ♻️ Smart Waste Management System 

An intelligent IoT-based waste management system built with Arduino Uno that can **automatically segregate dry and wet waste**, **detect the rottenness of garbage**, and **monitor bin fill level** to improve waste processing and hygiene.

## 🔧 Project Overview

This project aims to address urban waste handling issues by automating the process of waste sorting and monitoring using sensors and embedded logic.

## 🚀 Features

- **🗂️ Waste Segregation**  
  - Automatically classifies waste as *dry* or *wet* using appropriate sensors.

- **🦠 Rot Level Detection**  
  - Detects how rotten the garbage is by monitoring gases (e.g., using MQ sensors), providing data for timely disposal.

- **🗑️ Bin Fill Level Detection**  
  - Ultrasonic or IR sensors track how full the bin is and alert when it reaches capacity.

- **⚡ Real-Time Monitoring** *(Optional Expansion)*  
  - Can be integrated with WiFi modules (e.g., ESP8266) for remote monitoring.

## 🛠️ Hardware Used

- Arduino Uno  
- Moisture Sensor / Capacitive Soil Sensor  
- MQ Gas Sensor (e.g., MQ-135 for air quality / rottenness detection)  
- Ultrasonic Sensor (e.g., HC-SR04) or IR Sensor for bin fill level  
- Servo Motor (for flap control/segregation)  
- LEDs / Buzzer (for alerts)  
- Power supply and jumper wires  
- Dustbin enclosure  

## 🔌 How It Works

1. Waste is deposited into the smart bin.
2. The system uses sensors to:
   - Determine if the waste is dry or wet.
   - Analyze rottenness via gas emissions.
   - Measure how full the bin is.
3. Based on sensor readings, the waste is directed to the appropriate section.
4. Visual/audible indicators can alert when the bin is full or if waste is decaying.

## Demo
https://drive.google.com/file/d/1G_d5OOKax3mAhTxVHYs6PWjbEKGWJ4qx/view?usp=sharing

