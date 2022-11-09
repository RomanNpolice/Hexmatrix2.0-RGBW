#include <ESP8266WiFi.h>
#include <WiFiManager.h>
#include <time.h>
#define FASTLED_ESP8266_NODEMCU_PIN_ORDER
#include "FastLED.h"
#include "FastLED_RGBW.h"

#if FASTLED_VERSION < 3001000
#error "Requires FastLED 3.1 or later; check github for latest code."
#endif

#define DATA_PIN    2
#define LED_TYPE    WS2812B
#define COLOR_ORDER RGB
#define NUM_LEDS    96
#define BRIGHTNESS  200
#define BACKGROUNDBRIGHTNESS 150
#define DIMMINGBRIGHTNESS 80
#define BRIGHTNESS_NIGHT  30
#define MAXULONG 4294967295

CRGBW leds[NUM_LEDS];
CRGB *_leds = (CRGB *) &leds[0];

//Digits color values in RGB
int r = 0;
int g = 0;
int b = 0;
int w = 255;

const char* ESP_HOST_NAME = "esp-" + ESP.getFlashChipId();

//Your time zone
int timezone = 9.0 * 3600;
int dst = 0;

WiFiClient wifiClient;

void connectWifi()
{
  wifiledset();
  WiFi.mode(WIFI_STA);
  WiFiManager wm;
  wm.autoConnect("RGB HexClock");
}

void setup() {
  Serial.begin(115200);
  delay(500);
  Serial.println();
  Serial.println("\n\nNext Loop-Step: " + String(millis()) + ":");
  configTime(timezone, dst, "pool.ntp.org", "time.nist.gov");
  FastLED.addLeds<LED_TYPE, DATA_PIN, COLOR_ORDER>(_leds, getRGBWsize(NUM_LEDS))
  .setCorrection(TypicalLEDStrip)
  .setDither(BRIGHTNESS < 255);
  FastLED.setBrightness(BRIGHTNESS);
  connectWifi();
}


void loop()
{
  time_t now = time(nullptr);
  struct tm* p_tm = localtime(&now);
  //  Serial.print("-------------------------------------------------\n");
  //  Serial.print("Date & Time : ");
  //  Serial.print(p_tm->tm_mday);
  //  Serial.print("/");
  //  Serial.print(p_tm->tm_mon + 1);
  //  Serial.print("/");
  //  Serial.print(p_tm->tm_year + 1900);
  //  Serial.print(" ");
  int hour = p_tm->tm_hour;
  int minute = p_tm->tm_min;
  if (hour > 12)
  {
    hour = hour - 12;
  }
  //  Serial.print(p_tm->tm_hour);
  //  Serial.print(":");
  //  Serial.print(minute);
  //  Serial.print(":");
  //  Serial.println(p_tm->tm_sec);
  pride();
  if (hour == 0 || hour == 12)
  {
    if (p_tm->tm_hour == 12) {
      FastLED.setBrightness(BRIGHTNESS_NIGHT);
    }
    hour12();
    if (millis() > MAXULONG - 3300000)
    {
      ESP.restart();
    }
  }
  if (hour == 1)
  {
    hour1();
  }
  if (hour == 2)
  {
    hour2();
  }
  if (hour == 3)
  {
    hour3();
  }
  if (hour == 4)
  {
    hour4();
  }
  if (hour == 5)
  {
    hour5();
  }
  if (hour == 6)
  {
    hour6();
  }
  if (hour == 7)
  {
    FastLED.setBrightness(BRIGHTNESS);
    hour7();
  }
  if (hour == 8)
  {
    hour8();
  }
  if (hour == 9)
  {
    hour9();
  }
  if (hour == 10)
  {
    hour10();
    if (p_tm->tm_hour >= 11 + hour)
    {
      FastLED.setBrightness(BRIGHTNESS - DIMMINGBRIGHTNESS);
    }
  }
  if (hour == 11)
  {
    hour11();
    if (p_tm->tm_hour >= 11 + hour)
    {
      FastLED.setBrightness(BRIGHTNESS_NIGHT);
    }
  }

  if (minute == 0)
  {
    min0();
  }
  if (minute == 1)
  {
    min1();
  }
  if (minute == 2)
  {
    min2();
  }
  if (minute == 3)
  {
    min3();
  }
  if (minute == 4)
  {
    min4();
  }
  if (minute == 5)
  {
    min5();
  }
  if (minute == 6)
  {
    min6();
  }
  if (minute == 7)
  {
    min7();
  }
  if (minute == 8)
  {
    min8();
  }
  if (minute == 9)
  {
    min9();
  }
  if (minute == 10)
  {
    min10();
  }
  if (minute == 11)
  {
    min11();
  }
  if (minute == 12)
  {
    min12();
  }
  if (minute == 13)
  {
    min13();
  }
  if (minute == 14)
  {
    min14();
  }
  if (minute == 15)
  {
    min15();
  }
  if (minute == 16)
  {
    min16();
  }
  if (minute == 17)
  {
    min17();
  }
  if (minute == 18)
  {
    min18();
  }
  if (minute == 19)
  {
    min19();
  }
  if (minute == 20)
  {
    min20();
  }
  if (minute == 21)
  {
    min21();
  }
  if (minute == 22)
  {
    min22();
  }
  if (minute == 23)
  {
    min23();
  }
  if (minute == 24)
  {
    min24();
  }
  if (minute == 25)
  {
    min25();
  }
  if (minute == 26)
  {
    min26();
  }
  if (minute == 27)
  {
    min27();
  }
  if (minute == 28)
  {
    min28();
  }
  if (minute == 29)
  {
    min29();
  }
  if (minute == 30)
  {
    min30();
    if (p_tm->tm_hour == 12 + 1) {
      FastLED.setBrightness(BRIGHTNESS);
    }
  }
  if (minute == 31)
  {
    min31();
  }
  if (minute == 32)
  {
    min32();
  }
  if (minute == 33)
  {
    min33();
  }
  if (minute == 34)
  {
    min34();
  }
  if (minute == 35)
  {
    min35();
  }
  if (minute == 36)
  {
    min36();
  }
  if (minute == 37)
  {
    min37();
  }
  if (minute == 38)
  {
    min38();
  }
  if (minute == 39)
  {
    min39();
  }
  if (minute == 40)
  {
    min40();
  }
  if (minute == 41)
  {
    min41();
  }
  if (minute == 42)
  {
    min42();
  }
  if (minute == 43)
  {
    min43();
  }
  if (minute == 44)
  {
    min44();
  }
  if (minute == 45)
  {
    min45();
  }
  if (minute == 46)
  {
    min46();
  }
  if (minute == 47)
  {
    min47();
  }
  if (minute == 48)
  {
    min48();
  }
  if (minute == 49)
  {
    min49();
  }
  if (minute == 50)
  {
    min50();
  }
  if (minute == 51)
  {
    min51();
  }
  if (minute == 52)
  {
    min52();
  }
  if (minute == 53)
  {
    min53();
  }
  if (minute == 54)
  {
    min54();
  }
  if (minute == 55)
  {
    min55();
  }
  if (minute == 56)
  {
    min56();
  }
  if (minute == 57)
  {
    min57();
  }
  if (minute == 58)
  {
    min58();
  }
  if (minute == 59)
  {
    min59();
  }
  FastLED.show();
}

