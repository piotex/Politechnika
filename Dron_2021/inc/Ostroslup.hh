#ifndef OSTROSLUP_HH
#define OSTROSLUP_HH
 
#include "Prostopadloscian.hh"

class Ostroslup : public Prostopadloscian {
protected:
public:
    Ostroslup();
    Ostroslup(std::shared_ptr<drawNS::Draw3DAPI>& _api, Wektor<double, 3> dlB, Wektor<double, 3> pol);

    void get_wyliczonePunkty(Wektor<double, 3>* ret) override;
    bool czy_kolizja(InterfejsDron* dron) override;
};
#endif