#include "Wirniki.hh"


Wirniki::Wirniki(){
  // int dana = 50;// do testow czy sie kreca
  int dana = 10;
  bok = dana;
  wysokosc=dana;
}
Wirniki::Wirniki(std::shared_ptr<drawNS::Draw3DAPI> &_api, double b, double h){
  api = _api;
  bok = b;
  wysokosc=h;
}


void Wirniki::przesun(Wektor<double,3> dyst) {
    pSrodka = pSrodka + dyst ;
}  

void Wirniki::obrot(double kat){

    MacierzObrotu mac2('z',kat);
    orientacja = orientacja * mac2;
}



