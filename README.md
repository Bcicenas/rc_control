# RC Control
  Arduino scripts for controlling RC car using NRF24L01+PA+LNA Wireless Module.

# Project idea
  Control RC car components using arduino. This project is for two arduino uno boards.
  - First used as transmitter.
  - Second used as receiver.
# Block diagram
![alt text](https://github.com/MrBenedict/rc_control/blob/main/rc.jpg)
# Transmitter
  1. Listens input from PC on COM4 port.
  2. Sends input data to receiver

# Input data for transmitter
  Transmitter listens for 3 bytes of data:
  - 1 byte - integer used for stearing. 1 - go left, 2 - straight, 3 - go right
  - 2 byte - integer used for going forward. 1 - nothin, 2 - go forward
  - 3 byte - integer used for reverse. 1 - nothin, 3 - go in reverse
  ```
   # example python code how to send data to arduino
   import serial
   import time
   import struct
   
   arduino = serial.Serial(port='COM4', baudrate=9600, timeout=.1)
   
   def write_read(x):
     arduino.write(struct.pack("BBB", x[0], x[1], x[2])) # sends data for arduino
     data = arduino.readline() # reads data from arduino
     return data
     
   data_to_send = [1, 2, 3]
   write_read(data_to_send)
   ```
# Receiver
  1. Listens input data from transmitter.
  2. Uses input data to control steering servo and ESC(Electronic Speed Controller).

# Used hardware
  1. Two Arduino unos.
  2. Two NRF24L01+PA+LNA Wireless Modules for transmitter and receiver.
  3. Servo motor - PowerHD HD-1160A.
  4. ESC - 105906SC - 15WP.

# Resources
- [How nRF24L01+ Wireless Module Works & Interface with Arduino](https://lastminuteengineers.com/nrf24l01-arduino-wireless-communication/)
- [Servo Motor Basics with Arduino](https://docs.arduino.cc/learn/electronics/servo-motors)
- [Arduino Brushless Motor Control Tutorial | ESC | BLDC](https://howtomechatronics.com/tutorials/arduino/arduino-brushless-motor-control-tutorial-esc-bldc/)
- [Arduino Python Communication Via USB](https://www.instructables.com/Arduino-Python-Communication-via-USB/)
