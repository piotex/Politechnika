#include "Wektor.hh"

//-----------------------------------------------------------------konstruktory------------------------------------------------//
template<class TYP, int _ROZMIAR>
Wektor<TYP,_ROZMIAR>::Wektor()
{
    for (int i=0; i<size; i++)
    {
        (*this)[i] = 0;
    }
    ile_utworzono++;
    ile_istnieje++;
}
template<class TYP, int _ROZMIAR>
Wektor<TYP,_ROZMIAR>::Wektor(TYP *tab)
{
    for (int i=0; i<size; i++){
        (*this)[i] = tab[i];
    }
    ile_utworzono++;
    ile_istnieje++;
}
template<class TYP, int _ROZMIAR>
Wektor<TYP,_ROZMIAR>::Wektor(const Wektor<TYP,_ROZMIAR> &W) {
  ile_istnieje++;
  ile_utworzono++;
  for (int i=0; i<_ROZMIAR; ++i)
    tab[i] = W.tab[i];
}
template<class TYP, int _ROZMIAR>
Wektor<TYP,_ROZMIAR>::Wektor(TYP x, TYP y, TYP z)
{
    (*this)[0] = x;
    (*this)[1] = y;
    (*this)[2] = z;
    ile_utworzono++;
    ile_istnieje++;
}
template<class TYP, int _ROZMIAR>
Wektor<TYP,_ROZMIAR>::~Wektor()
{
    ile_istnieje--;
}

//-----------------------------------------------------------------get set------------------------------------------------//

template<class TYP, int _ROZMIAR>
unsigned long Wektor<TYP,_ROZMIAR>::zwroc_ile_istn(){
    return ile_istnieje;
}
template<class TYP, int _ROZMIAR>
unsigned long Wektor<TYP,_ROZMIAR>::zwroc_ile_utw(){
    return ile_utworzono;
}

template<class TYP, int _ROZMIAR>
const TYP & Wektor<TYP,_ROZMIAR>::operator[] (int index) const
{
    if (index < 0 || index >= size) 
    {
        std::cerr << "indeks poza zakresem @" << std::endl;
        exit(1);
    }
    return this->tab[index];
}
template<class TYP, int _ROZMIAR>
TYP & Wektor<TYP,_ROZMIAR>::operator[] (int index)
{
    if (index < 0 || index >= size) 
    {
        std::cerr << "indeks poza zakresem !" << std::endl;
        exit(1);
    }
    return this->tab[index];
}
//----------------------------------------------------------------------------------operator ---- podstawa----------------------
template<class TYP, int _ROZMIAR>
const bool Wektor<TYP,_ROZMIAR>::operator == (const Wektor & w2) const
{
    for (int i = 0; i < size; i++)
    {
        if (abs((*this).tab[2] - tab[2]) > COMPARE_VAL)
            return false;
    }
    return true;        
}
template<class TYP, int _ROZMIAR>
const bool Wektor<TYP,_ROZMIAR>::operator != (const Wektor & W2) const
{
    return !((*this)==W2);
}
template<class TYP, int _ROZMIAR>
const Wektor<TYP,_ROZMIAR> Wektor<TYP,_ROZMIAR>::operator+ (Wektor const &w) const //W1 + W2
{
  Wektor ret;
  for (int i = 0; i < size; i++)    
  {
    ret[i] = (*this)[i] + w[i];
  }
  return ret;
}
template<class TYP, int _ROZMIAR>
const Wektor<TYP,_ROZMIAR> Wektor<TYP,_ROZMIAR>::operator- (Wektor const &w) const
{
  Wektor ret;
  for (int i = 0; i < size; i++)    
  {
    ret[i] = (*this)[i] - w[i];
  }
  return ret;
}
template<class TYP, int _ROZMIAR>
void Wektor<TYP,_ROZMIAR>::operator += (const Wektor & w) //W1 += W2  
{
    for (int i = 0; i < size; i++)
    {
        (*this).tab[i] = (*this).tab[i] + w.tab[i];
    }
}
template<class TYP, int _ROZMIAR>
void Wektor<TYP,_ROZMIAR>::operator -= (const Wektor & w) //W1 -= W2  
{
    for (int i = 0; i < size; i++)
    {
        (*this).tab[i] = (*this).tab[i] - w.tab[i];
    }
}

