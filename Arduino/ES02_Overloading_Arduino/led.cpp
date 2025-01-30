#include "led.h"
#include <Arduino.h>

// Implementazione classe LED
  LED::LED(const int PIN) : PIN(PIN), isAcceso(false) { 
      pinMode(PIN, OUTPUT);
  }

  void LED::accendi() {
      digitalWrite(PIN, HIGH);
      isAcceso = true;
  }

  void LED::accendi(int durata) {
      accendi();
      delay(durata);
      spegni();
  }

  void LED::spegni() {
      digitalWrite(PIN, LOW);
      isAcceso = false;
  }

  void LED::spegni(int ritardo) {
      delay(ritardo);
      spegni();
  }

  void LED::inverti() {
      if (isAcceso) {
          spegni();
      } else {
          accendi();
      }
  }

  void LED::lampeggio(int numLampeggi) {
      for (int i = 0; i < numLampeggi; i++) {
          inverti();
          delay(500);
          inverti();
          delay(500);
      }
  }

  void LED::lampeggio(int numLampeggi, int durata) {
      for (int i = 0; i < numLampeggi; i++) {
          inverti();
          delay(durata);
          inverti();
          delay(durata);
      }
  }

    void LED::test(int numTest) {
    switch(numTest) {
        case 1: accendi(); break;
        case 2: accendi(500); break;
        case 3: spegni(); break;
        case 4: spegni(300); break;
        case 5: inverti(); break;
        case 6: lampeggio(3); break;
        case 7: lampeggio(2, 1000); break;
        default: break;
    }
  }