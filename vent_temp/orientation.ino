unsigned long lastOrientationRequest = 0;

void getOrientation(int i) {
  if ((millis() - lastOrientationRequest) > i) {

    Wire.beginTransmission(MPU_addr);
    Wire.write(0x3B);
    Wire.endTransmission(false);
    Wire.requestFrom(MPU_addr, 14, true);
    AcX = Wire.read() << 8 | Wire.read();
    AcY = Wire.read() << 8 | Wire.read();
    AcZ = Wire.read() << 8 | Wire.read();
    int xAng = map(AcX, minVal, maxVal, -90, 90);
    int yAng = map(AcY, minVal, maxVal, -90, 90);
    int zAng = map(AcZ, minVal, maxVal, -90, 90);

    roll = RAD_TO_DEG * (atan2(-xAng, -zAng) + PI);

    Serial.print("Roll= ");
    Serial.println(roll);

    Serial.println("-----------------------------------------");

    lastOrientationRequest = millis();
  }
}
