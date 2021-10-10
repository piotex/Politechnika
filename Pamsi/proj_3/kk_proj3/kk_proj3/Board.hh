#ifndef BOARD // include guard
#define BOARD
#include<iostream>
#include <vector>

class Board
{
public:
	Board(int size);
	~Board();
	
	char** tab;										//tutaj trzymamy dane macierzy/tablicy/planszy
	int size;										//dalo by sie zastapic sizeof czy czyms podobnym - rozmiar tablicy w x-sie

	void plotBoard();								//funckcja wyswietlajaca planszse w konsoli, mozna by open3d albo czyms to zastapic, tak zeby ladnie rysowalo
	bool isBoardFull();								//funcka sprawdzajaca czy plansza jest pelna
	bool isPossibleMove(int x, int y);				//funkcja sprawdzajaca czy ruch ktory ccemy wykonac jest mozliwy
	bool addElement(int x, int y, char element);	//funkcja dodajaca element do bazy danych
	void clearBoard();								//funkcja czyszczaca tablice - raczej nie potrzebna
private:	//todo - pobawic sie w get-y, set-y i privatowanie pol

protected:
};




#endif