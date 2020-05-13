#ifndef APARTAMENT_H_INCLUDED
#define APARTAMENT_H_INCLUDED
#include "Locuinta.h"
class Apartament: public Locuinta
{
private:
    int etaj;
public:
    friend void swap(Apartament& first, Apartament& second) noexcept;

    Apartament(std::string nume=" ", double suprafata=0, int discount=0, double pretmp=0,int etaj=0);
    ~Apartament() override;
    Apartament(const Apartament &other);
    Apartament(Apartament &&other);
    Apartament &operator = (Apartament other);
    double calc_chirie() override;
    void const afis() override;
    friend ostream & operator << (ostream &out, const Apartament &other);
    friend istream & operator >> (istream &in, Apartament &other);
};


#endif // APARTAMENT_H_INCLUDED
