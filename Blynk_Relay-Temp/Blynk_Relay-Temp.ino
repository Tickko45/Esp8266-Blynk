#define BLYNK_TEMPLATE_ID "TMPLRsJw8mvT"
#define BLYNK_DEVICE_NAME "RelayTemp"
#define BLYNK_AUTH_TOKEN "4h7pVjRSEFPmVMGJgiK8jo7T-yzuC4-n"

#define BLYNK_PRINT Serial

#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>
#include "DHT.h"

DHT dht;

char auth[] = BLYNK_AUTH_TOKEN; //BLYNK TOKEN

char ssid[] = "KUNGKO"; //WiFi Name
char pass[] = "t0631361663"; //Password

int Temperature; //อุณหภูมิ
int Humidity; //ความชื้น
int Tempspec = 25; //อุณหภูมิที่กำหนด

WidgetLED LED_1(V6); //Blynk LED สถานะเปิด-ปิด Relay 1
WidgetLED LED_2(V7); //Blynk LED สถานะเปิด-ปิด Relay 2
WidgetLED LED_3(V8); //Blynk LED สถานะเปิด-ปิด Relay 3
WidgetLED LED_4(V9); //Blynk LED สถานะเปิด-ปิด Relay 4

//Relay 1
BLYNK_WRITE(V2) //กำหนด Blynk Pin V2
{
  int value = param.asInt(); //รับค่า switch จาก Blynk
  Serial.println(value);
  if(Temperature > Tempspec){ //ตรวจสอบค่าอุณหภูมิสำหรับการทำงานที่ Blynk
    value = 1; //Set value = 1
    Serial.println("Relay Auto 1 ON");
    Serial.println(value);
    LED_1.on(); //Blynk LED สถานะเปิด Relay 1
    }
  if(value == 1)
  {
    digitalWrite(D5, HIGH); //Relay 1 ON
    Serial.println("Relay 1 ON");
    LED_1.on(); //Blynk LED สถานะเปิด Relay 1
  }
  if(value == 0)
  {
     digitalWrite(D5, LOW); //Relay 1 OFF
     Serial.println("Relay 1 OFF");
     LED_1.off(); //Blynk LED สถานะปิด Relay 1
  }
}

//Relay 2
BLYNK_WRITE(V3) //กำหนด Blynk Pin V3
{
  int value = param.asInt(); //รับค่า switch จาก Blynk
  Serial.println(value);
    if(Temperature > Tempspec){ //ตรวจสอบค่าอุณหภูมิสำหรับการทำงานที่ Blynk
    value = 1; //Set value = 1 
    Serial.println("Relay Auto 1 ON");
    Serial.println(value);
    LED_2.on(); //Blynk LED สถานะเปิด Relay 2
    }
  if(value == 1)
  {
    digitalWrite(D6, HIGH); //Relay 2 ON
    Serial.println("Relay 2 ON");
    LED_2.on(); //Blynk LED สถานะเปิด Relay 2
  }
  if(value == 0)
  {
     digitalWrite(D6, LOW); //Relay 2 OFF
     Serial.println("Relay 2 OFF");
     LED_2.off(); //Blynk LED สถานะปิด Relay 2
  }
}

//Relay 3
BLYNK_WRITE(V4) //กำหนด Blynk Pin V4
{
  int value = param.asInt(); //รับค่า switch จาก Blynk
  Serial.println(value);
    if(Temperature > Tempspec){ //ตรวจสอบค่าอุณหภูมิสำหรับการทำงานที่ Blynk
    value = 1; //Set value = 1
    Serial.println("Relay Auto 1 ON");
    Serial.println(value);
    LED_3.on(); //Blynk LED สถานะเปิด Relay 3
    }
  if(value == 1)
  {
    digitalWrite(D7, HIGH); //Relay 3 ON
    Serial.println("Relay 3 ON");
    LED_3.on(); //Blynk LED สถานะเปิด Relay 3
  }
  if(value == 0)
  {
     digitalWrite(D7, LOW); //Relay 3 OFF
     Serial.println("Relay 3 OFF");
     LED_3.off(); //Blynk LED สถานะปิด Relay 3
  }
}

