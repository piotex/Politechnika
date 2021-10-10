#ifndef SCENA_HH
#define SCENA_HH
#include "Dron.hh"
#include "Wzgorze.hh"
#include "Plaskowyz.hh"
#include "Ostroslup.hh"
#include "Graniastoslup.hh"
#include "Plaszczyzna.hh"


#include <stdio.h>      /* printf, scanf, puts, NULL */
#include <stdlib.h>     /* srand, rand */
#include <time.h>       /* time */


class Scena {    
    public:
        std::vector<std::shared_ptr<Figura3D>> przeszkody_na_scenie;
        std::shared_ptr<Dron> aktualny_dron;

        Scena();
        ~Scena();

        void stworzDrona(std::shared_ptr<drawNS::Draw3DAPI> api);
        void stworzFigure(std::shared_ptr<drawNS::Draw3DAPI> api,int idx);
        void wymaz_figure(int index);
        void pelaczDrona(int index);


    
};

#endif