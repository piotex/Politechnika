#include <avr/io.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <stdio.h>
#include <util/delay.h>
#include <avr/sfr_defs.h>
#include <math.h>
#include <avr/interrupt.h>
#include <avr/eeprom.h>
#include <avr/iom32.h>

#include "HD44780.h"

#ifndef _BV
#define _BV(bit) (1 << (bit))
#endif

#ifndef inb
#define inb(addr) (addr)
#endif

#ifndef outb
#define outb(addr, data) addr = (data)
#endif

#ifndef sbi
#define sbi(reg, bit) reg |= (_BV(bit))
#endif

#ifndef cbi
#define cbi(reg, bit) reg &= ~(_BV(bit))
#endif

#ifndef tbi
#define tbi(reg, bit) reg ^= (_BV(bit))
#endif

// MIN/MAX/ABS macros
#define MIN(a, b) ((a < b) ? (a) : (b))
#define MAX(a, b) ((a > b) ? (a) : (b))
#define ABS(x) ((x > 0) ? (x) : (-x))
//----------------------------------------------------------------------------------------------------------------------------------------//
//----------------------------------------------------------------------------------------------------------------------------------------//
char cyfra[11] = {0b011111100, 0b001100000, 0b011011010, 0b011110010, 0b001100110, 0b010110110, 0b010111110, 0b011100000, 0b011111110, 0b011110110 , 0b000000010};  //ostatni to kropka, a zaczynamy od gory i w lewo :<
volatile int licznik_100ms=0;
volatile int flaga_ile_razy_wcisnieto_ok=0;

//----------------------------------------------------------------------------------------------------------------------------------------//
//----------------------------------------------------------------------------------------------------------------------------------------//
void ADC_init()
{
	sbi(ADMUX, REFS0); // konfiguracja napiecia referencyjnego na AVCC
	cbi(ADMUX, REFS1); // konfiguracja podzielnika czestotliwosci dla ukladu przetwornika. Mniejsza od 100KHz

	//	Czestotliwosc sygnalu taktujacego 62,5 kHz
	sbi(ADCSRA, ADPS0); //Tymi bitami definiujemy pozadana relacje
	sbi(ADCSRA, ADPS1); //	 miedzy czestotliwoscia zegara sytemowego XTAL,
	sbi(ADCSRA, ADPS2); //	 a czestotliwoscia przebiegu taktujacego przetwornik.

	sbi(ADCSRA, ADEN); //uruchomienie ukladu przetwornika

	//	konfiguracja/wybor kanalu/pinu na ktorym bedzie dokonywany pomiar
	cbi(ADMUX, MUX0); //Bity wyboru wejscia analogowego.
	cbi(ADMUX, MUX1); //   Wejscie wybrane kombinacja tych bitow
	cbi(ADMUX, MUX2); //   jest dolaczone do przetwornika
	cbi(ADMUX, MUX3);
}

int uint16_tADC_10bit()
{
	sbi(ADCSRA, ADSC); //uruchomienie pojedynczego pomiaru - ustawienie bitu
	while (bit_is_set(ADCSRA, ADSC)) //oczekiwanie na zakoñczenie pomiaru – oczekiwanie na wyzerowanie bitu
	{
	}
	return ADC; // wynik pomiaru
}

int ADC_measure(){
	//wzor na na przeliczenie wartosci zwracanej [V]: (ADC_10bit()*ref_val)/1024
	int max_val = 1022;//powinno byc 1024 ale lepiej dziala tak
	int ref_val = 5;	//napiecie referencyjne
	int ret = (int)(((double)uint16_tADC_10bit()*ref_val)*100/max_val);

	return ret; //zwraca wyliczona wartosc
}

int set_b_number(int val, char* buff){
	if(val%100 > 10){
		sprintf(buff,"Pomiar1:%d.%dV",val/100,val%100);	 //		   				     : Pomiar1: 2.12
	}
	else{
		sprintf(buff,"Pomiar1:%d.0%dV",val/100,val%100); //rozni sie zerem w zapisie : Pomiar1: 2.03
	}
	return 0;
}


