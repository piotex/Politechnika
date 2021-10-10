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

void ADC_init()
{
	sbi(ADMUX, REFS0); // konfiguracja napiêcia referencyjnego na AVCC
	cbi(ADMUX, REFS1); // konfiguracja podzielnika czêstotliwoœci dla uk³adu przetwornika. Mniejsza od 100KHz

	//	Czestotliwosc sygnalu taktujacego 62,5 kHz
	sbi(ADCSRA, ADPS0); //Tymi bitami definiujemy po¿¹dan¹ relacjê
	sbi(ADCSRA, ADPS1); //	 miêdzy czêstotliwoœci¹ zegara sytemowego XTAL,
	sbi(ADCSRA, ADPS2); //	 a czêstotliwoœci¹ przebiegu taktuj¹cego przetwornik.

	sbi(ADCSRA, ADEN); //uruchomienie uk³adu przetwornika

	//	konfiguracja/wybór kana³u/pinu na którym bêdzie dokonywany pomiar
	cbi(ADMUX, MUX0); //Bity wyboru wejœcia analogowego.
	cbi(ADMUX, MUX1); //   Wejœcie wybrane kombinacj¹ tych bitów
	cbi(ADMUX, MUX2); //   jest do³¹czone do przetwornika
	cbi(ADMUX, MUX3);
}

int uint16_tADC_10bit()
{
	sbi(ADCSRA, ADSC); //uruchomienie pojedynczego pomiaru
	while (bit_is_set(ADCSRA, ADSC))
	{
	}
	return ADC;
}

int ADC_10bit()
{
	char line[20];
	//LCD_Clear();			//na 3 odkomentowac
	//LCD_GoTo(0, 0);			//na 3 odkomentowac

	int A_D = uint16_tADC_10bit(); //odczytana wartoœæ z rejestru pomiarowego przetwornika A/D

	//LCD_WriteText(line);			//na 3 odkomentowac
	return A_D;
}
int ADC_measure(){
	//wzor na na przeliczenie wartoœci zwracanej [V]: (ADC_10bit()*ref_val)/1024
	int max_val = 1022;//powinno byc 1024 ale lepiej dziala tak
	int ref_val = 5;	//napiecie referencyjne
	int ret = (int)(((double)ADC_10bit()*ref_val)*100/max_val);

	return ret;
}

int zadanie_3(){
	while (1)
	{
		ADC_10bit();
		_delay_ms(100);
	}
	return 0;
}
int set_b_number(int val, char* buff){
	if(val%100 > 10){
		sprintf(buff,"Pomiar1:%d.%dV",val/100,val%100);
	}
	else{
		sprintf(buff,"Pomiar1:%d.0%dV",val/100,val%100);
	}
	return 0;
}

int zadanie_4(){
	char buff[20];
	while(1){
		int val = ADC_measure();
		set_b_number(val,buff);

		LCD_Clear();
		LCD_GoTo(0, 1);
		LCD_WriteText(buff);
		_delay_ms(100);
	}
	return 0;
}

// 1-wieksze
// 0-mniejsze
int komparator(int a, int b){
	if(a > b){
		return 1;
	}
	return 0;
}

int zadanie_45(){

	//komparator jest to uklad sluzacy do porownywania dwuch liczb/napiec
	char buff_1[20];
	char buff_2[20];
	int val=0;

	while(1){
		val = ADC_measure();
		LCD_Clear();
		LCD_GoTo(0, 0);

		if(komparator(val,250)){
			sprintf(buff_2,"on");
			sbi(PORTC,PC3);
		}
		else{
			sprintf(buff_2,"off");
			cbi(PORTC,PC3);
		}

		set_b_number(val,buff_1);
		LCD_WriteText(buff_1);
		LCD_GoTo(0, 1);
		LCD_WriteText(buff_2);
		_delay_ms(100);
	}

	return 0;
}

int main()
{
	DDRC = 0xFF;
	PORTC = 0;

	ADC_init();
	LCD_Initalize();
	LCD_Home();

	zadanie_45();
}
