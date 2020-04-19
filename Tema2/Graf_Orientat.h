#ifndef GRAF_ORIENTAT_H_INCLUDED
#define GRAF_ORIENTAT_H_INCLUDED
#include "Matrice.h"
#include "Graf.h"
class Graf_Orientat: public Graf {
  private:
    Matrice<int> A;
    int *viz;
  public:
    friend void swap(Graf_Orientat& first, Graf_Orientat& second)noexcept;
    Graf_Orientat(int nr_noduri = 0);
    Graf_Orientat(const Graf_Orientat &other);
    ~Graf_Orientat() override;
    void DFS(int nod) override;
    void conex_din_nod(int nod) override;
    void componente_conexe() override;
    void add_muchie(int x, int y) override;
    friend ostream & operator << (ostream &out,  const Graf_Orientat &other);
    friend istream & operator >> (istream &in, Graf_Orientat &other);
};


#endif // GRAF_ORIENTAT_H_INCLUDED
