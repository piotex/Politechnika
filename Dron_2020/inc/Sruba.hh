#ifndef SROBA_HH
#define SROBA_HH

#include "Graniastoslup.hh"

class Sruba : public Graniastoslup{    
  protected:
  public:
    /*!
    * \brief konstruktor ustawiajacy poczatkowe wartosci Sruba
    */ 
    Sruba();
    /*!
    * \brief konstruktor ustawiajacy poczatkowe wartosci Sruba
    * \param api - przekazywany przez referencje obiekt do tworzenia obrazu w gnuplocie  
    */ 
    Sruba(std::shared_ptr<drawNS::Draw3DAPI> &api, double b, double h);

    /*!
    * \brief funkcja sluzaca do przesuniecia o zadany wektor srodka figury
    */ 
    virtual void przesun(Wektor<double,3> odleglosc);

    /*!
    * \brief funkcja sluzaca do obrotu o zadany kat figury
    */ 
    virtual void obrot(TypObrotu typ, double kat);
};



#endif
