#include "Dron.hh"

Dron::Dron(){
    typ_figury = 9;
    predkosc = 5;
    dlugosciBokow = Wektor<double,3>(100,50,20);
}
Dron::Dron(std::shared_ptr<drawNS::Draw3DAPI> &_api, Wektor<double,3> boki, std::string c){
    typ_figury = 9;
    api = _api;
    kolor = c;
    predkosc = 5;
    dlugosciBokow = boki;
    g1.set_api(_api);
    g2.set_api(_api);
    g3.set_api(_api);
    g4.set_api(_api);
    g1.set_pSrodka(Wektor<double, 3>(dlugosciBokow[0] / 2 , dlugosciBokow[1] / 2,  dlugosciBokow[2] / 2));
    g2.set_pSrodka(Wektor<double, 3>(-dlugosciBokow[0] / 2, dlugosciBokow[1] / 2,  dlugosciBokow[2] / 2));
    g3.set_pSrodka(Wektor<double, 3>(-dlugosciBokow[0] / 2, -dlugosciBokow[1] / 2, dlugosciBokow[2] / 2));
    g4.set_pSrodka(Wektor<double, 3>(dlugosciBokow[0] / 2 , -dlugosciBokow[1] / 2, dlugosciBokow[2] / 2));
    rysuj();
}

Wektor<double,3> obrotZ(Wektor<double,3> a,Wektor<double,3> osObroty,double kat){

    Wektor<double,3> ret ;
    ret[0] = (a[0]-osObroty[0])*cos(kat*PI/180) - (a[1]-osObroty[1])*sin (kat*PI/180) + (osObroty[0]);
    ret[1] = (a[0]-osObroty[0])*sin(kat*PI/180) + (a[1]-osObroty[1])*cos (kat*PI/180) + (osObroty[1]);
    ret[2]=a[2];
    /*
    MacierzObrotu mac(TypObrotu.Z, kat);
    orientacja = orientacja * mac;
    */
    return ret;
}

void Dron::get_punktyKrytyczne(vector<Wektor<double,3>> &punkty){
    Wektor<double,3> tab[8];
    get_wyliczonePunkty(tab);
    Wektor<double,3> przesuniecieNiewygodne(-10,-10,0);
    Wektor<double,3> przesuniecieNiewygodne2(10,-10,0);
    get_zorientowanyWektor(przesuniecieNiewygodne);
    get_zorientowanyWektor(przesuniecieNiewygodne2);

    tab[3] += przesuniecieNiewygodne2;
    tab[2] += przesuniecieNiewygodne;
    tab[7] += przesuniecieNiewygodne2;
    tab[6] += przesuniecieNiewygodne;

    for (int i = 0; i < 8; i++)
    {
      punkty.push_back(tab[i] );
    }
}

int Dron::obrot(double kat,vector<std::shared_ptr<Figura3D>> fp){
    double speed = 5;
    double predkosc_lokal = speed * (kat / abs(kat));
    kat = abs(kat);
    while (kat > 0)
    {
        /*
        for (unsigned int i = 0; i < fp.capacity(); i++)
        {
            //std::cout << "\n\nxxxxx\n\n" << fp.capacity() << i << "__";
            if (fp[i]->czy_kolizja(this)) {
                MacierzObrotu mac('z', -predkosc_lokal);
                orientacja = orientacja * mac;

                g1.pSrodka = obrotZ(g1.pSrodka, pSrodka, predkosc_lokal);
                g1.obrot(-predkosc_lokal);

                g2.pSrodka = obrotZ(g2.pSrodka, pSrodka, predkosc_lokal);
                g2.obrot( -predkosc_lokal);

                g3.pSrodka = obrotZ(g3.pSrodka, pSrodka, predkosc_lokal);
                g3.obrot( -predkosc_lokal);

                g4.pSrodka = obrotZ(g4.pSrodka, pSrodka, predkosc_lokal);
                g4.obrot( -predkosc_lokal);
                rysuj();
                std::cout << "\n\nwystapila kolizja\n\n";
                return 1;
            }
        }
        */
        MacierzObrotu mac('z', predkosc_lokal);
        orientacja = orientacja * mac;

        g1.pSrodka = obrotZ(g1.pSrodka, pSrodka, -predkosc_lokal);
        g1.obrot(predkosc_lokal);

        g2.pSrodka = obrotZ(g2.pSrodka, pSrodka, -predkosc_lokal);
        g2.obrot(predkosc_lokal);

        g3.pSrodka = obrotZ(g3.pSrodka, pSrodka, -predkosc_lokal);
        g3.obrot(predkosc_lokal);

        g4.pSrodka = obrotZ(g4.pSrodka, pSrodka, -predkosc_lokal);
        g4.obrot(predkosc_lokal);

        rysuj();
        kat -= speed;
    }
    rysuj();
  return 0;
}


