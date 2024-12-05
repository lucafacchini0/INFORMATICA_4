#include <iostream>

class Frazione {
    public:
        Frazione() 
            : numeratore(0), denominatore(1) {}

        Frazione(int numeratore, int denominatore)
            : numeratore(numeratore), denominatore(denominatore) {}

        void stampa() const { std::cout << numeratore << " / " << denominatore; }

    private:
        int numeratore;
        int denominatore;
};

class FrazioneComposta {
    public:
        FrazioneComposta(const Frazione& numeratore, const Frazione& denominatore)
            : numeratore(numeratore), denominatore(denominatore) {}

        void stampa() const {
            numeratore.stampa();
            std::cout << " / ";
            denominatore.stampa();
            std::cout << std::endl;
        }

    private:
        Frazione numeratore;
        Frazione denominatore;
};

int main() {
    Frazione f1(3, 4);
    Frazione f2(5, 6);
    FrazioneComposta fc(f1, f2);

    std::cout << "Frazione composta: ";
    fc.stampa();

    return 0;
}