//Relay 4
BLYNK_WRITE(V5) //กำหนด Blynk Pin V5
{
  int value = param.asInt(); //รับค่า switch จาก Blynk
  Serial.println(value);
    if(Temperature > Tempspec){ //ตรวจสอบค่าอุณหภูมิสำหรับการทำงานที่ Blynk
    value = 1; //Set value = 1
    Serial.println("Relay Auto 1 ON");
    Serial.println(value);
    LED_4.on(); //Blynk LED สถานะเปิด Relay 4
    }
  if(value == 1)
  {
    digitalWrite(D8, HIGH); //Relay 4 ON
    Serial.println("Relay 4 ON");
    LED_4.on(); //Blynk LED สถานะเปิด Relay 4
  }
  if(value == 0)
  {
     digitalWrite(D8, LOW); //Relay 4 OFF
     Serial.println("Relay 4 OFF");
     LED_4.off(); //Blynk LED สถานะปิด Relay 4
  }
}

void setup()
{
  Serial.begin(115200);
  Blynk.begin(auth, ssid, pass);
  dht.setup(D1); // data pin D1
  pinMode(D5,OUTPUT); //Relay 1
  pinMode(D6,OUTPUT); //Relay 2
  pinMode(D7,OUTPUT); //Relay 3
  pinMode(D8,OUTPUT); //Relay 4

  digitalWrite(D5, LOW); //Relay 1 OFF
  digitalWrite(D6, LOW); //Relay 1 OFF
  digitalWrite(D7, LOW); //Relay 1 OFF
  digitalWrite(D8, LOW); //Relay 1 OFF
}

void loop()
{
  Blynk.run();

  Temperature = dht.getTemperature(); //รับค่าอุณหภูมิจาก Sensor
  Humidity = dht.getHumidity(); //รับค่าความชื้นจาก Sensor

  // Print serial messages แสดงค่าอุณหภูมิ และค่าความชื้น
  Serial.print("Humidity: " + String(Humidity) + " %");
  Serial.print("\t");
  Serial.println("Temperature: " + String(Temperature) + " C");

  // Update Blynk data อัปเดทค่าอุณหภูมิ และค่าความชื้น
  Blynk.virtualWrite(V0, Temperature); //กำหนด Blynk Pin V0
  Blynk.virtualWrite(V1, Humidity); //กำหนด Blynk Pin V1

  if(Temperature > Tempspec) { //ตรวจสอบค่าอุณหภูมิสำหรับการทำงาน
    digitalWrite(D5, HIGH); //Relay 1 ON
    digitalWrite(D6, HIGH); //Relay 2 ON
    digitalWrite(D7, HIGH); //Relay 3 ON
    digitalWrite(D8, HIGH); //Relay 4 ON
    Serial.println("Relay 1 ON"); 
    Serial.println("Relay 2 ON"); 
    Serial.println("Relay 3 ON"); 
    Serial.println("Relay 4 ON"); 
    LED_1.on(); //Blynk LED สถานะเปิด Relay 1
    LED_2.on(); //Blynk LED สถานะเปิด Relay 2
    LED_3.on(); //Blynk LED สถานะเปิด Relay 3
    LED_4.on(); //Blynk LED สถานะเปิด Relay 4
    }
  else{
    digitalWrite(D5, LOW); //Relay 1 OFF
    digitalWrite(D6, LOW); //Relay 2 OFF
    digitalWrite(D7, LOW); //Relay 3 OFF
    digitalWrite(D8, LOW); //Relay 4 OFF
    Serial.println("Relay 1 OFF");
    Serial.println("Relay 2 OFF");
    Serial.println("Relay 3 OFF");
    Serial.println("Relay 4 OFF");
    LED_1.off();  //Blynk LED สถานะปิด Relay 1
    LED_2.off();  //Blynk LED สถานะปิด Relay 2
    LED_3.off();  //Blynk LED สถานะปิด Relay 3
    LED_4.off();  //Blynk LED สถานะปิด Relay 4
    }
 
  delay(3000);
}
