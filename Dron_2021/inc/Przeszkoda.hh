#ifndef PRZESZKODA_HH
#define PRZESZKODA_HH

#include "InterfejsDron.hh"

class Przeszkoda 
{     
  public:
	virtual bool czy_kolizja(InterfejsDron* dron) = 0; 

};



#endif
