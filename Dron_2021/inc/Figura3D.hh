#ifndef FIGURA3D_HH
#define FIGURA3D_HH


#include "MacierzObrotu.hh"
#include "Dr3D_gnuplot_api.hh"
#include "Przeszkoda.hh"
#include <string.h>

using std::vector;
using drawNS::Point3D;
using drawNS::APIGnuPlot3D;


class Figura3D : public Przeszkoda {
  public:
      mutable int id;
      /*
      0- typ domyslny
      1- plaszczyzna
      2-Wzgorze
      3-Plaskowyz
      4-Ostroslup
      5-Graniastoslup
      6-
      7-
      8-
      9- dron
      */
      int typ_figury;
      std::shared_ptr<drawNS::Draw3DAPI> api;
      std::string kolor;

    Wektor<double,3> pSrodka; 
    MacierzObrotu orientacja;
    Figura3D();
    Figura3D(std::shared_ptr<drawNS::Draw3DAPI> &api);

    virtual void rysuj() = 0;         
    virtual void usunFigure() ;

    virtual void set_pSrodka(const Wektor<double,3> &wek);
    virtual void set_pSrodka(const double x, const double y, const double z);
    virtual void set_orientacja(const MacierzObrotu &mac);
    virtual void set_api(std::shared_ptr<drawNS::Draw3DAPI> &api);
    virtual void get_zorientowanyWektor(Wektor<double,3> &wek) const;
};

#endif