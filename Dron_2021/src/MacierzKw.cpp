#include "MacierzKw.hh"

template<class _TYP, int _ROZMIAR>
MacierzKw<_TYP,_ROZMIAR>::MacierzKw()
{
    Wektor<_TYP,_ROZMIAR> w;
    for (int i = 0; i < size; i++)
    {
        (*this)[i] = w;     
    }
}
template<class _TYP, int _ROZMIAR>
MacierzKw<_TYP,_ROZMIAR>::MacierzKw(Wektor<_TYP,_ROZMIAR> _tab[])
{
    for (int i = 0; i < size; i++)
    {
        (*this)[i] = _tab[i];     
    }
}
template<class _TYP, int _ROZMIAR>
const Wektor<_TYP,_ROZMIAR> & MacierzKw<_TYP,_ROZMIAR>::operator[] (int index) const
{
    if(index < 0 || index >= size) 
    {
        std::cerr << "indeks poza zakresem #" << std::endl;
        exit(1);
    }
    return this->tab[index];
}
template<class _TYP, int _ROZMIAR>
Wektor<_TYP,_ROZMIAR>& MacierzKw<_TYP,_ROZMIAR>::operator[] (int index) 
{
    if (index < 0 || index >= size) 
    {
        std::cerr << "indeks poza zakresem $" << std::endl;
        exit(1);
    }
    return this->tab[index];
}
template<class _TYP, int _ROZMIAR>
const bool MacierzKw<_TYP,_ROZMIAR>::operator== (const MacierzKw<_TYP,_ROZMIAR> & M) const
{
    for(int i=0;i<size;i++)
    {
        if(tab[i]!=M[i])
	        return false;
    }
    return true;
}
template<class _TYP, int _ROZMIAR>
const bool MacierzKw<_TYP,_ROZMIAR>::operator!= (const MacierzKw<_TYP,_ROZMIAR> & M) const
{
    return !((*this) == M);
}
template<class _TYP, int _ROZMIAR>
MacierzKw<_TYP,_ROZMIAR> getMalaMacierz(MacierzKw<_TYP,_ROZMIAR> base, int zakaz){
    MacierzKw<_TYP,_ROZMIAR> m;
    m.size = base.size-1;
    for(int i=1,w=0;i<base.size;i++,w++){
        for(int j=0,k=0;j<base.size;j++){
            if (j!=zakaz)
            {
                m[w][k] = base[i][j];
                k++;
            }
        }
    }
    return m;
}
template<class _TYP, int _ROZMIAR>
const _TYP MacierzKw<_TYP,_ROZMIAR>::wyznacznik(Metoda_Obl_Wyznacznika odw )const
{
    _TYP ret(0.0);

    switch(odw)
    {
        case Sarrus:{
                if (size == 3)
                {
                    ret += (*this)[0][0] * (*this)[1][1] * (*this)[2][2] ;
                    ret += (*this)[1][0] * (*this)[2][1] * (*this)[0][2] ;
                    ret += (*this)[2][0] * (*this)[0][1] * (*this)[1][2] ;

                    ret -= (*this)[2][0] * (*this)[1][1] * (*this)[0][2] ;
                    ret -= (*this)[0][0] * (*this)[2][1] * (*this)[1][2] ;
                    ret -= (*this)[1][0] * (*this)[0][1] * (*this)[2][2] ;
                    return ret;
                }
                if (size == 2)
                {
                    ret += (*this)[0][0] * (*this)[1][1] - (*this)[1][0] * (*this)[0][1] ;
                    return ret;
                }
                std::cout<<"Bledny rozmiar macierzy dla obliczania metoda Sarusa!";
                exit(8);
        }
        case Laplace:{
                std::cout<<"nie zaimplementowano!";
                exit(8);
        }
        case Gauss:{ // taki nie czysty 
            MacierzKw<_TYP,_ROZMIAR> copy = (*this);
            _TYP mnoznikiWyznacznika(1);

            while (copy.size > 3)
            {
                if (copy[0][0] != _TYP(0))
                {
                    mnoznikiWyznacznika *= copy[0][0];
                    copy[0] = copy[0] / copy[0][0];             // 1 w pierwszyn rzedzie
                }else{
                    MacierzKw<_TYP,_ROZMIAR> copy_copy = copy;
                    for (int numerNiezerowyPierwszyArgument = 0; numerNiezerowyPierwszyArgument < copy.size; numerNiezerowyPierwszyArgument++)
                    {
                        if (copy[numerNiezerowyPierwszyArgument][0] != _TYP(0)){
                            copy[0] = copy_copy[numerNiezerowyPierwszyArgument];
                            copy[numerNiezerowyPierwszyArgument] = copy_copy[0];
                            break;
                        }    
                    }
                    mnoznikiWyznacznika *= copy[0][0] * (-1);
                    copy[0] = copy[0] / copy[0][0];             // 1 w pierwszyn rzedzie
                }
             
                for (int j = 1; j < copy.size; j++)         // 0 w pierwszej kolumnie
                {
                    copy[j] = copy[j] - (copy[0] * copy[j][0]);
                }    
                copy = getMalaMacierz(copy,0);      // wyliczenie wyznacznika po laplacie wzgledem 1 kolumny - jak jest 1 0 0 0 0... to jest dosc prosto
            }
            ret = copy.wyznacznik(Sarrus);     //gdy zostaje nam maczerz trzy x  trzy liczymy po sarusie
            ret *= mnoznikiWyznacznika ;
            
            return ret;
        }
    }
    return ret;
}
template<class _TYP, int _ROZMIAR>
const MacierzKw<_TYP,_ROZMIAR> MacierzKw<_TYP,_ROZMIAR>::transponuj() const 
{
    MacierzKw ret;
    for (int i=0; i < size; i++)
        for (int j=0; j < size; j++)
            ret[j][i] = tab[i][j];
    return ret;
}
template<class _TYP, int _ROZMIAR>
const Wektor<_TYP,_ROZMIAR> MacierzKw<_TYP,_ROZMIAR>::get_Kolumna(const int numerKolumny)const
{
    Wektor<_TYP,_ROZMIAR> ret;
    for (int i = 0; i < size; i++)
    {
        ret[i] = (*this)[i][numerKolumny];
    }
    return ret;
}
template<class _TYP, int _ROZMIAR>
void MacierzKw<_TYP,_ROZMIAR>::set_Kolumna(const int numerKolumny, Wektor<_TYP,_ROZMIAR> w)
{
    for (int i = 0; i < size; i++)
    {
        (*this)[i][numerKolumny] = w[i];
    }
}   
template<class _TYP, int _ROZMIAR>  
const MacierzKw<_TYP,_ROZMIAR> MacierzKw<_TYP,_ROZMIAR>::operator*(const MacierzKw & w)const
{
    MacierzKw<_TYP,_ROZMIAR> ret;
    MacierzKw<_TYP,_ROZMIAR> pomocnicza = w;
    pomocnicza.transponuj();

    for (int i=0; i < size; i++)
        for (int j=0; j < size; j++)
            ret[i][j] = tab[i] * pomocnicza[j];
    return ret;
}
template<class _TYP, int _ROZMIAR>
const MacierzKw<_TYP,_ROZMIAR> MacierzKw<_TYP,_ROZMIAR>::operator+(const MacierzKw &w) const 
{
    MacierzKw ret;
    for (int i=0; i < size; i++)
        ret [i] = tab[i] + w[i];
    return ret;
}
template<class _TYP, int _ROZMIAR>
const MacierzKw<_TYP,_ROZMIAR> MacierzKw<_TYP,_ROZMIAR>::operator-(const MacierzKw<_TYP,_ROZMIAR> &w) const 
{
    MacierzKw ret;
    for (int i=0; i < size; i++)
        ret [i] = tab[i] - w[i];
    return ret;
}
template<class _TYP, int _ROZMIAR>
const MacierzKw<_TYP,_ROZMIAR> MacierzKw<_TYP,_ROZMIAR>::operator *(_TYP l) const 
{
    MacierzKw ret;
    for (int i=0; i < size; i++)
        ret[i] = tab[i] * l;
    return ret;
}
template<class _TYP, int _ROZMIAR>
const Wektor<_TYP,_ROZMIAR> MacierzKw<_TYP,_ROZMIAR>::operator *(const Wektor<_TYP,_ROZMIAR> &w) const 
{
    Wektor<_TYP,_ROZMIAR> ret;
    for (int i=0; i < size; i++)
        ret[i] += tab[i] * w;
    return ret;
}
template<class _TYP, int _ROZMIAR>
std::ostream & operator<<(std::ostream & strm,const MacierzKw<_TYP,_ROZMIAR> & m)
{   
    for (int i = 0; i < m.size; i++)
    {
        strm << m[i] << "\r\n"  ;
    }
    return strm;
}
template<class _TYP, int _ROZMIAR>
std::istream& operator>> (std::istream &stream, MacierzKw<_TYP,_ROZMIAR>& wyr)
{
    for (int i = 0; i < wyr.size; i++)
    {
        stream >> wyr[i];
    }
    return stream;
}

