#ifndef LOCUINTA_H_INCLUDED
#define LOCUINTA_H_INCLUDED
#pragma once
#include <string.h>
#include <iostream>
#include "exception.h"
using namespace std;
class Locuinta // Abstract class
{
private:
    int mIndex;
    std::string nume;
protected:
    static int index;
    double suprafata;
    double pretmp;
    int discount;
public:
    friend void swap(Locuinta &first, Locuinta &second) noexcept;

    Locuinta(std::string nume="", double suprafata=0, int discount=0, double pretmp=0);
    virtual ~Locuinta();
    Locuinta(const Locuinta &other);
    Locuinta(Locuinta &&other);

    std::string const get_nume() const;
    void set_nume(std::string new_nume);
    int const get_index () const;
    void set_index(int val);
    double virtual  calc_chirie() = 0 ;
    void virtual const afis();
    bool operator < (const Locuinta &other) const;
    friend ostream & operator << (ostream &out, const Locuinta &other);
    friend istream & operator >> (istream &in, Locuinta &other);
};


#endif // LOCUINTA_H_INCLUDED
