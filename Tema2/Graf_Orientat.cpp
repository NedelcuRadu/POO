#include "Graf_Orientat.h"
#include "exception.h"
void swap(Graf_Orientat& first, Graf_Orientat& second) noexcept{ // nothrow
    // enable ADL (not necessary in our case, but good practice)
    using std::swap;

    // by swapping the members of two objects,
    // the two objects are effectively swapped
    swap(first.nr_noduri, second.nr_noduri);
    swap(first.viz, second.viz);
    swap(first.A, second.A);
}
Graf_Orientat::Graf_Orientat(int nr_noduri): Graf(nr_noduri), A(nr_noduri, nr_noduri), viz(nr_noduri ? new int [nr_noduri] : nullptr) {
    cout << "Graf_Orientat Constructor\n";
};
Graf_Orientat::Graf_Orientat(const Graf_Orientat &other): Graf(other), A(other.A), viz(nr_noduri ? new int [nr_noduri] : nullptr) {
    std::copy(other.viz, other.viz + nr_noduri, viz);
    std::cout << "Graf_Orientat Copy Constructor\n";
}
Graf_Orientat::~Graf_Orientat() {
    cout << "Graf_Orientat Destructor\n";
    delete []viz;
}
void Graf_Orientat::DFS(int nod) {
    try {
        cout << nod << " ";
        viz[nod] = 1;
        for(int i = 0; i < nr_noduri; i++)
            if(A[nod][i] && viz[i] == -1) {
                DFS(i);
            }
    } catch(const char* err) {
        cerr << err;
    }
};
void Graf_Orientat::conex_din_nod(int nod) {
    for(int i = 0; i < nr_noduri; i++)
        viz[i] = -1;
    viz[nod] = nod;
    DFS(nod);
    std::cout << '\n';
}
void Graf_Orientat::componente_conexe() {
    for(int i = 0; i < nr_noduri; i++)
        viz[i] = -1;
    for(int i = 0; i < nr_noduri; i++)
        if(viz[i] == -1) {
            DFS(i);
            cout << '\n';
        }
}
void Graf_Orientat::add_muchie(int x, int y) {
    if (x > A.get_n() || y > A.get_m() || y<0 || x<0)
        throw MyException(__LINE__,__FILE__,__FUNCTION__,"Graf_Orientat Out Of Range");
    A[x][y] = 1;
}
ostream & operator << (ostream &out,  const Graf_Orientat &other) {
    out << other.A;
    return out;
}
istream & operator >> (istream &in, Graf_Orientat &other) {
    int nr_noduri, nr_arce;
    int x, y;
    cout << "Dati nr de noduri: ";
    in >> nr_noduri;
    Graf_Orientat temp(nr_noduri);
    cout << "Dati nr de arce: ";
    cin >> nr_arce;
    for(int i = 0; i < nr_arce; i++) {
        cin >> x >> y;
        temp.add_muchie(x, y);
    }
    swap(temp, other);
    return in;
}

