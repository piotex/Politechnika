#include "Sruba.hh"


Sruba::Sruba(){
  // int dana = 50;// do testow czy sie kreca
  int dana = 10;
  bok = dana;
  wysokosc=dana;
}
Sruba::Sruba(std::shared_ptr<drawNS::Draw3DAPI> &_api, double b, double h){
  api = _api;
  bok = b;
  wysokosc=h;
}


void Sruba::przesun(Wektor<double,3> dyst) {
    pSrodka = pSrodka + dyst ;
}  

void Sruba::obrot(TypObrotu typ, double kat){

    MacierzObrotu mac2(typ,kat);
    orientacja = orientacja * mac2;
}



