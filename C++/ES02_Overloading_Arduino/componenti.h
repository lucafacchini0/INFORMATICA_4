#ifndef COMPONENTI_H
#define COMPONENTI_H

namespace Componenti {

  class Bottone {
    public:
      Bottone(const int PIN);
      bool isPremuto();
      bool longPress();
      bool click();
      bool doubleClick();

    private:
      const int PIN;
      unsigned long contatorePremuto;
      bool statoPrecedente;
      unsigned long ultimoTempoClick;
      bool primoClickRilevato;
  };

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

}

#endif // COMPONENTI_H