template<class TYP, int _ROZMIAR>
const Wektor<TYP,_ROZMIAR> Wektor<TYP,_ROZMIAR>::operator* (TYP l) const // W1 * 2
{
    Wektor ret;
    for (int i = 0; i < size; i++)    
    {
        ret[i] = (*this)[i] * l;
    }
    return ret;
}
template<class TYP, int _ROZMIAR>
const Wektor<TYP,_ROZMIAR> Wektor<TYP,_ROZMIAR>::operator/ (TYP l) const // W1 / 2
{
    Wektor ret;
    if(abs(l)<COMPARE_VAL) 
        throw std::runtime_error("BLAD - dzielenie przez 0# ");
    for (int i = 0; i < size; i++)    
    {
        ret[i] = (*this)[i] / l;
    }
    return ret;
}

//---------------------------------------------------------------------------------skalary--------------------------------------------
template<class TYP, int _ROZMIAR>
const double Wektor<TYP,_ROZMIAR>::dlugosc() const
{
    double ret = 0;
    for (int i = 0; i < size; i++)    
    {
        ret += (*this)[i]*(*this)[i];
    }
    return sqrt( ret );
}
template<class TYP, int _ROZMIAR>
const TYP Wektor<TYP,_ROZMIAR>::operator* (Wektor<TYP,_ROZMIAR> const &Wek) const //skalarne
{
    TYP ilS ;
    for (int i = 0; i < size; i++)    
    {
        ilS += (*this)[i] * Wek[i];
    }
    return ilS;
}
//---------------------------------------------------------------------------------strumienie--------------------------------------------
template<class TYP, int _ROZMIAR>
std::istream& operator>> (std::istream &strm, Wektor<TYP,_ROZMIAR>& l)         
{
    for (int i = 0; i < _ROZMIAR; i++)
    {
        strm >> l[i];
    }
    return strm;
}
template<class TYP, int _ROZMIAR>
std::ostream & operator<<(std::ostream & strm,const Wektor<TYP,_ROZMIAR> & W)
{   
    for (int i = 0; i < _ROZMIAR; i++)
    {
        strm << "  " <<  W[i] ;
    }
    return strm;
}


//-----------------------------------------specjalizowane------------------------------

template<>
const bool Wektor<LiczbaZespolona,ROZMIAR>::operator == (const Wektor & w2) const
{
    for (int i = 0; i < size; i++)
    {
        if ( tab[i].getRe() != w2[i].getRe()  ||  tab[i].getIm() != w2[i].getIm() )
            return false;
    }
    return true;        
}
template<>
const Wektor<LiczbaZespolona,ROZMIAR> Wektor<LiczbaZespolona,ROZMIAR>::operator/ (LiczbaZespolona l) const // W1 / 2
{
    Wektor ret;
    if(l.modul() < COMPARE_VAL)
        throw std::runtime_error("BLAD - dzielenie przez 0# ");
    for (int i = 0; i < size; i++)    
    {
        ret[i] = (*this)[i] / l;
    }
    return ret;
}
template<>
const double Wektor<LiczbaZespolona,ROZMIAR>::dlugosc() const
{
    LiczbaZespolona ret;
    for (int i = 0; i < size; i++)    
    {
        ret += (*this)[i]*(*this)[i];
    }
    return sqrt( ret.modul() );
}
template<>
const double Wektor<double,ROZMIAR>::operator* (Wektor<double,ROZMIAR> const &Wek) const //skalarne
{
    double ilS =0;
    for (int i = 0; i < size; i++)    
    {
        ilS += (*this)[i] * Wek[i];
    }
    return ilS;
}











