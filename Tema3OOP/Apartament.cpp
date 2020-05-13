#include "Apartament.h"
void swap(Apartament& first, Apartament& second) noexcept   // nothrow
{
    // enable ADL (not necessary in our case, but good practice)
    using std::swap;
    // by swapping the members of two objects,
    // the two objects are effectively swapped
    swap(dynamic_cast<Locuinta&>(first),dynamic_cast<Locuinta&>(second));
    swap(first.etaj, second.etaj);
}

Apartament::Apartament(std::string nume, double suprafata, int discount, double pretmp,int etaj):Locuinta(nume,suprafata,discount,pretmp),etaj(etaj)
{
    if(etaj<-1)
        throw MyException(__LINE__,__FILE__,__FUNCTION__, "Etajul nu poate fi mai mic de -1 (Doar nu e beci)\n");
};
Apartament::~Apartament() {};
Apartament::Apartament(const Apartament &other):Locuinta(other),etaj(other.etaj) {};
Apartament::Apartament(Apartament &&other)
{   index-=1;
    swap(*this,other);
};
Apartament& Apartament::operator = (Apartament other)
{
    swap(*this,other);
    return *this;
}
double Apartament::calc_chirie()
{
    return pretmp*suprafata*discount/100;
}
void const Apartament::afis()
{
    Locuinta::afis();
    std::cout<<"Etajul: "<<etaj<<'\n';
}
ostream & operator << (ostream &out, const Apartament &other)
{
    out<<static_cast<Locuinta&>(const_cast<Apartament&>(other));
    out<<"Etajul: "<<other.etaj<<'\n';
    return out;
}
istream & operator >> (istream &in, Apartament &other)
{
    in>>static_cast<Locuinta&>(other);
    std::cout<<"Etajul apartamentului:\n";
    in>>other.etaj;
    while(other.etaj<0)
    {
        std::cout<<"Etajul apartamentului nu poate fi mai mic decat -1 (Demisol mai inteleg, da' beci?), incearca iar.\n";
        in>>other.etaj;
    }
    return in;
}

