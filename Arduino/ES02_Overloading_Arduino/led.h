#ifndef LED_H
#define LED_H

class LED {
public:
    LED(const int PIN);
    void accendi();
    void accendi(int durata);
    void spegni();
    void spegni(int ritardo);
    void inverti();
    void lampeggio(int numLampeggi);
    void lampeggio(int numLampeggi, int durata);
    void test(int numTest);

private:
    const int PIN;
    bool isAcceso; 
};

#endif // LED_H