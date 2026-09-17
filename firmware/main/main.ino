#include <FastLED.h>
#include <ESP32Servo.h>

#define LEDS_PIN_1      10   // Первая лента на GPIO 10
#define LEDS_PIN_2      2    // Вторая лента на GPIO 2 (не забудьте про подтяжку к 3V3!)
#define NUM_LEDS_1      8   // Количество диодов в первой ленте
#define NUM_LEDS_2      8   // Количество диодов во второй ленте

#define LED_TYPE        WS2812B
#define COLOR_ORDER     GRB

// Создаем два отдельных массива под каждую ленту
CRGB strip1[NUM_LEDS_1];
CRGB strip2[NUM_LEDS_2];
Servo Lservo;  // create Servo object to control a servo
Servo Rservo;  // create Servo object to control a servo
// twelve Servo objects can be created on most boards

int pos = 100;    // variable to store the servo position


void setup() {
  // Serial.begin(115200);
  // Инициализируем первую ленту на пине 10
  FastLED.addLeds<LED_TYPE, LEDS_PIN_1, COLOR_ORDER>(strip1, NUM_LEDS_1).setCorrection(TypicalLEDStrip);
  
  // Инициализируем вторую ленту на пине 2
  FastLED.addLeds<LED_TYPE, LEDS_PIN_2, COLOR_ORDER>(strip2, NUM_LEDS_2).setCorrection(TypicalLEDStrip);

  FastLED.setBrightness(20); // Общая яркость
  Lservo.attach(20);  // attaches the servo on pin 9 to the Servo object
  Rservo.attach(1);  // attaches the servo on pin 9 to the Servo object
}

void loop() {
  // Красим первую ленту в СИНИЙ цвет
  for(int i = 0; i < NUM_LEDS_1; i++) {
    strip1[i] = CRGB::Green;
    strip2[i] = CRGB::Red;
  }

  FastLED.show(); // Отправляем данные на обе ленты одновременно
  for (pos = 0; pos <= 40; pos++) { // goes from 0 degrees to 180 degrees
    Lservo.write(100 + pos);              // tell servo to go to position in variable 'pos'
    Rservo.write(140 - pos);              // tell servo to go to position in variable 'pos'
    delay(17);                       // waits 15 ms for the servo to reach the position
  }
  delay(500);
  FastLED.clear();
  for(int i = 0; i < NUM_LEDS_1; i++) {
    strip1[i] = CRGB::Red;
    strip2[i] = CRGB::Green;
  }
  FastLED.show();
  delay(500);
  FastLED.clear();

  for (pos = 0; pos <= 40; pos++) { // goes from 0 degrees to 180 degrees
    Rservo.write(100 + pos);              // tell servo to go to position in variable 'pos'
    Lservo.write(140 - pos);              // tell servo to go to position in variable 'pos'
    delay(17);                       // waits 15 ms for the servo to reach the position
  }
  delay(3000);
}
