#ifndef MACIERZOBROTU_HH
#define MACIERZOBROTU_HH

#include "MacierzKw.hh"



class MacierzObrotu : public MacierzKw<double,3> {    
  
  public:           
    MacierzObrotu();
    MacierzObrotu(const MacierzKw<double,3> &mac);
    MacierzObrotu(char typ, double kat);
    const MacierzObrotu operator*(const MacierzObrotu & M2)const;
    const MacierzObrotu operator*(const double & w)const;
    const Wektor<double,ROZMIAR> operator*(const Wektor<double,ROZMIAR> & W2)const;
};

#endif