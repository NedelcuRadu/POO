#ifndef GRAF_NEORIENTAT_H_INCLUDED
#define GRAF_NEORIENTAT_H_INCLUDED
#include "Lista.h"
#pragma once
#include "Graf.h"
class Graf_Neorientat: virtual public Graf {
    Lista<int> l;
  public:
    friend void swap(Graf_Neorientat& first, Graf_Neorientat& second);
    Graf_Neorientat(int nr_noduri = 0);
    ~Graf_Neorientat() override;
    Graf_Neorientat(const Graf_Neorientat &other);
    Graf_Neorientat(Graf_Neorientat &&other);
    Graf_Neorientat &operator = (Graf_Neorientat other);
    void add_muchie(int x, int y) override;
    void DFS_neorientat(int nod);
    void conex_din_nod(int nod) override;
    void componente_conexe() override;
    friend ostream & operator << (ostream &out, const Graf_Neorientat &other);
    friend istream & operator >> (istream &in, Graf_Neorientat &other);
};

#endif // GRAF_NEORIENTAT_H_INCLUDED
