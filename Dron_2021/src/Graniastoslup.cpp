#include "Graniastoslup.hh"

Graniastoslup::Graniastoslup(){
    wysokosc = 100;
    bok = 50;
}
Graniastoslup::Graniastoslup(std::shared_ptr<drawNS::Draw3DAPI> &_api, double b, double h){
    typ_figury = 5;
    api = _api;
    bok = b;
    wysokosc = h;
}
void Graniastoslup::set_pro(double b, double w){
    bok = b;
    wysokosc = w;
}

void Graniastoslup::get_wyliczonePunkty(Wektor<double,3> *ret){
    double h = bok * sqrtl(3) /2;
    double _x = bok;
    double _x2 = bok / 2;
    //powoduje ze sroba jest w tym samym kierunku co dron

    Wektor<double,3> z(0,0,wysokosc);

    Wektor<double, 3> x2_0(_x, 0, 0);
    Wektor<double, 3> x2_1(_x2, h, 0);
    Wektor<double, 3> x2_2(-_x2, h, 0);
    Wektor<double, 3> x2_3(-_x, 0, 0);
    Wektor<double, 3> x2_4(-_x2, -h, 0);
    Wektor<double, 3> x2_5(_x2, -h, 0);
    

    get_zorientowanyWektor(x2_0);
    get_zorientowanyWektor(x2_1);
    get_zorientowanyWektor(x2_2);
    get_zorientowanyWektor(x2_3);
    get_zorientowanyWektor(x2_4);
    get_zorientowanyWektor(x2_5);

    get_zorientowanyWektor(z);
    
    //rysuje wzgledem srodka 

    ret[0] = pSrodka + x2_0;
    ret[1] = pSrodka + x2_1;
    ret[2] = pSrodka + x2_2;
    ret[3] = pSrodka + x2_3;
    ret[4] = pSrodka + x2_4;
    ret[5] = pSrodka + x2_5;

    ret[6] = pSrodka + x2_0 + z;
    ret[7] = pSrodka + x2_1 + z;
    ret[8] = pSrodka + x2_2 + z;
    ret[9] = pSrodka + x2_3 + z;
    ret[10]= pSrodka + x2_4 + z;
    ret[11]= pSrodka + x2_5 + z;


    
}
void Graniastoslup::rysuj() {
    
    if (id != 0)
        usunFigure();
    Wektor<double,3> tab[12];
    get_wyliczonePunkty(tab);
        
    vector<vector<Point3D>> prost = vector<vector<Point3D>> {{
                                        drawNS::Point3D(tab[0][0],tab[0][1],tab[0][2]), 
                                        drawNS::Point3D(tab[1][0],tab[1][1],tab[1][2]), 
                                        drawNS::Point3D(tab[2][0],tab[2][1],tab[2][2]), 
                                        drawNS::Point3D(tab[3][0],tab[3][1],tab[3][2]), 
                                        drawNS::Point3D(tab[4][0],tab[4][1],tab[4][2]), 
                                        drawNS::Point3D(tab[5][0],tab[5][1],tab[5][2])
                                    },{
                                        drawNS::Point3D(tab[6][0],tab[6][1],tab[6][2]), 
                                        drawNS::Point3D(tab[7][0],tab[7][1],tab[7][2]), 
                                        drawNS::Point3D(tab[8][0],tab[8][1],tab[8][2]), 
                                        drawNS::Point3D(tab[9][0],tab[9][1],tab[9][2]), 
                                        drawNS::Point3D(tab[10][0],tab[10][1],tab[10][2]), 
                                        drawNS::Point3D(tab[11][0],tab[11][1],tab[11][2])
                                    }};

    id = api->draw_polyhedron(prost);
}

bool Graniastoslup::czy_kolizja(InterfejsDron* dron) {
    return false;
}
