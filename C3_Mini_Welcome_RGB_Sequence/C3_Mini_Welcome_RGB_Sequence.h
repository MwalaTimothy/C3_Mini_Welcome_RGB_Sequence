#ifndef C3_MINI_WELCOME_RGB_SEQUENCE_H
#define C3_MINI_WELCOME_RGB_SEQUENCE_H

#include <FastLED.h> // Include the FastLED library

class C3MiniWelcomeRGBSequence {
  private:
    int pin;          // Pin connected to the built-in RGB LED
    int blinkCount;   // Number of times to blink
    CRGB leds[1];     // Array to hold the LED data (only 1 LED)

  public:
    // Constructor
    C3MiniWelcomeRGBSequence(int ledPin = 7, int count = 1) : pin(ledPin), blinkCount(count) {
      FastLED.addLeds<WS2812, 7, GRB>(leds, 1); // Initialize the LED on pin 7
    }

    // Blink the LED
    void blink() {
      for (int i = 0; i < blinkCount; i++) {
        // Red
        leds[0] = CRGB::Red;
        FastLED.show();
        delay(100);
        leds[0] = CRGB::Black;
        FastLED.show();
        delay(100);

        // Green
        leds[0] = CRGB::Green;
        FastLED.show();
        delay(100);
        leds[0] = CRGB::Black;
        FastLED.show();
        delay(100);

        // Blue
        leds[0] = CRGB::Blue;
        FastLED.show();
        delay(100);
        leds[0] = CRGB::Black;
        FastLED.show();
        delay(100);
      }
    }
};

// Create a global instance of the C3MiniWelcomeRGBSequence class
C3MiniWelcomeRGBSequence welcomeSequence;

// Define the setup function
void setup() {
  welcomeSequence.blink(); // Blink the built-in RGB LED 5 times
}

// Define an empty loop function
void loop() {
  // The loop function is empty because we only want to blink the LED on startup
}

#endif