int Dron::do_przodu(double p,vector<std::shared_ptr<Figura3D>> fp){
    double speed = 10;
    double predkosc_lokal = speed * ( p / abs(p) );
    p= abs(p);

    while (p>0)
    {
        /*
        for (unsigned int i = 0; i < fp.capacity(); i++)
        {
            if(fp[i]->czy_kolizja(this)){
                Wektor<double,3> dyst(0,-predkosc_lokal,0);
                get_zorientowanyWektor(dyst);
                pSrodka = pSrodka + dyst;

                g1.przesun(dyst);
                g2.przesun(dyst);
                g3.przesun(dyst);
                g4.przesun(dyst);

                rysuj();
                std::cout<<"\n\nwystapila kolizja\n\n";
                return 1;
            }
        }
        */
        Wektor<double,3> dyst(0,predkosc_lokal,0);
        get_zorientowanyWektor(dyst);
        pSrodka = pSrodka + dyst;

        g1.przesun(dyst);
        g2.przesun(dyst);
        g3.przesun(dyst);
        g4.przesun(dyst);

        rysuj();
        p-= speed;
    }
    rysuj();
    return 0;
}


int Dron::do_gory(double l, vector<std::shared_ptr<Figura3D>> fp) {
    double speed = 10;
    double predkosc_lokal = speed * (l / abs(l));
    l = abs(l);

    while (l > 0)
    {
        for (unsigned int i = 0; i < fp.capacity(); i++)
        {
            if (fp[i]->czy_kolizja(this)) {
                Wektor<double, 3> dyst(0, 0, -predkosc_lokal);
                get_zorientowanyWektor(dyst);
                pSrodka = pSrodka + dyst;

                g1.przesun(dyst);
                g2.przesun(dyst);
                g3.przesun(dyst);
                g4.przesun(dyst);

                rysuj();
                std::cout << "\n\nwystapila kolizja\n\n";
                return 1;
            }
        }

        Wektor<double, 3> dyst(0, 0, predkosc_lokal);
        get_zorientowanyWektor(dyst);
        pSrodka = pSrodka + dyst;

        g1.przesun(dyst);
        g2.przesun(dyst);
        g3.przesun(dyst);
        g4.przesun(dyst);

        rysuj();
        l -= speed;
    }
    rysuj();
    return 0;
}

void Dron::rysuj(){
  Prostopadloscian::rysuj();
  g1.rysuj();
  g2.rysuj();
  g3.rysuj();
  g4.rysuj();
}

Wektor<double,3> Dron::get_srodek_masyDrona(){
    Wektor<double,3> ret;
    ret[0] = pSrodka[0];
    ret[1] = pSrodka[1] ;
    ret[2] = pSrodka[2] ;
    return ret;
}

Wektor<double,3> Dron::get_wymiary_Drona(){
    Wektor<double,3> ret;
    ret[0] = dlugosciBokow[0] + g1.bok;
    ret[1] = dlugosciBokow[1] + g1.bok*sqrt(3);
    ret[2] = dlugosciBokow[2] + g1.wysokosc;
    return ret;
}

bool Dron::czy_kolizja(InterfejsDron* przeszkoda){

    if (przeszkoda == this)
    {
    }
    else{
      vector<Wektor<double,3>> punkty;
      vector<Wektor<double,3>> punkty_przeszkody;
      przeszkoda->get_punktyKrytyczne(punkty);
      get_punktyKrytyczne(punkty_przeszkody);

      bool okx = false;
      bool oky = false;
      bool okz = false;

      for (int i = 0; i < 8; i++)
      {
          if ((punkty[i][0] > punkty_przeszkody[0][0] && punkty[i][0] < punkty_przeszkody[1][0] )|| (punkty[i][0] > punkty_przeszkody[1][0] && punkty[i][0] < punkty_przeszkody[0][1]))
          {
              okx = true;
          }
          if (punkty[i][1] > punkty_przeszkody[3][1] && punkty[i][1] < punkty_przeszkody[0][1])
          {
              oky = true;
          }
          if (punkty[i][2] < punkty_przeszkody[0][2] && punkty[i][2] > punkty_przeszkody[4][2])
          {
              okz = true;
          }
      }
      if(okz && okx && oky){
          return true;
      }

      return false;

    }
    return false;

}

void Dron::usunFigure() {
    api->erase_shape(id);

    api->erase_shape(g4.id);
    api->erase_shape(g3.id);
    api->erase_shape(g2.id);
    api->erase_shape(g1.id);
}

void Dron::set_pSrodka(const double x, const double y, const double z)
{
    pSrodka = Wektor<double, 3>(x, y, z);
    g1.set_pSrodka(Wektor<double, 3>(x+dlugosciBokow[0]/2,    y+dlugosciBokow[1] / 2,  z+dlugosciBokow[2] / 2));
    g2.set_pSrodka(Wektor<double, 3>(x+-dlugosciBokow[0] / 2, y+dlugosciBokow[1] / 2,  z+dlugosciBokow[2] / 2));
    g3.set_pSrodka(Wektor<double, 3>(x+-dlugosciBokow[0] / 2, y+-dlugosciBokow[1] / 2, z+dlugosciBokow[2] / 2));
    g4.set_pSrodka(Wektor<double, 3>(x+dlugosciBokow[0] / 2,  y+-dlugosciBokow[1] / 2, z+dlugosciBokow[2] / 2));
}

