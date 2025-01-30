#include "led.h"
#include "bottone.h"

#define NUM_LED 4
#define NUM_PULSANTI 4

LED leds[NUM_LED] = { 
  LED(1), LED(2), LED(3), LED(4) 
};

Bottone bottoni[NUM_PULSANTI] = { 
  Bottone(8), Bottone(9), Bottone(10), Bottone(11) 
};


void setup() {
  Serial.begin(115200);

  // Inserisci che test vuoi effettuare.
  // ES: il primo led e il primo bottone
  leds[0].test(-1);
  bottoni[0].test(-1);

  // Cambia -1 con il test che vuoi effettuare
}

void loop() {
  if(bottoni[0].click()) {
    leds[0].inverti();
  } 

  if(bottoni[1].doubleClick()) {
    leds[1].inverti();
  }

  if(bottoni[2].longPress()) {
    leds[2].inverti();
  }

  if(bottoni[3].click()) {
   leds[3].lampeggio(2);
   }
}
