#include "BluetoothSerial.h"

BluetoothSerial my_bluetooth;
const char* nama_bluetooth = "promo_bot";

void setup() {

//-- Motor KIRI
pinMode(17, OUTPUT);
pinMode(12, OUTPUT);
//-- Motor Kanan  
pinMode(18, OUTPUT);
pinMode(19, OUTPUT);
 
Serial.begin(115200);
delay(100);

my_bluetooth.begin(nama_bluetooth);

}

void loop() {

  if(my_bluetooth.available()){
    char dat = my_bluetooth.read();
    Serial.println(dat);
    
    if (dat=='B'){
      digitalWrite(17,HIGH);
      digitalWrite(12,LOW);
      digitalWrite(18,LOW);
      digitalWrite(19,HIGH);
      Serial.println(" Motor Gerak ke Depan");
      
    }
    
    if (dat=='F'){
      digitalWrite(17,LOW);
      digitalWrite(12,HIGH);
      digitalWrite(18,HIGH);
      digitalWrite(19,LOW);
      Serial.println(" Motor Gerak ke Mengundur");
    }
    if (dat=='S'){
      digitalWrite(17,LOW);
      digitalWrite(12,LOW);
      digitalWrite(18,LOW);
      digitalWrite(19,LOW);
      Serial.println(" Motor Berhenti");
    }

    if (dat=='R'){
      digitalWrite(17,LOW);
      digitalWrite(12,HIGH);
      digitalWrite(18,LOW);
      digitalWrite(19,HIGH);
      Serial.println(" Motor Gerak ke KANAN");
    }

    if (dat=='L'){
      digitalWrite(17,HIGH);
      digitalWrite(12,LOW);
      digitalWrite(18,HIGH);
      digitalWrite(19,LOW);
      Serial.println(" Motor Gerak ke KIRI");
    }
  }
}
