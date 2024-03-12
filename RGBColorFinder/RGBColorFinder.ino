#include <FastLED_NeoPixel.h>

#define LEDPIN 12
#define R_PIN A0
#define G_PIN A1
#define B_PIN A2
#define NUM_LEDS 1
#define BRIGHTNESS 200

#define LED_TYPE WS2812B

enum ColorOrder{
  RED = 0,
  GREEN,
  BLUE,
  MAXCOLOR
};

FastLED_NeoPixel<NUM_LEDS, LEDPIN, NEO_GRB> pixel;
int prev_rgb[MAXCOLOR] = {0, 0, 0};
int rgb_pin_order[MAXCOLOR] = {R_PIN, G_PIN, B_PIN};

void setup() {
  Serial.begin(115200);
  pinMode(R_PIN,INPUT);
  pinMode(G_PIN,INPUT);
  pinMode(B_PIN,INPUT);
  delay(500);

	pixel.begin();
	pixel.setBrightness(BRIGHTNESS);

}

void loop() {
  int read_rgb_raw[MAXCOLOR], rgb[MAXCOLOR];
  bool isColorChange = false;
  for (int color_order = RED; color_order < MAXCOLOR; color_order++)
  {
    read_rgb_raw[color_order] = analogRead(rgb_pin_order[color_order]);
    if (prev_rgb[color_order] != read_rgb_raw[color_order])
    {
      prev_rgb[color_order] = read_rgb_raw[color_order];
      isColorChange = true;
    }
  }
  if(isColorChange)
  {
    for (int color_order = RED; color_order < MAXCOLOR; color_order++)
      rgb[color_order] = map(read_rgb_raw[color_order], 0, 1023, 0, 255);
    pixel.setPixelColor(0, pixel.Color(rgb[RED], rgb[GREEN], rgb[BLUE]));
    pixel.show();
    
    String Message = "CurrentColor=   R ";
    Message += rgb[RED];  Message += "\tG ";
    Message += rgb[GREEN];Message += "\tB ";
    Message += rgb[BLUE];
    Serial.println(Message);
  }
  delay(100);
}
