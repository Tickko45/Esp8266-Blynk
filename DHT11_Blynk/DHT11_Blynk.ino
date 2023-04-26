/*************************************************************
  Download latest Blynk library here:
    https://github.com/blynkkk/blynk-library/releases/latest

  Blynk is a platform with iOS and Android apps to control
  Arduino, Raspberry Pi and the likes over the Internet.
  You can easily build graphic interfaces for all your
  projects by simply dragging and dropping widgets.

    Downloads, docs, tutorials: http://www.blynk.cc
    Sketch generator:           http://examples.blynk.cc
    Blynk community:            http://community.blynk.cc
    Follow us:                  http://www.fb.com/blynkapp
                                http://twitter.com/blynk_app

  Blynk library is licensed under MIT license
  This example code is in public domain.

 *************************************************************
  This example runs directly on NodeMCU.

  Note: This requires ESP8266 support package:
    https://github.com/esp8266/Arduino

  Please be sure to select the right NodeMCU module
  in the Tools -> Board menu!

  For advanced settings please follow ESP examples :
   - ESP8266_Standalone_Manual_IP.ino
   - ESP8266_Standalone_SmartConfig.ino
   - ESP8266_Standalone_SSL.ino

  Change WiFi ssid, pass, and Blynk auth token to run :)
  Feel free to apply it to any other example. It's simple!
 *************************************************************/

/* Comment this out to disable prints and save space */
#define BLYNK_PRINT Serial

/* Fill-in your Template ID (only if using Blynk.Cloud) */
#define BLYNK_TEMPLATE_ID   "TMPLzIYx9NHx"


#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>
#include "DHT.h"

DHT dht;

// You should get Auth Token in the Blynk App.
// Go to the Project Settings (nut icon).
char auth[] = "2SP5xhA3m20qes3dqJKH6pnphTFPL86k";

// Your WiFi credentials.
// Set password to "" for open networks.
char ssid[] = "KUNGKO"; //WiFi Name
char pass[] = "t0631361663"; //Password

int Temperature;
int Humidity;

void setup()
{
  // Debug console
  Serial.begin(9600);

  dht.setup(D1); // data pin D1

  Blynk.begin(auth, ssid, pass);
}

void loop()
{
  Blynk.run();

  Temperature = dht.getTemperature();
  Humidity = dht.getHumidity();

  // Print serial messages
  Serial.print("Humidity: " + String(Humidity) + " %");
  Serial.print("\t");
  Serial.println("Temperature: " + String(Temperature) + " C");

  // Update Blynk data
  Blynk.virtualWrite(V0, Temperature);
  Blynk.virtualWrite(V1, Humidity);
  
  delay(1000);  
}
