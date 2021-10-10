#include "Prostopadloscian.hh"


Prostopadloscian::Prostopadloscian(){
    dlugosciBokow = Wektor<double,3>(10,10,10);
}
Prostopadloscian::Prostopadloscian(std::shared_ptr<drawNS::Draw3DAPI> &_api, Wektor<double,3> dlB){
    api = _api;
    dlugosciBokow = dlB;
    kolor = "black";
}

void Prostopadloscian::get_wyliczonePunkty(Wektor<double,3> *ret){

  Wektor<double,3> zorientowane_polowy_dl_b = orientacja * (dlugosciBokow/2);    // zorientowany wektor o dlugosci polowy kazdego boku - na jego podstawie okreslany jest pierwszy punkt a potem kolejna za pomoca dodania dlugosci odpowiednich bokow

  Wektor<double,3> bokX(dlugosciBokow[0],0,0);
  Wektor<double,3> bokY(0,dlugosciBokow[1],0);
  Wektor<double,3> bokZ(0,0,dlugosciBokow[2]);

  get_zorientowanyWektor(bokX);
  get_zorientowanyWektor(bokY);
  get_zorientowanyWektor(bokZ);
  
  ret[0] = pSrodka + zorientowane_polowy_dl_b;
  ret[1] = pSrodka + zorientowane_polowy_dl_b - bokX;
  ret[2] = pSrodka + zorientowane_polowy_dl_b - bokX - bokY;
  ret[3] = pSrodka + zorientowane_polowy_dl_b - bokY;

  ret[4] = pSrodka + zorientowane_polowy_dl_b - bokZ;
  ret[5] = pSrodka + zorientowane_polowy_dl_b - bokZ - bokX;
  ret[6] = pSrodka + zorientowane_polowy_dl_b - bokZ - bokX - bokY;
  ret[7] = pSrodka + zorientowane_polowy_dl_b - bokZ - bokY;
}


void Prostopadloscian::rysuj() {

    if (id != 0) {
        usunFigure();
    }
    else {
        id = api->draw_polyhedron(vector<vector<Point3D>>{}, kolor);
    }
    int ilosc_w = 8;

    Wektor<double,3> tab[ilosc_w] ;
    get_wyliczonePunkty(tab);
    //ilosc_w = tab.capacity();
    //vector<vector<Point3D>> prost = vector<vector<Point3D>>(2, vector<Point3D>{});
    /*
    for (int i = 0; i < 2; i++)
    {
        for (int j = 0; j < ilosc_w/2; j++)
        {
            prost[i].pushBack(drawNS::Point3D(tab[j+(i*(ilosc_w/2))][0],tab[j+(i*(ilosc_w/2))][1], tab[j+(i*(ilosc_w/2))][2]));
        }
    }
    */

    vector<vector<Point3D>> prost = vector<vector<Point3D>> {{
                                        drawNS::Point3D(tab[0][0],tab[0][1],tab[0][2]), 
                                        drawNS::Point3D(tab[1][0],tab[1][1],tab[1][2]), 
                                        drawNS::Point3D(tab[2][0],tab[2][1],tab[2][2]), 
                                        drawNS::Point3D(tab[3][0],tab[3][1],tab[3][2])
                                    },{
                                        drawNS::Point3D(tab[4][0],tab[4][1],tab[4][2]), 
                                        drawNS::Point3D(tab[5][0],tab[5][1],tab[5][2]), 
                                        drawNS::Point3D(tab[6][0],tab[6][1],tab[6][2]), 
                                        drawNS::Point3D(tab[7][0],tab[7][1],tab[7][2])
                                    }};
    id = api->draw_polyhedron(prost,kolor);
 
}

