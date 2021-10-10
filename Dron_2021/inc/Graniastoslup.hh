#ifndef GRANIASTOSLUP_HH
#define GRANIASTOSLUP_HH


#include "Figura3D.hh"

class Graniastoslup : public Figura3D{    
  protected:
  public:
    Graniastoslup();
    Graniastoslup(std::shared_ptr<drawNS::Draw3DAPI> &api, double b, double h);

    double bok;
    double wysokosc;
    
    virtual void set_pro(double b, double w);
    virtual void get_wyliczonePunkty(Wektor<double,3> *ret);    
    
    void rysuj() override;
    bool czy_kolizja(InterfejsDron* dron) override;
};



#endif
