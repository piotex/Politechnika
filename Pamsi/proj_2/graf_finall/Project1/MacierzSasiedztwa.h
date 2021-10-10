#pragma once
#include "Wierzcholek.h"

class MacierzSasiedztwa
{
public:
	MacierzSasiedztwa(const int liczba_wierzcholkow);
	~MacierzSasiedztwa();

	int** krawedz;					//graf
	Wierzcholek* wierzcholki;		//
	int** droga_do_wierzcholka;		//oznaczenia kolejnych wierzcholkow na najkrotszej drodze

	private:
		int _liczba_wierzcholkow;

};


MacierzSasiedztwa::MacierzSasiedztwa(const int liczba_wierzcholkow)
{
	_liczba_wierzcholkow = liczba_wierzcholkow;

	krawedz = new int*[_liczba_wierzcholkow];
	droga_do_wierzcholka = new int* [_liczba_wierzcholkow];
	wierzcholki = new Wierzcholek [_liczba_wierzcholkow];

	for (int i = 0; i < _liczba_wierzcholkow; i++) {
		krawedz[i] = new int[_liczba_wierzcholkow];
	}

	for (int i = 0; i < _liczba_wierzcholkow; i++) {
		droga_do_wierzcholka[i] = new int[_liczba_wierzcholkow];
		for (int j = 0; j < _liczba_wierzcholkow; j++)
		{
			droga_do_wierzcholka[i][j] = -1;
		}
	}

	for (int i = 0; i < _liczba_wierzcholkow; i++) {
		wierzcholki[i] = Wierzcholek();
	}
}

MacierzSasiedztwa::~MacierzSasiedztwa()
{
	for (int i = 0; i < _liczba_wierzcholkow; i++)
		delete[] krawedz[i];
	delete[] krawedz;

	for (int i = 0; i < _liczba_wierzcholkow; i++)
		delete[] droga_do_wierzcholka[i];
	delete[] droga_do_wierzcholka;

	delete[] wierzcholki;
}
