#include <FastLED.h>

#define LEDS_PIN_1      10   // Первая лента на GPIO 10
#define NUM_LEDS_1      15   // Количество диодов в первой ленте

#define LEDS_PIN_2      2    // Вторая лента на GPIO 2 (не забудьте про подтяжку к 3V3!)
#define NUM_LEDS_2      20   // Количество диодов во второй ленте

#define LED_TYPE        WS2812B
#define COLOR_ORDER     GRB

// Создаем два отдельных массива под каждую ленту
CRGB strip1[NUM_LEDS_1];
CRGB strip2[NUM_LEDS_2];

void setup() {
  Serial.begin(115200);
  // Инициализируем первую ленту на пине 10
  FastLED.addLeds<LED_TYPE, LEDS_PIN_1, COLOR_ORDER>(strip1, NUM_LEDS_1).setCorrection(TypicalLEDStrip);
  
  // Инициализируем вторую ленту на пине 2
  FastLED.addLeds<LED_TYPE, LEDS_PIN_2, COLOR_ORDER>(strip2, NUM_LEDS_2).setCorrection(TypicalLEDStrip);

  FastLED.setBrightness(50); // Общая яркость
}

void loop() {
  // Красим первую ленту в СИНИЙ цвет
  for(int i = 0; i < NUM_LEDS_1; i++) {
    strip1[i] = CRGB::Green;
    strip2[i] = CRGB::Red;
  }

  FastLED.show(); // Отправляем данные на обе ленты одновременно
  delay(500);
  FastLED.clear();
  for(int i = 0; i < NUM_LEDS_1; i++) {
    strip1[i] = CRGB::Red;
    strip2[i] = CRGB::Green;
  }
  FastLED.show();
  delay(500);
  FastLED.clear();

  // Очищаем (выключаем) обе ленты
  // FastLED.clear();
  // FastLED.show();
  // delay(500);
}
