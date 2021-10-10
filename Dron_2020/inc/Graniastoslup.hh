#ifndef GRANIASTOSLUP_HH
#define GRANIASTOSLUP_HH

#include<iostream>
#include <math.h> 
#include "Figura3D.hh"

class Graniastoslup : public Figura3D{    
  protected:
  public:
    /*!
    * \brief konstruktor ustawiajacy poczatkowe wartosci
    */ 
    Graniastoslup();
    /*!
    * \brief  konstruktor ustawiajacy poczatkowe wartosci
    * \param api - przekazywany przez referencje obiekt do tworzenia obrazu w gnuplocie  
    * \param b - dlugosc boku podstawy Graniastoslup
    * \param h - wartosc wysokosci Graniastoslup
    */ 
    Graniastoslup(std::shared_ptr<drawNS::Draw3DAPI> &api, double b, double h);

    /*!
    * \brief pole przechowujace wartosc boku Graniastoslup
    */ 
    double bok;
    /*!
    * \brief pole przechowujace wartosc wysokosci Graniastoslup
    */ 
    double wysokosc;
    /*!
    * \brief metoda ustawiajaca bok i wysokosc Graniastoslup
    * \param b - dlugosc boku podstawy Graniastoslup
    * \param h - wartosc wysokosci Graniastoslup
    */ 
    virtual void set_pro(double b, double w);
    /*!
    * \brief metoda wyliczajaca wspolzedne punktow skladowych figury
    * \param ret - tablica w ktorej zostana zapisane punkty
    */ 
    virtual void get_wyliczonePunkty(Wektor<double,3> *ret);    
    /*!
    * \brief  rysuj() - funkcja sluzaca rysowaniu Graniastoslup w gnuplocie
    */ 
    void rysuj() override;

};



#endif
