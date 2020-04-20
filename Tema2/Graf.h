#ifndef GRAF_H_INCLUDED
#define GRAF_H_INCLUDED
#pragma once
#include <bits/stdc++.h>
using namespace std;
class Graf {
  protected:
    int nr_noduri;
    bool *viz;
  public:
    friend void swap(Graf& first, Graf& second)noexcept;
    Graf(int nr_noduri = 0);
    virtual ~Graf();
    Graf(const Graf& other);
    Graf(Graf &&other);
    Graf & operator = (Graf &&other);
    virtual void add_muchie(int x, int y ) = 0;
    virtual void conex_din_nod(int nod) = 0;
    virtual void componente_conexe() = 0;
    void reset_viz();
    friend ostream & operator << (ostream &out, Graf const&other);
};


#endif // GRAF_H_INCLUDED
