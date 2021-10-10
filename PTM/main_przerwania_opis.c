#include <avr/io.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <util/delay.h>
#include <avr/sfr_defs.h>
#include <math.h>
#include <avr/interrupt.h>
#include <avr/eeprom.h>

#ifndef _BV
#define _BV(bit)				(1<<(bit))
#endif

#ifndef inb
#define	inb(addr)			(addr)
#endif

#ifndef outb
#define	outb(addr, data)	addr = (data)
#endif

#ifndef sbi
#define sbi(reg,bit)		reg |= (_BV(bit))
#endif

#ifndef cbi
#define cbi(reg,bit)		reg &= ~(_BV(bit))
#endif

#ifndef tbi
#define tbi(reg,bit)		reg ^= (_BV(bit))
#endif

/*
 *  Gotowe zaimplementowane:
 #define 	bit_is_set(sfr, bit)   (_SFR_BYTE(sfr) & _BV(bit))
 #define 	bit_is_clear(sfr, bit)   (!(_SFR_BYTE(sfr) & _BV(bit)))
 #define 	loop_until_bit_is_set(sfr, bit)   do { } while (bit_is_clear(sfr, bit))
 #define 	loop_until_bit_is_clear(sfr, bit)   do { } while (bit_is_set(sfr, bit))

 */

// MIN/MAX/ABS macros
#define MIN(a,b)			((a<b)?(a):(b))
#define MAX(a,b)			((a>b)?(a):(b))
#define ABS(x)				((x>0)?(x):(-x))

volatile uint8_t minuty, sekundy;
volatile uint16_t liczba7Seg;

volatile char znaki[4];

char cyfra[10] = { 0b1111111, 0b1111111, 0b1111111, 0b1111111, 0b1111111,
		0b1111111, 0b1111111, 0b1111111, 0b1111111, 0b1111111 };

//Inicjalizacja Timer1 do wywolywania przerwania z czêstotliwoœci¹ 2Hz
void TimerInit() {
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
	//OCR1A = 15625;	//2Hz
	OCR1A = 625;		//50Hz

//Uruchomienie przerwania OCIE1A
	sbi(TIMSK,OCIE1A);
}

//Inicjalizacja portow do obs³ugi wyswietlacza 7 segmentowego
void seg7Init() {
	//Inicjalizacja kolumn

	//Inicjalizacja segmentu

}

//Wyswietla na wyswietlaczu 7 segmentowym cyfre z argumentu
void seg7ShowCyfra(uint8_t cyfraDoWyswietlenia) {
	PORTC = cyfra[cyfraDoWyswietlenia];	//co to robi - wytlumaczyc prowadzacemu

}


int main() {
	TimerInit();
	seg7Init();

	sei(); //funkcja uruchamia globalne przerwania
	sbi(DDRB,PB0);	//ustawiamy rejestr kierunku B na wyjscie


	while (1) {
		//tbi(PORTB,PB0);
		_delay_ms(500);

		/*
		for (uint8_t i = 0; i < 10; i++) {
			seg7ShowCyfra(i);
			_delay_ms(200);
		}
		*/
	}

	return 0;
}

//Funkcja uruchamiana z przerwaniem po przepelnieniu licznika w timer1
ISR(TIMER1_COMPA_vect) {
	tbi(PORTB,PB0);
}
