#include "../inc/LiczbaZespolona.hh"
using std::abs;

//----------------------------------------------------------------------------------konstruktor---------------------------------
LiczbaZespolona::LiczbaZespolona():re{0},im{0}{}
LiczbaZespolona::LiczbaZespolona( double a ) : re( a ) { im =0; }
 
LiczbaZespolona::LiczbaZespolona(double _re, double _im):re{_re},im{_im}{}
//-------------------------------------------------------------------------------------specjalne---------------------------------
void LiczbaZespolona::setIm(double _im){
  im = _im;
}
void LiczbaZespolona::setRe(double _re){
  re = _re;
}
const double LiczbaZespolona::getIm()const{
  return im;
}
const double LiczbaZespolona::getRe()const{
  return re;
}
double LiczbaZespolona::modul()const
{
  return sqrt(re*re + im*im);
}
LiczbaZespolona LiczbaZespolona::sprzezenie()const
{
  LiczbaZespolona l(re,-im);
  return l;
}
//--------------------------------------------------------------------------------------logiczne---------------------------------
const bool LiczbaZespolona::operator==(LiczbaZespolona  lz)const
{  
  if (abs( re - lz.re ) < COMPARE_VAL && abs( im - lz.im ) < COMPARE_VAL )
  {
    return true;
  }
  return false;
}
const bool LiczbaZespolona::operator!=(LiczbaZespolona lz)const
{
  LiczbaZespolona lzB(re,im);
  return !(lzB==lz);
}
const bool LiczbaZespolona::operator<(double  lz)const{

  if ((*this).modul() < lz){
    return true;
  }
  return false;  
}
const bool LiczbaZespolona::operator>(double  lz)const{
  if ((*this).modul() > lz){
    return true;
  }
  return false;  
}
//-------------------------------------------------------------------------------operator ---- bez zwrotka ----------------------
LiczbaZespolona& LiczbaZespolona::operator=( double d){
  re = d;
  im = 0;
  return (*this);
}
void LiczbaZespolona::operator+=(LiczbaZespolona  lz)
{
  re += lz.re;
  im += lz.im;
}
void LiczbaZespolona::operator-=(LiczbaZespolona  lz)
{
  re -= lz.re;
  im -= lz.im;
}
void LiczbaZespolona::operator*=(LiczbaZespolona  lz)
{
  LiczbaZespolona copy(re,im);
  re = (copy.re * lz.re) - (copy.im * lz.im);
  im = (copy.re * lz.im) + (copy.im * lz.re);
}
void LiczbaZespolona::operator/=(LiczbaZespolona  lz)
{
  LiczbaZespolona copy(re,im);
  double m = lz.modul()*lz.modul() ;
  if(abs(m)<COMPARE_VAL)
      throw std::runtime_error("BLAD - dzielenie przez 0/=0 ");
  re = ( copy.re * lz.re + copy.im * lz.im ) / m;
  im = ( copy.im * lz.re - copy.re * lz.im ) / m; 
}
//--------------------------------------------------------
const LiczbaZespolona LiczbaZespolona::operator*(double  d)const
{
  LiczbaZespolona wynik(re*d,im*d);
  return wynik;
}
const LiczbaZespolona LiczbaZespolona::operator/(double  d)const
{
  if(abs(d)<COMPARE_VAL)
      throw std::runtime_error("BLAD - dzielenie przez 0@ ");
  LiczbaZespolona wynik(re/d,im/d);
  return wynik;
}
//----------------------------------------------------------------------------------operator ---- zwrotka ----------------------
const LiczbaZespolona LiczbaZespolona::operator+(LiczbaZespolona  lz)const
{
  LiczbaZespolona Wynik(re + lz.re,im + lz.im);
  return Wynik;
}
const LiczbaZespolona LiczbaZespolona::operator-(LiczbaZespolona  lz)const
{
  LiczbaZespolona Wynik(re - lz.re,im - lz.im);
  return Wynik;
}
const LiczbaZespolona LiczbaZespolona::operator*(LiczbaZespolona  lz)const
{
  LiczbaZespolona Wynik( (re * lz.re) - (im * lz.im) , (re * lz.im) + (im * lz.re) );
  return Wynik;
}
const LiczbaZespolona LiczbaZespolona::operator/(LiczbaZespolona  lz)const
{
  double m = lz.re * lz.re + lz.im * lz.im ;
  if(abs(m)<COMPARE_VAL)
      throw std::runtime_error("BLAD - dzielenie przez 0 ");
  LiczbaZespolona Wynik;
  Wynik.re = ((*this).re * lz.re + (*this).im * lz.im) / m;
  Wynik.im = ((*this).im * lz.re - (*this).re * lz.im) / m;

  return Wynik;
}
//---------------------------------------------------------------------------------------strumienie-----------------------------
std::istream& operator>> (std::istream &strm, LiczbaZespolona& l)         
{
  double re = 0;
  double im = 0;
  char znak = 'x';
  strm >> znak;
  if (znak != '(')
    strm.setstate(std::ios::failbit); 
  strm>>re>>im>>znak;
  l.setIm(im);
  l.setRe(re);
  if (znak != 'i')
    strm.setstate(std::ios::failbit); 
  strm>>znak;
  if (znak != ')')
    strm.setstate(std::ios::failbit); 

  return strm;
}
std::ostream & operator<< (std::ostream &wyjscie, const LiczbaZespolona &s) 
{
  double re = s.getRe();
  double im = s.getIm();
  wyjscie << "(" <<re << std::showpos <<im << std::noshowpos << "i)";
  return wyjscie;
}
