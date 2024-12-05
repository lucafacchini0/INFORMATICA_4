#include <iostream>

class Rettangolo {
    public:
        Rettangolo() 
            : base(0), altezza(0) {}

        Rettangolo(double base) 
            : base(base), altezza(0) {}
    
        Rettangolo(double base, double altezza) 
            : base(base), altezza(altezza) {}

        void setBase(double x) { base = x; }
        void setAltezza(double x) { altezza = x; }
        double getBase() { return base; }
        double getAltezza() { return altezza; }
        double getPerimetro() { return (base * 2) + (altezza *2 ); }
        double getArea() { return base * altezza; }
        
        void stampa() {
            std::cout << "Base:" << getBase() << std::endl;
            std::cout << "Altezza:" << getAltezza() << std::endl;
            std::cout << "Perimetro:" << getPerimetro() << std::endl;
            std::cout << "Area:" << getArea() << std::endl;
        }
        
    private:
        double base;
        double altezza;
};

int main() {
    Rettangolo rettangolo1(10, 20);
}