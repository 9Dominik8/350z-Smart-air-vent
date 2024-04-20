// Libraries for OLED and MPU6050
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>


//----------------------------------------------------------------------------//

#define SCREEN_WIDTH 128  // OLED display width, in pixels
#define SCREEN_HEIGHT 32  // OLED display height, in pixels

// Declaration for an SSD1306 display connected to I2C (SDA, SCL pins)
#define OLED_RESET 4  // Reset pin # (or -1 if sharing Arduino reset pin)
Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, OLED_RESET);
//----------------------------------------------------------------------------//

//Variables for MPU6050 accelerometer
const int MPU_addr = 0x68;
int16_t AcX, AcY, AcZ, Tmp, GyX, GyY, GyZ;
int minVal = 265;
int maxVal = 402;
//----------------------------------------------------------------------------//
//Variable for roll value in degrees 0-360
double roll;
//----------------------------------------------------------------------------//
//Variables foe thermistor
int thermistorPin = 0;
int Vo;
float R1 = 1000;
float logR2, R2, tKelvin;
float c1 = 1.654552649e-03, c2 = 1.954185804e-04, c3 = 7.544505858e-07;
//----------------------------------------------------------------------------//

float temp;

char buffer[40];  // Buffer for debug only

void setup() {
  Serial.begin(115200);
  Wire.begin();
  Wire.beginTransmission(MPU_addr);
  Wire.write(0x6B);
  Wire.write(0);
  Wire.endTransmission(true);



  // SSD1306_SWITCHCAPVCC = generate display voltage from 3.3V internally
  if (!display.begin(SSD1306_SWITCHCAPVCC, 0x3C)) {  // Address 0x3C for 128x32
    Serial.println(F("SSD1306 allocation failed"));
    for (;;)
      ;  // Don't proceed, loop forever
  }
  //Invoke function to draw logo logoDisplay(time in ms);
  logoDisplay(2000);
}

void loop() {
  //Request angle => used in displayUI to change UI orientation getOrientation(time in ms between iterration);
  getOrientation(1000);
  //Draw UI with correct orientation
  displayUI();
  //Get temperature from sensor
  getSensortemp(1000);
}