void info()
{
	char hello[20] = "Program PTM 2021";
	char index[20] = "252871 252839";
	LCD_Clear();
	LCD_GoTo(0, 0);
	LCD_WriteText(hello);
	LCD_GoTo(0, 1);
	LCD_WriteText(index);
	_delay_ms(4000);																																//poprawic to, do testow biore 500
}

bool czy_liczba_pierwsza(int liczba)
{
	if (liczba < 2)
		return false; //gdy liczba jest mniejsza ni¿ 2 to nie jest pierwsz¹

	for (int i = 2; i * i <= liczba; i++)
		if (liczba % i == 0)
			return false; //gdy znajdziemy dzielnik, to dana liczba nie jest pierwsza
	return true;
}

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//	PIND2 - OK
//	PIND0 - UP
//	PIND1 - DOWN
//	PIND3 - X
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

int get_korekta_liczby_na_liczbe_w_zakresie(int liczba){
	if(liczba < 0){
		return 0;
	}
	if(liczba > 50){
		return 50;
	}
	return liczba;
}
int odpal_odpowiendnie_diody(int liczba){
	if (liczba % 2 == 0)	//liczba parzysta
	{
		sbi(PORTD, 4);
		cbi(PORTD, 5);
		_delay_ms(10);
	}
	if (liczba % 2 == 1)	//liczba nieparzysta
	{
		cbi(PORTD, 4);
		sbi(PORTD, 5);
		_delay_ms(10);
	}
	if (czy_liczba_pierwsza(liczba))
	{
		sbi(PORTD, 6);
		_delay_ms(10);
	}
	else
	{
		cbi(PORTD, 6);
		_delay_ms(10);
	}
	return 0;
}

int get_index_do_w_7(int liczba){
	if(liczba >= 0 && liczba <= 9){
		return liczba;
	}
	return 10;
}
int print_liczba(int liczba){
	char buff[20];
	liczba = get_korekta_liczby_na_liczbe_w_zakresie(liczba);
	sprintf(buff, "%d", liczba);
	LCD_Clear();
	LCD_GoTo(0, 0);
	LCD_WriteText(buff);
	return 0;
}
int set_7_segment(int liczba){
	PORTC = cyfra[get_index_do_w_7(liczba)];
	return 0;
}

void liczby()
{
	int liczba = 0;

	while (bit_is_set(PIND, 2))		//jezeli [X]  nie wcisniete
	{
		cbi(PORTD, 7);
		while (bit_is_clear(PIND, 0))	//jezeli [UP] wcisniete
		{
			while (bit_is_clear(PIND, 0)){	// czekamy na puszczenie przycisku
				_delay_ms(10);
			}
			sbi(PORTD, 7);
			_delay_ms(10);
			if(liczba < 50){
				liczba++;
			}
		}
		while (bit_is_clear(PIND, 1))	//jezeli [DOWN] wcisniete
		{
			while (bit_is_clear(PIND, 1)){	// czekamy na puszczenie przycisku
				_delay_ms(10);
			}
			sbi(PORTD, 7);
			_delay_ms(10);
			if(liczba > 0){
				liczba--;
			}
		}
		print_liczba(liczba);																													///tutaj wydzielilem
		set_7_segment(liczba);																													///tutaj dodalem
		odpal_odpowiendnie_diody(liczba);																										///tutaj wydzielilem
	}
	//sbi(PORTD, 7);
	PORTC = 0;
}

