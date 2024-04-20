void displayUI() {
  //Angles for changing the orientation for UI
  //----------------------------------------------------------------------------//
  if (roll > 45 && roll < 135) {
    display.setRotation(3);
  } else if (roll > 135 && roll < 225) {
    display.setRotation(2);
  } else if (roll > 225 && roll < 315) {
    display.setRotation(1);
  } else {
    display.setRotation(0);
  }
  //----------------------------------------------------------------------------//
  display.clearDisplay();
  display.setTextColor(SSD1306_WHITE);
  //Draw model name
  //----------------------------------------------------------------------------//
  display.setTextSize(1);
  display.setCursor(0, 0);
  display.println(F("350 Z"));
  //Draw Oil Temp text
  //----------------------------------------------------------------------------//
  display.setTextSize(1);
  display.setCursor(0, 15);
  display.println(F("Oil"));
  display.println(F("Temp"));
  //Draw sensor temperature
  //----------------------------------------------------------------------------//
  display.setTextSize(3);
  if (display.getRotation() == 1 || display.getRotation() == 3) {
    display.setCursor(48, 15);
  } else {
    display.setCursor(48, 9);
  }
    display.println(temp, 0);
  
  //Draw Celsius symbol
  //----------------------------------------------------------------------------//
  display.setTextSize(1);
  if (display.getRotation() == 1 || display.getRotation() == 3) {
    display.setCursor(14, 108);
  } else {
    display.setCursor(110, 11);
  }
  display.println(F("o"));

  display.setTextSize(2);
  if (display.getRotation() == 1 || display.getRotation() == 3) {
    display.setCursor(20, 114);
  } else {
    display.setCursor(116, 17);
  }
  display.println(F("C"));
  //----------------------------------------------------------------------------//

  display.display();
}
