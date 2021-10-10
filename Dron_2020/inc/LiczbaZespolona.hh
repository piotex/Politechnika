#ifndef LZESPOLONA_HH
#define LZESPOLONA_HH

#include<iostream>
#include <iostream>
#include <cmath>
#include "../inc/Rozmiar.hh"

class LiczbaZespolona {    

  double re;    
  double im;
  

  public:           
    LiczbaZespolona();
    LiczbaZespolona(double re, double im);
    explicit LiczbaZespolona( double a );
    //----------------------------------------------------------------------
    void setIm(double im);
    void setRe(double re);
    const double getIm()const;
    const double getRe()const;

    double modul()const;
    LiczbaZespolona sprzezenie()const;
    //----------------------------------------------------------------------
    const LiczbaZespolona operator+(LiczbaZespolona  lz)const;
    const LiczbaZespolona operator-(LiczbaZespolona  lz)const;
    const LiczbaZespolona operator*(LiczbaZespolona  lz)const;
    const LiczbaZespolona operator/(LiczbaZespolona  lz)const;
    //----------------------------------------------------------------------
    void operator+=(LiczbaZespolona  lz);
    void operator-=(LiczbaZespolona  lz);
    void operator*=(LiczbaZespolona  lz);
    void operator/=(LiczbaZespolona  lz);
    //----------------------------------------
    const LiczbaZespolona operator*(double  d)const;
    const LiczbaZespolona operator/(double  d)const;
    //----------------------------------------------------------------------
    const bool operator!=(LiczbaZespolona  lz)const;
    const bool operator==(LiczbaZespolona  lz)const;
    const bool operator<(double  lz)const;
    const bool operator>(double  lz)const;
    LiczbaZespolona& operator=( double d);
};

std::istream& operator>>(std::istream &strm, LiczbaZespolona& l);
std::ostream& operator<<(std::ostream &wyjscie, const LiczbaZespolona &s);

#endif