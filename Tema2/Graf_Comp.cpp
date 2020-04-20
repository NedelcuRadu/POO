#include "Graf_Comp.h"

 void swap(Graf_Comp& first, Graf_Comp& second)noexcept {
        using std::swap;
        swap(dynamic_cast<Graf_Neorientat&>(first), dynamic_cast<Graf_Neorientat&>(second));
        swap(dynamic_cast<Graf_Orientat&>(first), dynamic_cast<Graf_Orientat&>(second));
                swap(dynamic_cast<Graf&>(first), dynamic_cast<Graf&>(second)); // Cand dam swap la primele derivate, baza ajunge sa fie aceeasi
    }
    Graf_Comp::Graf_Comp(int nr_noduri): Graf_Neorientat(nr_noduri), Graf_Orientat(nr_noduri),Graf(nr_noduri) {
        cout << "Graf_Comp Constructor\n";
    };
    Graf_Comp::~Graf_Comp() {
        cout << "Graf_Comp Destructor\n";
    }
    Graf_Comp::Graf_Comp(const Graf_Comp &other): Graf_Neorientat(other), Graf_Orientat(other) {
        cout << "Graf_Comp Copy Constructor\n";
    };
    Graf_Comp::Graf_Comp(Graf_Comp &&other): Graf_Comp() {
        swap(*this, other);
        cout << "Graf_Comp Move Constructor\n";
    };
    Graf_Comp &Graf_Comp::operator = (Graf_Comp other) {
        std::cout << "Graf_Comp Move\n";
        swap(*this, other);
        return *this;
    };

    void Graf_Comp::add_muchie(int x, int y) {
        Graf_Neorientat::add_muchie(x, y);
        Graf_Orientat::add_muchie(x, y);
    }
    void Graf_Comp::conex_din_nod(int nod ) {
        cout << "Orientat:\n";
        Graf_Orientat::conex_din_nod(nod);
        cout << "Neorientat:\n";
          Graf_Neorientat::conex_din_nod(nod);
    std::cout << '\n';
    }
    void Graf_Comp::componente_conexe(){
        cout << "Orientat:\n";
         Graf_Orientat::componente_conexe();
        cout << "Neorientat:\n";
        Graf_Neorientat::componente_conexe();
    }
    ostream & operator << (ostream &out,  Graf_Comp &other) {
        out << "Orientat:\n";
        out << dynamic_cast<Graf_Orientat&>(other) ;
        out << "Neorientat:\n";
        out << dynamic_cast<Graf_Neorientat&>(other) ;
        return out;
    }
    istream & operator >> (istream &in, Graf_Comp &other) {
        int nr_noduri, nr_arce;
        int x, y;
        cout << "Dati nr de noduri: ";
        in >> nr_noduri;
        Graf_Comp temp(nr_noduri);
        if(nr_noduri > 0) {
            cout << "Dati nr de arce: ";
            cin >> nr_arce;
            for(int i = 0; i < nr_arce; i++) {
                cin >> x >> y;
                temp.add_muchie(x, y);
            }
        }
        swap(temp, other);
        return in;
    }
    int Graf_Comp::get_nr_noduri()
    {
        return nr_noduri;
    }
