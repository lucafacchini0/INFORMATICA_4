#include "componenti.h"

namespace Componenti {

  // Implementazione classe Bottone
  Bottone::Bottone(const int PIN) 
    : PIN(PIN), contatorePremuto(0), statoPrecedente(false), 
      ultimoTempoClick(0), primoClickRilevato(false) {
      pinMode(PIN, INPUT_PULLUP);
  }

  bool Bottone::isPremuto() {
      return !digitalRead(PIN);
  }

  bool Bottone::longPress() {
      if (isPremuto()) { 
          unsigned long startTime = millis();
          while (isPremuto()) { 
              if (millis() - startTime >= 2000) { 
                  return true;
              }
          }
      }
      return false; 
  }

  bool Bottone::click() {
      unsigned long tempoAttuale = millis();

      if (isPremuto() && !statoPrecedente) {
          delay(10); 
          if (isPremuto()) {
              statoPrecedente = true;
              return true;
          }
      }

      if (!isPremuto() && statoPrecedente) {
          statoPrecedente = false;
      }

      return false;
  }

  bool Bottone::doubleClick() {
      unsigned long tempoAttuale = millis();

      if (isPremuto()) {
          delay(10); 
          if (isPremuto()) {
              while (isPremuto()) {}

              if (primoClickRilevato && (tempoAttuale - ultimoTempoClick) <= 400) {
                  primoClickRilevato = false;
                  return true;
              }

              primoClickRilevato = true;
              ultimoTempoClick = tempoAttuale;
          }
      }

      if (primoClickRilevato && (tempoAttuale - ultimoTempoClick) > 400) {
          primoClickRilevato = false;
      }

      return false;
  }

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
}
