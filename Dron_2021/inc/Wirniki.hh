#ifndef WIRNIKI_HH
#define WIRNIKI_HH

#include "Graniastoslup.hh"

class Wirniki : public Graniastoslup{    
  protected:
  public:
    Wirniki();
    Wirniki(std::shared_ptr<drawNS::Draw3DAPI> &api, double b, double h);

    virtual void przesun(Wektor<double,3> odleglosc);
    virtual void obrot(double kat);
};



#endif
