#include "polinom.h"
using namespace std;

int main() {
     Polinom a(2,2);
    Polinom b(2,3);
    Polinom c(b);
    cout<<b<<"Constructor de copiere \n";
    b.add_monom(3,4);
    cout<<"A: "<<a<<" B: "<<b<<'\n';
    cout<<"Calculul lui "<<b<<" in 2.3: "<<b.calcul(2.3);
    cout<<'\n';
    cout<<"A+B: "<<a+b;
    cout<<'\n';
    cout<<"B-A: "<<b-a<<endl;
    cout<<"B*A: "<<b*a;
    vector<Polinom> Obj = b.citire_polinoame(2);

    for (auto i:Obj)
        cout<<i;
     
    return 0;
}
