#ifndef INTERDRON_HH
#define INTERDRON_HH
#include<iostream>
#include "MacierzObrotu.hh"
#include "Dr3D_gnuplot_api.hh"
using std::vector;

class InterfejsDron {    
    public:


    virtual Wektor<double,3> get_srodek_masyDrona()=0;
    virtual Wektor<double,3> get_wymiary_Drona()=0;
    
    virtual void get_punktyKrytyczne(std::vector<Wektor<double,3>> &punkty)=0;
};

#endif