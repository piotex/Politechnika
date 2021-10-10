#include "Wektor.cpp"

typedef double TYP;

template class Wektor<TYP,ROZMIAR>;
template std::istream & operator>>(std::istream &strm, Wektor<TYP,ROZMIAR> &W);
template std::ostream & operator<< (std::ostream &strm, const Wektor<TYP,ROZMIAR> &W);

