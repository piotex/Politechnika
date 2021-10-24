#include <avr/io.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <util/delay.h>


#define F_CPU 8000000  //8MHz

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


void ADC_init()
{
	sbi(ADMUX, REFS0); // konfiguracja napi�cia referencyjnego na AVCC
	cbi(ADMUX, REFS1); // konfiguracja podzielnika cz�stotliwo�ci dla uk�adu przetwornika. Mniejsza od 100KHz

	//	Czestotliwosc sygnalu taktujacego 62,5 kHz
	sbi(ADCSRA, ADPS0); //	Tymi bitami definiujemy po��dan� relacj�
	sbi(ADCSRA, ADPS1); //	 mi�dzy cz�stotliwo�ci� zegara sytemowego XTAL,
	sbi(ADCSRA, ADPS2); //	 a cz�stotliwo�ci� przebiegu taktuj�cego przetwornik.

	sbi(ADCSRA, ADEN); //uruchomienie uk�adu przetwornika

	//	konfiguracja/wyb�r kana�u/pinu na kt�rym b�dzie dokonywany pomiar
	cbi(ADMUX, MUX0); //Bity wyboru wej�cia analogowego.
	cbi(ADMUX, MUX1); //   Wej�cie wybrane kombinacj� tych bit�w
	cbi(ADMUX, MUX2); //   jest do��czone do przetwornika
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
	//char line[20];
	//LCD_Clear();			//na 3 odkomentowac
	//LCD_GoTo(0, 0);			//na 3 odkomentowac

	int A_D = uint16_tADC_10bit(); //odczytana warto�� z rejestru pomiarowego przetwornika A/D

	//LCD_WriteText(line);			//na 3 odkomentowac
	return A_D;
}
//funkcja zwraca napiecie w [mV]
int ADC_measure(){
	//wzor na na przeliczenie warto�ci zwracanej [V]: (ADC_10bit()*ref_val)/1024
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

		_delay_ms(100);
	}
	return 0;
}

int test(){
	DDRD = 0xFF;
	PORTD = (0x00);

	while(1){
		int val = ADC_measure();
		if(val < 1000){
			sbi(DDRD, PD0);
		}
		if(val >= 1000 && val < 2000){
			sbi(DDRD, PD0);
		}
		if(val >= 2000 && val < 3000){
			sbi(DDRD, PD1);
		}
		if(val >= 3000 && val < 4000){
			sbi(DDRD, PD2);
		}
		if(val >= 4000 && val < 5000){
			sbi(DDRD, PD3);
		}
		if(val >= 5000 ){
			sbi(DDRD, PD4);
		}
		_delay_ms(300);
	}

	return 0;
}
void test2(){
	DDRD = 0xFF;
	//+PORTD = (0x00);

	while(1){
		PORTD = (0xFF);
		_delay_ms(500);
		PORTD = (0x00);
		_delay_ms(500);
	}

}
void test3(){
	DDRD = 0b00000001;
	DDRC = 0b00000000;
	ADMUX = 0b01100000;
	ADCSRA = 0b10000111;
		// Main program loop
    while (1)
    {
		// Start an ADC conversion by setting ADSC bit (bit 6)
		ADCSRA = ADCSRA | (1 << ADSC);
		// Wait until the ADSC bit has been cleared
		while(ADCSRA & (1 << ADSC));

		if(ADCH > 40)
		{
			// Turn LED on
			PORTD = PORTD | (1 << PD0);
		}
		else
		{
			// Turn LED off
			PORTD = PORTD & ~(1 << PD0);
		}
	}

}

int main()
{
	//DDRC = 0xFF;
	//PORTC = 0;

	//ADC_init();
	//LCD_Initalize();
	//LCD_Home();

	//zadanie_45();


	//test();
	test3();
}
