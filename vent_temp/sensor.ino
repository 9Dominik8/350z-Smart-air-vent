unsigned long lastTempRequest = 0;

void getSensortemp(int i) {
  if ((millis() - lastTempRequest) > i) {
    Vo = analogRead(thermistorPin);
    R2 = R1 * (4094.0 / (float)Vo - 1.0);  // resistance of the Thermistor
    logR2 = log(R2);
    tKelvin = (1.0 / (c1 + c2 * logR2 + c3 * logR2 * logR2 * logR2));
    temp = tKelvin - 273.15;

    Serial.print(temp);
    Serial.print(" C");
    Serial.print(" Ohm; ");
    Serial.print(R2);
    Serial.print(" Analog Read; ");
    Serial.println(Vo);

    lastTempRequest = millis();
  }
}