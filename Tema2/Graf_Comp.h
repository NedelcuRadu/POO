#ifndef GRAF_COMP_H_INCLUDED
#define GRAF_COMP_H_INCLUDED
#include "Graf_Orientat.h"
#include "Graf_Neorientat.h"
class Graf_Comp: public Graf_Neorientat, public Graf_Orientat {
  public:
    friend void swap(Graf_Comp& first, Graf_Comp& second)noexcept;
    Graf_Comp(int nr_noduri = 0);
    ~Graf_Comp() override;
    Graf_Comp(const Graf_Comp &other);
    Graf_Comp(Graf_Comp &&other);
    Graf_Comp &operator = (Graf_Comp other);

    void add_muchie(int x, int y);
    void conex_din_nod(int nod ) override;
    void componente_conexe() override;
    friend ostream & operator << (ostream &out,  Graf_Comp &other);
    friend istream & operator >> (istream &in, Graf_Comp &other);
    int get_nr_noduri();
};


#endif // GRAF_COMP_H_INCLUDED
