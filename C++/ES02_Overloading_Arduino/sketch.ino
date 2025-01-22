#include "componenti.h"

#define NUM_LED 4
#define NUM_PULSANTI 4

Componenti::LED leds[NUM_LED] = {
  Componenti::LED(1),
  Componenti::LED(2),
  Componenti::LED(3),
  Componenti::LED(4)
};

Componenti::Bottone bottoni[NUM_PULSANTI] = {
  Componenti::Bottone(8),
  Componenti::Bottone(9),
  Componenti::Bottone(10),
  Componenti::Bottone(11)

};

void test(int opzione) {
  
  switch(opzione) {

    case 1: 
      leds[0].accendi();
      delay(1000); 
      leds[0].spegni();
      break;

    case 2:
      leds[0].accendi(500);  
      break;

    case 3:
      leds[0].spegni(300); 
      break;

    case 4:
      leds[0].inverti();  
      break;

    case 5:
      leds[0].lampeggio(3);  // Fa lampeggiare il LED 3 volte
      break;

    case 6:
      leds[0].lampeggio(2, 1000);  // Fa lampeggiare l'LED 2 volte con 1 secondo di durata
      break;

    default:     
      break;
  }
}


void setup() {
  test(-1); // inserisci un numero per fare il test!
}

void loop() {

  /*
   @note: Posso premere più bottoni contemporaneamente.
   Attenzione però: non impiego il multithreading.
   in ogni caso, se il codice dovesse imbattere in
   un ciclo while, tutto verrà bloccato. E pertanto
   non sarei in grado di premere più pulsanti
   contemporaneamente.
  */
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
