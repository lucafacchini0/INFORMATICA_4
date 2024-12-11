// Link Wokwi
// https://wokwi.com/projects/416977636772498433
class LED {
  public:
    LED(const int PIN) : PIN(PIN) { pinMode(PIN, OUTPUT); }

    void accendi() { digitalWrite(PIN, HIGH); }
    void spegni() { digitalWrite(PIN, LOW); }

  private:
    const int PIN; 
};

LED led(8);

void setup() {
  // LED led(8); 
}

void loop() {
  led.accendi(); 
  delay(200);   
  led.spegni();  
  delay(200);   
}