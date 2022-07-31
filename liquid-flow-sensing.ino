void setup()
{
    pinMode(D0, OUTPUT);

}

void loop()
{
    digitalWrite(ledPin, HIGH);
    delay(2000);
    digitalWrite(ledPin, LOW);
    delay(2000);
}
