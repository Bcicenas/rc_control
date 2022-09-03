//Include Libraries
#include <SPI.h>
#include <nRF24L01.h>
#include <RF24.h>
#include <Servo.h>
//create an RF24 object
RF24 radio(9, 8);  // CE, CSN
Servo servo1; // Servo PowerHD HD-1160A
Servo servo2; // for ESC control
//address through which two modules communicate.
const byte address[6] = "00001";
int startingAngle = 85;
int currentAngle = startingAngle;    // variable to store the servo position
int rightAngle = 180;
int leftAngle = 0;
int x = 0;
int y = 0;
int z = 0;
int escPos = 90;

void setup()
{
  while (!Serial);
    Serial.begin(9600);
  
  radio.begin();
  
  //set the address
  radio.openReadingPipe(0, address);
  
  //Set module as receiver
  radio.startListening();
  servo1.attach(6, 800, 2200);
  servo2.attach(5,800,2200);
}

void loop()
{
  
  //Read the data if available in buffer
  if (radio.available())
  {
    char text[3] = {0};
    radio.read(&text, sizeof(text));
    x = text[0] - '0';
    y = text[1] - '0';
    z = text[2] - '0';
    servo1.write(currentAngle);
    servo2.write(escPos);
    Serial.println(text);
    if (x == 1) currentAngle = leftAngle;
    if (x == 3) currentAngle = rightAngle;
    if (x == 2) currentAngle = startingAngle;

    if (y == 1 && z == 1) escPos = 90;
    if (y == 2) escPos = 60;
    if (z == 2) escPos = 120;
  }

}
