#ifndef FACTORYPRZESZKODA_HH
#define FACTORYPRZESZKODA_HH

#include "Przeszkoda.hh"
#include "Dron.hh"
#include "Plaszczyzna.hh"
#include "Plaszczyzna_Wody.hh"
#include "PrzeszkodaPrent.hh"
#include "PrzeszkodaProstopadloscian.hh"
#include "Dr3D_gnuplot_api.hh"

using std::vector;

class FactoryPrzeszkody {   
  public:
        FactoryPrzeszkody();
        FactoryPrzeszkody(std::shared_ptr<drawNS::Draw3DAPI> &api);
        vector<std::shared_ptr<Przeszkoda>> dic1;
        // vector<Przeszkoda> dic;

        std::shared_ptr<drawNS::Draw3DAPI> api;
        void get_kolekcja(vector<std::shared_ptr<Przeszkoda>> &dic1);
};



#endif
