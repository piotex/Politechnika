#include "Scena.hh"

Scena::Scena() 
{
    
}

Scena::~Scena(){}

void Scena::stworzDrona(std::shared_ptr<drawNS::Draw3DAPI> api) {
    Dron* dd = new Dron(api, Wektor<double, 3>(50, 80, 20), "black");

    dd->set_pSrodka(0,0,200);


    std::shared_ptr<Dron> nowy_dron(dd);
    przeszkody_na_scenie.push_back(nowy_dron);

    nowy_dron->rysuj();
    aktualny_dron = nowy_dron;
}

/*
1 - plaszczyzna
2 - Wzgorze
3 - Plaskowyz
4 - Ostroslup
5 - Graniastoslup*/
void Scena::stworzFigure(std::shared_ptr<drawNS::Draw3DAPI> api, int typ_moj) {

    double zzzz = -50;

    int lowest = -200;
    int range = lowest*(-2);
    int sizemin = 30;
    int sizemax = 100;
    srand(time(NULL));
    double random_pol_1 = lowest + rand() % range;
    double random_pol_2 = lowest + rand() % range;
    double size_1 = sizemin + rand() % sizemax;
    double size_2 = sizemin + rand() % sizemax;
    double size_3 = sizemin + rand() % sizemax;


    switch (typ_moj)
    {
        case 0:
            //domuslny
            break;
        case 1:
            przeszkody_na_scenie.push_back(std::shared_ptr<Plaszczyzna>(new Plaszczyzna(api, Wektor<double, 3>(lowest, lowest, zzzz))));
            break;
        case 2:
            // Wzgorze
            przeszkody_na_scenie.push_back(std::shared_ptr<Wzgorze>(new Wzgorze(api, Wektor<double, 3>(size_1, size_3, size_2), Wektor<double, 3>(random_pol_1, random_pol_2, zzzz))));
            break;
        case 3:
            // Plaskowyz
            przeszkody_na_scenie.push_back(std::shared_ptr<Plaskowyz>(new Plaskowyz(api, Wektor<double, 3>(size_1, size_3, size_2), Wektor<double, 3>(random_pol_1, random_pol_2, zzzz))));
            break;
        case 4:
            // Ostroslup
            przeszkody_na_scenie.push_back(std::shared_ptr<Ostroslup>(new Ostroslup(api, Wektor<double, 3>(size_1, size_1, size_2), Wektor<double, 3>(random_pol_1, random_pol_2, zzzz))));
            break;
            break;
        case 5:
            // code block
            break;
        case 6:
            // code block
            break;
        case 7:
            // code block
            break;
        case 8:
            // code block
            break;
        case 9:
            // Dron
            stworzDrona(api);
            break;
        default:
            break;
    }
}

void Scena::wymaz_figure(int index)
{
    std::cout << "\nsize of vector" << przeszkody_na_scenie.size() << std::endl;
    std::cout << "\ncapacity of vector" << przeszkody_na_scenie.capacity() << std::endl;

    przeszkody_na_scenie[index]->usunFigure();
    przeszkody_na_scenie.erase(przeszkody_na_scenie.begin() + index);
}

void Scena::pelaczDrona(int index) {
    
    int licznik = 0;

    std::cout << "\nsize of vector" << przeszkody_na_scenie.size() << std::endl;
    std::cout << "\ncapacity of vector" << przeszkody_na_scenie.capacity() << std::endl;
    int cccc = przeszkody_na_scenie.size();

    for (int i = 0; i < cccc; i++)
    {
        ///*
        if (9 == przeszkody_na_scenie[i]->typ_figury )
        {
            if (licznik == index)
            {
                aktualny_dron = std::dynamic_pointer_cast<Dron>(przeszkody_na_scenie[i]);
            }
            licznik++;
        }
        //*/
    }
    
}
