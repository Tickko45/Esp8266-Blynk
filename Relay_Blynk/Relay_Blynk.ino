#define BLYNK_TEMPLATE_ID "TMPLFK0qXK-u"
#define BLYNK_DEVICE_NAME "HOME AUTOMATION"
#define BLYNK_AUTH_TOKEN "_XoWdMKXjAK08qi0abzUdCFX_0fXELpa"

#define BLYNK_PRINT Serial

#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>

char auth[] = BLYNK_AUTH_TOKEN;

char ssid[] = "KUNGKO"; //WiFi Name
char pass[] = "t0631361663"; //Password

BLYNK_WRITE(V0)
{
  int value = param.asInt();
  Serial.println(value);
  if(value == 1)
  {
    digitalWrite(D5, HIGH);
    Serial.println("Relay 1 ON");
  }
  if(value == 0)
  {
     digitalWrite(D5, LOW);
     Serial.println("Relay 1 OFF");
  }
}

BLYNK_WRITE(V1)
{
  int value = param.asInt();
  Serial.println(value);
  if(value == 1)
  {
    digitalWrite(D6, HIGH);
    Serial.println("Relay 2 ON");
  }
  if(value == 0)
  {
     digitalWrite(D6, LOW);
     Serial.println("Relay 2 OFF");
  }
}

BLYNK_WRITE(V2)
{
  int value = param.asInt();
  Serial.println(value);
  if(value == 1)
  {
    digitalWrite(D7, HIGH);
    Serial.println("Relay 3 ON");
  }
  if(value == 0)
  {
     digitalWrite(D7, LOW);
     Serial.println("Relay 3 OFF");
  }
}

BLYNK_WRITE(V3)
{
  int value = param.asInt();
  Serial.println(value);
  if(value == 1)
  {
    digitalWrite(D8, HIGH);
    Serial.println("Relay 4 ON");
  }
  if(value == 0)
  {
     digitalWrite(D8, LOW);
     Serial.println("Relay 4 OFF");
  }
}


void setup()
{
  Serial.begin(115200);
  Blynk.begin(auth, ssid, pass);
  pinMode(D5,OUTPUT);
  pinMode(D6,OUTPUT);
  pinMode(D7,OUTPUT);
  pinMode(D8,OUTPUT);
}

void loop()
{
  Blynk.run();
}
