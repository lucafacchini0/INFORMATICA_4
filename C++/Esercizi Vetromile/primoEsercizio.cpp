#include <iostream>

class Frazione {
    public:
        // Costruttori
        Frazione() {}
        Frazione(int numeratore, int denominatore) {
            this->numeratore = numeratore;
            this->denominatore = denominatore;
        }

        // Getters
        int getNumeratore() { return numeratore; }
        int getDenominatore() { return denominatore; }

        // Setter
        void setNumeratore(int x) { numeratore = x; }
        void setDenominatore(int x) { denominatore = x; }

        // Stampe
        void stampaFrazione() {
            std::cout << numeratore << " / " << denominatore << std::endl;
        }

    private:
        int numeratore;
        int denominatore;
};

int main() {
    Frazione frazione1;
    frazione1.setNumeratore(3);
    frazione1.setDenominatore(4);
    frazione1.stampaFrazione();

    Frazione frazione2(10, 20);
    frazione2.stampaFrazione();
}