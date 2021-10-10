#include "FactoryPrzeszkody.hh"

FactoryPrzeszkody::FactoryPrzeszkody(){

}
FactoryPrzeszkody::FactoryPrzeszkody(std::shared_ptr<drawNS::Draw3DAPI> &_api){
    api = _api;

    std::shared_ptr<Plaszczyzna_Wody> plaszczyzna_1(new Plaszczyzna_Wody(api,Wektor<double,3>(-300,-300,380)));
    std::shared_ptr<Plaszczyzna> plaszczyzna_2(new Plaszczyzna(api,Wektor<double,3>(-300,-300,-180)));
    dic1.push_back(plaszczyzna_1);
    dic1.push_back(plaszczyzna_2);
    std::shared_ptr<PrzeszkodaProstopadloscian> prostopadloscian_1(new PrzeszkodaProstopadloscian(api,Wektor<double,3>(25,150,60),Wektor<double,3>(125,50,50)));
    std::shared_ptr<PrzeszkodaProstopadloscian> prostopadloscian_2(new PrzeszkodaProstopadloscian(api,Wektor<double,3>(25,100,40),Wektor<double,3>(125,50,0)));
    std::shared_ptr<PrzeszkodaProstopadloscian> prostopadloscian_3(new PrzeszkodaProstopadloscian(api,Wektor<double,3>(70,70,70),Wektor<double,3>(125,-50,-50)));
    dic1.push_back(prostopadloscian_1);
    dic1.push_back(prostopadloscian_2);
    dic1.push_back(prostopadloscian_3);
    std::shared_ptr<PrzeszkodaPrent> pret_4(new PrzeszkodaPrent(api,50,Wektor<double,3>(0,150,50)));
    std::shared_ptr<PrzeszkodaPrent> pret_5(new PrzeszkodaPrent(api,100,Wektor<double,3>(0,150,0)));
    std::shared_ptr<PrzeszkodaPrent> pret_6(new PrzeszkodaPrent(api,150,Wektor<double,3>(0,150,-50)));
    std::shared_ptr<PrzeszkodaPrent> pret_7(new PrzeszkodaPrent(api,150,Wektor<double,3>(-180,0,50),OsY));
    dic1.push_back(pret_4);
    dic1.push_back(pret_5);
    dic1.push_back(pret_6);
    dic1.push_back(pret_7);
}
void FactoryPrzeszkody::get_kolekcja(vector<std::shared_ptr<Przeszkoda>> &dic11){
    dic11 = dic1;
}
