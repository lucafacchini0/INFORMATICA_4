#ifndef RETTANGOLO_H
#define RETTANGOLO_H

class Rettangolo {
    
    private:
        double base;
        double altezza;

        // Metodi di calcolo
        double calcoloPerimetro();
        double calcoloArea();

    public:
        // Costruttori
        Rettangolo();
        Rettangolo(double base);
        Rettangolo(double base, double altezza);

        // Distruttore
        ~Rettangolo();


        // Setters
        void setBase(double base);
        void setAltezza(double altezza);

        // Getters
        double getBase();
        double getAltezza();
        double getPerimetro();
        double getArea();

        // Generali
        void stampa();
};

#endif // RETTANGOLO_H