void pride()
{
  static uint16_t sPseudotime = 0;
  static uint16_t sLastMillis = 0;
  static uint16_t sHue16 = 0;

  uint8_t sat8 = beatsin88( 87, 220, 250);
  uint8_t brightdepth = beatsin88( 341, 96, 224);
  uint16_t brightnessthetainc16 = beatsin88( 203, (25 * 256), (40 * 256));
  uint8_t msmultiplier = beatsin88(147, 23, 60);

  uint16_t hue16 = sHue16;//gHue * 256;
  uint16_t hueinc16 = beatsin88(113, 1, 3000);

  uint16_t ms = millis();
  uint16_t deltams = ms - sLastMillis ;
  sLastMillis  = ms;
  sPseudotime += deltams * msmultiplier;
  sHue16 += deltams * beatsin88( 400, 5, 9);
  uint16_t brightnesstheta16 = sPseudotime;

  for ( uint16_t i = 0 ; i < NUM_LEDS; i++) {
    hue16 += hueinc16;
    uint8_t hue8 = hue16 / 256;

    brightnesstheta16  += brightnessthetainc16;
    uint16_t b16 = sin16( brightnesstheta16  ) + 32768;

    uint16_t bri16 = (uint32_t)((uint32_t)b16 * (uint32_t)b16) / 65536;
    uint8_t bri8 = (uint32_t)(((uint32_t)bri16) * brightdepth) / 65536;
    bri8 += (255 - brightdepth);
    bri8 = bri8 * BACKGROUNDBRIGHTNESS / 256;

    CRGB newcolor = CHSV( hue8, sat8, bri8);

    uint16_t pixelnumber = i;
    pixelnumber = (NUM_LEDS - 1) - pixelnumber;

    nblend((CRGB&)leds[pixelnumber], newcolor, 64);
    leds[pixelnumber] = CRGBW(leds[pixelnumber].red, leds[pixelnumber].green, leds[pixelnumber].blue, 0);
  }
}
/*------------------------------------Wifi Setup------------------------------------*/
void wifiledset() {
  leds[35] = CRGBW(w, w/2, w, 0);
  leds[21] = CRGBW(w, w/2, w, 0);
  leds[17] = CRGBW(w, w/2, w, 0);
  leds[16] = CRGBW(w, w/2, w, 0);
  leds[8]  = CRGBW(w, w/2, w, 0);
  leds[9]  = CRGBW(w, w/2, w, 0);
  leds[15] = CRGBW(w, w/2, w, 0);
  leds[14] = CRGBW(w, w/2, w, 0);
  leds[28] = CRGBW(w, w/2, w, 0);
  leds[26] = CRGBW(w, w/2, w, 0);
  leds[45] = CRGBW(w, w/2, w, 0);
  leds[41] = CRGBW(w, w/2, w, 0);
  leds[31] = CRGBW(w, w/2, w, 0);
  leds[32] = CRGBW(w, w/2, w, 0);
  leds[38] = CRGBW(w, w/2, w, 0);
  leds[50] = CRGBW(w, w/2, w, 0);
  leds[62] = CRGBW(w, w/2, w, 0);
  leds[56] = CRGBW(w, w/2, w, 0);
  leds[55] = CRGBW(w, w/2, w, 0);
  leds[65] = CRGBW(w, w/2, w, 0);
  leds[71] = CRGBW(w, w/2, w, 0);
  leds[72] = CRGBW(w, w/2, w, 0);
  leds[80] = CRGBW(w, w/2, w, 0);
  leds[79] = CRGBW(w, w/2, w, 0);
  leds[86] = CRGBW(w, w/2, w, 0);
  leds[87] = CRGBW(w, w/2, w, 0);
  FastLED.show();
}

/*------------------------------------Hour LEDs------------------------------------*/
void hour12()
{
  leds[2] = CRGBW(r, g, b, w);
  leds[3] = CRGBW(r, g, b, w);
  leds[5] = CRGBW(r, g, b, w);
  leds[7] = CRGBW(r, g, b, w);
  leds[10] = CRGBW(r, g, b, w);
  leds[14] = CRGBW(r, g, b, w);
  leds[15] = CRGBW(r, g, b, w);
  leds[17] = CRGBW(r, g, b, w);
  leds[22] = CRGBW(r, g, b, w);
  leds[24] = CRGBW(r, g, b, w);
  leds[30] = CRGBW(r, g, b, w);
  leds[31] = CRGBW(r, g, b, w);
  leds[33] = CRGBW(r, g, b, w);
}
void hour1()
{
  leds[9] = CRGBW(r, g, b, w);
  leds[15] = CRGBW(r, g, b, w);
  leds[24] = CRGBW(r, g, b, w);
  leds[31] = CRGBW(r, g, b, w);
  leds[40] = CRGBW(r, g, b, w);
}
void hour2()
{
  leds[8] = CRGBW(r, g, b, w);
  leds[9] = CRGBW(r, g, b, w);
  leds[15] = CRGBW(r, g, b, w);
  leds[23] = CRGBW(r, g, b, w);
  leds[24] = CRGBW(r, g, b, w);
  leds[32] = CRGBW(r, g, b, w);
  leds[39] = CRGBW(r, g, b, w);
  leds[40] = CRGBW(r, g, b, w);
}
void hour3()
{
  leds[8] = CRGBW(r, g, b, w);
  leds[9] = CRGBW(r, g, b, w);
  leds[15] = CRGBW(r, g, b, w);
  leds[23] = CRGBW(r, g, b, w);
  leds[24] = CRGBW(r, g, b, w);
  leds[31] = CRGBW(r, g, b, w);
  leds[39] = CRGBW(r, g, b, w);
  leds[40] = CRGBW(r, g, b, w);
}
void hour4()
{
  leds[15] = CRGBW(r, g, b, w);
  leds[16] = CRGBW(r, g, b, w);
  leds[23] = CRGBW(r, g, b, w);
  leds[24] = CRGBW(r, g, b, w);
  leds[31] = CRGBW(r, g, b, w);
  leds[40] = CRGBW(r, g, b, w);
}
void hour5()
{
  leds[8] = CRGBW(r, g, b, w);
  leds[9] = CRGBW(r, g, b, w);
  leds[16] = CRGBW(r, g, b, w);
  leds[23] = CRGBW(r, g, b, w);
  leds[24] = CRGBW(r, g, b, w);
  leds[31] = CRGBW(r, g, b, w);
  leds[39] = CRGBW(r, g, b, w);
  leds[40] = CRGBW(r, g, b, w);
}
void hour6()
{
  leds[8] = CRGBW(r, g, b, w);
  leds[9] = CRGBW(r, g, b, w);
  leds[16] = CRGBW(r, g, b, w);
  leds[23] = CRGBW(r, g, b, w);
  leds[24] = CRGBW(r, g, b, w);
  leds[31] = CRGBW(r, g, b, w);
  leds[32] = CRGBW(r, g, b, w);
  leds[39] = CRGBW(r, g, b, w);
  leds[40] = CRGBW(r, g, b, w);
}
void hour7()
{
  leds[8] = CRGBW(r, g, b, w);
  leds[9] = CRGBW(r, g, b, w);
  leds[15] = CRGBW(r, g, b, w);
  leds[16] = CRGBW(r, g, b, w);
  leds[24] = CRGBW(r, g, b, w);
  leds[31] = CRGBW(r, g, b, w);
  leds[40] = CRGBW(r, g, b, w);
}
void hour8()
{
  leds[8] = CRGBW(r, g, b, w);
  leds[9] = CRGBW(r, g, b, w);
  leds[15] = CRGBW(r, g, b, w);
  leds[16] = CRGBW(r, g, b, w);
  leds[23] = CRGBW(r, g, b, w);
  leds[24] = CRGBW(r, g, b, w);
  leds[31] = CRGBW(r, g, b, w);
  leds[32] = CRGBW(r, g, b, w);
  leds[39] = CRGBW(r, g, b, w);
  leds[40] = CRGBW(r, g, b, w);
}
void hour9()
{
  leds[8] = CRGBW(r, g, b, w);
  leds[9] = CRGBW(r, g, b, w);
  leds[15] = CRGBW(r, g, b, w);
  leds[16] = CRGBW(r, g, b, w);
  leds[23] = CRGBW(r, g, b, w);
  leds[24] = CRGBW(r, g, b, w);
  leds[31] = CRGBW(r, g, b, w);
  leds[39] = CRGBW(r, g, b, w);
  leds[40] = CRGBW(r, g, b, w);
}
void hour10()
{
  leds[2] = CRGBW(r, g, b, w);
  leds[3] = CRGBW(r, g, b, w);
  leds[5] = CRGBW(r, g, b, w);
  leds[7] = CRGBW(r, g, b, w);
  leds[9] = CRGBW(r, g, b, w);
  leds[10] = CRGBW(r, g, b, w);
  leds[17] = CRGBW(r, g, b, w);
  leds[22] = CRGBW(r, g, b, w);
  leds[24] = CRGBW(r, g, b, w);
  leds[25] = CRGBW(r, g, b, w);
  leds[30] = CRGBW(r, g, b, w);
  leds[31] = CRGBW(r, g, b, w);
  leds[33] = CRGBW(r, g, b, w);
}
void hour11()
{
  leds[3] = CRGBW(r, g, b, w);
  leds[5] = CRGBW(r, g, b, w);
  leds[7] = CRGBW(r, g, b, w);
  leds[9] = CRGBW(r, g, b, w);
  leds[15] = CRGBW(r, g, b, w);
  leds[17] = CRGBW(r, g, b, w);
  leds[22] = CRGBW(r, g, b, w);
  leds[24] = CRGBW(r, g, b, w);
  leds[31] = CRGBW(r, g, b, w);
  leds[33] = CRGBW(r, g, b, w);
}

