#ifndef PLASKOWYZ_HH
#define PLASKOWYZ_HH

#include "Przeszkoda.hh"
#include "Prostopadloscian.hh"

class Plaskowyz : public Prostopadloscian {      
  protected:
  public:
      Plaskowyz();
      Plaskowyz(std::shared_ptr<drawNS::Draw3DAPI> &_api, Wektor<double,3> dlB, Wektor<double,3> pol);

    bool czy_kolizja(InterfejsDron* dron) override; 
};



#endif
