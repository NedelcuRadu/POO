#include "Graf_Comp.h"
template<class T>
T* citeste_n(int n) {
    T A[n];
    for(int i = 0; i < n; i++) {
        cin >> A[i];
    }
    for(int i = 0; i < n; i++)
        cout << A[i] << '\n';
    return A;
}

int main() {

    Graf_Neorientat A(4);
    A.add_muchie(0, 1);
    Graf_Neorientat B = move(A);
    B.add_muchie(2, 3);
    cout << "------B-------:\n";
    cout << B;
    cout << "----------A---------:\n" << A; // A acum e gol
    Graf_Orientat C(6);
    C.add_muchie(1, 0);
    C.add_muchie(0, 5);
    C.add_muchie(5, 1);
    C.add_muchie(5, 0);
    C.add_muchie(2, 1);
    C.add_muchie(1, 3);
    C.add_muchie(3, 1);
    C.add_muchie(4, 3);
    C.add_muchie(5, 3);
    cout << "Componentele conexe ale lui C:\n";
    C.componente_conexe();
    cout << "-----------C---------:\n";
    cout << C;
    cout << "Exemplu Exceptie Bad Alloc:\n";
    try {
        Lista<int> A(-2);
    } catch(bad_alloc &ba) {
        cout << "List Constructor bad alloc " << ba.what();
    }
    cout << "Exemplu MyException:\n";
    try {
        Vector<int> B(4);
        cout << B[5];
    } catch(MyException &ex) {
        ex.what();
    }
    cout << "------Diamond Inheritance:-----\n";
    Graf_Comp D(4);
    D.add_muchie(2, 1);
    D.add_muchie(2, 3);
    Graf_Comp E = move(D);
    cout << "-----------D---------:\n";
    cout << D;
    cout << "Nr noduri: " << D.get_nr_noduri() << '\n';
    cout << "-----------E---------:\n";
    cout << E;
    cout << "Nr noduri: " << E.get_nr_noduri() << '\n';
    cout << "------Citirea a N obiecte:-------\n";
    citeste_n<Graf_Orientat>(2);
    return 0;

}