/*----------------------------Minutes LEDs----------------------------*/
void min0()
{
  leds[62] = CRGBW(r, g, b, w);
  leds[63] = CRGBW(r, g, b, w);
  leds[64] = CRGBW(r, g, b, w);
  leds[65] = CRGBW(r, g, b, w);
  leds[70] = CRGBW(r, g, b, w);
  leds[71] = CRGBW(r, g, b, w);
  leds[72] = CRGBW(r, g, b, w);
  leds[73] = CRGBW(r, g, b, w);
  leds[85] = CRGBW(r, g, b, w);
  leds[86] = CRGBW(r, g, b, w);
  leds[87] = CRGBW(r, g, b, w);
  leds[88] = CRGBW(r, g, b, w);
  leds[90] = CRGBW(r, g, b, w);
  leds[91] = CRGBW(r, g, b, w);
  leds[92] = CRGBW(r, g, b, w);
  leds[93] = CRGBW(r, g, b, w);
}
void min1()
{
  leds[62] = CRGBW(r, g, b, w);
  leds[64] = CRGBW(r, g, b, w);
  leds[65] = CRGBW(r, g, b, w);
  leds[70] = CRGBW(r, g, b, w);
  leds[71] = CRGBW(r, g, b, w);
  leds[73] = CRGBW(r, g, b, w);
  leds[78] = CRGBW(r, g, b, w);
  leds[85] = CRGBW(r, g, b, w);
  leds[86] = CRGBW(r, g, b, w);
  leds[88] = CRGBW(r, g, b, w);
  leds[90] = CRGBW(r, g, b, w);
  leds[92] = CRGBW(r, g, b, w);
  leds[93] = CRGBW(r, g, b, w);
}
void min2()
{
  leds[62] = CRGBW(r, g, b, w);
  leds[63] = CRGBW(r, g, b, w);
  leds[64] = CRGBW(r, g, b, w);
  leds[65] = CRGBW(r, g, b, w);
  leds[70] = CRGBW(r, g, b, w);
  leds[71] = CRGBW(r, g, b, w);
  leds[73] = CRGBW(r, g, b, w);
  leds[78] = CRGBW(r, g, b, w);
  leds[79] = CRGBW(r, g, b, w);
  leds[85] = CRGBW(r, g, b, w);
  leds[86] = CRGBW(r, g, b, w);
  leds[87] = CRGBW(r, g, b, w);
  leds[90] = CRGBW(r, g, b, w);
  leds[91] = CRGBW(r, g, b, w);
  leds[92] = CRGBW(r, g, b, w);
  leds[93] = CRGBW(r, g, b, w);
}
void min3()
{
  leds[62] = CRGBW(r, g, b, w);
  leds[63] = CRGBW(r, g, b, w);
  leds[64] = CRGBW(r, g, b, w);
  leds[65] = CRGBW(r, g, b, w);
  leds[70] = CRGBW(r, g, b, w);
  leds[71] = CRGBW(r, g, b, w);
  leds[73] = CRGBW(r, g, b, w);
  leds[78] = CRGBW(r, g, b, w);
  leds[79] = CRGBW(r, g, b, w);
  leds[85] = CRGBW(r, g, b, w);
  leds[86] = CRGBW(r, g, b, w);
  leds[88] = CRGBW(r, g, b, w);
  leds[90] = CRGBW(r, g, b, w);
  leds[91] = CRGBW(r, g, b, w);
  leds[92] = CRGBW(r, g, b, w);
  leds[93] = CRGBW(r, g, b, w);
}
void min4()
{
  leds[64] = CRGBW(r, g, b, w);
  leds[65] = CRGBW(r, g, b, w);
  leds[70] = CRGBW(r, g, b, w);
  leds[71] = CRGBW(r, g, b, w);
  leds[72] = CRGBW(r, g, b, w);
  leds[73] = CRGBW(r, g, b, w);
  leds[78] = CRGBW(r, g, b, w);
  leds[79] = CRGBW(r, g, b, w);
  leds[85] = CRGBW(r, g, b, w);
  leds[86] = CRGBW(r, g, b, w);
  leds[88] = CRGBW(r, g, b, w);
  leds[90] = CRGBW(r, g, b, w);
  leds[92] = CRGBW(r, g, b, w);
  leds[93] = CRGBW(r, g, b, w);
}
void min5()
{
  leds[62] = CRGBW(r, g, b, w);
  leds[63] = CRGBW(r, g, b, w);
  leds[64] = CRGBW(r, g, b, w);
  leds[65] = CRGBW(r, g, b, w);
  leds[70] = CRGBW(r, g, b, w);
  leds[71] = CRGBW(r, g, b, w);
  leds[72] = CRGBW(r, g, b, w);
  leds[78] = CRGBW(r, g, b, w);
  leds[79] = CRGBW(r, g, b, w);
  leds[85] = CRGBW(r, g, b, w);
  leds[86] = CRGBW(r, g, b, w);
  leds[88] = CRGBW(r, g, b, w);
  leds[90] = CRGBW(r, g, b, w);
  leds[91] = CRGBW(r, g, b, w);
  leds[92] = CRGBW(r, g, b, w);
  leds[93] = CRGBW(r, g, b, w);
}
void min6()
{
  leds[62] = CRGBW(r, g, b, w);
  leds[63] = CRGBW(r, g, b, w);
  leds[64] = CRGBW(r, g, b, w);
  leds[65] = CRGBW(r, g, b, w);
  leds[70] = CRGBW(r, g, b, w);
  leds[71] = CRGBW(r, g, b, w);
  leds[72] = CRGBW(r, g, b, w);
  leds[78] = CRGBW(r, g, b, w);
  leds[79] = CRGBW(r, g, b, w);
  leds[85] = CRGBW(r, g, b, w);
  leds[86] = CRGBW(r, g, b, w);
  leds[87] = CRGBW(r, g, b, w);
  leds[88] = CRGBW(r, g, b, w);
  leds[90] = CRGBW(r, g, b, w);
  leds[91] = CRGBW(r, g, b, w);
  leds[92] = CRGBW(r, g, b, w);
  leds[93] = CRGBW(r, g, b, w);
}
void min7()
{
  leds[62] = CRGBW(r, g, b, w);
  leds[63] = CRGBW(r, g, b, w);
  leds[64] = CRGBW(r, g, b, w);
  leds[65] = CRGBW(r, g, b, w);
  leds[70] = CRGBW(r, g, b, w);
  leds[71] = CRGBW(r, g, b, w);
  leds[72] = CRGBW(r, g, b, w);
  leds[73] = CRGBW(r, g, b, w);
  leds[78] = CRGBW(r, g, b, w);
  leds[85] = CRGBW(r, g, b, w);
  leds[86] = CRGBW(r, g, b, w);
  leds[88] = CRGBW(r, g, b, w);
  leds[90] = CRGBW(r, g, b, w);
  leds[92] = CRGBW(r, g, b, w);
  leds[93] = CRGBW(r, g, b, w);
}
void min8()
{
  leds[62] = CRGBW(r, g, b, w);
  leds[63] = CRGBW(r, g, b, w);
  leds[64] = CRGBW(r, g, b, w);
  leds[65] = CRGBW(r, g, b, w);
  leds[70] = CRGBW(r, g, b, w);
  leds[71] = CRGBW(r, g, b, w);
  leds[72] = CRGBW(r, g, b, w);
  leds[73] = CRGBW(r, g, b, w);
  leds[78] = CRGBW(r, g, b, w);
  leds[79] = CRGBW(r, g, b, w);
  leds[85] = CRGBW(r, g, b, w);
  leds[86] = CRGBW(r, g, b, w);
  leds[87] = CRGBW(r, g, b, w);
  leds[88] = CRGBW(r, g, b, w);
  leds[90] = CRGBW(r, g, b, w);
  leds[91] = CRGBW(r, g, b, w);
  leds[92] = CRGBW(r, g, b, w);
  leds[93] = CRGBW(r, g, b, w);
}
void min9()
{
  leds[62] = CRGBW(r, g, b, w);
  leds[63] = CRGBW(r, g, b, w);
  leds[64] = CRGBW(r, g, b, w);
  leds[65] = CRGBW(r, g, b, w);
  leds[70] = CRGBW(r, g, b, w);
  leds[71] = CRGBW(r, g, b, w);
  leds[72] = CRGBW(r, g, b, w);
  leds[73] = CRGBW(r, g, b, w);
  leds[78] = CRGBW(r, g, b, w);
  leds[79] = CRGBW(r, g, b, w);
  leds[85] = CRGBW(r, g, b, w);
  leds[86] = CRGBW(r, g, b, w);
  leds[88] = CRGBW(r, g, b, w);
  leds[90] = CRGBW(r, g, b, w);
  leds[91] = CRGBW(r, g, b, w);
  leds[92] = CRGBW(r, g, b, w);
  leds[93] = CRGBW(r, g, b, w);
}
void min10()
{
  leds[62] = CRGBW(r, g, b, w);
  leds[63] = CRGBW(r, g, b, w);
  leds[65] = CRGBW(r, g, b, w);
  leds[70] = CRGBW(r, g, b, w);
  leds[72] = CRGBW(r, g, b, w);
  leds[73] = CRGBW(r, g, b, w);
  leds[81] = CRGBW(r, g, b, w);
  leds[85] = CRGBW(r, g, b, w);
  leds[87] = CRGBW(r, g, b, w);
  leds[88] = CRGBW(r, g, b, w);
  leds[90] = CRGBW(r, g, b, w);
  leds[91] = CRGBW(r, g, b, w);
  leds[93] = CRGBW(r, g, b, w);
}
void min11()
{
  leds[63] = CRGBW(r, g, b, w);
  leds[65] = CRGBW(r, g, b, w);
  leds[70] = CRGBW(r, g, b, w);
  leds[72] = CRGBW(r, g, b, w);
  leds[79] = CRGBW(r, g, b, w);
  leds[81] = CRGBW(r, g, b, w);
  leds[85] = CRGBW(r, g, b, w);
  leds[87] = CRGBW(r, g, b, w);
  leds[91] = CRGBW(r, g, b, w);
  leds[93] = CRGBW(r, g, b, w);
}
void min12()
{
  leds[62] = CRGBW(r, g, b, w);
  leds[63] = CRGBW(r, g, b, w);
  leds[65] = CRGBW(r, g, b, w);
  leds[70] = CRGBW(r, g, b, w);
  leds[73] = CRGBW(r, g, b, w);
  leds[78] = CRGBW(r, g, b, w);
  leds[79] = CRGBW(r, g, b, w);
  leds[81] = CRGBW(r, g, b, w);
  leds[85] = CRGBW(r, g, b, w);
  leds[87] = CRGBW(r, g, b, w);
  leds[90] = CRGBW(r, g, b, w);
  leds[91] = CRGBW(r, g, b, w);
  leds[93] = CRGBW(r, g, b, w);
}
void min13()
{
  leds[62] = CRGBW(r, g, b, w);
  leds[63] = CRGBW(r, g, b, w);
  leds[65] = CRGBW(r, g, b, w);
  leds[70] = CRGBW(r, g, b, w);
  leds[73] = CRGBW(r, g, b, w);
  leds[78] = CRGBW(r, g, b, w);
  leds[79] = CRGBW(r, g, b, w);
  leds[81] = CRGBW(r, g, b, w);
  leds[85] = CRGBW(r, g, b, w);
  leds[88] = CRGBW(r, g, b, w);
  leds[90] = CRGBW(r, g, b, w);
  leds[91] = CRGBW(r, g, b, w);
  leds[93] = CRGBW(r, g, b, w);
}
void min14()
{
  leds[65] = CRGBW(r, g, b, w);
  leds[70] = CRGBW(r, g, b, w);
  leds[72] = CRGBW(r, g, b, w);
  leds[73] = CRGBW(r, g, b, w);
  leds[78] = CRGBW(r, g, b, w);
  leds[79] = CRGBW(r, g, b, w);
  leds[81] = CRGBW(r, g, b, w);
  leds[85] = CRGBW(r, g, b, w);
  leds[88] = CRGBW(r, g, b, w);
  leds[90] = CRGBW(r, g, b, w);
  leds[93] = CRGBW(r, g, b, w);
}
void min15()
{
  leds[62] = CRGBW(r, g, b, w);
  leds[63] = CRGBW(r, g, b, w);
  leds[65] = CRGBW(r, g, b, w);
  leds[70] = CRGBW(r, g, b, w);
  leds[72] = CRGBW(r, g, b, w);
  leds[78] = CRGBW(r, g, b, w);
  leds[79] = CRGBW(r, g, b, w);
  leds[81] = CRGBW(r, g, b, w);
  leds[85] = CRGBW(r, g, b, w);
  leds[88] = CRGBW(r, g, b, w);
  leds[90] = CRGBW(r, g, b, w);
  leds[91] = CRGBW(r, g, b, w);
  leds[93] = CRGBW(r, g, b, w);
}
void min16()
{
  leds[62] = CRGBW(r, g, b, w);
  leds[63] = CRGBW(r, g, b, w);
  leds[65] = CRGBW(r, g, b, w);
  leds[70] = CRGBW(r, g, b, w);
  leds[72] = CRGBW(r, g, b, w);
  leds[78] = CRGBW(r, g, b, w);
  leds[79] = CRGBW(r, g, b, w);
  leds[81] = CRGBW(r, g, b, w);
  leds[85] = CRGBW(r, g, b, w);
  leds[87] = CRGBW(r, g, b, w);
  leds[88] = CRGBW(r, g, b, w);
  leds[90] = CRGBW(r, g, b, w);
  leds[91] = CRGBW(r, g, b, w);
  leds[93] = CRGBW(r, g, b, w);
}
void min17()
{
  leds[62] = CRGBW(r, g, b, w);
  leds[63] = CRGBW(r, g, b, w);
  leds[65] = CRGBW(r, g, b, w);
  leds[70] = CRGBW(r, g, b, w);
  leds[72] = CRGBW(r, g, b, w);
  leds[73] = CRGBW(r, g, b, w);
  leds[78] = CRGBW(r, g, b, w);
  leds[81] = CRGBW(r, g, b, w);
  leds[85] = CRGBW(r, g, b, w);
  leds[88] = CRGBW(r, g, b, w);
  leds[90] = CRGBW(r, g, b, w);
  leds[93] = CRGBW(r, g, b, w);
}
void min18()
{
  leds[62] = CRGBW(r, g, b, w);
  leds[63] = CRGBW(r, g, b, w);
  leds[65] = CRGBW(r, g, b, w);
  leds[70] = CRGBW(r, g, b, w);
  leds[72] = CRGBW(r, g, b, w);
  leds[73] = CRGBW(r, g, b, w);
  leds[78] = CRGBW(r, g, b, w);
  leds[79] = CRGBW(r, g, b, w);
  leds[81] = CRGBW(r, g, b, w);
  leds[85] = CRGBW(r, g, b, w);
  leds[87] = CRGBW(r, g, b, w);
  leds[88] = CRGBW(r, g, b, w);
  leds[90] = CRGBW(r, g, b, w);
  leds[91] = CRGBW(r, g, b, w);
  leds[93] = CRGBW(r, g, b, w);
}
void min19()
{
  leds[62] = CRGBW(r, g, b, w);
  leds[63] = CRGBW(r, g, b, w);
  leds[65] = CRGBW(r, g, b, w);
  leds[70] = CRGBW(r, g, b, w);
  leds[72] = CRGBW(r, g, b, w);
  leds[73] = CRGBW(r, g, b, w);
  leds[78] = CRGBW(r, g, b, w);
  leds[79] = CRGBW(r, g, b, w);
  leds[81] = CRGBW(r, g, b, w);
  leds[85] = CRGBW(r, g, b, w);
  leds[88] = CRGBW(r, g, b, w);
  leds[90] = CRGBW(r, g, b, w);
  leds[91] = CRGBW(r, g, b, w);
  leds[93] = CRGBW(r, g, b, w);
}
void min20()
{
  leds[62] = CRGBW(r, g, b, w);
  leds[63] = CRGBW(r, g, b, w);
  leds[64] = CRGBW(r, g, b, w);
  leds[65] = CRGBW(r, g, b, w);
  leds[71] = CRGBW(r, g, b, w);
  leds[72] = CRGBW(r, g, b, w);
  leds[73] = CRGBW(r, g, b, w);
  leds[80] = CRGBW(r, g, b, w);
  leds[81] = CRGBW(r, g, b, w);
  leds[85] = CRGBW(r, g, b, w);
  leds[87] = CRGBW(r, g, b, w);
  leds[88] = CRGBW(r, g, b, w);
  leds[90] = CRGBW(r, g, b, w);
  leds[91] = CRGBW(r, g, b, w);
  leds[92] = CRGBW(r, g, b, w);
  leds[93] = CRGBW(r, g, b, w);
}
void min21()
{
  leds[62] = CRGBW(r, g, b, w);
  leds[64] = CRGBW(r, g, b, w);
  leds[65] = CRGBW(r, g, b, w);
  leds[71] = CRGBW(r, g, b, w);
  leds[73] = CRGBW(r, g, b, w);
  leds[78] = CRGBW(r, g, b, w);
  leds[80] = CRGBW(r, g, b, w);
  leds[81] = CRGBW(r, g, b, w);
  leds[85] = CRGBW(r, g, b, w);
  leds[88] = CRGBW(r, g, b, w);
  leds[90] = CRGBW(r, g, b, w);
  leds[92] = CRGBW(r, g, b, w);
  leds[93] = CRGBW(r, g, b, w);
}
void min22()
{
  leds[62] = CRGBW(r, g, b, w);
  leds[63] = CRGBW(r, g, b, w);
  leds[64] = CRGBW(r, g, b, w);
  leds[65] = CRGBW(r, g, b, w);
  leds[71] = CRGBW(r, g, b, w);
  leds[73] = CRGBW(r, g, b, w);
  leds[78] = CRGBW(r, g, b, w);
  leds[79] = CRGBW(r, g, b, w);
  leds[80] = CRGBW(r, g, b, w);
  leds[81] = CRGBW(r, g, b, w);
  leds[85] = CRGBW(r, g, b, w);
  leds[87] = CRGBW(r, g, b, w);
  leds[90] = CRGBW(r, g, b, w);
  leds[91] = CRGBW(r, g, b, w);
  leds[92] = CRGBW(r, g, b, w);
  leds[93] = CRGBW(r, g, b, w);
}
void min23()
{
  leds[62] = CRGBW(r, g, b, w);
  leds[63] = CRGBW(r, g, b, w);
  leds[64] = CRGBW(r, g, b, w);
  leds[65] = CRGBW(r, g, b, w);
  leds[71] = CRGBW(r, g, b, w);
  leds[73] = CRGBW(r, g, b, w);
  leds[78] = CRGBW(r, g, b, w);
  leds[79] = CRGBW(r, g, b, w);
  leds[80] = CRGBW(r, g, b, w);
  leds[81] = CRGBW(r, g, b, w);
  leds[85] = CRGBW(r, g, b, w);
  leds[88] = CRGBW(r, g, b, w);
  leds[90] = CRGBW(r, g, b, w);
  leds[91] = CRGBW(r, g, b, w);
  leds[92] = CRGBW(r, g, b, w);
  leds[93] = CRGBW(r, g, b, w);
}
void min24()
{
  leds[64] = CRGBW(r, g, b, w);
  leds[65] = CRGBW(r, g, b, w);
  leds[71] = CRGBW(r, g, b, w);
  leds[72] = CRGBW(r, g, b, w);
  leds[73] = CRGBW(r, g, b, w);
  leds[78] = CRGBW(r, g, b, w);
  leds[79] = CRGBW(r, g, b, w);
  leds[80] = CRGBW(r, g, b, w);
  leds[81] = CRGBW(r, g, b, w);
  leds[85] = CRGBW(r, g, b, w);
  leds[88] = CRGBW(r, g, b, w);
  leds[90] = CRGBW(r, g, b, w);
  leds[92] = CRGBW(r, g, b, w);
  leds[93] = CRGBW(r, g, b, w);
}
void min25()
{
  leds[62] = CRGBW(r, g, b, w);
  leds[63] = CRGBW(r, g, b, w);
  leds[64] = CRGBW(r, g, b, w);
  leds[65] = CRGBW(r, g, b, w);
  leds[71] = CRGBW(r, g, b, w);
  leds[72] = CRGBW(r, g, b, w);
  leds[78] = CRGBW(r, g, b, w);
  leds[79] = CRGBW(r, g, b, w);
  leds[80] = CRGBW(r, g, b, w);
  leds[81] = CRGBW(r, g, b, w);
  leds[85] = CRGBW(r, g, b, w);
  leds[88] = CRGBW(r, g, b, w);
  leds[90] = CRGBW(r, g, b, w);
  leds[91] = CRGBW(r, g, b, w);
  leds[92] = CRGBW(r, g, b, w);
  leds[93] = CRGBW(r, g, b, w);
}
void min26()
{
  leds[62] = CRGBW(r, g, b, w);
  leds[63] = CRGBW(r, g, b, w);
  leds[64] = CRGBW(r, g, b, w);
  leds[65] = CRGBW(r, g, b, w);
  leds[71] = CRGBW(r, g, b, w);
  leds[72] = CRGBW(r, g, b, w);
  leds[78] = CRGBW(r, g, b, w);
  leds[79] = CRGBW(r, g, b, w);
  leds[80] = CRGBW(r, g, b, w);
  leds[81] = CRGBW(r, g, b, w);
  leds[85] = CRGBW(r, g, b, w);
  leds[87] = CRGBW(r, g, b, w);
  leds[88] = CRGBW(r, g, b, w);
  leds[90] = CRGBW(r, g, b, w);
  leds[91] = CRGBW(r, g, b, w);
  leds[92] = CRGBW(r, g, b, w);
  leds[93] = CRGBW(r, g, b, w);
}
void min27()
{
  leds[62] = CRGBW(r, g, b, w);
  leds[63] = CRGBW(r, g, b, w);
  leds[64] = CRGBW(r, g, b, w);
  leds[65] = CRGBW(r, g, b, w);
  leds[71] = CRGBW(r, g, b, w);
  leds[72] = CRGBW(r, g, b, w);
  leds[73] = CRGBW(r, g, b, w);
  leds[78] = CRGBW(r, g, b, w);
  leds[80] = CRGBW(r, g, b, w);
  leds[81] = CRGBW(r, g, b, w);
  leds[85] = CRGBW(r, g, b, w);
  leds[88] = CRGBW(r, g, b, w);
  leds[90] = CRGBW(r, g, b, w);
  leds[92] = CRGBW(r, g, b, w);
  leds[93] = CRGBW(r, g, b, w);
}
void min28()
{
  leds[62] = CRGBW(r, g, b, w);
  leds[63] = CRGBW(r, g, b, w);
  leds[64] = CRGBW(r, g, b, w);
  leds[65] = CRGBW(r, g, b, w);
  leds[71] = CRGBW(r, g, b, w);
  leds[72] = CRGBW(r, g, b, w);
  leds[73] = CRGBW(r, g, b, w);
  leds[78] = CRGBW(r, g, b, w);
  leds[79] = CRGBW(r, g, b, w);
  leds[80] = CRGBW(r, g, b, w);
  leds[81] = CRGBW(r, g, b, w);
  leds[85] = CRGBW(r, g, b, w);
  leds[87] = CRGBW(r, g, b, w);
  leds[88] = CRGBW(r, g, b, w);
  leds[90] = CRGBW(r, g, b, w);
  leds[91] = CRGBW(r, g, b, w);
  leds[92] = CRGBW(r, g, b, w);
  leds[93] = CRGBW(r, g, b, w);
}
void min29()
{
  leds[62] = CRGBW(r, g, b, w);
  leds[63] = CRGBW(r, g, b, w);
  leds[64] = CRGBW(r, g, b, w);
  leds[65] = CRGBW(r, g, b, w);
  leds[71] = CRGBW(r, g, b, w);
  leds[72] = CRGBW(r, g, b, w);
  leds[73] = CRGBW(r, g, b, w);
  leds[78] = CRGBW(r, g, b, w);
  leds[79] = CRGBW(r, g, b, w);
  leds[80] = CRGBW(r, g, b, w);
  leds[81] = CRGBW(r, g, b, w);
  leds[85] = CRGBW(r, g, b, w);
  leds[88] = CRGBW(r, g, b, w);
  leds[90] = CRGBW(r, g, b, w);
  leds[91] = CRGBW(r, g, b, w);
  leds[92] = CRGBW(r, g, b, w);
  leds[93] = CRGBW(r, g, b, w);
}
void min30()
{
  leds[62] = CRGBW(r, g, b, w);
  leds[63] = CRGBW(r, g, b, w);
  leds[64] = CRGBW(r, g, b, w);
  leds[65] = CRGBW(r, g, b, w);
  leds[71] = CRGBW(r, g, b, w);
  leds[72] = CRGBW(r, g, b, w);
  leds[73] = CRGBW(r, g, b, w);
  leds[80] = CRGBW(r, g, b, w);
  leds[81] = CRGBW(r, g, b, w);
  leds[86] = CRGBW(r, g, b, w);
  leds[87] = CRGBW(r, g, b, w);
  leds[88] = CRGBW(r, g, b, w);
  leds[90] = CRGBW(r, g, b, w);
  leds[91] = CRGBW(r, g, b, w);
  leds[92] = CRGBW(r, g, b, w);
  leds[93] = CRGBW(r, g, b, w);
}
void min31()
{
  leds[62] = CRGBW(r, g, b, w);
  leds[64] = CRGBW(r, g, b, w);
  leds[65] = CRGBW(r, g, b, w);
  leds[71] = CRGBW(r, g, b, w);
  leds[73] = CRGBW(r, g, b, w);
  leds[78] = CRGBW(r, g, b, w);
  leds[80] = CRGBW(r, g, b, w);
  leds[81] = CRGBW(r, g, b, w);
  leds[86] = CRGBW(r, g, b, w);
  leds[88] = CRGBW(r, g, b, w);
  leds[90] = CRGBW(r, g, b, w);
  leds[92] = CRGBW(r, g, b, w);
  leds[93] = CRGBW(r, g, b, w);
}
void min32()
{
  leds[62] = CRGBW(r, g, b, w);
  leds[63] = CRGBW(r, g, b, w);
  leds[64] = CRGBW(r, g, b, w);
  leds[65] = CRGBW(r, g, b, w);
  leds[71] = CRGBW(r, g, b, w);
  leds[73] = CRGBW(r, g, b, w);
  leds[78] = CRGBW(r, g, b, w);
  leds[79] = CRGBW(r, g, b, w);
  leds[80] = CRGBW(r, g, b, w);
  leds[81] = CRGBW(r, g, b, w);
  leds[86] = CRGBW(r, g, b, w);
  leds[87] = CRGBW(r, g, b, w);
  leds[90] = CRGBW(r, g, b, w);
  leds[91] = CRGBW(r, g, b, w);
  leds[92] = CRGBW(r, g, b, w);
  leds[93] = CRGBW(r, g, b, w);
}
void min33()
{
  leds[62] = CRGBW(r, g, b, w);
  leds[63] = CRGBW(r, g, b, w);
  leds[64] = CRGBW(r, g, b, w);
  leds[65] = CRGBW(r, g, b, w);
  leds[71] = CRGBW(r, g, b, w);
  leds[73] = CRGBW(r, g, b, w);
  leds[78] = CRGBW(r, g, b, w);
  leds[79] = CRGBW(r, g, b, w);
  leds[80] = CRGBW(r, g, b, w);
  leds[81] = CRGBW(r, g, b, w);
  leds[86] = CRGBW(r, g, b, w);
  leds[88] = CRGBW(r, g, b, w);
  leds[90] = CRGBW(r, g, b, w);
  leds[91] = CRGBW(r, g, b, w);
  leds[92] = CRGBW(r, g, b, w);
  leds[93] = CRGBW(r, g, b, w);
}
void min34()
{
  leds[64] = CRGBW(r, g, b, w);
  leds[65] = CRGBW(r, g, b, w);
  leds[71] = CRGBW(r, g, b, w);
  leds[72] = CRGBW(r, g, b, w);
  leds[73] = CRGBW(r, g, b, w);
  leds[78] = CRGBW(r, g, b, w);
  leds[79] = CRGBW(r, g, b, w);
  leds[80] = CRGBW(r, g, b, w);
  leds[81] = CRGBW(r, g, b, w);
  leds[86] = CRGBW(r, g, b, w);
  leds[88] = CRGBW(r, g, b, w);
  leds[90] = CRGBW(r, g, b, w);
  leds[92] = CRGBW(r, g, b, w);
  leds[93] = CRGBW(r, g, b, w);
}
void min35()
{
  leds[62] = CRGBW(r, g, b, w);
  leds[63] = CRGBW(r, g, b, w);
  leds[64] = CRGBW(r, g, b, w);
  leds[65] = CRGBW(r, g, b, w);
  leds[71] = CRGBW(r, g, b, w);
  leds[72] = CRGBW(r, g, b, w);
  leds[78] = CRGBW(r, g, b, w);
  leds[79] = CRGBW(r, g, b, w);
  leds[80] = CRGBW(r, g, b, w);
  leds[81] = CRGBW(r, g, b, w);
  leds[86] = CRGBW(r, g, b, w);
  leds[88] = CRGBW(r, g, b, w);
  leds[90] = CRGBW(r, g, b, w);
  leds[91] = CRGBW(r, g, b, w);
  leds[92] = CRGBW(r, g, b, w);
  leds[93] = CRGBW(r, g, b, w);
}
void min36()
{
  leds[62] = CRGBW(r, g, b, w);
  leds[63] = CRGBW(r, g, b, w);
  leds[64] = CRGBW(r, g, b, w);
  leds[65] = CRGBW(r, g, b, w);
  leds[71] = CRGBW(r, g, b, w);
  leds[72] = CRGBW(r, g, b, w);
  leds[78] = CRGBW(r, g, b, w);
  leds[79] = CRGBW(r, g, b, w);
  leds[80] = CRGBW(r, g, b, w);
  leds[81] = CRGBW(r, g, b, w);
  leds[86] = CRGBW(r, g, b, w);
  leds[87] = CRGBW(r, g, b, w);
  leds[88] = CRGBW(r, g, b, w);
  leds[90] = CRGBW(r, g, b, w);
  leds[91] = CRGBW(r, g, b, w);
  leds[92] = CRGBW(r, g, b, w);
  leds[93] = CRGBW(r, g, b, w);
}
void min37()
{
  leds[62] = CRGBW(r, g, b, w);
  leds[63] = CRGBW(r, g, b, w);
  leds[64] = CRGBW(r, g, b, w);
  leds[65] = CRGBW(r, g, b, w);
  leds[71] = CRGBW(r, g, b, w);
  leds[72] = CRGBW(r, g, b, w);
  leds[73] = CRGBW(r, g, b, w);
  leds[78] = CRGBW(r, g, b, w);
  leds[80] = CRGBW(r, g, b, w);
  leds[81] = CRGBW(r, g, b, w);
  leds[86] = CRGBW(r, g, b, w);
  leds[88] = CRGBW(r, g, b, w);
  leds[90] = CRGBW(r, g, b, w);
  leds[92] = CRGBW(r, g, b, w);
  leds[93] = CRGBW(r, g, b, w);
}
void min38()
{
  leds[62] = CRGBW(r, g, b, w);
  leds[63] = CRGBW(r, g, b, w);
  leds[64] = CRGBW(r, g, b, w);
  leds[65] = CRGBW(r, g, b, w);
  leds[71] = CRGBW(r, g, b, w);
  leds[72] = CRGBW(r, g, b, w);
  leds[73] = CRGBW(r, g, b, w);
  leds[78] = CRGBW(r, g, b, w);
  leds[79] = CRGBW(r, g, b, w);
  leds[80] = CRGBW(r, g, b, w);
  leds[81] = CRGBW(r, g, b, w);
  leds[86] = CRGBW(r, g, b, w);
  leds[87] = CRGBW(r, g, b, w);
  leds[88] = CRGBW(r, g, b, w);
  leds[90] = CRGBW(r, g, b, w);
  leds[91] = CRGBW(r, g, b, w);
  leds[92] = CRGBW(r, g, b, w);
  leds[93] = CRGBW(r, g, b, w);
}
void min39()
{
  leds[62] = CRGBW(r, g, b, w);
  leds[63] = CRGBW(r, g, b, w);
  leds[64] = CRGBW(r, g, b, w);
  leds[65] = CRGBW(r, g, b, w);
  leds[71] = CRGBW(r, g, b, w);
  leds[72] = CRGBW(r, g, b, w);
  leds[73] = CRGBW(r, g, b, w);
  leds[78] = CRGBW(r, g, b, w);
  leds[79] = CRGBW(r, g, b, w);
  leds[80] = CRGBW(r, g, b, w);
  leds[81] = CRGBW(r, g, b, w);
  leds[86] = CRGBW(r, g, b, w);
  leds[88] = CRGBW(r, g, b, w);
  leds[90] = CRGBW(r, g, b, w);
  leds[91] = CRGBW(r, g, b, w);
  leds[92] = CRGBW(r, g, b, w);
  leds[93] = CRGBW(r, g, b, w);
}
void min40()
{
  leds[62] = CRGBW(r, g, b, w);
  leds[63] = CRGBW(r, g, b, w);
  leds[70] = CRGBW(r, g, b, w);
  leds[71] = CRGBW(r, g, b, w);
  leds[72] = CRGBW(r, g, b, w);
  leds[73] = CRGBW(r, g, b, w);
  leds[80] = CRGBW(r, g, b, w);
  leds[81] = CRGBW(r, g, b, w);
  leds[86] = CRGBW(r, g, b, w);
  leds[87] = CRGBW(r, g, b, w);
  leds[88] = CRGBW(r, g, b, w);
  leds[90] = CRGBW(r, g, b, w);
  leds[91] = CRGBW(r, g, b, w);
  leds[92] = CRGBW(r, g, b, w);
}
void min41()
{
  leds[62] = CRGBW(r, g, b, w);
  leds[70] = CRGBW(r, g, b, w);
  leds[71] = CRGBW(r, g, b, w);
  leds[73] = CRGBW(r, g, b, w);
  leds[78] = CRGBW(r, g, b, w);
  leds[80] = CRGBW(r, g, b, w);
  leds[81] = CRGBW(r, g, b, w);
  leds[86] = CRGBW(r, g, b, w);
  leds[88] = CRGBW(r, g, b, w);
  leds[90] = CRGBW(r, g, b, w);
  leds[92] = CRGBW(r, g, b, w);
}
void min42()
{
  leds[62] = CRGBW(r, g, b, w);
  leds[63] = CRGBW(r, g, b, w);
  leds[70] = CRGBW(r, g, b, w);
  leds[71] = CRGBW(r, g, b, w);
  leds[73] = CRGBW(r, g, b, w);
  leds[78] = CRGBW(r, g, b, w);
  leds[79] = CRGBW(r, g, b, w);
  leds[80] = CRGBW(r, g, b, w);
  leds[81] = CRGBW(r, g, b, w);
  leds[86] = CRGBW(r, g, b, w);
  leds[87] = CRGBW(r, g, b, w);
  leds[90] = CRGBW(r, g, b, w);
  leds[91] = CRGBW(r, g, b, w);
  leds[92] = CRGBW(r, g, b, w);
}
void min43()
{
  leds[62] = CRGBW(r, g, b, w);
  leds[63] = CRGBW(r, g, b, w);
  leds[70] = CRGBW(r, g, b, w);
  leds[71] = CRGBW(r, g, b, w);
  leds[73] = CRGBW(r, g, b, w);
  leds[78] = CRGBW(r, g, b, w);
  leds[79] = CRGBW(r, g, b, w);
  leds[80] = CRGBW(r, g, b, w);
  leds[81] = CRGBW(r, g, b, w);
  leds[86] = CRGBW(r, g, b, w);
  leds[88] = CRGBW(r, g, b, w);
  leds[90] = CRGBW(r, g, b, w);
  leds[91] = CRGBW(r, g, b, w);
  leds[92] = CRGBW(r, g, b, w);
}
void min44()
{
  leds[70] = CRGBW(r, g, b, w);
  leds[71] = CRGBW(r, g, b, w);
  leds[72] = CRGBW(r, g, b, w);
  leds[73] = CRGBW(r, g, b, w);
  leds[78] = CRGBW(r, g, b, w);
  leds[79] = CRGBW(r, g, b, w);
  leds[80] = CRGBW(r, g, b, w);
  leds[81] = CRGBW(r, g, b, w);
  leds[86] = CRGBW(r, g, b, w);
  leds[88] = CRGBW(r, g, b, w);
  leds[90] = CRGBW(r, g, b, w);
  leds[92] = CRGBW(r, g, b, w);
}
void min45()
{
  leds[62] = CRGBW(r, g, b, w);
  leds[63] = CRGBW(r, g, b, w);
  leds[70] = CRGBW(r, g, b, w);
  leds[71] = CRGBW(r, g, b, w);
  leds[72] = CRGBW(r, g, b, w);
  leds[78] = CRGBW(r, g, b, w);
  leds[79] = CRGBW(r, g, b, w);
  leds[80] = CRGBW(r, g, b, w);
  leds[81] = CRGBW(r, g, b, w);
  leds[86] = CRGBW(r, g, b, w);
  leds[88] = CRGBW(r, g, b, w);
  leds[90] = CRGBW(r, g, b, w);
  leds[91] = CRGBW(r, g, b, w);
  leds[92] = CRGBW(r, g, b, w);
}
void min46()
{
  leds[62] = CRGBW(r, g, b, w);
  leds[63] = CRGBW(r, g, b, w);
  leds[70] = CRGBW(r, g, b, w);
  leds[71] = CRGBW(r, g, b, w);
  leds[72] = CRGBW(r, g, b, w);
  leds[78] = CRGBW(r, g, b, w);
  leds[79] = CRGBW(r, g, b, w);
  leds[80] = CRGBW(r, g, b, w);
  leds[81] = CRGBW(r, g, b, w);
  leds[86] = CRGBW(r, g, b, w);
  leds[87] = CRGBW(r, g, b, w);
  leds[88] = CRGBW(r, g, b, w);
  leds[90] = CRGBW(r, g, b, w);
  leds[91] = CRGBW(r, g, b, w);
  leds[92] = CRGBW(r, g, b, w);
}
void min47()
{
  leds[62] = CRGBW(r, g, b, w);
  leds[63] = CRGBW(r, g, b, w);
  leds[70] = CRGBW(r, g, b, w);
  leds[71] = CRGBW(r, g, b, w);
  leds[72] = CRGBW(r, g, b, w);
  leds[73] = CRGBW(r, g, b, w);
  leds[78] = CRGBW(r, g, b, w);
  leds[80] = CRGBW(r, g, b, w);
  leds[81] = CRGBW(r, g, b, w);
  leds[86] = CRGBW(r, g, b, w);
  leds[88] = CRGBW(r, g, b, w);
  leds[90] = CRGBW(r, g, b, w);
  leds[92] = CRGBW(r, g, b, w);
}
void min48()
{
  leds[62] = CRGBW(r, g, b, w);
  leds[63] = CRGBW(r, g, b, w);
  leds[70] = CRGBW(r, g, b, w);
  leds[71] = CRGBW(r, g, b, w);
  leds[72] = CRGBW(r, g, b, w);
  leds[73] = CRGBW(r, g, b, w);
  leds[78] = CRGBW(r, g, b, w);
  leds[79] = CRGBW(r, g, b, w);
  leds[80] = CRGBW(r, g, b, w);
  leds[81] = CRGBW(r, g, b, w);
  leds[86] = CRGBW(r, g, b, w);
  leds[87] = CRGBW(r, g, b, w);
  leds[88] = CRGBW(r, g, b, w);
  leds[90] = CRGBW(r, g, b, w);
  leds[91] = CRGBW(r, g, b, w);
  leds[92] = CRGBW(r, g, b, w);
}
void min49()
{
  leds[62] = CRGBW(r, g, b, w);
  leds[63] = CRGBW(r, g, b, w);
  leds[70] = CRGBW(r, g, b, w);
  leds[71] = CRGBW(r, g, b, w);
  leds[72] = CRGBW(r, g, b, w);
  leds[73] = CRGBW(r, g, b, w);
  leds[78] = CRGBW(r, g, b, w);
  leds[79] = CRGBW(r, g, b, w);
  leds[80] = CRGBW(r, g, b, w);
  leds[81] = CRGBW(r, g, b, w);
  leds[86] = CRGBW(r, g, b, w);
  leds[88] = CRGBW(r, g, b, w);
  leds[90] = CRGBW(r, g, b, w);
  leds[91] = CRGBW(r, g, b, w);
  leds[92] = CRGBW(r, g, b, w);
}
void min50()
{
  leds[62] = CRGBW(r, g, b, w);
  leds[63] = CRGBW(r, g, b, w);
  leds[64] = CRGBW(r, g, b, w);
  leds[65] = CRGBW(r, g, b, w);
  leds[70] = CRGBW(r, g, b, w);
  leds[72] = CRGBW(r, g, b, w);
  leds[73] = CRGBW(r, g, b, w);
  leds[80] = CRGBW(r, g, b, w);
  leds[81] = CRGBW(r, g, b, w);
  leds[86] = CRGBW(r, g, b, w);
  leds[87] = CRGBW(r, g, b, w);
  leds[88] = CRGBW(r, g, b, w);
  leds[90] = CRGBW(r, g, b, w);
  leds[91] = CRGBW(r, g, b, w);
  leds[92] = CRGBW(r, g, b, w);
  leds[93] = CRGBW(r, g, b, w);
}
void min51()
{
  leds[62] = CRGBW(r, g, b, w);
  leds[64] = CRGBW(r, g, b, w);
  leds[65] = CRGBW(r, g, b, w);
  leds[70] = CRGBW(r, g, b, w);
  leds[73] = CRGBW(r, g, b, w);
  leds[78] = CRGBW(r, g, b, w);
  leds[80] = CRGBW(r, g, b, w);
  leds[81] = CRGBW(r, g, b, w);
  leds[86] = CRGBW(r, g, b, w);
  leds[88] = CRGBW(r, g, b, w);
  leds[90] = CRGBW(r, g, b, w);
  leds[92] = CRGBW(r, g, b, w);
  leds[93] = CRGBW(r, g, b, w);
}
void min52()
{
  leds[62] = CRGBW(r, g, b, w);
  leds[63] = CRGBW(r, g, b, w);
  leds[64] = CRGBW(r, g, b, w);
  leds[65] = CRGBW(r, g, b, w);
  leds[70] = CRGBW(r, g, b, w);
  leds[73] = CRGBW(r, g, b, w);
  leds[78] = CRGBW(r, g, b, w);
  leds[79] = CRGBW(r, g, b, w);
  leds[80] = CRGBW(r, g, b, w);
  leds[81] = CRGBW(r, g, b, w);
  leds[86] = CRGBW(r, g, b, w);
  leds[87] = CRGBW(r, g, b, w);
  leds[90] = CRGBW(r, g, b, w);
  leds[91] = CRGBW(r, g, b, w);
  leds[92] = CRGBW(r, g, b, w);
  leds[93] = CRGBW(r, g, b, w);
}
void min53()
{
  leds[62] = CRGBW(r, g, b, w);
  leds[63] = CRGBW(r, g, b, w);
  leds[64] = CRGBW(r, g, b, w);
  leds[65] = CRGBW(r, g, b, w);
  leds[70] = CRGBW(r, g, b, w);
  leds[73] = CRGBW(r, g, b, w);
  leds[78] = CRGBW(r, g, b, w);
  leds[79] = CRGBW(r, g, b, w);
  leds[80] = CRGBW(r, g, b, w);
  leds[81] = CRGBW(r, g, b, w);
  leds[86] = CRGBW(r, g, b, w);
  leds[88] = CRGBW(r, g, b, w);
  leds[90] = CRGBW(r, g, b, w);
  leds[91] = CRGBW(r, g, b, w);
  leds[92] = CRGBW(r, g, b, w);
  leds[93] = CRGBW(r, g, b, w);
}
void min54()
{
  leds[64] = CRGBW(r, g, b, w);
  leds[65] = CRGBW(r, g, b, w);
  leds[70] = CRGBW(r, g, b, w);
  leds[72] = CRGBW(r, g, b, w);
  leds[73] = CRGBW(r, g, b, w);
  leds[78] = CRGBW(r, g, b, w);
  leds[79] = CRGBW(r, g, b, w);
  leds[80] = CRGBW(r, g, b, w);
  leds[81] = CRGBW(r, g, b, w);
  leds[86] = CRGBW(r, g, b, w);
  leds[88] = CRGBW(r, g, b, w);
  leds[90] = CRGBW(r, g, b, w);
  leds[92] = CRGBW(r, g, b, w);
  leds[93] = CRGBW(r, g, b, w);
}
void min55()
{
  leds[62] = CRGBW(r, g, b, w);
  leds[63] = CRGBW(r, g, b, w);
  leds[64] = CRGBW(r, g, b, w);
  leds[65] = CRGBW(r, g, b, w);
  leds[70] = CRGBW(r, g, b, w);
  leds[72] = CRGBW(r, g, b, w);
  leds[78] = CRGBW(r, g, b, w);
  leds[79] = CRGBW(r, g, b, w);
  leds[80] = CRGBW(r, g, b, w);
  leds[81] = CRGBW(r, g, b, w);
  leds[86] = CRGBW(r, g, b, w);
  leds[88] = CRGBW(r, g, b, w);
  leds[90] = CRGBW(r, g, b, w);
  leds[91] = CRGBW(r, g, b, w);
  leds[92] = CRGBW(r, g, b, w);
  leds[93] = CRGBW(r, g, b, w);
}
void min56()
{
  leds[62] = CRGBW(r, g, b, w);
  leds[63] = CRGBW(r, g, b, w);
  leds[64] = CRGBW(r, g, b, w);
  leds[65] = CRGBW(r, g, b, w);
  leds[70] = CRGBW(r, g, b, w);
  leds[72] = CRGBW(r, g, b, w);
  leds[78] = CRGBW(r, g, b, w);
  leds[79] = CRGBW(r, g, b, w);
  leds[80] = CRGBW(r, g, b, w);
  leds[81] = CRGBW(r, g, b, w);
  leds[86] = CRGBW(r, g, b, w);
  leds[87] = CRGBW(r, g, b, w);
  leds[88] = CRGBW(r, g, b, w);
  leds[90] = CRGBW(r, g, b, w);
  leds[91] = CRGBW(r, g, b, w);
  leds[92] = CRGBW(r, g, b, w);
  leds[93] = CRGBW(r, g, b, w);
}
void min57()
{
  leds[62] = CRGBW(r, g, b, w);
  leds[63] = CRGBW(r, g, b, w);
  leds[64] = CRGBW(r, g, b, w);
  leds[65] = CRGBW(r, g, b, w);
  leds[70] = CRGBW(r, g, b, w);
  leds[72] = CRGBW(r, g, b, w);
  leds[73] = CRGBW(r, g, b, w);
  leds[78] = CRGBW(r, g, b, w);
  leds[80] = CRGBW(r, g, b, w);
  leds[81] = CRGBW(r, g, b, w);
  leds[86] = CRGBW(r, g, b, w);
  leds[88] = CRGBW(r, g, b, w);
  leds[90] = CRGBW(r, g, b, w);
  leds[92] = CRGBW(r, g, b, w);
  leds[93] = CRGBW(r, g, b, w);
}
void min58()
{
  leds[62] = CRGBW(r, g, b, w);
  leds[63] = CRGBW(r, g, b, w);
  leds[64] = CRGBW(r, g, b, w);
  leds[65] = CRGBW(r, g, b, w);
  leds[70] = CRGBW(r, g, b, w);
  leds[72] = CRGBW(r, g, b, w);
  leds[73] = CRGBW(r, g, b, w);
  leds[78] = CRGBW(r, g, b, w);
  leds[79] = CRGBW(r, g, b, w);
  leds[80] = CRGBW(r, g, b, w);
  leds[81] = CRGBW(r, g, b, w);
  leds[86] = CRGBW(r, g, b, w);
  leds[87] = CRGBW(r, g, b, w);
  leds[88] = CRGBW(r, g, b, w);
  leds[90] = CRGBW(r, g, b, w);
  leds[91] = CRGBW(r, g, b, w);
  leds[92] = CRGBW(r, g, b, w);
  leds[93] = CRGBW(r, g, b, w);
}
void min59()
{
  leds[62] = CRGBW(r, g, b, w);
  leds[63] = CRGBW(r, g, b, w);
  leds[64] = CRGBW(r, g, b, w);
  leds[65] = CRGBW(r, g, b, w);
  leds[70] = CRGBW(r, g, b, w);
  leds[72] = CRGBW(r, g, b, w);
  leds[73] = CRGBW(r, g, b, w);
  leds[78] = CRGBW(r, g, b, w);
  leds[79] = CRGBW(r, g, b, w);
  leds[80] = CRGBW(r, g, b, w);
  leds[81] = CRGBW(r, g, b, w);
  leds[86] = CRGBW(r, g, b, w);
  leds[88] = CRGBW(r, g, b, w);
  leds[90] = CRGBW(r, g, b, w);
  leds[91] = CRGBW(r, g, b, w);
  leds[92] = CRGBW(r, g, b, w);
  leds[93] = CRGBW(r, g, b, w);
}
