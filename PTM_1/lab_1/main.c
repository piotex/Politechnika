#include <avr/io.h>
#include <stdlib.h>
#include <string.h>
#include <util/delay.h>

#define F_CPU 8000000  //8MHz

#ifndef _BV
#define _BV(bit)				(1<<(bit))
#endif
#ifndef sbi
#define sbi(reg,bit)		reg |= (_BV(bit))
#endif
#ifndef cbi
#define cbi(reg,bit)		reg &= ~(_BV(bit))
#endif

void zadanie_3(){
	PORTD = (0xFF);
	//lub
	//PORTD = (1<<PD7)
	//PORTD = (1<<PD6)
	//PORTD = (1<<PD5)
	//PORTD = (1<<PD4)
	//PORTD = (1<<PD3)
	//PORTD = (1<<PD2)
	//PORTD = (1<<PD1)
	//PORTD = (1<<PD0)
	//lub
	//for (int i = 0; i < 8; i++)
	//{
	//	sbi(PORTD, i);
	//}

}
void zadanie_35(){					// ustawia calu port na 1 i 0
	PORTD = (0xFF);
	_delay_ms(500);
	PORTD = (0x00);
	_delay_ms(500);
}
void mrygnij(int dell, int i){		//funkcja upraszczajaca - przesuwa bit
	PORTD ^= (0x01<<i);
	_delay_ms(dell);
	PORTD ^= (0x01<<i);
}
void zadanie_4(){				// wed³ug wyk³adu - przesuwanie bitu ^= -> negacja tego bitu - wyjscia
	int dell = 180;

	for(int i=0;i<8;i++){
		mrygnij(dell,i);
	}
	for(int i=6;i>0;i--){		//tutaj jest 6 zeby sie szybko odbil
		mrygnij(dell,i);
	}
}
void zadanie_45(){
	if(!bit_is_set(PINB,PINB0)){	//sprawdzenie czy b0 jest !high = low - wcisniety
		PORTD = 0xFF;
	}else{							//w przeciwnym razie
		PORTD = 0;
	}
}


int main() {
	DDRD = 0xFF;
	PORTB = 0xFF;

	while (1) {

		//zadanie_3();
		//zadanie_35();
		//zadanie_4();
		zadanie_45();
	}
}


