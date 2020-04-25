/* Проект "Светомузыка"
 * Настраивается внизу
 * Проект в разработке
 * Разработан : Votin306
 */
 
//***************************Настройка ленты*******************************
#define NUM_LEDS 8
#define DATA_PIN 6
//*************************************************************************
//***************************Настройка микрофона***************************
#define MP_PIN 3
//*************************************************************************

CRGB leds[NUM_LEDS];
#include <FastLED.h>
int color; //создем данные с типом INT
int brigges;
void setup() {
  FastLED.addLeds<WS2812B, DATA_PIN, GRB>(leds, NUM_LEDS);
}

void loop() {
  color = analogRead(MP_PIN);
  brigges = analogRead(MP_PIN);
  color = map(color, 10 , 600 , 0 , 3);
  brigges = map(brigges, 10 , 600 , 0 , 200);
  for (int i = 0; i < NUM_LEDS; i++)
  {
    if(color == 0){leds[i] = CRGB::Red;}
    if(color == 1){leds[i] = CRGB::Black;}
    if(color == 2){leds[i] = CRGB::Green;}
    if(color == 3){leds[i] = CRGB::Blue;}
  }
  // Передаем цвета ленте.
  FastLED.show();
 }
