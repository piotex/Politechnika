#include "PrzeszkodaPrent.hh"


PrzeszkodaPrent::PrzeszkodaPrent(){
}

PrzeszkodaPrent::PrzeszkodaPrent(std::shared_ptr<drawNS::Draw3DAPI> &_api, double dlB, Wektor<double,3> pol,TypObrotu typ){
    if(dlB <= 0){
        std::cerr << "niedodatnia wartość dlugosci" << std::endl;
        exit(1);
    }  
    api = _api;
    dlugosc = dlB;
    pSrodka = pol;
    os = typ;
    rysuj();
}
double wieksza(double a, double b){
    if (a > b)
    {
        return a;
    }
    return b;
}
double mniejsza(double a, double b){
    if (a < b)
    {
        return a;
    }
    return b;
}

bool PrzeszkodaPrent::czy_kolizja(InterfejsDron* dron){
    vector<Wektor<double,3>> punkty;
    dron->get_punktyKrytyczne(punkty);
    if (os == OsX)
    {
        double x1 = pSrodka[0] + dlugosc;
        double x2 = pSrodka[0] - dlugosc;
        bool ok = false;
        for (int i = 0; i < 8; i++)
        {
            if (punkty[i][0] > x2 && punkty[i][0] < x1)
            {
                ok = true;
            }
        }
        if (ok)
        {
            if (punkty[0][2] > pSrodka[2] && punkty[4][2] < pSrodka[2])
            {
                if( (punkty[0][1] >  pSrodka[1] && punkty[3][1] < pSrodka[1]) 
                 || (punkty[3][1] >  pSrodka[1] && punkty[0][1] < pSrodka[1]) 
                 || (punkty[1][1] >  pSrodka[1] && punkty[2][1] < pSrodka[1]) 
                 || (punkty[2][1] >  pSrodka[1] && punkty[1][1] < pSrodka[1]) )
                {
                        return true;
                }
            } 
        }
    }
    if (os == OsY)
    {
        double x1 = pSrodka[1] + dlugosc;
        double x2 = pSrodka[1] - dlugosc;
        bool ok = false;
        for (int i = 0; i < 8; i++)
        {
            if (punkty[i][1] > x2 && punkty[i][1] < x1)
            {
                ok = true;
            }
        }
        if (ok)
        {
           if (punkty[0][2] >= pSrodka[2] && punkty[4][2] <= pSrodka[2])
            {
                if( (punkty[0][0] >  pSrodka[0] && punkty[3][0] < pSrodka[0]) 
                 || (punkty[3][0] >  pSrodka[0] && punkty[0][0] < pSrodka[0]) 
                 || (punkty[1][0] >  pSrodka[0] && punkty[2][0] < pSrodka[0]) 
                 || (punkty[2][0] >  pSrodka[0] && punkty[1][0] < pSrodka[0]) )
                {
                        return true;
                }
            }   
        }
    }
    if (os == OsZ)
    {
        double x1 = pSrodka[2] + dlugosc;
        double x2 = pSrodka[2] - dlugosc;
        bool ok = false;
        for (int i = 0; i < 8; i++)
        {
            if (punkty[i][2] > x2 && punkty[i][2] < x1)
            {
                ok = true;
            }
        }
        if (ok)
        {
            if( (punkty[0][1] >  pSrodka[1] && punkty[3][1] < pSrodka[1]) || (punkty[2][1] >  pSrodka[1] && punkty[1][1] < pSrodka[1]) )
            {
                if( (punkty[0][0] >  pSrodka[0] && punkty[1][0] < pSrodka[0]) || (punkty[2][0] >  pSrodka[0] && punkty[3][0] < pSrodka[0]) )
                {
                        return true;
                }
            }
        }
    }
    
    
    
    return false;
}

void PrzeszkodaPrent::rysuj(){
    if(id != 0)
        usunFigure();

    if (os == OsX)
    {
        double x1 = pSrodka[0] + dlugosc;
        double x2 = pSrodka[0] - dlugosc;
        id = api->draw_line(drawNS::Point3D(x1,pSrodka[1],pSrodka[2]), drawNS::Point3D(x2,pSrodka[1],pSrodka[2]));
    }
    if (os == OsY)
    {
        double x1 = pSrodka[1] + dlugosc;
        double x2 = pSrodka[1] - dlugosc;
        id = api->draw_line(drawNS::Point3D(pSrodka[0],x1,pSrodka[2]), drawNS::Point3D(pSrodka[0],x2,pSrodka[2]));
    }
    if (os == OsZ)
    {
        double x1 = pSrodka[2] + dlugosc;
        double x2 = pSrodka[2] - dlugosc;
        id = api->draw_line(drawNS::Point3D(pSrodka[0],pSrodka[1],x1), drawNS::Point3D(pSrodka[0],pSrodka[1],x2));
    }
}