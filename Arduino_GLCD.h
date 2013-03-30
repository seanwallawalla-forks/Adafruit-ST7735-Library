
#ifndef _ARDUINO_GLCD_H
#define _ARDUINO_GLCD_H

#include "Arduino.h"
#include <Adafruit_GFX.h>
#include <Adafruit_ST7735.h>

enum RectMode {
  CORNER,
  CORNERS,
  RADIUS,
  CENTER
};

typedef uint16_t color;

class Arduino_GLCD : public Adafruit_ST7735 {
public:
  Arduino_GLCD(uint8_t CS, uint8_t RS, uint8_t RST);

  void begin();
  
  // http://processing.org/reference/background_.html
  void background(uint8_t red, uint8_t green, uint8_t blue);
  void background(color c);

  // http://processing.org/reference/fill_.html
  void fill(uint8_t red, uint8_t green, uint8_t blue);
  void fill(color c);

  // http://processing.org/reference/noFill_.html
  void noFill();

  // http://processing.org/reference/stroke_.html
  void stroke(uint8_t red, uint8_t green, uint8_t blue);
  void stroke(color c);

  // http://processing.org/reference/noStroke_.html
  void noStroke();
  
  void text    (const char * text, uint16_t x, uint16_t y);
  void textWrap(const char * text, uint16_t x, uint16_t y);

  void textSize(uint8_t size);
  
  // similar to ellipse() in Processing, but with
  // a single radius.
  // http://processing.org/reference/ellipse_.html
  void circle(int16_t x, int16_t y, int16_t r);
  
  void point(int16_t x, int16_t y);
  
  void line(uint16_t x1, uint16_t y1, uint16_t x2, uint16_t y2);
  
  void quad(uint16_t x1, uint16_t y1, uint16_t x2, uint16_t y2, uint16_t x3, uint16_t y3, uint16_t x4, uint16_t y4);
  
  void rect(uint16_t x, uint16_t y, uint16_t width, uint16_t height, uint16_t radius = 0);
  
  void triangle(uint16_t x1, uint16_t y1, uint16_t x2, uint16_t y2, uint16_t x3, uint16_t y3);
  
  void rectMode(RectMode mode);
  
  void pushStyle();
  void popStyle();
  
private:
  color strokeColor;

};

color newColor(uint8_t red, uint8_t green, uint8_t blue);


#endif // _ARDUINO_GLCD_H