#include "bottone.h"
#include <Arduino.h>


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
void Bottone::test(int numTest) {
  switch(numTest) {
    case 1: 
      if (isPremuto()) {
        Serial.println("Bottone premuto");
      } else {
        Serial.println("Bottone non premuto");
      }
      break;

    case 2:
      if (longPress()) {
        Serial.println("Bottone premuto a lungo");
      } else {
        Serial.println("Bottone non premuto a lungo");
      }
      break;

    case 3:
      if (click()) {
        Serial.println("Bottone cliccato");
      } else {
        Serial.println("Bottone non cliccato");
      }
      break;

    case 4:
      if (doubleClick()) {
        Serial.println("Bottone doppio cliccato");
      } else {
        Serial.println("Bottone non doppio cliccato");
      }
      break;

    default:
      break;
  }
}