# rc_control
  Arduino scripts for controlling rc car using NRF24L01+PA+LNA Wireless Module.

# Project idea
  Control rc car components using arduino. This project is for two arduino uno boards.
  
    First used as transmitter.
    Second used as receiver.
# Block diagram
![alt text](https://github.com/MrBenedict/rc_control/blob/main/rc.jpg)
# Transmitter
  1. Listens input from pc on COM4 port.
  2. Sends input data to receiver

# Input data for transmitter
  Transmitter listens for 3 bytes of data:

    1 byte - integer used for stearing. 1 - go left, 2 - straight, 3 - go right
    2 byte - integer used for going forward. 1 - nothin, 2 - go forward
    3 byte - integer used for reverse. 1 - nothin, 3 - go in reverse
  
# Receiver
  1. Listens input data from transmitter.
  2. Uses input data to control steering servo and ESC(Electronic Speed Controller).

# Used hardware
  1. Two Arduino unos.
  2. Two NRF24L01+PA+LNA Wireless Modules for transmitter and receiver.
  3. Servo motor - PowerHD HD-1160A.
  4. ESC - 105906SC - 15WP.

# Resources
[How nRF24L01+ Wireless Module Works & Interface with Arduino](https://lastminuteengineers.com/nrf24l01-arduino-wireless-communication/)
[Servo Motor Basics with Arduino](https://docs.arduino.cc/learn/electronics/servo-motors)
[Arduino Brushless Motor Control Tutorial | ESC | BLDC](https://howtomechatronics.com/tutorials/arduino/arduino-brushless-motor-control-tutorial-esc-bldc/)
[Arduino Python Communication Via USB](https://www.instructables.com/Arduino-Python-Communication-via-USB/)