//Inicjalizacja Timer1 do wywolywania przerwania z czestotliwoscia 2Hz
void TimerInit()
{
	//Wybranie trybu pracy CTC z TOP OCR1A
	//rozdzial 16 w dokumentacji
	// zabawa z rejestrami
	// ustawiam 1 na wgm12 zeby sie zgadzalo z tabela 16-5 mode 4
		//wpisujemy tylko do wgm12 bo reszta na start jest 0
		sbi(TCCR1B,WGM12);

	//Wybranie dzielnika czestotliwosci
	//tabela 16-6
	//Liczymy  8M/(wartosc_prescalera)/2  <  65k		-> 2Hz -> prescaler ma byc  CALKOWITE  zeby nie tracic dokladnosci
	// ustawiamy rejestry zgodnie z tabela 16-6	dla danego prescalera
		//prescaler - jak bardzo zanizamy taktoawnie procka przy liczeniu czestotliwosci przerwan
		//22:40
		sbi(TCCR1B,CS12);	// prescaler = 256
		//sbi(TCCR1B,CS11);	// prescaler = 64
		//sbi(TCCR1B,CS10);	// prescaler = 64

	//Zapisanie do OCR1A wartosci odpowiadajacej 0,5s
	// wyliczona wartosc ze wzoru 8M/(wartosc_prescalera)/2
		//OCR1A = 15625;	//2Hz
		//OCR1A = 625;		//50Hz ale miernik wskazuje 25Hz
		OCR1A = 3125;		//10Hz ale miernik wskazuje 5Hz
		//inny prescaler
		//OCR1A = 1250;		//100Hz ale miernik wskazuje 50Hz			:<					- ze wzoru 8.000.000/prescaler/f_ktroa_chcemy_uzyskac

	//Uruchomienie przerwania OCIE1A
		sbi(TIMSK,OCIE1A);
}

int og_zegar_licznik(int* m, int* s){	// przekazanie przez para-referencje
	(*s) = licznik_100ms/10;
	if((*s)>59)
	{
		(*m)++;
		(*s) = 0;
		licznik_100ms = 0;

		if((*m)>59)
		{
			(*m) = 0;
		}
	}
	return 0;
}
int og_stoper_licznik(int* s, int* ms){	// przekazanie przez para-referencje
	//(*s) = licznik_100ms / 10;
	(*ms) = licznik_100ms;
	if((*ms)>9){
		(*ms) = 0;
		licznik_100ms = 0;

		(*s)++;
		if((*s)>59)
		{
			(*s) = 0;
		}
	}
	return 0;
}

void stoper()
{
	cbi(PORTD, 4);
	cbi(PORTD, 5);
	cbi(PORTD, 6);

	licznik_100ms=0;
	flaga_ile_razy_wcisnieto_ok = 0;
	int old_ms = 0;

	int ms = 0;
	int s = 0;

	while(bit_is_set(PIND, 2)){

		og_stoper_licznik(&s, &ms);

		while (bit_is_clear(PIND, 3))	//jezeli [OK] wcisniete
		{
			while (bit_is_clear(PIND, 3)){	// czekamy na puszczenie przycisku
				_delay_ms(1);
			}
			flaga_ile_razy_wcisnieto_ok++;
		}

		char buff[20];
		char c_s[5];
		char c_ms[5];
		sprintf(c_ms, "%d0", ms);
		if(s<10){
			sprintf(c_s, "0%d", s);
		}
		else{
			sprintf(c_s, "%d", s);
		}

		if(flaga_ile_razy_wcisnieto_ok%2 == 1 && licznik_100ms%10==0){
			tbi(PORTD, 4);
		}

		if(ms > old_ms || ms==0){
			old_ms = ms;
			sprintf(buff, "%s:%s", c_s,c_ms);
			LCD_Clear();
			LCD_GoTo(0, 0);
			LCD_WriteText(buff);
		}

		_delay_ms(5);
	}
}

void zegar()
{
	cbi(PORTD, 4);
	cbi(PORTD, 5);
	cbi(PORTD, 6);

	licznik_100ms=0;
	flaga_ile_razy_wcisnieto_ok = 1;
	int s = 0;
	int m = 0;
	int old_s = 0;

	while(bit_is_set(PIND, 2)){

		og_zegar_licznik(&m, &s);

		char buff[20];
		char ss[5];
		char mm[5];

		if(m<10){
			sprintf(mm, "0%d", m);
		}
		else{
			sprintf(mm, "%d", m);
		}
		if(s<10){
			sprintf(ss, "0%d", s);
		}
		else{
			sprintf(ss, "%d", s);
		}

		if(s > old_s || s==0){
			old_s = s;
			sprintf(buff, "%s:%s", mm,ss);
			LCD_Clear();
			LCD_GoTo(0, 0);
			LCD_WriteText(buff);
		}
		_delay_ms(100);
	}
}
void miernik()
{
	PORTC = 0;
	char buff_1[20];
	char buff_2[20];
	int literal = 0;
	int value = 0;
	ADC_init();
	while (bit_is_set(PIND, 2))
	{
		literal = uint16_tADC_10bit();
		value = ADC_measure();
		sprintf(buff_1, "literal = %d",literal);
		set_b_number(value,buff_2);
		LCD_Clear();
		LCD_GoTo(0, 0);
		LCD_WriteText(buff_1);
		LCD_GoTo(0, 1);
		LCD_WriteText(buff_2);
		_delay_ms(100);
	}
}


