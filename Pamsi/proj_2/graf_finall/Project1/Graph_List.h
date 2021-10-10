#pragma once
#include "Utils.h"


class Graph_List
{
public:
	Graph_List(int _rozmiar);
	~Graph_List();

	int* odleglosc_do_wierzcholka;	//trzyma sume drog ktore trzeba pokonac aby sie dostac do wierzcholka [i]
	int** droga_do_wierzcholka;		// trzyma oznaczenie kolejnych wierzcholkow przez ktore trzeba przejsc
	Wierzcholek* lista_wierzcholkow;	//trzyma wczytany graf

	int Oblicz_najkrotsza_droge(std::string file_to_read, std::string file_to_save, std::chrono::system_clock::time_point& start, std::chrono::system_clock::time_point& end);
private:
    int aktualny_wierzcholek;
	int rozmiar;
};

Graph_List::Graph_List(int _rozmiar)
{
	rozmiar = _rozmiar;
	
	odleglosc_do_wierzcholka = new int[rozmiar];
	droga_do_wierzcholka = new int* [rozmiar];
	lista_wierzcholkow = new Wierzcholek[rozmiar];
	for (int i = 0; i < rozmiar; i++)
	{
		lista_wierzcholkow[i] = Wierzcholek();
		droga_do_wierzcholka[i] = new int[rozmiar];
		for (int j = 0; j < rozmiar; j++)
		{
			droga_do_wierzcholka[i][j] = -1;
		}
	}
}

Graph_List::~Graph_List()
{
	delete[] odleglosc_do_wierzcholka;
	delete[] lista_wierzcholkow;
}

int Graph_List::Oblicz_najkrotsza_droge(std::string file_to_read, std::string file_to_save, std::chrono::system_clock::time_point& start, std::chrono::system_clock::time_point& end) {
    std::ifstream myfile_Read;
    myfile_Read.open(file_to_read);

    int liczba_krawedzi = -9;
    int ii = 0;
    int jj = 0;
    int val = -1;
    int nm_wierzch = 0;
    myfile_Read >> liczba_krawedzi >> rozmiar >> aktualny_wierzcholek;


    Graph_List gList = Graph_List(rozmiar);
    //tworze i ustawiam pomocniczy wskaznik na pierwszy element listy
    Wierzcholek* ten = &gList.lista_wierzcholkow[nm_wierzch];
    //wczytuje dane z pliku
    while (myfile_Read >> ii >> jj >> val) {
        if (ii > nm_wierzch)
        {
            nm_wierzch = ii;
            ten = &gList.lista_wierzcholkow[nm_wierzch];
        }
        ten->next = new Wierzcholek();
        ten->droga_do_wierzcholka = val;
        ten = ten->next;
    }

    // //////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    start = std::chrono::system_clock::now();
    // //////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////


    //ustawiam odleglosci na nieskonczonosc zeby potem znajdowac najkrotsze scierzki
    for (int i = 0; i < rozmiar; i++)
    {
        gList.odleglosc_do_wierzcholka[i] = NIESKONCZONOSC;
    }

    //ustawienie starowego wierzcholka na wierzcholek nm 0 ////////////////////////////////////////////////
    ten = &gList.lista_wierzcholkow[aktualny_wierzcholek];
    gList.odleglosc_do_wierzcholka[aktualny_wierzcholek] = 0;
    ten->odwiedzony = true;

    while (true)
    {
        ten = &gList.lista_wierzcholkow[aktualny_wierzcholek];
        for (int i = 0; i < rozmiar; i++)
        {
            //pobieram o ile jest odlegly nastepny wierzcholek
            int krawedz = ten->droga_do_wierzcholka;
            if (krawedz != INT32_MAX)
            {
                int nowa_droga = gList.odleglosc_do_wierzcholka[aktualny_wierzcholek] + krawedz;
                //ustawiam odleglosc wierzcholka na sume aktualnej odleglosci i drogi
                if (gList.odleglosc_do_wierzcholka[i] > nowa_droga)
                {                                                        //jezeli stara odleglosc jest wieksza od nowej to do sth
                    gList.odleglosc_do_wierzcholka[i] = nowa_droga;
                    //kopiowanie trasy aktualnego
                    for (int j = 0; j < rozmiar; j++)
                    {
                        gList.droga_do_wierzcholka[i][j] = gList.droga_do_wierzcholka[aktualny_wierzcholek][j];
                    }
                    //dodanie wierzcholka do trasy
                    for (int j = 0; j < rozmiar; j++)
                    {
                        if (gList.droga_do_wierzcholka[aktualny_wierzcholek][j] < 0)
                        {
                            gList.droga_do_wierzcholka[i][j] = aktualny_wierzcholek;
                            break;
                        }
                    }
                }
            }
            ten = ten->next;
        }

        //teraz musze przejsc do najblizszego nieodwiedzoneg wierzcholka
        int min_odl = INT32_MAX;
        int kandydat_na_nowy_akt_wierz = aktualny_wierzcholek;

        ten = &gList.lista_wierzcholkow[aktualny_wierzcholek];
        for (int i = 0; i < rozmiar; i++)
        {
            //sprawdzam do ktoreg nieodwiedzonego wierzcholka mam najblizej
            int krawedz = ten->droga_do_wierzcholka;
            if (krawedz < min_odl && gList.lista_wierzcholkow[i].odwiedzony == false)
            {
                min_odl = krawedz;
                kandydat_na_nowy_akt_wierz = i;
            }
            ten = ten->next;
        }
        //spr czy mam gdzie isc
        if (kandydat_na_nowy_akt_wierz == aktualny_wierzcholek)
        {
            break;
        }
        //ide do nastepnego wierzcholka
        aktualny_wierzcholek = kandydat_na_nowy_akt_wierz;
        gList.lista_wierzcholkow[kandydat_na_nowy_akt_wierz].odwiedzony = true;
    }

    //dopisanie ostatniego wierzcholka - celu podrozy
    for (int i = 0; i < rozmiar; i++)
    {
        for (int j = 0; j < rozmiar; j++)
        {
            if (gList.droga_do_wierzcholka[i][j] < 0)
            {
                gList.droga_do_wierzcholka[i][j] = i;
                break;
            }
        }
    }

    // //////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    end = std::chrono::system_clock::now();
    // //////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

    //plotuje sobie drobi do kolejnych wierzcholkow:
    if (file_to_save != "")
    {
        Utils().save_gList(gList.droga_do_wierzcholka, gList.odleglosc_do_wierzcholka, rozmiar, file_to_save);
    }

	return -1;
}