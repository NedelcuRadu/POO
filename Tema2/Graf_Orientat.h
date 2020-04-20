#ifndef GRAF_ORIENTAT_H_INCLUDED
#define GRAF_ORIENTAT_H_INCLUDED
#pragma once
#include "Matrice.h"
#include "Graf.h"
class Graf_Orientat: virtual public Graf {
  private:
    Matrice<int> A;
  public:
    friend void swap(Graf_Orientat& first, Graf_Orientat& second)noexcept;
    Graf_Orientat(int nr_noduri = 0);
    Graf_Orientat(const Graf_Orientat &other);
    ~Graf_Orientat() override;
    Graf_Orientat(Graf_Orientat &&other);
    Graf_Orientat &operator = (Graf_Orientat other);
    void DFS_orientat(int nod);
    void conex_din_nod(int nod) override;
    void componente_conexe() override ;
    void add_muchie(int x, int y) override;
    friend ostream & operator << (ostream &out,  const Graf_Orientat &other);
    friend istream & operator >> (istream &in, Graf_Orientat &other);
};


#endif // GRAF_ORIENTAT_H_INCLUDED
