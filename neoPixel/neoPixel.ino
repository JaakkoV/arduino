// NeoPixel Ring simple sketch (c) 2013 Shae Erisson
// released under the GPLv3 license to match the rest of the AdaFruit NeoPixel library

#include <Adafruit_NeoPixel.h>
#ifdef __AVR__
#include <avr/power.h>
#endif

// Which pin on the Arduino is connected to the NeoPixels?
// On a Trinket or Gemma we suggest changing this to 1
#define PIN            9
int button = 11;
int buttonState = 0;

// How many NeoPixels are attached to the Arduino?
#define NUMPIXELS      24

// When we setup the NeoPixel library, we tell it how many pixels, and which pin to use to send signals.
// Note that for older NeoPixel strips you might need to change the third parameter--see the strandtest
// example for more information on possible values.
Adafruit_NeoPixel pixels = Adafruit_NeoPixel(NUMPIXELS, PIN, NEO_GRB + NEO_KHZ800);

int delayval = 500; // delay for half a second

void setup() {
  Serial.begin(9600);
	pixels.begin(); // This initializes the NeoPixel library.
  pinMode(button, INPUT);
}

void loop() {
  buttonState = digitalRead(button);
	// For a set of NeoPixels the first NeoPixel is 0, second is 1, all the way up to the count of pixels minus one.
  Serial.println(buttonState);

  if(buttonState == 1) {
        pixels.setPixelColor(0, pixels.Color(150, 0, 0)); // Moderately bright green color.
        pixels.show(); // This sends the updated pixel color to the hardware.
        delay(delayval);
        pixels.setPixelColor(0, pixels.Color(0, 0, 0)); // Moderately bright green color.
        pixels.show();
  }else {		// pixels.Color takes RGB values, from 0,0,0 up to 255,255,255
		pixels.setPixelColor(1, pixels.Color(0, 150, 0)); // Moderately bright green color.
		pixels.show(); // This sends the updated pixel color to the hardware.
        delay(delayval);
        pixels.setPixelColor(0, pixels.Color(0, 0, 0)); // Moderately bright green color.
        pixels.show();  }
}

