// Link Wokwi
// https://wokwi.com/projects/416977636772498433
class LED {
  public:
    LED(const int PIN) : PIN(PIN), stato(false) {
        pinMode(PIN, OUTPUT);
        spegni();
    }

    void accendi() {
        digitalWrite(PIN, HIGH);
        stato = true;
    }

    void spegni() {
        digitalWrite(PIN, LOW);
        stato = false;
    }

    void inverti() {
        if(stato) spegni();
        else accendi();
    }

    void lampeggio(int numLampeggi) {
        for (int i = 0; i < numLampeggi; i++) {
            accendi();
            delay(500);
            spegni();
            delay(500);
        }
    }

    void test(int numeroTest) {
        for (int i = 0; i < numeroTest; i++) {
            accendi();
            delay(300);
            spegni();
            delay(300);
        }
        lampeggio(3); // test terminato: 3 lampeggi
    }

  private:
    const int PIN;
    bool stato; // memorizza lo stato del LED (1=acceso, 0=spento)
};

LED led(8);

void setup() {}

void loop() {
    led.lampeggio(5); 
    delay(2000);       

    led.inverti();    
    delay(1000);      

    led.test(2);      
    delay(3000);       
}
