
int deger; 
void setup() {
  // put your setup code here, to run once:
Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:

deger=attach(9);

Serial.print("Okunan Deger: ");
Serial.println(deger);
delay(50);
}
