#ifndef MACIERZOBROTU_HH
#define MACIERZOBROTU_HH
#include<iostream>
#include "MacierzKw.hh"

          
/*!
* \brief typ wyliczeniowy do prostego operowania na obrotach i typach macierzy obrotu
*/ 
enum TypObrotu{
    OsX,
    OsY,
    OsZ
};

class MacierzObrotu : public MacierzKw<double,3> {    
  
  public:           
    /*!
    * \brief konstruktor ustawiajacy poczatkowe wartosci macierzy diagonalnej
    */ 
    MacierzObrotu();
    /*!
    * \brief konstruktor 
    * \param mac - macierz do sprawdzenia czy jest ortagonalna
    */ 
    MacierzObrotu(const MacierzKw<double,3> &mac);
    /*!
    * \brief konstruktor ustawiajacy poczatkowe wartosci
    * \param typ - typ macierzy obrotu
    * \param kat - kat w macierzy obrotu
    */ 
    MacierzObrotu(TypObrotu typ, double kat);
    /*!
    * \brief nadpisanie mnozenia dwuch macierzy obrotu
    * \param M2 - referencja do wartosci mnozonej
    */ 
    const MacierzObrotu operator*(const MacierzObrotu & M2)const;
    /*!
    * \brief nadpisanie mnozenia macierzy obrotu i liczby zmiennoprzecinkowej
    * \param w - referencja do wartosci mnozonej
    */ 
    const MacierzObrotu operator*(const double & w)const;
    /*!
    * \brief nadpisanie mnozenia macierzy obrotu i wektora
    * \param W2 - referencja do wartosci mnozonej
    */ 
    const Wektor<double,ROZMIAR> operator*(const Wektor<double,ROZMIAR> & W2)const;
};

#endif