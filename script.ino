// https://www.electroschematics.com/arduino-tilt-sensor-experiment/

// Add libraries
#include <WiFi.h>
#include <WiFiClientSecure.h>
#include <UniversalTelegramBot.h>
#include <ArduinoJson.h>

// Wifi network credentials
const char *WIFI_SSID = "<add your wifi name>";
const char *WIFI_PASSWORD = "<add your wifi password>";

// Initialize Telegram BOT  
const char *BOT_TOKEN "<add your Telegram bot token>";
const char *CHAT_ID "<add your chat ID>";

// Initialize variables
const int tiltSensorPin = 13;
const int ledPin = 2;
int defaultState = 1;
int runOnce = 0;
boolean alertState = false;

const char *READY_MESSAGE = "<your message here>"; 
const char *TELEGRAM_WELCOME_MESSAGE = "<your message here>"; 
const char *ALERT_MESSAGE = "<your message here>"


// Secure client 
WiFiClientSecure client;
UniversalTelegramBot bot(BOT_TOKEN, client);

void setup()
{
  Serial.begin(115200);
  delay(3000);  
  
  Serial.println(READY_MESSAGE);
  Serial.println(WIFI_SSID); 
  
  WiFi.mode(WIFI_STA);
  WiFi.begin(WIFI_SSID, WIFI_PASSWORD);

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
  Serial.println(TELEGRAM_WELCOME_MESSAGE);
  bot.sendMessage(CHAT_ID, TELEGRAM_WELCOME_MESSAGE, "");
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
    bot.sendMessage(CHAT_ID, ALERT_MESSAGE);
    runOnce = 1;
}

void zero() {
    runOnce = 0;
}
