#include <iostream>

class Rettangolo {
    public:
        Rettangolo() {
            base = 0;
            altezza = 0;
        }

        Rettangolo(int base, int altezza) {
            this->base = base;
            this->altezza = altezza;
        }

        int getBase() { return base; }
        void setBase(int base) {
            this->base = base;
        }
    private:
        int base;
        int altezza;
};

int main() {
    Rettangolo rec(10, 20);
}