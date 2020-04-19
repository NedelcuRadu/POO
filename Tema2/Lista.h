#ifndef LISTA_H_INCLUDED
#define LISTA_H_INCLUDED
#include "Vector.h"
#include "exception.h"
using namespace std;
template <class T>
class Lista {
  private:
    Vector<T> *l;
    int dim;
  public:
    friend void swap(Lista<T>& first, Lista<T>& second) { // nothrow
        // enable ADL (not necessary in our case, but good practice)
        using std::swap;

        // by swapping the members of two objects,
        // the two objects are effectively swapped
        swap(first.dim, second.dim);
        swap(first.l, second.l);
    }
    Lista<T>(int dim = 0): dim(dim), l(dim ? new Vector<T>[dim] : nullptr) {
        if(dim<0)
            throw MyException(__LINE__,__FILE__,__FUNCTION__, "List Dimension cannot be negative");
        cout << "Lista Constructor\n";
    }
    ~Lista<T>() {
        delete []l;
        cout << "Lista Destructor\n";
    }
    Lista<T>(const Lista<T> &other): dim(other.dim), l(other.dim ? new Vector<T>[other.dim] : nullptr) {
        copy(other.l, other.l + other.dim, l);
        cout << "Lista Copy\n";
    }
    Lista<T>(Lista<T> &&other): Lista<T>() {
        swap(*this, other);
        cout << "Lista Move Constructor\n";
    }
    Lista<T> & operator = (Lista<T> other) noexcept {
        swap(*this, other);
        cout << "Lista Assignment\n";
        return *this;
    }
    Vector<T> & operator [](int index) {
        if (index >= dim)
            throw out_of_range("List index out of range");
        return l[index];
    }
    int get_dim() {
        return dim;
    }
    friend ostream & operator << (ostream &out, Lista<T> const&other) {
        for(int i = 0; i <  other.dim; i++)
            out << i << ": " << other.l[i];
        return out;
    }
    friend istream & operator >> (istream &in, Lista<T> &obj) {
        int nr_elem, dim;
        int x;
        T y;
        cout << "Nr de elemente si dimensiunea: ";
        cin >> nr_elem >> dim;
        Lista <T> temp(dim);
        for(int i = 0; i < nr_elem; i++) {
            cout << "Linia si elementul: ";
            cin >> x >> y;
            temp[x].push_back(y);
        }
        obj = temp;


        return in;
    }
};


#endif // LISTA_H_INCLUDED
