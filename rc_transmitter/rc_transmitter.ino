//Include Libraries
#include <SPI.h>
#include <nRF24L01.h>
#include <RF24.h>

//create an RF24 object
RF24 radio(9, 8);  // CE, CSN

int positions[2]; // first steering value, second motors value
//address through which two modules communicate.
const byte address[6] = "00001";
char text[3];
void setup()
{
  while(!Serial);
    Serial.begin(9600);
    
  radio.begin();
  
  //set the address
  radio.openWritingPipe(address);
  
  //Set module as transmitter
  radio.stopListening();
  Serial.begin(9600);
  Serial.setTimeout(1);
 
}
void loop()
{
  if (Serial.available() > 2){
      positions[0] = Serial.read();
  //  while(!Serial.available());
    positions[1] = Serial.read();
    positions[2] = Serial.read();
    text[0] = positions[0] + 48;
    text[1] = positions[1] + 48;
    text[2] = positions[2] + 48; 
  }
  //Send message to receiver
  radio.write(&text, sizeof(text));
  delay(10);
}
