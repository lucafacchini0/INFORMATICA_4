#include <iostream>
#include "rettangolo.h"

Rettangolo::Rettangolo() 
    : base(0), altezza(0) {}

Rettangolo::Rettangolo(double valore)
    : base(valore), altezza(valore) {}

Rettangolo::Rettangolo(double base, double altezza)
    : base(base), altezza(altezza) {}

Rettangolo::~Rettangolo() {
    std::cout << "Hai chiamato distruttore" << std::endl;
}

// Metodi di calcolo
double Rettangolo::calcoloPerimetro() { return (base * 2) + (altezza * 2); }
double Rettangolo::calcoloArea() { return base * altezza; }

// Setters
void Rettangolo::setBase(double x) { base = x; }
void Rettangolo::setAltezza(double x) { altezza = x; }

// Getters
double Rettangolo::getBase() { return base; }
double Rettangolo::getAltezza() { return altezza; }
double Rettangolo::getPerimetro() { return Rettangolo::calcoloPerimetro(); }
double Rettangolo::getArea() { return Rettangolo::calcoloArea(); }

// Generali
void Rettangolo::stampa() {
    std::cout << "Base:" << getBase() << std::endl;
    std::cout << "Altezza:" << getAltezza() << std::endl;
    std::cout << "Perimetro:" << getPerimetro() << std::endl;
    std::cout << "Area:" << getArea() << std::endl;
    std::cout << std::endl;

}