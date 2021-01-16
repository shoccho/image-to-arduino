//Complie and upload this code into arduino
/* connect oled as follows 
GND - >GND
VCC -> 5V
SDA -> A4
SCL -> A5
*/

#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>


// change these if you have a different screen
#define SCREEN_WIDTH 128
#define SCREEN_HEIGHT 32

Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, -1);

unsigned char scrbffr [256] = {
//empty buffer
};
int i = 0;
byte read;

void setup() {
  Serial.begin(115200);

  if (!display.begin(SSD1306_SWITCHCAPVCC, 0x3C)) {
    Serial.println(F("SSD1306 allocation failed"));

  }

  display.setTextSize(1); 
  display.setTextColor(WHITE);  

  display.clearDisplay();
  while (!Serial) {
    ; 
  }
}

void loop() {
  
  if (Serial.read() == 'c') {
    for (i = 0; i < 256;) {
      if (Serial.available() > 0) {
        read = Serial.read();
        scrbffr[i++] = read;
      }
    }
  }
  display.clearDisplay();

  //----------------- x, y, image buffer, height, width , idk what is this :3
  display.drawBitmap(32, 0 , scrbffr,      64,      32,   1);

   /* here x,y are the starting position of the image (upper left corner)
      and the lower right corener would be  (x + width,  and y + height)
      */
  display.display();


i=0;

}