template<>
const double MacierzKw<double,3>::wyznacznik(Metoda_Obl_Wyznacznika odw )const
{
    double ret = 0;

    switch(odw)
    {
        case Sarrus:{
                if (size == 3)
                {
                    ret += (*this)[0][0] * (*this)[1][1] * (*this)[2][2] ;
                    ret += (*this)[1][0] * (*this)[2][1] * (*this)[0][2] ;
                    ret += (*this)[2][0] * (*this)[0][1] * (*this)[1][2] ;

                    ret -= (*this)[2][0] * (*this)[1][1] * (*this)[0][2] ;
                    ret -= (*this)[0][0] * (*this)[2][1] * (*this)[1][2] ;
                    ret -= (*this)[1][0] * (*this)[0][1] * (*this)[2][2] ;
                    return ret;
                }
                if (size == 2)
                {
                    ret += (*this)[0][0] * (*this)[1][1] - (*this)[1][0] * (*this)[0][1] ;
                    return ret;
                }
                std::cout<<"Bledny rozmiar macierzy dla obliczania metoda Sarusa!";
                exit(8);
        }
        case Laplace:{
                std::cout<<"nie zaimplementowano!";
                exit(8);
        }
        case Gauss:{ // taki nie czysty 
            MacierzKw<double,3> copy = (*this);
            double mnoznikiWyznacznika(1);

            while (copy.size > 3)
            {
                if(abs(copy[0][0]) > COMPARE_VAL){
                    mnoznikiWyznacznika *= copy[0][0];
                    copy[0] = copy[0] / copy[0][0];             // 1 w pierwszyn rzedzie
                }else{
                    MacierzKw<double,3> copy_copy = copy;
                    for (int numerNiezerowyPierwszyArgument = 0; numerNiezerowyPierwszyArgument < copy.size; numerNiezerowyPierwszyArgument++)
                    {
                        if(abs(copy[numerNiezerowyPierwszyArgument][0]) > COMPARE_VAL){
                            copy[0] = copy_copy[numerNiezerowyPierwszyArgument];
                            copy[numerNiezerowyPierwszyArgument] = copy_copy[0];
                            break;
                        }    
                    }
                    mnoznikiWyznacznika *= copy[0][0] * (-1);
                    copy[0] = copy[0] / copy[0][0];             // 1 w pierwszyn rzedzie
                }
             
                for (int j = 1; j < copy.size; j++)         // 0 w pierwszej kolumnie
                {
                    copy[j] = copy[j] - (copy[0] * copy[j][0]);
                }    
                copy = getMalaMacierz(copy,0);      // wyliczenie wyznacznika po laplacie wzgledem 1 kolumny - jak jest 1 0 0 0 0... to jest dosc prosto
            }
            ret = copy.wyznacznik(Sarrus);     //gdy zostaje nam maczerz trzy x  trzy liczymy po sarusie
            ret *= mnoznikiWyznacznika ;
            
            return ret;
        }
    }
    return ret;
}