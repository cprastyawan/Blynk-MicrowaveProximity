#define BLYNK_PRINT Serial

#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>

char auth[] = "YROT2uNrEak40sQtZbv83cP40Ek924EY";
char ssid[] = "wifi";
char pass[] = "nurcahyo";

#define ledPin D2
#define PinPIR D1

int nilaiPIR;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);
  delay(10);
  Blynk.begin(auth, ssid, pass);
  pinMode(ledPin, OUTPUT);
  pinMode(PinPIR, INPUT);
  digitalWrite(ledPin, LOW);
}

void loop() {
  // put your main code here, to run repeatedly:
  getPirValue();
  Blynk.run();
}

void getPirValue(){
  nilaiPIR = digitalRead(PinPIR);
  if(nilaiPIR){
    Serial.println(" Ada Gerakan Objek");
    Blynk.notify(" Ada Gerakan Objek ");
  }

  digitalWrite(ledPin, nilaiPIR);
}
