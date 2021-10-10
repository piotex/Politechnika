#ifndef Prostopadloscian_HH
#define Prostopadloscian_HH
#include<iostream>
#include <math.h> 
#include "Figura3D.hh"

class Prostopadloscian : public Figura3D{    
  protected:
  public:
    Wektor<double,3> dlugosciBokow;

    /*!
    * \brief konstruktor ustawiajacy poczatkowe wartosci Prostopadloscian
    */ 
    Prostopadloscian();
    /*!
    * \brief konstruktor ustawiajacy poczatkowe wartosci Prostopadloscian
    * \param api - przekazywany przez referencje obiekt do tworzenia obrazu w gnuplocie  
    */ 
    Prostopadloscian(std::shared_ptr<drawNS::Draw3DAPI> &api, Wektor<double,3> dlB);
    /*!
    * \brief funkcja sluzaca do tworzenia obrazu w gnuplocie 
    */ 
    void rysuj() override;
    /*!
    * \brief funkcja sluzaca do wyliczania punktow skladowych Prostopadloscian
    */ 
    void get_wyliczonePunkty(Wektor<double,3> *ret);

};

#endif