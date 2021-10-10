#pragma once
#include <ctime>   
#include <cstdlib> 
#include <iostream>
#include <fstream>
#include "Wierzcholek.h"
#include <chrono>

class Utils
{
public:
	Utils();
	~Utils();
    int** make_Matrix(int rozmiar_77, int gestosc, int aktualny_wierzcholek, std::string file_to_read);
    int** read_Matrix(int& rozmiar, int& aktualny_wierzcholek, std::string file_to_read);
    int save_Matrix(MacierzSasiedztwa& macierz, int rozmiar, std::string file_to_read);
    int save_gList(int** droga_do_wierzcholka, int* odleglosc_do_wierzcholka, int rozmiar, std::string file_to_save);
private:

};

Utils::Utils()
{
}

Utils::~Utils()
{
}

int Utils::save_gList(int** droga_do_wierzcholka, int* odleglosc_do_wierzcholka, int rozmiar, std::string file_to_save) {
    std::ofstream myfile;
    myfile.open(file_to_save);
    for (int j = 0; j < rozmiar; j++)
    {
        myfile << "Wierzcholek nm: " << j << " _ droga[wartosc]: " << odleglosc_do_wierzcholka[j] << " TRASA: ";
        for (int i = 0; i < rozmiar; i++)
        {
            if (droga_do_wierzcholka[j][i] >= 0)
            {
                myfile << droga_do_wierzcholka[j][i] << " ";
            }
        }
        myfile << "\n";
    }
    myfile.close();
    return 0;
}

int Utils::save_Matrix(MacierzSasiedztwa& macierz, int rozmiar, std::string file_to_save) {
    std::ofstream myfile;
    myfile.open(file_to_save);
    for (int j = 0; j < rozmiar; j++)
    {
        myfile << "Wierzcholek nm: " << j << " _ droga[wartosc]: " << macierz.wierzcholki[j].droga_do_wierzcholka << " TRASA: ";
        for (int i = 0; i < rozmiar; i++)
        {
            if (macierz.droga_do_wierzcholka[j][i] >= 0)
            {
                myfile << macierz.droga_do_wierzcholka[j][i] << " ";
            }
        }
        myfile << "\n";
    }
    myfile.close();
    return 0;
}

int** Utils::make_Matrix(int rozmiar_77, int gestosc, int aktualny_wierzcholek, std::string file_to_read) {
    int** graph = 0;
    graph = new int* [rozmiar_77];

    ///  //
    // ///////////////////////////////////////////////////////tworze graf////////////////////////////////////////////////////////////////////////////

    for (int i = 0; i < rozmiar_77; i++)
    {
        graph[i] = new int[rozmiar_77];
    }
    int k = 0;

    for (int i = 0; i < rozmiar_77; i++)
    {
        for (int j = 0; j < rozmiar_77; j++)
        {
            int r = (rand() % 12) + 1;
            graph[i][j] = r;
            graph[j][i] = r;
            /*
            if (k % (100 / (100-gestosc) ) == 0)
            {
                graph[i][j] = NIESKONCZONOSC;
                graph[j][i] = NIESKONCZONOSC;
            }
            k++;
            */
            if (i == j)
            {
                graph[i][j] = 0;
                graph[j][i] = 0;
            }
        }
    }
    ///////////////////kawalek do psucia grafu - ccc trzyma ilosc przerwanych polaczen
    int ccc = 0;
    for (int i = 0; i < ((rozmiar_77*(rozmiar_77-1))/2)*(100-gestosc)/100; i++)
    {
        int w = (rand() % (rozmiar_77-1)) + 1;
        int k = rozmiar_77 - w;
        if (w != k)
        {
            ccc++;
            graph[w][k] = NIESKONCZONOSC;
            graph[k][w] = NIESKONCZONOSC;
        }
    }

    //////////////////////////////////////////////////zapisuje graf//////////////////////////////////////////////////////////////////
    {
        std::ofstream myfile;
        myfile.open(file_to_read);
        //        iloœæ_krawêdzi         iloœæ_wierzcho³ków    wierzcho³ek_startowy
        myfile << (rozmiar_77 * (rozmiar_77 - 1) / 2)*gestosc/100 << " " << rozmiar_77 << " " << aktualny_wierzcholek << "\n";
        for (int i = 0; i < rozmiar_77; i++)
        {
            for (int j = 0; j < rozmiar_77; j++)
            {
                //        wierzcho³ek_pocz¹tkowy  wierzcho³ek_koñcowy  waga
                myfile << i << " " << j << " " << graph[i][j] << "\n";
            }
        }
        myfile.close();
    }
    return graph;
}

int** Utils::read_Matrix(int& rozmiar, int& aktualny_wierzcholek, std::string file_to_read) {
    int** graph = 0;
    std::ifstream myfile_Read;
    myfile_Read.open(file_to_read);
    int liczba_krawedzi = -9;
    int ii = 0;
    int jj = 0;
    myfile_Read >> liczba_krawedzi >> rozmiar >> aktualny_wierzcholek;
    graph = new int* [rozmiar];
    for (int i = 0; i < rozmiar; i++)
    {
        graph[i] = new int[rozmiar];
    }

    while (myfile_Read >> ii >> jj >> graph[ii][jj]) {
        jj++;
        if (jj >= rozmiar)
        {
            ii++;
            jj = 0;
            if (ii >= rozmiar) {
                break;
            }
        }
    }
    return graph;
}



