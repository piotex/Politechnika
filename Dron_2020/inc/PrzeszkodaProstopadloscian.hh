#ifndef PRZESZKODAPROSTOPADLOSCIAN_HH
#define PRZESZKODAPROSTOPADLOSCIAN_HH

#include "Przeszkoda.hh"
#include "Prostopadloscian.hh"

class PrzeszkodaProstopadloscian : public Przeszkoda ,public Prostopadloscian {      
  protected:
  public:
    /*!
    * \brief konstruktor ustawiajacy poczatkowe wartosci PrzeszkodaProstopadloscian
    */ 
    PrzeszkodaProstopadloscian();
    /*!
    * \brief konstruktor ustawiajacy poczatkowe wartosci PrzeszkodaProstopadloscian
    * \param api - przekazywany przez referencje obiekt do tworzenia obrazu w gnuplocie  
    */ 
    PrzeszkodaProstopadloscian(std::shared_ptr<drawNS::Draw3DAPI> &_api, Wektor<double,3> dlB, Wektor<double,3> pol);

    bool czy_kolizja(InterfejsDron* dron) override; 

};



#endif
