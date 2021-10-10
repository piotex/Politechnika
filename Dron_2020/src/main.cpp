#include<iostream>
#include "Dr3D_gnuplot_api.hh"
#include "Dron.hh"
#include "../inc/Wektor.hh"
#include "Prostopadloscian.hh"
#include "Plaszczyzna_Wody.hh"
#include "Graniastoslup.hh"
#include "FactoryPrzeszkody.hh"
#include "Przeszkoda.hh"

#include <unistd.h>
#include <termios.h>

using std::vector;
using drawNS::Point3D;
using drawNS::APIGnuPlot3D;
using std::cout;
using std::endl;



int main(int argc, char **argv)
{
        char c = 'x';
        char d = 'x';
        double kat =0;;
        double r=0;

        //doxygen info
        //https://www.youtube.com/watch?v=KPN1y_vstjY
        Wektor<double,3>::ile_istnieje = 0;
        Wektor<double,3>::ile_utworzono = 0;

        std::shared_ptr<drawNS::Draw3DAPI> api(new APIGnuPlot3D(-200,200,-200,200,-200,400,1000)); 
        api->change_ref_time_ms(0);
                
        FactoryPrzeszkody fp(api);
        vector<std::shared_ptr<Przeszkoda>> przeszkody;
        fp.get_kolekcja(przeszkody);

        std::shared_ptr<Dron> dron1(new Dron(api,Wektor<double,3>(50,80,20),R));
        std::shared_ptr<Dron> dron2(new Dron(api,Wektor<double,3>(50,80,20),G));
        std::shared_ptr<Dron> dron3(new Dron(api,Wektor<double,3>(50,80,20),B));
        dron2->teleport(150,-45,przeszkody);
        dron3->teleport(-150,45,przeszkody);

        przeszkody.push_back(dron1);
        przeszkody.push_back(dron2);
        przeszkody.push_back(dron3);

        
        std::cout << "r - zadaj ruch na wprost\n";
        std::cout << "o - zadaj zmiane orientacji\n";
        std::cout << "m - wyswietl menu\n";
        std::cout << "k - koniec dzialania programu\n\n";

        while (c!='k')
        {
                std::cout << "\npolecenie [r,o,m,k]>:" ;
                std::cin >> c;
                std::cout << "\nWybierz drona 'R' 'G' 'B'\n>:" ;
                std::cin >> d;

                switch (c)
                {
                        case 'r':{
                                std::cout << "Podaj wartosc kata (wznoszenia/opadania) w stopniach.\n" ;
                                std::cin >> kat;
                                std::cout << "Podaj wartosc odleglosci, na ktora ma sie przemiescic dron.\n" ;
                                std::cin >> r;
                                std::cout<<kat<<"  "<<r;
                                switch (d)
                                {
                                        case 'R':{
                                                dron1->plyn(r,kat,przeszkody);
                                                break;
                                        }
                                        case 'G':{
                                                dron2->plyn(r,kat,przeszkody);
                                                break;
                                        }
                                        case 'B':{
                                                dron3->plyn(r,kat,przeszkody);
                                                break;
                                        }
                                }
                                break;
                        }
                        case 'o':{
                                std::cout << "Podaj wartosc kata obrotu w stopniach.\n" ;
                                std::cin >> kat;
                                switch (d)
                                {
                                        case 'R':{
                                                dron1->obrot(OsZ,kat,przeszkody);
                                                break;
                                        }
                                        case 'G':{
                                                dron2->obrot(OsZ,kat,przeszkody);
                                                break;
                                        }
                                        case 'B':{
                                                dron3->obrot(OsZ,kat,przeszkody);
                                                break;
                                        }
                                }
                                break;
                        }
                        case 'm':{
                                std::cout << "\n\nr - zadaj ruch na wprost\no - zadaj zmiane orientacji\nm - wyswietl menu\n\nk - koniec dzialania programu\n\n";
                                break;
                        }
                        case 'k':{
                                std::cout << "Koniec programu\n\n" ;
                                exit(1);
                                break;
                        }
                        case 'z':{
                                int _id_doUsuniecia = 0;
                                vector<Wektor<double,3>> punkty;
                                dron1->get_punktyKrytyczne(punkty);
                                if(_id_doUsuniecia != 0)
                                api->erase_shape(_id_doUsuniecia);
                                vector<vector<Point3D>> prost = vector<vector<Point3D>> {{
                                                                drawNS::Point3D(punkty[0][0],punkty[0][1],punkty[0][2]), 
                                                                drawNS::Point3D(punkty[1][0],punkty[1][1],punkty[1][2]), 
                                                                drawNS::Point3D(punkty[2][0],punkty[2][1],punkty[2][2]), 
                                                                drawNS::Point3D(punkty[3][0],punkty[3][1],punkty[3][2])
                                                                },{
                                                                drawNS::Point3D(punkty[4][0],punkty[4][1],punkty[4][2]), 
                                                                drawNS::Point3D(punkty[5][0],punkty[5][1],punkty[5][2]), 
                                                                drawNS::Point3D(punkty[6][0],punkty[6][1],punkty[6][2]), 
                                                                drawNS::Point3D(punkty[7][0],punkty[7][1],punkty[7][2])
                                                                }};
                                _id_doUsuniecia = api->draw_polyhedron(prost,"red");
                                break;
                        }
                }
                std::cout << "\n--------------------------------\nAktualna ilosc obiektow Wektor3D: ";
                std::cout << Wektor<double,3>::zwroc_ile_istn() <<"\n" ;
                std::cout << "\nLaczna ilosc obiektow Wektor3D: ";
                std::cout << Wektor<double,3>::zwroc_ile_utw() <<"\n----------------------------------\n\n\n" ;


        }


}

