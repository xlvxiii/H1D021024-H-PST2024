#include <Arduino.h>
#include <ESPAsyncWebServer.h>
#include <ESP8266WiFi.h>

int led1 = D0;
int led2 = D2;
int led3 = D1;

const char *ssid = "TEKNIK UNSOED D3";
const char *password = "";

String website;
AsyncWebServer server(80);

void setup() {
  pinMode(led1, OUTPUT);
  pinMode(led2, OUTPUT);
  pinMode(led3, OUTPUT);

  // serial, media komunikasi nodemcu dengan perangkat lain
  Serial.begin(9600);
  delay(10);
  
  // // setting mode access point
  // Serial.println("Configuring access point...");
  // WiFi.mode(WIFI_AP);
  // WiFi.softAP(ssid, password);
  // Serial.print("Wifi: ");
  // Serial.println(ssid);
  // Serial.print("IP address: ");
  // Serial.println(WiFi.softAPIP());

  // setting mode station
Serial.print("Connecting to ");
  Serial.println(ssid);

  WiFi.mode(WIFI_STA);
  WiFi.begin(ssid, password);

  while (WiFi.status() != WL_CONNECTED)
  {
    delay(300);
    Serial.print(".");
  }
  
  Serial.println("");
  Serial.println("WiFi connected");
  Serial.print("IP address: ");
  Serial.println(WiFi.localIP());
  
  // isi website
  website+= "<h1> Web Control ESP8266</h1>";
  website+= "<p>LED 1: ";
  website+= "<a href=\"LED1ON\"\"><button>ON</button></a><a     href=\"LED1OFF\"\"><button>OFF</button></a></p><br>";
  website+= "<p>LED 2: ";
  website+= "<a href=\"LED2ON\"\"><button>ON</button></a><a href=\"LED2OFF\"\"><button>OFF</button></a></p><br>";
  website+= "<p>LED 3: ";
  website+= "<a href=\"LED3ON\"\"><button>ON</button></a><a href=\"LED3OFF\"\"><button>OFF</button></a></p>";

  // endpoint
  server.on("/", HTTP_GET, [](AsyncWebServerRequest *request){
    request->send(200, "text/html", website);
  });
  
  server.on("/LED1ON", HTTP_GET, [](AsyncWebServerRequest *request){
    digitalWrite(led1, HIGH);
    request->send(200, "text/html", website);
  });
  
  server.on("/LED2ON", HTTP_GET, [](AsyncWebServerRequest *request){
    digitalWrite(led2, HIGH);
    request->send(200, "text/html", website);
  });

  server.on("/LED3ON", HTTP_GET, [](AsyncWebServerRequest *request){
    digitalWrite(led3, HIGH);
    request->send(200, "text/html", website);
  });

  server.on("/LED1OFF", HTTP_GET, [](AsyncWebServerRequest *request){
    digitalWrite(led1, LOW);
    request->send(200, "text/html", website);
  });
  
  server.on("/LED2OFF", HTTP_GET, [](AsyncWebServerRequest *request){
    digitalWrite(led2, LOW);
    request->send(200, "text/html", website);
  });

  server.on("/LED3OFF", HTTP_GET, [](AsyncWebServerRequest *request){
    digitalWrite(led3, LOW);
    request->send(200, "text/html", website);
  });

  server.begin();
}

void loop() {
}