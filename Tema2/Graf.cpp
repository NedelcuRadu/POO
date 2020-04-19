#include "Graf.h"
#include <bits/stdc++.h>
using namespace std;
void swap(Graf& first, Graf& second) noexcept { // nothrow
        // enable ADL (not necessary in our case, but good practice)
        using std::swap;

        // by swapping the members of two objects,
        // the two objects are effectively swapped
        swap(first.nr_noduri, second.nr_noduri);
    }
    Graf::Graf(int nr_noduri): nr_noduri(nr_noduri) {
        std::cout << "Graf Construcor\n";
    }
    Graf::~Graf() {
        std::cout << "Graf Destructor\n";
    };
    Graf::Graf(const Graf& other): nr_noduri(other.nr_noduri) {
        std::cout << "Graf Copy Constructor\n";
    };
    Graf::Graf(Graf &&other): Graf()  {
        swap(*this, other);
        std::cout << "Graf Move Constructor\n";
    };
    Graf & Graf::operator = (Graf &&other) {
        std::cout << "Graf Move\n";
        swap(*this, other);
        return *this;
    }

    ostream & operator << (ostream &out, Graf const&other) {
        out << other.nr_noduri;
        return out;
    }
