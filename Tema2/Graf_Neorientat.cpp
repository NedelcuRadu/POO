#include "Graf_Neorientat.h"
#include <bits/stdc++.h>
using namespace std;

void swap(Graf_Neorientat& first, Graf_Neorientat& second) { // nothrow
    // enable ADL (not necessary in our case, but good practice)
    using std::swap;
    // by swapping the members of two objects,
    // the two objects are effectively swapped
    swap(first.nr_noduri, second.nr_noduri);
    swap(first.viz, second.viz);
    swap(first.l, second.l);
}
Graf_Neorientat::Graf_Neorientat(int nr_noduri): Graf(nr_noduri), l(nr_noduri), viz(nr_noduri ? new int [nr_noduri] : nullptr) {}
Graf_Neorientat::~Graf_Neorientat() {
    std::cout << "Graf_Neorientat Destructor\n";
    delete[]viz;
}
Graf_Neorientat::Graf_Neorientat(const Graf_Neorientat &other): Graf(other), l(other.l), viz(other.nr_noduri ? new int [other.nr_noduri] : nullptr) {
    std::copy(other.viz, other.viz + other.nr_noduri, viz);
    std::cout << "Graf_Neorientat Copy Constructor\n";
}
Graf_Neorientat::Graf_Neorientat(Graf_Neorientat &&other): Graf_Neorientat() {
    swap(*this, other);
    std::cout << "Graf_Neorientat Move Constructor\n";
}

Graf_Neorientat & Graf_Neorientat::operator = (Graf_Neorientat other) {
    std::cout << "Graf_Neorientat Move\n";
    swap(*this, other);
    return *this;
}

void Graf_Neorientat::add_muchie(int x, int y) { // Eroare daca x sau y > dimensiunea listei
    try {
        bool found = 1;
        for(int i = 0; i < l[x].size(); i++)
            if(l[x][i] == y)
                found = 0;
        if (found)
            l[x].push_back(y);
        found = 1;
        for(int i = 0; i < l[y].size(); i++)
            if(l[y][i] == x)
                found = 0;
        if (found)
            l[y].push_back(x);
    } catch(const char*) {
        std::cout << "Nu exista cel putin unul dintre nodurile: " << x << " " << y << '\n';
    }
}
void Graf_Neorientat::DFS(int nod) {
    viz[nod] = 1;
    cout << nod << " ";
    try {
        for(int i = 0; i < l[nod].size(); i++)
            if (viz[l[nod][i]] != -1)
                DFS(l[nod][i]);
    } catch(const char* err) {
        cerr << err;
    }
};
void Graf_Neorientat::conex_din_nod(int nod) {
    for(int i = 0; i < nr_noduri; i++)
        viz[i] = -1;
    DFS(nod);
    cout << '\n';
}
void Graf_Neorientat::componente_conexe() {
    for(int i = 0; i < nr_noduri; i++)
        viz[i] = -1;
    for(int i = 0; i < nr_noduri; i++)
        if(viz[i] == -1) {
            DFS(i);
            cout << '\n';
        }
}
ostream & operator << (ostream &out, const Graf_Neorientat &other) {
    out << other.l;
    return out;
}
istream & operator >> (istream &in, Graf_Neorientat &other) {
    int nr_noduri, nr_arce;
    int x, y;
    cout << "Dati nr de noduri: ";
    in >> nr_noduri;
    Graf_Neorientat temp(nr_noduri);
    cout << "Dati nr de arce: ";
    cin >> nr_arce;
    for(int i = 0; i < nr_arce; i++) {
        cin >> x >> y;
        temp.add_muchie(x, y);
    }
    swap(other, temp);
    return in;
}

