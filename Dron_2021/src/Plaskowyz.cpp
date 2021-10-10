#include "Plaskowyz.hh"

Plaskowyz::Plaskowyz()
{
	dlugosciBokow = Wektor<double, 3>(10, 10, 10);
}

Plaskowyz::Plaskowyz(std::shared_ptr<drawNS::Draw3DAPI>& _api, Wektor<double, 3> dlB, Wektor<double, 3> pol)
{
    typ_figury = 3;
    api = _api;
    dlugosciBokow = dlB;
    kolor = "black";
    pSrodka = pol;
    pSrodka[2] += (dlugosciBokow[2]/2);
    rysuj();
}

bool Plaskowyz::czy_kolizja(InterfejsDron* dron)
{
    vector<Wektor<double, 3>> punkty;
    dron->get_punktyKrytyczne(punkty);

    double x1 = pSrodka[0] + (dlugosciBokow[0] / 2);
    double x2 = pSrodka[0] - (dlugosciBokow[0] / 2);
    double y1 = pSrodka[1] + (dlugosciBokow[1] / 2);
    double y2 = pSrodka[1] - (dlugosciBokow[1] / 2);
    double z1 = pSrodka[2] + (dlugosciBokow[2] / 2);
    double z2 = pSrodka[2] - (dlugosciBokow[2] / 2);
    bool okx = false;
    bool oky = false;
    bool okz = false;
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
        if (punkty[i][2] > z2 && punkty[i][2] < z1)
        {
            okz = true;
        }
    }
    if (okz && okx && oky) {
        return true;
    }

    return false;
}

