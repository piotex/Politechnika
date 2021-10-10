#include<iostream>
#include "Dr3D_gnuplot_api.hh"
#include "Dron.hh"
#include "../inc/Wektor.hh"
#include "Prostopadloscian.hh"
#include "Graniastoslup.hh"
#include "Plaskowyz.hh"
#include "Wzgorze.hh"
#include "Plaszczyzna.hh"
#include "Ostroslup.hh"
#include "Scena.hh"


#include <unistd.h>
#include <termios.h>
#include <string.h>


using std::vector;
using drawNS::Point3D;
using drawNS::APIGnuPlot3D;
using std::cout;
using std::endl;



int main(int argc, char **argv)
{
    std::shared_ptr<drawNS::Draw3DAPI> api(new APIGnuPlot3D(-200, 200, -200, 200, -200, 400, 1000));
    api->change_ref_time_ms(0);
    Scena* scena = new Scena();

    scena->stworzDrona(api);
    //std::shared_ptr<Dron> aktualny_dron = scena->aktualny_dron;

    scena->stworzFigure(api, 1);


    //vector<std::shared_ptr<Przeszkoda>> dic1;
    //aktualny_dron->do_gory(0, dic1);
    

    //Dron* d = new Dron(api, Wektor<double, 3>(50, 80, 20), "black");

    
        char wybor = 'x';
        char wybor2 = 'w';
        int index = 0;
        double kat =0;
        double p=0;
        
        
        std::cout << "p - o ile do przodu(ruch poziomo)\n";
        std::cout << "l - o ile w gore(ruch pionowo)\n";
        std::cout << "o - obrót o kat w stopniach\n";
        std::cout << "d - dodawanie nowego elementu powierzchni\n";
        std::cout << "m - wyswietl menu\n";
        std::cout << "k - koniec dzialania programu\n\n";

        while (wybor!='k')
        {
                std::cout << "\nPodaj polecenie [p,l,d,o,m,x,k]>:" ;
                std::cin >> wybor;
               

                switch (wybor)
                {
                        case 'd':{
                                std::cout << "Dodaj nowey element powierzchni\n";
                                std::cout << "Wybierz rodzaj elemntu\n";
                                std::cout << "w - wzgorze\n";
                                std::cout << "o - ostroslup\n";
                                std::cout << "p - plaskowyz\n";
                                std::cout << "d - dron\n";
                                std::cin >> wybor2;

                                switch (wybor2){
                                        case 'w':{
                                            scena->stworzFigure(api,2);
                                            break;
                                        }
                                        case 'o':{
                                            scena->stworzFigure(api, 4);
                                            break;
                                        }
                                        case 'p': {
                                            scena->stworzFigure(api, 3);
                                            break;
                                        }
                                        case 'd': {
                                            scena->stworzFigure(api, 9);
                                            break;
                                        }
                                }
                                break;
                        }
                        case 'p':{
                                
                                std::cout << "Podaj odleglosc na jaka dron ma sie przemiescic w poziomie\n";
                                std::cin >> p;
                                scena->aktualny_dron->do_przodu(p, scena->przeszkody_na_scenie);
                                break;
                        }
                        case 'l':{
                                std::cout << "Podaj odleglosc na jaka dron ma sie przemiescic w pionie\n";
                                std::cin >> p;
                                scena->aktualny_dron->do_gory(p, scena->przeszkody_na_scenie);
                                break;
                        }
                        case 'o':{
                                std::cout << "Podaj kat w stopniach. o jaki dron ma sie obrocic\n" ;
                                std::cin >> kat;
                                scena->aktualny_dron->obrot(kat, scena->przeszkody_na_scenie);
                                break;
                        }
                        case 'm': {
                            std::cout << "\n\np - o ile do przodu(ruch poziomo) \nl - o ile w gore(ruch pionowo) \no - obrot o kat w stopniach \nm - wyswietl menu \n\nk - koniec dzialania programu\n\n";
                            break;
                        }
                        case 'x': {
                            std::cout << "Podaj indeks figury do usuniecia: \n";
                            std::cin >> index;
                            scena->wymaz_figure(index);
                            break;
                        }
                        case 'k':{
                                std::cout << "Koniec programu\n\n" ;
                                exit(1);
                                break;
                        }
                        
                }
        }

        
}

