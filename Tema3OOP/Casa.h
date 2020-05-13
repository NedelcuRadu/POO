#ifndef CASA_H_INCLUDED
#define CASA_H_INCLUDED
#include "Locuinta.h"
class Casa: public Locuinta
{
private:
    double curte;
    double pret_curte;
    vector<double> suprafete;
public:
    friend void swap(Casa& first, Casa& second) noexcept;
    Casa(std::string nume= " ", double suprafata=0, int discount=0, double pretmp=0,double curte=0,double pret_curte=0,vector<double> suprafete= {0});
    ~Casa() override;
    Casa(const Casa &other);
    Casa(Casa &&other);
    Casa &operator = (Casa other);
    void add_etaj(int suprafata);
    int const get_etaje() const;
    double calc_chirie();
    void const afis() override;
    friend ostream & operator << (ostream &out, const Casa &other);
    friend istream & operator >> (istream &in, Casa &other);
};

#endif // CASA_H_INCLUDED
