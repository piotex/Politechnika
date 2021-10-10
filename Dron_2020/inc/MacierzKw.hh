#ifndef MACIERZKW_HH
#define MACIERZKW_HH

#include <math.h>
#include <iostream>
#include <iomanip>
#include <cmath>

#include "Wektor.hh"

enum Metoda_Obl_Wyznacznika {Sarrus, Laplace, Gauss};

template<class _TYP, int _ROZMIAR>
class MacierzKw {
    protected:
        Wektor<_TYP,_ROZMIAR> tab[_ROZMIAR]; //2. propozycja, zalecana

    public:
        MacierzKw();
        MacierzKw(Wektor<_TYP,_ROZMIAR> tab[]);
        int size = _ROZMIAR;                             //lepsze bylo by protected, ale nie mozna dziedziczyc
        
        const _TYP wyznacznik(Metoda_Obl_Wyznacznika odw = Sarrus)const;// rozwiniecje laplace'a, gaussa, sarrusa
        const MacierzKw transponuj() const;

        const MacierzKw operator*(const MacierzKw & M2)const;
        const MacierzKw operator+(const MacierzKw & M2)const;
        const MacierzKw operator-(const MacierzKw & M2)const;

        const MacierzKw operator*(_TYP l)const;
        const Wektor<_TYP,_ROZMIAR> operator*(const Wektor<_TYP,_ROZMIAR> & W2)const;

        const bool operator== (const MacierzKw & M) const;
        const bool operator!= (const MacierzKw & M) const;

        const Wektor<_TYP,_ROZMIAR> & operator[] (int index) const;
        Wektor<_TYP,_ROZMIAR> & operator[] (int index); 

        const Wektor<_TYP,_ROZMIAR> get_Kolumna(const int numerKolumny)const;
        void set_Kolumna(const int numerKolumny,Wektor<_TYP,_ROZMIAR> w);
};
template<class _TYP, int _ROZMIAR>
const MacierzKw<_TYP,_ROZMIAR> & operator*(_TYP l, const MacierzKw<_TYP,_ROZMIAR> & M2);
template<class _TYP, int _ROZMIAR>
std::ostream & operator<<(std::ostream & strm,const MacierzKw<_TYP,_ROZMIAR> & W);
template<class _TYP, int _ROZMIAR>
std::istream& operator>> (std::istream &stream, MacierzKw<_TYP,_ROZMIAR>& wyr);



#endif