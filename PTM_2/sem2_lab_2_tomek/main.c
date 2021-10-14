#include <avr/io.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <util/delay.h>
#include <avr/sfr_defs.h>
#include <math.h>
#include <avr/interrupt.h>
#include <avr/pgmspace.h>

#include "HD44780.h"

#ifndef _BV
#define _BV(bit)				(1<<(bit))
#endif
#ifndef sbi
#define sbi(reg,bit)		reg |= (_BV(bit))
#endif

#ifndef cbi
#define cbi(reg,bit)		reg &= ~(_BV(bit))
#endif

int n_buff   =-99;
int bornYear =  0;

char buff[8];
char matrix_chars[] = {'7','8','9','-','4','5','6','+','1','2','3','C','*','0','#','='};

//funkcja do resetu zmiennych - wyzerowanie kalkulatora
void reset_cc(){
	bornYear=0;
	n_buff = -99;
}
int getKey16() {
	for (int i=0; i<4; i++) {           // powtórz dla ka¿dego wiersza
		cbi(PORTD, i);                  // ustaw stan niski
		for (int j=7; j>3; j--) {       // powtórz dla ka¿dej kolumny
			if (bit_is_clear(PIND,j)) { // czy na bicie jest stan niski
				sbi(PORTD, i);          // podaj stan wysoki na wiersz
				return ((i*4)+(8-j));   // zwróc numer przycisku
			}
		}
		sbi(PORTD, i);  // podaj stan wysoki na wiersz
		_delay_ms(1);
	}
	return -1;  // nie ma przycisku

}
//funkcja do odczytywania ktory przycisk wcisnieto -> 0-15 wierszami
int get_matrix_button_number(){
	int n = -1;
	for(int i=0;i<4;i++){
		PORTD = (0x01<<i);				//kolejno daje 1 na d0, d1, d2, d3
		_delay_ms(10);
		if (bit_is_set(PIND, PD4)) {
			n=0 + (4*i);
		}
		if (bit_is_set(PIND, PD5)) {
			n=1 + (4*i);
		}
		if (bit_is_set(PIND, PD6)) {
			n=2 + (4*i);
		}
		if (bit_is_set(PIND, PD7)) {
			n=3 + (4*i);
		}
		// _delay_ms(50);
	}
	return n;
}
//funkcja do konwersji nm. wcisnietego przycisku na symbol przycisku
char convert(int button_number){
	return matrix_chars[button_number];
}

//funkcja do powiekszania liczb
void add_to_number(int nn){
	bornYear = (bornYear*10) + nn;
}
//funkcja do realizacji przeznaczenia po wcisnieciu przycisku
void set_sth(int button_number){
	if(button_number>=0){
		switch( button_number )
		{
			case 0:
				add_to_number(7);
				break;
			case 1:
				add_to_number(8);
				break;
			case 2:
				add_to_number(9);
				break;
			case 4:
				add_to_number(4);
				break;
			case 5:
				add_to_number(5);
				break;
			case 6:
				add_to_number(6);
				break;
			case 8:
				add_to_number(1);
				break;
			case 9:
				add_to_number(2);
				break;
			case 10:
				add_to_number(3);
				break;
			case 13:
				add_to_number(0);
				break;

			case 3:									//	-
				break;
			case 7:									//	+
				break;
			case 12:								//	*
				break;
			case 11:								//	C
				reset_cc();

				break;
			case 15:								//	=
				break;
		}
	}
}

void hello(){
	LCD_Clear();
	LCD_GoTo(0, 0);
	LCD_WriteText("Program lab1");
	LCD_GoTo(0, 1);
	LCD_WriteText("Oblicza wiek");
	_delay_ms(5*1000);

}
void end(){
	int counter = 0;
	int max_time = 10*1000;		//przez 50 bo tomek

	while(counter < max_time ){
		int button_number = getKey16();
		if(button_number != n_buff && button_number != -1){
			n_buff = button_number;
			break;
		}
		counter++;
		_delay_ms(1);
	}
	LCD_Clear();
	LCD_GoTo(0, 0);
	LCD_WriteText("Podaj wiek:");
	reset_cc();
}


//funkcja do realizacji zadania z laboratorium
void zadanie_1(){
	int curentYear = 2021;
	PORTD = 0x00;

	LCD_Initalize();
	LCD_Home();

			// ustawianie portów
	for(int k = 0; k < 8; k++){
		if (k<4) {
			sbi(DDRD, k);
		}
		if (k>3) {
			cbi(DDRD, k);
		}
		sbi(PORTD, k);
	}

	hello();

	LCD_Clear();
	LCD_GoTo(0, 0);
	LCD_WriteText("Podaj wiek:");

	while(1){
		int button_number = getKey16();				//pobranie numeru przycisku na klawiaturze
		if(button_number !=n_buff){									//jezeli przycisk sie zmienil
			char c_fromMatrix = convert(button_number);
			if(c_fromMatrix>=48 && c_fromMatrix<=57)				//jezeli convert zwroci liczbe (nie znak)
			{
				int liczba = c_fromMatrix - 48;
				add_to_number(liczba);
			}
			if(bornYear > curentYear){
				LCD_Clear();
				LCD_GoTo(0, 0);
				LCD_WriteText("Podaj wiek:");
				bornYear = 0;
			}
			if(bornYear > 1000 ){
				sprintf(buff,"Masz %d lat",curentYear - bornYear);
				LCD_Clear();
				LCD_GoTo(0, 0);
				LCD_WriteText(buff);									//wyswietl string w buff
				if(curentYear - bornYear < 18){
					sprintf(buff,"Niepelnioletni");
					LCD_GoTo(0, 1);
					LCD_WriteText(buff);
				}
				if(curentYear - bornYear >= 18 && curentYear - bornYear < 25){
					sprintf(buff,"Student");
					LCD_GoTo(0, 1);
					LCD_WriteText(buff);
				}
				if(curentYear - bornYear >= 25 && curentYear - bornYear < 65){
					sprintf(buff,"Pracownik");
					LCD_GoTo(0, 1);
					LCD_WriteText(buff);
				}
				if(curentYear - bornYear >= 65){
					sprintf(buff,"Emeryt");
					LCD_GoTo(0, 1);
					LCD_WriteText(buff);
				}



				n_buff = button_number;
				end();
			}
			else{
				sprintf(buff,"%d", bornYear);
				LCD_GoTo(0, 1);
				LCD_WriteText(buff);									//wyswietl string w buff
			}

			_delay_ms(10);
			n_buff = button_number;
		}
	}

}

void test(){
	PORTD = 0x00;
	LCD_Clear();
	LCD_GoTo(0, 0);
	LCD_WriteText("");

	LCD_Initalize();
	LCD_Home();

		// ustawianie portów
	for(int k = 0; k < 8; k++){
		if (k<4) {
			sbi(DDRD, k);
		}
		if (k>3) {
			cbi(DDRD, k);
		}
		sbi(PORTD, k);
	}


	while(1){
			int button_number = getKey16();				//pobranie numeru przycisku na klawiaturze
			if(button_number !=n_buff){									//jezeli przycisk sie zmienil
				char c_fromMatrix = convert(button_number);
				buff[0] = c_fromMatrix;
				LCD_Clear();
				LCD_GoTo(0, 0);
				LCD_WriteText(buff);									//wyswietl string w buff
				_delay_ms(100);
				n_buff = button_number;
			}
		}
}

// glowna funkcja programu
int main() {
	LCD_Initalize();
	LCD_Home();

	zadanie_1();
	//test();
}
