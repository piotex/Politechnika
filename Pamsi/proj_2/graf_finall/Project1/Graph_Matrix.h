#pragma once
#include <string>
#include <iostream>
#include "MacierzSasiedztwa.h"
#include "Utils.h"
#include <ctime>   
#include <cstdlib> 
#include <fstream>


class Graph_Matrix
{
public:
	Graph_Matrix();
	~Graph_Matrix();

	int Oblicz_najkrotsza_droge(std::string file_to_read, std::string file_to_save, std::chrono::system_clock::time_point& start, std::chrono::system_clock::time_point& end);
    int rozmiar;
    int aktualny_wierzcholek;
private:


};

Graph_Matrix::Graph_Matrix()
{
    rozmiar = -1;
    aktualny_wierzcholek = -1;
}

Graph_Matrix::~Graph_Matrix()
{
}


int Graph_Matrix::Oblicz_najkrotsza_droge(std::string file_to_read, std::string file_to_save, std::chrono::system_clock::time_point& start, std::chrono::system_clock::time_point& end) {
    srand(time(0));             // do generowania liczb losowych

    // //////sposoby wczytania /////////////////////////////////////////////////////////////////////////////////
    //graph = Utils().make_Matrix(rozmiar,gestosc,aktualny_wierzcholek,true);
    int** graph = Utils().read_Matrix(rozmiar, aktualny_wierzcholek, file_to_read);
    MacierzSasiedztwa macierz(rozmiar);

    // ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    //przekopiowanie grafu do macierzy
    for (int i = 0; i < rozmiar; i++)
    {
        for (int j = 0; j < rozmiar; j++)
        {
            macierz.krawedz[i][j] = graph[i][j];
        }
    }

    for (int i = 0; i < rozmiar; i++)
        delete[] graph[i];
    delete[] graph;

    // //////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    start = std::chrono::system_clock::now();
    // //////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////


    //ustawienie starowego wierzcholka na wierzcholek nm 0 ////////////////////////////////////////////////
    macierz.wierzcholki[aktualny_wierzcholek].odwiedzony = true;
    //dla bezpieczenstwa ustawiam reszte drog na INT32_MAX zeby wiedziec ze na razie nie ma polaczenia
    for (int i = 0; i < rozmiar; i++)
    {
        macierz.wierzcholki[i].droga_do_wierzcholka = NIESKONCZONOSC;
    }
    macierz.wierzcholki[aktualny_wierzcholek].droga_do_wierzcholka = 0;

    //////////////////////////////////////////////////

    while (true)
    {
        for (int i = 0; i < rozmiar; i++)
        {
            //pobieram o ile jest odlegly nastepny wierzcholek
            int krawedz = macierz.krawedz[aktualny_wierzcholek][i];
            if (krawedz != INT32_MAX) {                                                                                                         //<- tu by mozna bylo poprawic na NIESKONCZONOSC
                int nowa_droga = macierz.wierzcholki[aktualny_wierzcholek].droga_do_wierzcholka + krawedz;
                //ustawiam odleglosc wierzcholka na sume aktualnej odleglosci i drogi
                if (macierz.wierzcholki[i].droga_do_wierzcholka > nowa_droga) {
                    macierz.wierzcholki[i].droga_do_wierzcholka = macierz.wierzcholki[aktualny_wierzcholek].droga_do_wierzcholka + krawedz;
                    //kopiowanie trasy aktualnego
                    for (int j = 0; j < rozmiar; j++)
                    {
                        macierz.droga_do_wierzcholka[i][j] = macierz.droga_do_wierzcholka[aktualny_wierzcholek][j];
                    }
                    //dodanie wierzcholka do trasy
                    for (int j = 0; j < rozmiar; j++)
                    {
                        if (macierz.droga_do_wierzcholka[aktualny_wierzcholek][j] < 0)
                        {
                            macierz.droga_do_wierzcholka[i][j] = aktualny_wierzcholek;
                            break;
                        }
                    }
                }
            }
        }
        //teraz musze przejsc do najblizszego nieodwiedzoneg wierzcholka
        int min_odl = INT32_MAX;
        int kandydat_na_nowy_akt_wierz = aktualny_wierzcholek;


        for (int i = 0; i < rozmiar; i++)
        {
            //sprawdzam do ktoreg nieodwiedzonego wierzcholka mam najblizej
            if (macierz.wierzcholki[i].droga_do_wierzcholka < min_odl && macierz.wierzcholki[i].odwiedzony == false)
            {
                min_odl = macierz.wierzcholki[i].droga_do_wierzcholka;
                kandydat_na_nowy_akt_wierz = i;
            }
        }
        //spr czy mam gdzie isc
        if (kandydat_na_nowy_akt_wierz == aktualny_wierzcholek)
        {
            break;
        }
        //ide do nastepnego wierzcholka
        aktualny_wierzcholek = kandydat_na_nowy_akt_wierz;
        macierz.wierzcholki[aktualny_wierzcholek].odwiedzony = true;
    }
    for (int i = 0; i < rozmiar; i++)
    {
        for (int j = 0; j < rozmiar; j++)
        {
            if (macierz.droga_do_wierzcholka[i][j] < 0)
            {
                macierz.droga_do_wierzcholka[i][j] = i;
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
        Utils().save_Matrix(macierz, rozmiar, file_to_save);
    }
    return 0;
}