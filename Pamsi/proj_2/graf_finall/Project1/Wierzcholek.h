#pragma once
#define NIESKONCZONOSC 9999

class Wierzcholek
{
public:
	Wierzcholek();
	~Wierzcholek();

	Wierzcholek* next;					// list
	bool odwiedzony = false;
	int droga_do_wierzcholka = NIESKONCZONOSC;

private:

};

Wierzcholek::Wierzcholek()
{
}

Wierzcholek::~Wierzcholek()
{
}