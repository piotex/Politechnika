#ifndef PRZESZKODA_HH
#define PRZESZKODA_HH

#include "InterfejsDron.hh"

class Przeszkoda {     
  protected:
  public:
    /*!
    * \brief abstrakcyjna metoda - docelowo sprawdza kolizje
    * \param dron - instancja klasy dron przekazana ponieważ zawiera wszystkie punkty drona potrzebne do wykrycia kolizji
    */ 
    virtual bool czy_kolizja(InterfejsDron* dron) = 0; 
};



#endif
