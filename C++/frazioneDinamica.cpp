#include <iostream>
#include <memory>

class Frazione {
    public:
        Frazione() 
            : numeratore(0), denominatore(1) {}

        Frazione(int numeratore, int denominatore)
            : numeratore(numeratore), denominatore(denominatore) {}

        Frazione(std::shared_ptr<Frazione> numeratore, std::shared_ptr<Frazione> denominatore)
            : numeratore(0), denominatore(1), numeratorePtr(numeratore), denominatorePtr(denominatore) {}

        void stampa() const {
            if (numeratorePtr && denominatorePtr) {
                numeratorePtr->stampa();
                std::cout << " / ";
                denominatorePtr->stampa();
            } else {
                std::cout << numeratore << " / " << denominatore;
            }
        }

    private:
        int numeratore;
        int denominatore;
        std::shared_ptr<Frazione> numeratorePtr;
        std::shared_ptr<Frazione> denominatorePtr;
};

int main() {
    auto f1 = std::make_shared<Frazione>(3, 4);
    auto f2 = std::make_shared<Frazione>(5, 6);

    auto fc = std::make_shared<Frazione>(f1, f2);

    auto f3 = std::make_shared<Frazione>(7, 8);
    auto fc2 = std::make_shared<Frazione>(fc, f3);
    auto fc6 = std::make_shared<Frazione>(fc2, f3);

    std::cout << "Frazione composta: ";
    fc6->stampa();
    std::cout << std::endl;

    return 0;
}
