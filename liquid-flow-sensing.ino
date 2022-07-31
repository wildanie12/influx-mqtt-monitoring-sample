#include <ESP8266WiFi.h>
const char *ssid = "HUAWEI-AY498A";
const char *password = "15764233";
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

}

void loop()
{
    client.loop();
}
