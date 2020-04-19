#include <bits/stdc++.h>
#include "Graf_Orientat.h"
#include "Graf_Neorientat.h"
#include "Vector.h"
#include "exception.h"
using namespace std;
template<class T>
vector<T> citeste_n(int n) {
    vector<T> A;
    for(int i = 0; i < n; i++) {
        T temp;
        cin >> temp;
        A.push_back(temp);
    }
    for(int i = 0; i < n; i++)
        cout << A[i] << '\n';
    return A;
}
int main() {

    Graf_Neorientat A(4);
    A.add_muchie(0, 1);
    Graf_Neorientat B=move(A);
    B.add_muchie(2, 3);
    cout << B;
    cout<<A; // A acum e gol
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
    C.componente_conexe();
    cout << C;
    citeste_n<Graf_Orientat>(2);
    try {
        Lista<int> A(-2);
    } catch(bad_alloc &ba) {
        cout << "List Constructor bad alloc " << ba.what();
    }
    try{Vector<int> B(4);
    cout<<B[5];}
    catch(MyException &ex)
    {
        ex.what();
    }

    return 0;

}
