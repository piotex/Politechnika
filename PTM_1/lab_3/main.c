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

volatile char znaki[4];

char cyfra[10] = {0b011111100, 0b001100000, 0b011011011, 0b011110010, 0b001100110, 0b010110111,
				  0b010111111, 0b011100000, 0b011111110, 0b011110111};
char null[1] = {0b000000000};
//Inicjalizacja Timer1 do wywolywania przerwania z cz�stotliwo�ci� 2Hz
void TimerInit()
{
	//Wybranie trybu pracy CTC z TOP OCR1A
	sbi(TCCR1B, WGM12); //to z dokumentacji Atmegi
	//Wybranie dzielnika czestotliwosci
	sbi(TCCR1B, CS12);
	//Zapisanie do OCR1A wartosci odpowiadajacej 0,5s
	OCR1A = 15625;
	//Uruchomienie przerwania OCIE1A
	sbi(TIMSK, OCIE1A);
}

//Inicjalizacja portow do obs�ugi wyswietlacza 7 segmentowego
void seg7Init()
{
	//Inicjalizacja segmentu
	DDRC = 0xff;
	PORTC = 0xff;
}

//Wyswietla na wyswietlaczu 7 segmentowym cyfre z argumentu
void seg7ShowCyfra(uint8_t cyfraDoWyswietlenia)
{
	PORTC = cyfra[cyfraDoWyswietlenia]; //co to robi - wytlumaczyc prowadzacemu
}
void seg7null()
{
	PORTC = null[0]; //co to robi - wytlumaczyc prowadzacemu
}

int main()
{
	TimerInit();
	seg7Init();

	sei(); //funkcja uruchamia globalne przerwania
	sbi(DDRB, PB0);
	sbi(DDRD, PD0);
	sbi(PORTD, PD0);
	// DDRC = 0xff;
	// PORTC = 0x00;
	uint8_t i = 10;
	while (1)
	{
		for (i = 10; i >= 0; --i)
		{
			seg7ShowCyfra(i);
			_delay_ms(1000);
			if (i == 0)
			{
				seg7null();
				sbi(PORTB, PB0);
				_delay_ms(5000);
				cbi(PORTB, PB0);
				i = 10;
			}
		}
	}

	return 0;
}

//Funkcja uruchamiana z przerwaniem po przepelnieniu licznika w timer1
ISR(TIMER1_COMPA_vect)
{
	// tbi(PORTB, PB0);
}
