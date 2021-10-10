#include "Wzgorze.hh"

Wzgorze::Wzgorze()
{
    dlugosciBokow = Wektor<double, 3>(10, 10, 10);
}

Wzgorze::Wzgorze(std::shared_ptr<drawNS::Draw3DAPI>& _api, Wektor<double, 3> dlB, Wektor<double, 3> pol)
{
    typ_figury = 2;
    api = _api;
    dlugosciBokow = dlB;
    kolor = "black";
    pSrodka = pol;
    pSrodka[2] += (dlugosciBokow[2] / 2);
    rysuj();
}

bool Wzgorze::czy_kolizja(InterfejsDron* dron)
{
    vector<Wektor<double, 3>> punkty;
    dron->get_punktyKrytyczne(punkty);

    double x1 = pSrodka[0] + (dlugosciBokow[0] / 2);
    double x2 = pSrodka[0] - (dlugosciBokow[0] / 2);
    double y1 = pSrodka[1] + (dlugosciBokow[1] / 2);
    double y2 = pSrodka[1] - (dlugosciBokow[1] / 2);
    bool okx = false;
    bool oky = false;
    for (int i = 0; i < 8; i++)
    {
        if (punkty[i][0] > x2 && punkty[i][0] < x1)
        {
            okx = true;
        }
        if (punkty[i][1] > y2 && punkty[i][1] < y1)
        {
            oky = true;
        }
    }
    if (okx && oky) {
        return true;
    }

    return false;
}
void Wzgorze::get_wyliczonePunkty(Wektor<double, 3>* ret) {

    Wektor<double, 3> zorientowane_polowy_dl_b = orientacja * (dlugosciBokow / 2);    // zorientowany wektor o dlugosci polowy kazdego boku - na jego podstawie okreslany jest pierwszy punkt a potem kolejna za pomoca dodania dlugosci odpowiednich bokow

    Wektor<double, 3> bokX(dlugosciBokow[0], 0, 0);
    Wektor<double, 3> bokY(0, dlugosciBokow[1], 0);
    Wektor<double, 3> bokZ(0, 0, dlugosciBokow[2]);

    get_zorientowanyWektor(bokX);
    get_zorientowanyWektor(bokY);
    get_zorientowanyWektor(bokZ);

    ret[0] = pSrodka + zorientowane_polowy_dl_b - bokZ;////
    ret[1] = pSrodka + zorientowane_polowy_dl_b - bokZ - bokX;////
    ret[2] = pSrodka + zorientowane_polowy_dl_b - bokX - bokY;
    ret[3] = pSrodka + zorientowane_polowy_dl_b - bokY;

    ret[4] = pSrodka + zorientowane_polowy_dl_b - bokZ;///
    ret[5] = pSrodka + zorientowane_polowy_dl_b - bokZ - bokX;////
    ret[6] = pSrodka + zorientowane_polowy_dl_b - bokZ - bokX - bokY;
    ret[7] = pSrodka + zorientowane_polowy_dl_b - bokZ - bokY;
}


