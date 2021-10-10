#ifndef PLASZCZYZNA_HH
#define PLASZCZYZNA_HH

#include "Figura3D.hh"
#include "InterfejsDron.hh"
#include "Przeszkoda.hh"

class Plaszczyzna : public Figura3D, public Przeszkoda{
    protected:
        int rozmiar = 80;
        int numer = 8;
    public:
        /*!
        * \brief konstruktor ustawiajacy poczatkowe wartosci Plaszczyzna
        */ 
        Plaszczyzna();
        /*!
        * \brief konstruktor ustawiajacy poczatkowe wartosci Plaszczyzna
        * \param api - przekazywany przez referencje obiekt do tworzenia obrazu w gnuplocie  
        */ 
        Plaszczyzna(std::shared_ptr<drawNS::Draw3DAPI> &api,Wektor<double,3> pol);
        /*!
        * \brief funkcja sluzaca do tworzenia obrazu w gnuplocie 
        */ 
        void rysuj() override; 

        bool czy_kolizja(InterfejsDron* dron) override; 

};

#endif