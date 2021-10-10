#include "Dron.hh"

Dron::Dron(){
    predkosc = 5;
    dlugosciBokow = Wektor<double,3>(100,50,20);
}
Dron::Dron(std::shared_ptr<drawNS::Draw3DAPI> &_api, Wektor<double,3> boki,Kolor c){
    api = _api;
    kolor = c;
    predkosc = 5;
    dlugosciBokow = boki;
    g1.set_api(_api);
    g2.set_api(_api);
    g1.set_pSrodka(Wektor<double,3> (-25,-45,0));
    g2.set_pSrodka(Wektor<double,3> (25,-45,0));
    rysuj();
}

Wektor<double,3> obrotZ(Wektor<double,3> a,Wektor<double,3> osObroty,double kat){

    Wektor<double,3> ret ;//= (mkX * w1)+masPoint;
    ret[0] = (a[0]-osObroty[0])*cos(kat*PI/180) - (a[1]-osObroty[1])*sin (kat*PI/180) + (osObroty[0]);
    ret[1] = (a[0]-osObroty[0])*sin(kat*PI/180) + (a[1]-osObroty[1])*cos (kat*PI/180) + (osObroty[1]);
    ret[2]=a[2];
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

int Dron::obrot(TypObrotu typ, double kat,vector<std::shared_ptr<Przeszkoda>> fp){
  bool wartko = true;
  if (typ==OsZ)
  {
    double predkosc_lokal = 1 * ( kat / abs(kat) );
    kat= abs(kat);
    while (kat>0)
    {
        for (unsigned int i = 0; i < fp.size(); i++)
        {
            if(fp[i]->czy_kolizja(this)){
                MacierzObrotu mac(typ,-predkosc_lokal);
                orientacja = orientacja * mac;

                g1.pSrodka = obrotZ(g1.pSrodka,pSrodka,predkosc_lokal);
                g1.obrot(OsZ,-predkosc_lokal);

                g2.pSrodka = obrotZ(g2.pSrodka,pSrodka,predkosc_lokal);
                g2.obrot(OsZ,-predkosc_lokal);
                rysuj();
                std::cout<<"\n\nwystapila kolizja\n\n";
                return 1;
            }
        }
      
        MacierzObrotu mac(typ,predkosc_lokal);
        orientacja = orientacja * mac;

        g1.pSrodka = obrotZ(g1.pSrodka,pSrodka,-predkosc_lokal);
        g1.obrot(OsZ,predkosc_lokal);

        g2.pSrodka = obrotZ(g2.pSrodka,pSrodka,-predkosc_lokal);
        g2.obrot(OsZ,predkosc_lokal);
        if (!wartko)
        {
            if (static_cast<int>(kat)%static_cast<int>(predkosc) == 0)    // szybciej sie porusza a na koncu i tak jest rysuj wiec zawszecos wyrysuje
            {
                g1.obrot(OsY,-120);
                g2.obrot(OsY,12);
                for (int i = 0; i < 3; i++)
                {
                    g1.obrot(OsY,40);
                    g2.obrot(OsY,-40);
                    rysuj();
                }
            }
        }
        else
        {
            if (static_cast<int>(kat)%static_cast<int>(predkosc) == 0)
              rysuj();   
        }
        kat-=1;
    }
    rysuj();
  }
  else
  {
    MacierzObrotu mac(typ,kat);
    orientacja = orientacja * mac;
  }
  return 0;
}

int Dron::teleport(double r,double kat,vector<std::shared_ptr<Przeszkoda>> fp){
    double predkosc_lokal = 1 * ( r / abs(r) );
    r= abs(r);
    while (r>0)
    {
        for (unsigned int i = 0; i < fp.size(); i++)
        {
            if(fp[i]->czy_kolizja(this)){
                Wektor<double,3> dyst(0,-predkosc_lokal,0);
                obrot(OsX,-kat,fp); //zmiana wektora kierunkowego
                get_zorientowanyWektor(dyst);
                pSrodka = pSrodka + dyst;
                obrot(OsX,kat,fp); //powrot wektora kierunkowego

                g1.przesun(dyst);
                g2.przesun(dyst);

                rysuj();
                std::cout<<"\n\nwystapila kolizja\n\n";
                return 1;
            }
        }

        Wektor<double,3> dyst(0,predkosc_lokal,0);
        obrot(OsX,-kat,fp); //zmiana wektora kierunkowego
        get_zorientowanyWektor(dyst);
        pSrodka = pSrodka + dyst;
        obrot(OsX,kat,fp); //powrot wektora kierunkowego

        g1.przesun(dyst);
        g2.przesun(dyst);
        r--;
    }
    rysuj();
    return 0;
}


int Dron::plyn(double r,double kat,vector<std::shared_ptr<Przeszkoda>> fp){
    bool wartko = false;

    double predkosc_lokal = 1 * ( r / abs(r) );
    r= abs(r);

    while (r>0)
    {
        for (unsigned int i = 0; i < fp.size(); i++)
        {
            if(fp[i]->czy_kolizja(this)){
                Wektor<double,3> dyst(0,-predkosc_lokal,0);
                obrot(OsX,-kat,fp); //zmiana wektora kierunkowego
                get_zorientowanyWektor(dyst);
                pSrodka = pSrodka + dyst;
                obrot(OsX,kat,fp); //powrot wektora kierunkowego

                g1.przesun(dyst);
                g2.przesun(dyst);

                rysuj();
                std::cout<<"\n\nwystapila kolizja\n\n";
                return 1;
            }
        }

        Wektor<double,3> dyst(0,predkosc_lokal,0);
        obrot(OsX,-kat,fp); //zmiana wektora kierunkowego
        get_zorientowanyWektor(dyst);
        pSrodka = pSrodka + dyst;
        obrot(OsX,kat,fp); //powrot wektora kierunkowego

        g1.przesun(dyst);
        g2.przesun(dyst);
        if (!wartko)
        {
            if (static_cast<int>(r)%static_cast<int>(predkosc) == 0)    // szybciej sie porusza a na koncu i tak jest rysuj wiec zawszecos wyrysuje
            {
                g1.obrot(OsY,-120);
                g2.obrot(OsY,-120);
                for (int i = 0; i < 3; i++)
                {
                    g1.obrot(OsY,40);
                    g2.obrot(OsY,40);
                    rysuj();
                }
            }
        }
        else{
          if (static_cast<int>(r)%static_cast<int>(predkosc/2) == 0)
            rysuj();    
        }
        r--;
    }
    rysuj();
    return 0;
}

void Dron::rysuj(){
  Prostopadloscian::rysuj();
  g1.rysuj();
  g2.rysuj();
}

Wektor<double,3> Dron::get_srodek_masyDrona(){
    Wektor<double,3> ret;
    ret[0] = pSrodka[0];
    ret[1] = pSrodka[1] - g1.wysokosc/2;
    ret[2] = pSrodka[2] ;
    return ret;
}

Wektor<double,3> Dron::get_wymiary_Drona(){
    Wektor<double,3> ret;
    ret[0] = dlugosciBokow[0] + g1.bok;
    ret[1] = dlugosciBokow[1] + g1.wysokosc;
    if (dlugosciBokow[1] < (g1.bok*sqrt(3)/2*2))
    {
      ret[2] = dlugosciBokow[2] + ( (g1.bok*sqrt(3)/2*2) - dlugosciBokow[1]  );
    }
    else{
      ret[2] = dlugosciBokow[2] ;
    }
    return ret;
}

bool Dron::czy_kolizja(InterfejsDron* dron){

    if (dron == this)
    {
    }
    else{
      vector<Wektor<double,3>> punkty;
      vector<Wektor<double,3>> punkty_przeszkody;
      dron->get_punktyKrytyczne(punkty);
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
