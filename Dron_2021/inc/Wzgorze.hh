#ifndef WZOGRZE
#define WZOGRZE
 
#include "Przeszkoda.hh"
#include "Prostopadloscian.hh"

class Wzgorze :  public Prostopadloscian {
protected:
public:
    Wzgorze();
    Wzgorze(std::shared_ptr<drawNS::Draw3DAPI>& _api, Wektor<double, 3> dlB, Wektor<double, 3> pol);

    void get_wyliczonePunkty(Wektor<double, 3>* ret) override;
    bool czy_kolizja(InterfejsDron* dron) override;
};
#endif