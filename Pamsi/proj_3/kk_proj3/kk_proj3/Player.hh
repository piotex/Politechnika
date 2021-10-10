#ifndef PLAYER // include guard
#define PLAYER
#include<iostream>
#include <vector>
#include"Board.hh"

#define INF 1000000
#define WIN_PT 100

class Player
{
public:
	Player(char _znak, Board* board, int ile_zeby_wygrac);	//konstruktor
	~Player();							//destruktor

	// spytac o to uzytkownika w main
	int ile_zeby_wygrac;				//pole trzymajace info o tym ile musi byc znaczkow w wierszu/kolumnie/przekotnej zeby zadzialalo
	int _rec_depth;						//WAZNE - pole trzymajace info o tym jak gleboko wchodzimy w rekurencji - ile stopni w dol
	char znak;							//podle do trzymania znaku gracza, todo - poprawic to na enuma
	Board* board;						//wskaznik na plansze, tak, zeby gralo sie na jednej

	void MakeMove(int x, int y);		//funkcja do wstawiania znaczka gracza w pole x y
	void UndoMove(int x, int y);		//funkcja do cofania wstawiania znaczka gracza w pole x y

	bool VerticalWin(int number);		//funkcja sprawdzajaca czy gracz wygral w pionie 
	bool HorizontalWin(int number);		//funkcja sprawdzajaca czy gracz wygral w poziomie
	bool DiagonalWin(int number);		//funkcja sprawdzajaca czy gracz wygral na przekotnej
	bool IsWinner(int number_to_win);	//funkcja sprawdzajaca czy gracz wygral

	int check_score(Player opponent);	//funkcja sprawdzajaca wynik
		
	int Min(Player opponent, int rec_depth);	//funkcja algorytmu szukajaca najmniej punktowanego ruchy
	int Max(Player opponent, int rec_depth);	//funkcja algorytmu szukaj¹ca nawy¿ej punktowanego ruchu
	int* BestDecision(Player opponent);			//funkcja zwracajaca najleprzy dla gracza ai ruch

};




#endif