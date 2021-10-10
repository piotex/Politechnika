#include "Figura3D.hh"

Figura3D::Figura3D() {
    pSrodka = Wektor<double,3>(0,0,0);
}
Figura3D::Figura3D(std::shared_ptr<drawNS::Draw3DAPI> &_api){
    api = _api;
    kolor = Black;
}

void Figura3D::usunFigure(){
    api->erase_shape(id);
}
void Figura3D::set_pSrodka(const Wektor<double,3> &wek){
    pSrodka = wek;
}
void Figura3D::set_orientacja(const MacierzObrotu &mac){
    orientacja = mac;
}
void Figura3D::get_zorientowanyWektor(Wektor<double,3> &wek) const{
    wek = orientacja * wek;
}
void Figura3D::set_api(std::shared_ptr<drawNS::Draw3DAPI> &_api){
    api = _api;
}
void Figura3D::set_pSrodka(const double x, const double y, const double z){
    Wektor<double,3> wek(x,y,z);
    pSrodka = wek;
}
