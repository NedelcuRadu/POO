#include "Graf_Orientat.h"
#include "exception.h"
void swap(Graf_Orientat& first, Graf_Orientat& second) noexcept{ // nothrow
    // enable ADL (not necessary in our case, but good practice)
    using std::swap;

    // by swapping the members of two objects,
    // the two objects are effectively swapped
    swap(dynamic_cast<Graf&>(first),dynamic_cast<Graf&>(second));
    swap(first.A, second.A);
}
Graf_Orientat::Graf_Orientat(int nr_noduri): Graf(nr_noduri), A(nr_noduri, nr_noduri) {
    cout << "Graf_Orientat Constructor\n";
};
Graf_Orientat::Graf_Orientat(const Graf_Orientat &other): Graf(other), A(other.A){
    std::cout << "Graf_Orientat Copy Constructor\n";
}
Graf_Orientat::~Graf_Orientat() {
    cout << "Graf_Orientat Destructor\n";
}
Graf_Orientat::Graf_Orientat(Graf_Orientat &&other): Graf_Orientat()
{ swap(*this,other);
    cout<<"Graf_Orientat Move Constructor";

}

Graf_Orientat & Graf_Orientat::operator = (Graf_Orientat other) {
    std::cout << "Graf_Orientat Move\n";
    swap(*this, other);
    return *this;
}
void Graf_Orientat::DFS_orientat(int nod) {
    try {
        cout << nod << " ";
        viz[nod] = 1;
        for(int i = 0; i < nr_noduri; i++)
            if(A[nod][i] && !viz[i]) {
                DFS_orientat(i);
            }
    } catch(const char* err) {
        cerr << err;
    }
};
void Graf_Orientat::conex_din_nod(int nod) {
    reset_viz();
    viz[nod] = 1;
    DFS_orientat(nod);
    std::cout << '\n';
}
void Graf_Orientat::componente_conexe() {
    reset_viz();
    for(int i = 0; i < nr_noduri; i++)
        if(viz[i] == 0) {
            DFS_orientat(i);
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
    if(nr_noduri>0)
    {cout << "Dati nr de arce: ";
    cin >> nr_arce;
    for(int i = 0; i < nr_arce; i++) {
        cin >> x >> y;
        temp.add_muchie(x, y);
    }}
    swap(temp, other);
    return in;
}

