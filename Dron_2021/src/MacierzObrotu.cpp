#include "MacierzObrotu.hh"

MacierzObrotu::MacierzObrotu(){
    for (int i = 0; i < 3; i++)
    {
        tab[i][i] = 1;
    }
}
MacierzObrotu::MacierzObrotu(const MacierzKw<double,3> &mac){
    if(abs(tab[0] * tab[1]) > COMPARE_VAL ||  abs(tab[1] * tab[2]) > COMPARE_VAL  ||  abs(tab[0] * tab[2]) > COMPARE_VAL ) //warunek iloczynu skalarnego
        throw std::runtime_error("BLAD - macierz nie jest ortagonalna");
    if(abs((*this).wyznacznik() - 1) > COMPARE_VAL)
        throw std::runtime_error("BLAD - macierz nie jest ortagonalna - wyznacznik");
}
MacierzObrotu::MacierzObrotu(char typ, double kat){
    kat = kat * PI / 180;
    switch (typ)
    {
        case 'x':{
            tab[0][0] = 1;
            tab[0][1] = 0;
            tab[0][2] = 0;
            tab[1][0] = 0;
            tab[1][1] = cos(kat);
            tab[1][2] = -sin(kat);
            tab[2][0] = 0;
            tab[2][1] = sin(kat);
            tab[2][2] = cos(kat);
            break;
        }
        case 'y':{
            tab[0][0] = cos(kat);
            tab[0][1] = 0;
            tab[0][2] = sin(kat);
            tab[1][0] = 0;
            tab[1][1] = 1;
            tab[1][2] = 0;
            tab[2][0] = -sin(kat); 
            tab[2][1] = 0;
            tab[2][2] = cos(kat);
            break;
        }
        case 'z':{
            tab[0][0] = cos(kat);
            tab[0][1] = -sin(kat);
            tab[0][2] = 0;
            tab[1][0] = sin(kat);
            tab[1][1] = cos(kat);
            tab[1][2] = 0;
            tab[2][0] = 0;
            tab[2][1] = 0;
            tab[2][2] = 1;
            break;
        }
    }
}

const MacierzObrotu MacierzObrotu::operator*(const double & w)const{
    MacierzObrotu ret;
    for (int i=0; i < size; i++)
        ret[i] = tab[i] * w;
    return ret;
}
const MacierzObrotu MacierzObrotu::operator*(const MacierzObrotu & w)const{
    MacierzObrotu ret;
    MacierzObrotu pomocnicza = w;
    pomocnicza.transponuj();

    for (int i=0; i < size; i++)
        for (int j=0; j < size; j++)
            ret[i][j] = tab[i] * pomocnicza[j];
    return ret;
}
const Wektor<double,3> MacierzObrotu::operator *(const Wektor<double,3> &w) const 
{
    Wektor<double,3> ret;
    for (int i=0; i < size; i++)
        ret[i] += tab[i] * w;
    return ret;
}
