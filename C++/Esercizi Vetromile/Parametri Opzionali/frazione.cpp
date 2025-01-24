#include <iostream>

class Frazione {

    public:

        Frazione(int numeratore=0, int denominatore=1) {
            this->numeratore = numeratore;
            this->denominatore = denominatore;
        }

    private:
        int numeratore;
        int denominatore;
};