// https://www.electroschematics.com/arduino-tilt-sensor-experiment/

// Add libraries
#include <WiFi.h>
#include <WiFiClientSecure.h>
#include <UniversalTelegramBot.h>
#include <ArduinoJson.h>

// Wifi network credentials
const char *ssid = "<add your wifi name>";
const char *password = "<add your wifi password>";

// Initialize variables
const int tiltSensorPin = 13;
const int ledPin = 2;
int defaultState = 1;
int runOnce = 0;
boolean alertState = false;


// Initialize Telegram BOT  
#define BOTtoken "<add your Telegram bot token>"  // your Bot Token (Get from Botfather)
#define CHAT_ID "<add your chat ID>"

// Secure client 
WiFiClientSecure client;
UniversalTelegramBot bot(BOTtoken, client);

void setup()
{
  Serial.begin(115200);
  delay(3000);  
  
  Serial.println("Ready for detecting motion");
  Serial.println(ssid); 
  
  WiFi.mode(WIFI_STA);
  WiFi.begin(ssid, password);

  // Add root certificate for api.telegram.org
  client.setCACert(TELEGRAM_CERTIFICATE_ROOT); 
  
  // Connecting to wifi
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }

  // Connected
  Serial.println("");
  Serial.println("WiFi connected");
  Serial.println("IP address: ");
  Serial.println(WiFi.localIP());


  pinMode (tiltSensorPin, INPUT);
  pinMode (ledPin, OUTPUT);
  
  // Message to bot and serial
  Serial.println("<add your initial message for Telegram>");
  bot.sendMessage(CHAT_ID, "<add your initial message for Telegram Bot>", "");
}


void loop() {
    int currentState = digitalRead(13);    
    if (currentState == 1) { 
      zero();
    } else {
      alertState = true;
      if (alertState == true && runOnce == 0) {
        tiltAlert();
      } else {
        alertState = false;
      }
    }   
    delay(2000);
}

void tiltAlert() {
    bot.sendMessage(CHAT_ID, "<add your alert message for Telegram Bot>");
    runOnce = 1;
}

void zero() {
    runOnce = 0;
}