char *choosen(char *str)
{
	char *strcat(char *dest, const char *src);
	size_t len = strlen(str);
	char pause = ' ';
	for (int i = 0; i < 12 - len; i++)
	{
		strcat(str, pause);
	}
	char *tmp = "  	X";
	// strcat(str, tmp);
	return strcat(str, tmp);
}

int menu()
{
	LCD_Clear();
	char choices[5][20] = {"1. Info   ", "2. Liczby ", "3. Stoper ", "4. Zegar  ", "5. Miernik"};
	char buff_1[20];
	char buff_2[20];

	LCD_Clear();
	LCD_GoTo(0, 0);
	sprintf(buff_1,"%s   X",choices[0]);
	LCD_WriteText(buff_1);
	LCD_GoTo(0, 1);
	sprintf(buff_2,"%s",choices[1]);
	LCD_WriteText(buff_2);
	_delay_ms(100);
	int i = 0;

	while (bit_is_set(PIND, 3))
	{
		while (bit_is_clear(PIND, 1)) //down
		{
			if (i <= 3)
			{
				i++;
				while (bit_is_clear(PIND, 1)) //na dol
					;
				LCD_Clear();
				LCD_GoTo(0, 0);
				sprintf(buff_1,"%s",choices[i - 1]);
				LCD_WriteText(buff_1);
				LCD_GoTo(0, 1);
				sprintf(buff_2,"%s   X",choices[i]);
				LCD_WriteText(buff_2);
				_delay_ms(100);
			}
			else
				i = 3;
		}
		while (bit_is_clear(PIND, 0)) //up
		{
			if (i >= 1)
			{
				i--;
				while (bit_is_clear(PIND, 1)) //na dol
					;
				LCD_Clear();
				LCD_GoTo(0, 0);
				sprintf(buff_1,"%s   X",choices[i]);
				LCD_WriteText(buff_1);
				LCD_GoTo(0, 1);
				sprintf(buff_2,"%s",choices[i + 1]);
				LCD_WriteText(buff_2);
				_delay_ms(100);
			}
			else
				i = 1;
		}
	}
	return i;
}

void to_do(int wybor)
{
	if (wybor == 0)
		info();

	if (wybor == 1)
		liczby();

	if (wybor == 2)
		stoper();

	if (wybor == 3)
		zegar();

	if (wybor == 4)
		miernik();
}

int main()
{
	TimerInit();	//funkcja nasza
	sei(); 			//funkcja uruchamia globalne przerwania
	//------------------------//
	LCD_Initalize();
	LCD_Home();
	//------------------------//
	DDRC = 0xFF;
	//------------------------//
	DDRD = 0xFF;
	//------------------------//
	cbi(DDRD, PC0);
	cbi(DDRD, PC1);
	cbi(DDRD, PC2);
	cbi(DDRD, PC3);
	//------------------------//
	sbi(PORTD, PD0);
	sbi(PORTD, PD1);
	sbi(PORTD, PD2);
	sbi(PORTD, PD3);
	//------------------------//

	int wybor = 0;
	info();
	LCD_Clear();
	while (1)
	{
		wybor = menu();
		cbi(PORTD, 7);
		to_do(wybor);
		cbi(PORTD, 7);
		cbi(PORTD, 6);
		cbi(PORTD, 5);
		cbi(PORTD, 4);
	}
}

//Funkcja uruchamiana z przerwaniem po przepelnieniu licznika w timer1
ISR(TIMER1_COMPA_vect)
{
	if(flaga_ile_razy_wcisnieto_ok%2 == 1){		//dla 1, 3, 5,... wcisniec przycisku ok liczymy, dla innych zatrzymujemy zliczanie - niestety 1, bo wybor funkcji juz zwieksza wartosc flagi
		licznik_100ms++;
	}
}
