#include <PubSubClient.h>
#include <ESP8266WiFi.h>

const char *ssid = "HUAWEI-AY498A";
const char *password = "15764233";

const char *mqttHost = "10.0.0.2";
const int mqttPort = 1883;

WiFiClient espClient;
PubSubClient client(espClient);

void setup()
{
    Serial.begin(115200);

    WiFi.begin(ssid, password);
    while (WiFi.status() != WL_CONNECTED)
    {
        Serial.println("Connecting to WiFi...");
        delay(500);
    }

    Serial.println("Connected WiFi");
    Serial.print("SSID: ");
    Serial.print(WiFi.SSID());
    Serial.printf("IP: ");
    Serial.print(WiFi.localIP());

    client.setServer("10.0.0.2", 1883);
    client.connect("ESP8266Client", NULL, NULL);
    if (!client.connected())
    {
        Serial.print("failed with state ");
        Serial.print(client.state());
        delay(2000);
    }
    Serial.println("mqtt client is connected");

    client.subscribe("test");
    client.publish("test", "ngok this is from esp");
}

void loop()
{
    client.loop();
}
