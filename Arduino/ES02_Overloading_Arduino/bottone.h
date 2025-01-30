#ifndef BOTTONE_H
#define BOTTONE_H

class Bottone {
public:
    Bottone(const int PIN);
    bool isPremuto();
    bool longPress();
    bool click();
    bool doubleClick();
    void test(int numTest);

private:
    const int PIN;
    unsigned long contatorePremuto;
    bool statoPrecedente;
    unsigned long ultimoTempoClick;
    bool primoClickRilevato;
        unsigned long tempoPressione;

};

#endif // BOTTONE_H