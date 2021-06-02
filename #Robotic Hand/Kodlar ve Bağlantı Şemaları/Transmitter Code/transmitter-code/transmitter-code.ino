//Transmitter Code (Glove) - Alper Burak PUSAR

#include <SPI.h>                      //the communication interface with the modem
#include "RF24.h"                     //the library which helps us to control the radio modem

int msg[5]; //Total number of data to be sent (data package)

//define the flex sensor input pins
int flex_5 = A5;
int flex_4 = A4;
int flex_3 = A3;
int flex_2 = A2;
int flex_1 = A1;

//define variables for flex sensor values
int flex_5_val;
int flex_4_val;
int flex_3_val;
int flex_2_val;
int flex_1_val;

RF24 radio(9,10);                     //9 and 10 are a digital pin numbers to which signals CE and CSN are connected.
                                      
const uint64_t pipe = 0xE8E8F0F0E1LL; //the address of the modem, that will receive data from Arduino.


void setup(void){
  Serial.begin(9600);
  radio.begin();                      //it activates the modem.
  radio.openWritingPipe(pipe);        //sets the address of the receiver to which the program will send data.
}

void loop(void){

  flex_5_val = analogRead(flex_5); 
  flex_5_val = map(flex_5_val, 720, 840, 0, 180);
  
  flex_4_val = analogRead(flex_4);
  flex_4_val = map(flex_4_val, 750, 835, 0, 180);
 
  flex_3_val = analogRead(flex_3);
  flex_3_val = map(flex_3_val, 730, 810, 0, 180);
 
  flex_2_val = analogRead(flex_2);
  flex_2_val = map(flex_2_val, 830, 700, 0, 270);
  
  flex_1_val = analogRead(flex_1);
  flex_1_val = map(flex_1_val, 820, 800, 50, 110);
  
  msg[0] = flex_5_val;
  msg[1] = flex_4_val;
  msg[2] = flex_3_val;
  msg[3] = flex_2_val;
  msg[4] = flex_1_val;
  radio.write(msg, sizeof(msg));
}
