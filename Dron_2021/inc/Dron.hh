#ifndef DRON_HH
#define DRON_HH
#include "Wirniki.hh"
#include "Prostopadloscian.hh"
#include "Przeszkoda.hh"


class Dron : public Prostopadloscian, public InterfejsDron {   
  public:
      double predkosc;
      Wirniki g1;
      Wirniki g2;
      Wirniki g3;
      Wirniki g4;
    Dron();
    Dron(std::shared_ptr<drawNS::Draw3DAPI> &_api, Wektor<double,3> boki,std::string kolor);
    
    void rysuj() override;
 
    Wektor<double,3> get_srodek_masyDrona() override;
    Wektor<double,3> get_wymiary_Drona() override;

    void set_pSrodka(const double x, const double y, const double z) override;
    void get_punktyKrytyczne(vector<Wektor<double,3>> &punkty) override;

    int obrot(double kat,vector<std::shared_ptr<Figura3D>> fp);

    int do_przodu(double p, vector<std::shared_ptr<Figura3D>> fp);
    int do_gory(double l,vector<std::shared_ptr<Figura3D>> fp);

    bool czy_kolizja(InterfejsDron* dron) override; 
    void usunFigure() override;

};

#endif

