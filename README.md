# Autonomous Obstacle Detector Bot

## Demonstration

To see the Autonomous Obstacle Detector Bot in action, please watch the following demonstration video:

[![Autonomous Obstacle Detector Bot Demo](https://img.youtube.com/vi/0GG2nRpJhfU/0.jpg)](https://www.youtube.com/watch?v=0GG2nRpJhfU)

Click the image above or [this link](https://youtu.be/0GG2nRpJhfU) to watch the video.

## Overview

This project involves creating an autonomous robot capable of detecting and avoiding obstacles. The robot uses an Arduino board, a servo motor, and an ultrasonic sensor. When the bot detects an obstacle at a distance of 15 cm, it stops and uses the ultrasonic sensor mounted on the servo motor to measure the distances on its left and right sides. Based on these measurements, it turns in the direction where the distance is greater than 15 cm and proceeds forward.

## Components

- **Arduino Board**
- **Servo Motor**
- **Ultrasonic Sensor**
- **Motors**
- **Motor Driver (L293D)**
- **Wires**
- **Tires**
- **12V Battery**

## How It Works

1. **Obstacle Detection**: The ultrasonic sensor continuously measures the distance to the nearest object in front of the robot.
2. **Stopping Condition**: When an obstacle is detected at a distance of 15 cm or less, the robot stops.
3. **Distance Measurement**: The servo motor rotates the ultrasonic sensor to check distances to the left and right of the robot.
4. **Decision Making**: The robot compares the distances measured on both sides. It turns in the direction where the distance is greater than 15 cm.
5. **Proceeding Forward**: After turning, the robot moves forward until it encounters another obstacle.

## Steps to Build the Autonomous Obstacle Detector Bot

1. **Assemble the Hardware**:
   - Connect the ultrasonic sensor to the servo motor and mount it on the robot.
   - Connect the motors to the motor driver (L293D) and then to the Arduino board.
   - Wire the 12V battery to the Arduino and motor driver for power.
   - Ensure all connections are secure and the components are properly powered.

2. **Set Up the Software**:
   - Install the Arduino IDE on your computer.
   - Write the Arduino code to read the ultrasonic sensor data, control the servo motor, and manage the motors.
   - Upload the Arduino code to the Arduino board.

3. **Calibrate the Sensor**:
   - Ensure the ultrasonic sensor and servo motor are properly calibrated to provide accurate distance measurements.

4. **Test and Adjust**:
   - Run the program and observe the robot's behavior.
   - Make necessary adjustments to the code to improve obstacle detection and avoidance performance.

## Conclusion

This project demonstrates the integration of sensors, microcontrollers, and motor control to create an autonomous robot capable of obstacle detection and avoidance. It's an excellent way to learn about robotics, sensor data processing, and decision-making algorithms. Enjoy building and experimenting with your Autonomous Obstacle Detector Bot!
