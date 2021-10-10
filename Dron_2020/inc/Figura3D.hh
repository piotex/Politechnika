#ifndef FIGURA3D_HH
#define FIGURA3D_HH

#include<iostream>
#include "MacierzObrotu.hh"
#include "Dr3D_gnuplot_api.hh"

using std::vector;
using drawNS::Point3D;
using drawNS::APIGnuPlot3D;

enum Kolor{
    R,
    G,
    B,
    Black
};
class Figura3D {    
  protected:
    mutable int id;
    std::shared_ptr<drawNS::Draw3DAPI> api;

    Kolor kolor;


  public: 
    Wektor<double,3> pSrodka; 
    MacierzObrotu orientacja;
    Figura3D();
    Figura3D(std::shared_ptr<drawNS::Draw3DAPI> &api);

    virtual void rysuj() = 0;         
    virtual void usunFigure() ;

    virtual void set_pSrodka(const Wektor<double,3> &wek);
    /*!
    * \brief set_pSrodka() - funkcja sluzaca ustawieniu nowych wspolzednych srodka
    * \param x - nowa wartosc x srodka figury
    * \param y - nowa wartosc y srodka figury
    * \param z - nowa wartosc z srodka figury
    */ 
    virtual void set_pSrodka(const double x, const double y, const double z);
    /*!
    * \brief sluzy do ustawienia nowej orientacji Figura3D
    * \param mac - nowa wartosc orientacji Figura3D
    */ 
    virtual void set_orientacja(const MacierzObrotu &mac);
    /*!
    * \brief sluzy do ustawienia api Figura3D
    * \param mac - nowa wartosc api do rysowania w gnuplocie
    */ 
    virtual void set_api(std::shared_ptr<drawNS::Draw3DAPI> &api);

    /*!
    * \brief metoda sluzaca do orientacji wektora
    * \param wek - wektor do zorientowania
    */ 
    virtual void get_zorientowanyWektor(Wektor<double,3> &wek) const;
};

#endif