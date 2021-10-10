#ifndef Prostopadloscian_HH
#define Prostopadloscian_HH

#include "Figura3D.hh"

class Prostopadloscian : public Figura3D{    
  protected:
  public:
    Wektor<double,3> dlugosciBokow;
    Prostopadloscian();
    Prostopadloscian(std::shared_ptr<drawNS::Draw3DAPI> &api, Wektor<double,3> dlB);
    virtual void get_wyliczonePunkty(Wektor<double,3> *ret);

    void rysuj() override;
};

#endif