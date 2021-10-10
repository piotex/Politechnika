#include <avr/io.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <util/delay.h>
#include <avr/sfr_defs.h>
#include <math.h>
#include <avr/interrupt.h>
#include <avr/eeprom.h>
#include <avr/iom32.h>

//Dominika Arkabus  252839
//Piotr Kubon 		252871


//zapoznajemy się z budową wyświetlacza 7-segmentowego. Ile linii mikokontrolera potrzeba do obsługi takiego wyświetlacza?
//to zalezy, mozna uzyc tylko jednej ale trzeba bedzie wprowadizc dodatkowy element, w przypadku polaczenia bezposredniego uzywamy 7 (8 z kropka) lini

//co robi i jak działa funkcja “seg7ShowCyfra”
//wpisuje ciag 0 i 1 na port odpowiednio dla liczby z tablicy o podanym indeksie

//co to są przerwania? Do czego można je wykorzystywać?
//jest to procedura wykonywana co pewien okres cykli procesora, przerywajaca glowny program
//mozna je wykozystac do wszystkiego, wazne, zeby zmiescic sie w okreslonym czasie, np generowanie sygnalu pwm czy zmiana w locie stany flag glownego programu





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

/*
 *  Gotowe zaimplementowane:
 #define 	bit_is_set(sfr, bit)   (_SFR_BYTE(sfr) & _BV(bit))
 #define 	bit_is_clear(sfr, bit)   (!(_SFR_BYTE(sfr) & _BV(bit)))
 #define 	loop_until_bit_is_set(sfr, bit)   do { } while (bit_is_clear(sfr, bit))
 #define 	loop_until_bit_is_clear(sfr, bit)   do { } while (bit_is_set(sfr, bit))

 */

// MIN/MAX/ABS macros
#define MIN(a, b) ((a < b) ? (a) : (b))
#define MAX(a, b) ((a > b) ? (a) : (b))
#define ABS(x) ((x > 0) ? (x) : (-x))

volatile uint8_t minuty, sekundy;
volatile uint16_t liczba7Seg;
uint8_t i = 0;

volatile char znaki[4];

char cyfra[10] = {	0b01111110,
					0b00110000,
					0b01101101,
					0b01111001,
					0b00110011,
					0b01011011,
					0b01011111,
					0b01110000,
					0b01111111,
					0b01111011};
char null[1] = {0b000000000};

volatile int8_t flaga_liczba_do_wysw = -9;
volatile int8_t flaga_pauza = 0;
volatile int8_t flaga_wcisnieto = 0;
volatile int8_t is_it_my_first_time = 0;


//Inicjalizacja Timer1 do wywolywania przerwania z czestotliwoscia 2Hz
void TimerInit()
{
	//Wybranie trybu pracy CTC z TOP OCR1A
	//rozdzial 16 w dokumentacji
	// zabawa z rejestrami
	// ustawiam 1 na wgm12 zeby sie zgadzalo z tabela 16-5 mode 4
		sbi(TCCR1B,WGM12);

	//Wybranie dzielnika czestotliwosci
	//tabela 16-6
	//Liczymy  8M/(wartosc_prescalera)/2  <  65k		-> 2Hz -> prescaler ma byc calkowite zeby nie tracic dokladnosci
	// ustawiamy rejestry zgodnie z tabela 16-6	dla danego prescalera
		sbi(TCCR1B,CS12);

	//Zapisanie do OCR1A wartosci odpowiadajacej 0,5s
	// wyliczona wartosc ze wzoru 8M/(wartosc_prescalera)/2
		OCR1A = 15625;	//2Hz
		//OCR1A = 625;		//50Hz

	//Uruchomienie przerwania OCIE1A
		sbi(TIMSK,OCIE1A);
}

//Inicjalizacja portow do obslugi wyswietlacza 7 segmentowego
void seg7Init()
{
	//Inicjalizacja segmentu
	DDRC = 0xff;
	PORTC = 0xff;
}

//Wyswietla na wyswietlaczu 7 segmentowym cyfre z argumentu
void seg7ShowCyfra(uint8_t cyfraDoWyswietlenia)
{
	//wpisanie na port ciagu 0 i 1 w odpowiedniej kolejnosci z tablicy
	PORTC = cyfra[cyfraDoWyswietlenia]; //co to robi - wytlumaczyc prowadzacemu
}
void seg7null()
{
	//wpisanie na port samych 0 - wygaszenie wyswietlacza
	PORTC = null[0]; //co to robi - wytlumaczyc prowadzacemu
}



int main()
{
	TimerInit();
	seg7Init();

	sei(); //funkcja uruchamia globalne przerwania
	//ustawiamy rejestr kierunku B na wyjscie
	DDRB = 0xFF;
	//ustawiamy rejestr kierunku D na wejscie bez pullupa
	PORTD = 0x00;

	flaga_liczba_do_wysw = -9;
	is_it_my_first_time = 0;
	while (1)
	{
		if(flaga_liczba_do_wysw >=0 && flaga_liczba_do_wysw <= 9){
			seg7ShowCyfra(flaga_liczba_do_wysw);
		}
		else{
			seg7null();
		}

		if(flaga_pauza==1){
			//tutaj albo reset == null albo reset==0
			//seg7ShowCyfra(0);
			seg7null();

			sbi(PORTB, PB0);
			_delay_ms(5000);
			cbi(PORTB, PB0);
			flaga_pauza = 0;
		}

		if (bit_is_set(PIND, PD0)) {
			if(is_it_my_first_time!=0){
				flaga_wcisnieto++;
			}
			else{
				flaga_liczba_do_wysw=9;
				is_it_my_first_time++;
			}
			//czekam az puszcze
			int n = 0;
			while(n==0){
				if(bit_is_set(PIND, PD0)){
					n=0;
				}
				else{
					n=1;
				}
			}
		}


	}

	return 0;
}

//Funkcja uruchamiana z przerwaniem po przepelnieniu licznika w timer1
ISR(TIMER1_COMPA_vect)
{

	if(is_it_my_first_time != 0){

		if(flaga_wcisnieto == 0){
			if(flaga_pauza==0){
				flaga_liczba_do_wysw --;
				if(flaga_liczba_do_wysw<0)
				{
					flaga_pauza = 1;
					flaga_liczba_do_wysw = 9;
				}
			}
		}
		if(flaga_wcisnieto == 1){
		}
		if(flaga_wcisnieto >= 2){
			flaga_wcisnieto = 0;
			flaga_pauza = 0;
			flaga_liczba_do_wysw = 9;
		}
	}

	//tbi(PORTB, PB0);		//odkomentowac przy opisie zadania na 3
	//z wyliczonych wartosci przerwanie powinno nastepowac co 0,5s a wiec czestotliwosc wskazana powinna wynisic 2hz. Niestety z powodu ograniczen programowych symulator nie reaguje wystarczajaco wolno, a wiec nie jest mozliwy pomiar.

}
