#include <Arduino.h>
#include <Adafruit_Sensor.h>
#include <DHT.h>
#include <DHT_U.h>
#include <OneWire.h>
#include <DallasTemperature.h>
#include <ESP8266WiFi.h>

// Data wire is plugged into port 2 on the Arduino
#define ONE_WIRE_BUS D7

#define DHTPIN 2
#define DHTTYPE DHT11

#define LED 2
#define RED_LED 5   // D1
#define GREEN_LED 4 // D2

#define HOSTNAME "TEMPERATURA"

// Setup a oneWire instance to communicate with any OneWire devices (not just Maxim/Dallas temperature ICs)
OneWire oneWire(ONE_WIRE_BUS);

// Pass our oneWire reference to Dallas Temperature.
DallasTemperature sensors(&oneWire);
DHT_Unified dht(DHTPIN, DHTTYPE);

uint32_t delayMS;

WiFiServer server(80);

IPAddress local_IP(192, 168, 0, 100);
// Set your Gateway IP address
IPAddress gateway(192, 168, 0, 1);
IPAddress subnet(255, 255, 255, 0);

float insideTemp;
float outsideTemp;

float insideTemperature()
{
  // Get temperature event and print its value.
  sensors_event_t event;
  dht.temperature().getEvent(&event);
  if (isnan(event.relative_humidity))
  {
    return DEVICE_DISCONNECTED_C;
  }
  return event.temperature;
}

float outsideTemperature()
{
  // call sensors.requestTemperatures() to issue a global temperature
  // request to all devices on the bus
  sensors.requestTemperatures(); // Send the command to get temperatures
                                 // We use the function ByIndex, and as an example get the temperature from the first sensor only.
  return sensors.getTempCByIndex(0);
}

void serveWebpage()
{

  WiFiClient client = server.available();
  if (client)
  {

while (client.connected()) {

      if (client.available()) {

        char c = client.read();


      Serial.println("Connected to client");

      String line = client.readStringUntil('\r');
      Serial.println(line);


      client.print("HTTP/1.1 200 OK\r\n");
      client.print("Host: 192.168.0.100\r\n");
      client.print("Content-type: text/html; charset=utf-8\r\n");
      client.print("Connection: close\r\n");
      client.print("\r\n");
      client.println("<html>");
      client.print("<p>W domu: ");
      client.print(insideTemp);
      client.println("°C</p>");
      client.print("<p>W ogródku: ");
      client.print(outsideTemp);
      client.println("°C</p>");
      client.println("</html>");
      client.print("\r\n");
    }

    // close the connection:
    client.stop();
  }
}
void setup()
{
  Serial.begin(115200);

  WiFi.hostname(HOSTNAME);
  if (!WiFi.config(local_IP, gateway, subnet))
  {
    Serial.println("STA Failed to configure");
  }
  WiFi.begin("o==[]:::::::::::::::::::::::::>", "Mikrofala2021!");

  Serial.print("Connecting");
  while (WiFi.status() != WL_CONNECTED)
  {
    delay(500);
    Serial.print(".");
  }

  Serial.print("Connected, IP address: ");
  Serial.println(WiFi.localIP());

  Serial.println("Start");
  pinMode(GREEN_LED, OUTPUT);
  pinMode(RED_LED, OUTPUT);
  sensors.begin();
  // Initialize device.
  dht.begin();
  sensor_t sensor;
  dht.temperature().getSensor(&sensor);
  // Set delay between sensor readings based on sensor details.
  delayMS = (sensor.min_delay / 1000) + 1000;

  server.begin();
}

void loop()
{
  // Delay between measurements.
  delay(delayMS);

  insideTemp = insideTemperature();
  outsideTemp = outsideTemperature();

  Serial.print("Inside: ");
  Serial.println(insideTemp);
  Serial.print("Outside: ");
  Serial.println(outsideTemp);

  if (insideTemp == DEVICE_DISCONNECTED_C || outsideTemp == DEVICE_DISCONNECTED_C)
  {
    digitalWrite(GREEN_LED, HIGH);
    digitalWrite(RED_LED, HIGH);
  }
  else if (insideTemp > (outsideTemp - 0.7))
  {
    digitalWrite(GREEN_LED, HIGH);
    digitalWrite(RED_LED, LOW);
  }
  else
  {
    digitalWrite(GREEN_LED, LOW);
    digitalWrite(RED_LED, HIGH);
  }

  serveWebpage();
}