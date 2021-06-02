#include <SPI.h>
#include <nRF24L01.h>
#include <RF24.h>
RF24 radio(7, 8); //radio(CE, CS);
const uint64_t kod = 0xE8E8F0F0E1LL;

int sayi[1];
int pot;

void setup() {
Serial.begin(9600);

radio.begin();
radio.openWritingPipe(kod);

}

void loop() {

pot = analogRead(A0);
sayi[0] = map(pot, 0, 1023, 0, 179);

radio.write(sayi, 1);

Serial.println(sayi[0]);
}
