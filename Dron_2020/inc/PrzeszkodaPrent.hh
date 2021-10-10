#ifndef PRZESZKODAPRENT_HH
#define PRZESZKODAPRENT_HH

#include "Przeszkoda.hh"
#include "Figura3D.hh"

class PrzeszkodaPrent : public Przeszkoda ,public Figura3D {      
  protected:
  public:
    /*!
    * \brief pole reprezentujace dlugosc preta
    */ 
    double dlugosc;
    TypObrotu os;
    /*!
    * \brief konstruktor ustawiajacy poczatkowe wartosci PrzeszkodaProstopadloscian
    */ 
    PrzeszkodaPrent();
    /*!
    * \brief konstruktor ustawiajacy poczatkowe wartosci PrzeszkodaProstopadloscian
    * \param api - przekazywany przez referencje obiekt do tworzenia obrazu w gnuplocie  
    */ 
    PrzeszkodaPrent(std::shared_ptr<drawNS::Draw3DAPI> &_api, double dlB, Wektor<double,3> pol, TypObrotu os = OsX);

    bool czy_kolizja(InterfejsDron* dron) override; 
    /*!
    * \brief funkcja sluzaca do tworzenia obrazu w gnuplocie 
    */ 
    void rysuj() override;
};



#endif
