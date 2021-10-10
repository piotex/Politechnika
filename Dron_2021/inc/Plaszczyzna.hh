#ifndef PLASZCZYZNA_HH
#define PLASZCZYZNA_HH

#include "Figura3D.hh"
#include "InterfejsDron.hh"
#include "Przeszkoda.hh"

class Plaszczyzna : public Figura3D{
    protected:
        int rozmiar = 80;
        int numer = 8;
    public:
        Plaszczyzna();
        Plaszczyzna(std::shared_ptr<drawNS::Draw3DAPI> &api,Wektor<double,3> pol);
        void rysuj() override; 

        bool czy_kolizja(InterfejsDron* dron) override; 

};

#endif