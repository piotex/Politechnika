// Project1.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
#include "Graph_Matrix.h"
#include "Graph_List.h"
#include <chrono>

int main()
{
    /////////user pref //////////////////////////
    int rozmiar = 10;
    int gestosc = 100;   //w %
    //90% - 
    /// //////////////////////////////////////////
    int aktualny_wierzcholek = 0;
    std::string file_to_read = "graf_in.txt";
    std::string file_to_save = "out_data.txt";
    std::chrono::system_clock::time_point start = std::chrono::system_clock::now();
    std::chrono::system_clock::time_point stop = std::chrono::system_clock::now();
    int cykle = 100;

    double totalTime = 0;

    for (int i = 0; i < cykle; i++)
    {
        Utils().make_Matrix(rozmiar, gestosc, aktualny_wierzcholek, file_to_read);



        Graph_Matrix().Oblicz_najkrotsza_droge(file_to_read, file_to_save, start, stop);
        //Graph_List(rozmiar).Oblicz_najkrotsza_droge(file_to_read, file_to_save,start,stop);


        std::chrono::duration<double> diff = stop - start;
        totalTime += diff.count();
    }
    std::cout << "Czas: " << totalTime << std::endl;    //wynik w sekundach :)

    return 0;

}




