/* MiCROBOT 
 * 16 line sensors test code
 * 
 * May 2021
 * 
 */

#include <SPI.h>
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>
//#include <Logos.h>
#define SCREEN_WIDTH 128 // OLED display width, in pixels
#define SCREEN_HEIGHT 64 // OLED display height, in pixels
// Declaration for an SSD1306 display connected to I2C (SDA, SCL pins)
#define OLED_RESET 4 // Reset pin # (or -1 if sharing Arduino reset pin)
Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, OLED_RESET);
#define NUMFLAKES 10 // Number of snowflakes in the animation example
#define imageWidth 128
#define imageHeight 64
int sensorPin = A0; //Selection of analog pin to be read
int sensorValue = 0; //Variable that captures the analog value of the sensor
int ValueFinal = 0; //Variable to be displayed on the OLED
int i=0; //Incremental variable for sampling the sensors.
int buttonState=0;
int k=0; //Variable that for the selection of the corresponding sensor.
void setup() {
Serial.begin(9600);
// SSD1306_SWITCHCAPVCC = generate display voltage from 3.3V internally
if(!display.begin(SSD1306_SWITCHCAPVCC, 0x3C)) { // Address 0x3D for 128x64
Serial.println(F("SSD1306 allocation failed"));
for(;;); // Don't proceed, loop forever
}
pinMode(A1, INPUT);
pinMode(A2, OUTPUT);//S1
pinMode(A3, OUTPUT);//S2
pinMode(4, OUTPUT);//S3
pinMode(7, OUTPUT);//S4
drawbitmap();
sixteenline();
}
void drawbitmap(void) { ///prints the MiCROBOT logo
display.clearDisplay();
display.drawBitmap(0,0,bitmap, 128, 64, 1);
display.display();
delay(2000);
}
void sixteenline(void) { ///Function that prints the text "16LINESENSORS"
display.clearDisplay();
display.drawBitmap(0,0,16LINESENSORS, 128, 64, 1);
display.display();
delay(2000);
}
void lectura(int k) { //Function for the selection of the specific sensor.
    switch (k) {
            case 15: digitalWrite(A2, LOW);digitalWrite(A3, LOW);digitalWrite(4, LOW);digitalWrite(7, LOW);break;
            case 14: digitalWrite(A2, HIGH);digitalWrite(A3, LOW);digitalWrite(4, LOW);digitalWrite(7, LOW);break;
            case 13: digitalWrite(A2, LOW);digitalWrite(A3, HIGH);digitalWrite(4, LOW);digitalWrite(7, LOW);break;
            case 12: digitalWrite(A2, HIGH);digitalWrite(A3, HIGH);digitalWrite(4, LOW);digitalWrite(7, LOW);break;
            case 11: digitalWrite(A2, LOW);digitalWrite(A3, LOW);digitalWrite(4, HIGH);digitalWrite(7, LOW);break;
            case 10: digitalWrite(A2, HIGH);digitalWrite(A3, LOW);digitalWrite(4, HIGH);digitalWrite(7, LOW);break;
            case 9: digitalWrite(A2, LOW);digitalWrite(A3, HIGH);digitalWrite(4, HIGH);digitalWrite(7, LOW);break;
            case 8: digitalWrite(A2, HIGH);digitalWrite(A3, HIGH);digitalWrite(4, HIGH);digitalWrite(7, LOW);break;
            case 7: digitalWrite(A2, LOW);digitalWrite(A3, LOW);digitalWrite(4, LOW);digitalWrite(7, HIGH);break;
            case 6: digitalWrite(A2, HIGH);digitalWrite(A3, LOW);digitalWrite(4, LOW);digitalWrite(7, HIGH);break;
            case 5: digitalWrite(A2, LOW);digitalWrite(A3, HIGH);digitalWrite(4, LOW);digitalWrite(7, HIGH);break;
            case 4: digitalWrite(A2, HIGH);digitalWrite(A3, HIGH);digitalWrite(4, LOW);digitalWrite(7, HIGH);break;
            case 3: digitalWrite(A2, LOW);digitalWrite(A3, LOW);digitalWrite(4, HIGH);digitalWrite(7, HIGH);break;
            case 2: digitalWrite(A2, HIGH);digitalWrite(A3, LOW);digitalWrite(4, HIGH);digitalWrite(7, HIGH);break;
            case 1: digitalWrite(A2, LOW);digitalWrite(A3, HIGH);digitalWrite(4, HIGH);digitalWrite(7, HIGH);break;
            case 0: digitalWrite(A2, HIGH);digitalWrite(A3, HIGH);digitalWrite(4, HIGH);digitalWrite(7, HIGH);break;
    }
}

void loop() { // Main code to be repeated indefinitely.
      display.clearDisplay(); // Clear the screen buffer
      display.fillRect(0, 2, 128, 61, SSD1306_WHITE);
      for(i=0; i<=15; i++) {
      lectura(15-i);
      sensorValue = analogRead(sensorPin);
      ValueFinal=(61-sensorValue*(61/1023.0));
      display.fillRect((i*8), 3, 8, ValueFinal, SSD1306_BLACK);//x coordinate, y coordinate, rectangle width, rectangle height, color
      display.drawRect((i*8), 2, (8+i*8), 61, SSD1306_BLACK);//coordinate, y1 coordinate, x2 coordinate, y2 coordinate, color.
    }
  display.display(); //Refresh the screen with the loaded values.
}
