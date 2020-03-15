#include "polinom.h"
using namespace std;

int main() {
    Polinom a(2,2);
    Polinom b(2,3);
    b.add_monom(3,4);
    Polinom c = a*b;
    cout<<c;
    return 0;
}
