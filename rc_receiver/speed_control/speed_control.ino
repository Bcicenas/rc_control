//Include Libraries
#include <SPI.h>
#include <nRF24L01.h>
#include <RF24.h>
#include <Servo.h>
Servo servo2; // for ESC control
int escPos = 100;

void setup()
{
  servo2.attach(5,544,2400);

}

void loop()
{
  
  servo2.write(90);
//  servo2.write(180);
//  servo2.write(0);

}
