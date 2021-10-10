#ifndef PLASZCZYZNAWODY_HH
#define PLASZCZYZNAWODY_HH

#include "Plaszczyzna.hh"

class Plaszczyzna_Wody : public Plaszczyzna {
    public:   
        /*!
        * \brief konstruktor ustawiajacy poczatkowe wartosci Plaszczyzna_Wody
        */ 
        Plaszczyzna_Wody();
        /*!
        * \brief konstruktor ustawiajacy poczatkowe wartosci Plaszczyzna_Wody
        * \param api - przekazywany przez referencje obiekt do tworzenia obrazu w gnuplocie  
        */ 
        Plaszczyzna_Wody(std::shared_ptr<drawNS::Draw3DAPI> &api,Wektor<double,3> pol);
        /*!
        * \brief funkcja sluzaca do tworzenia obrazu w gnuplocie 
        */ 
        void rysuj() override;   
        bool czy_kolizja(InterfejsDron* dron) override; 
};

#endif