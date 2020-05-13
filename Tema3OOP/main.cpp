#include <bits/stdc++.h>
#include "Firma.h"
using namespace std;

template <class T>
vector<T> citire_n (int nr_elem)
{   vector<T> obiecte;
    obiecte.reserve(nr_elem);
    for(int i=0;i<nr_elem;i++)
    {
        T temp;
        cin>>temp;
        obiecte.push_back(temp);
    }
    return obiecte;
}
int main()
{    unique_ptr<Firma> F ( Firma::get_instance("Radu", "Moldovei"));
    Apartament A("Radu",32,2,20,3);
    //Apartament B = move(A); // Mutam A in C (Move semantics)
    Apartament C ("Ana",23,1,30,2);
    Casa D("Cornel",23,3,23,23,45, {2,3,4});
    Casa E("Kevin",20,4,12,4,5,{3,7});
    //cout<<A; // A este gol
    //cout<<B; // B contine A
    F->add(A);
    F->add(C);
    F->add(D);
    F->add(E);
    F->afis();
    F->total_chirie();
    try{ Apartament J("",-2,1,-4,-6);}
    catch (MyException &ex)
    {
    cout<<ex.what();
    }
    vector<Apartament> J = citire_n<Apartament>(2);
    for(auto &i:J)
        cout<<i;
    return 0;
}
