#ifndef MATRICE_H_INCLUDED
#include <bits/stdc++.h>
using namespace std;
template <class T>
class Matrice {
  private:
    T **a;
    int n, m;
  public:
    friend void swap(Matrice& first, Matrice& second) { // nothrow
        // enable ADL (not necessary in our case, but good practice)
        using std::swap;

        // by swapping the members of two objects,
        // the two objects are effectively swapped
        swap(first.n, second.n);
        swap(first.m, second.m);
        swap(first.a, second.a);
    }
    Matrice(int n = 0, int m = 0, T default_value = 0): n(n), m(m) {
        cout << "Matrice Constructor\n";
        if (n * m != 0) {

            try {

                a = new T*[n];
                for(int i = 0; i < n; i++) {
                    a[i] = new T[m];
                }

            } catch(bad_alloc&ba) {
                cerr << "Bad_alloc caught in Matrice constructor: " << ba.what() << '\n';
            }
            for(int i = 0; i < n; i++)
                for(int j = 0; j < m; j++)
                    a[i][j] = default_value;
        } else
            a = nullptr;
    }
    ~Matrice() {
        cout << "Matrice Destructor\n";
        for(int i = 0; i < n; i++)
            delete []a[i];
        delete []a;
    }
    Matrice(const Matrice &other): n(other.n), m(other.m) {
        a = new T*[n];
        for(int i = 0; i < n; i++) {
            a[i] = new T[m];
        }
        for(int i = 0; i < n; i++)
            for(int j = 0; j < m; j++)
                a[i][j] = other.a[i][j];
        cout << "Matrice Copy Constructor\n";
    }
    Matrice(Matrice && other) noexcept: Matrice() {
        cout << "Matrice Move Constructor\n";
        swap(*this, other);
    }
    Matrice &operator = (Matrice other) {
        cout << "Matrice Move\n";
        swap(*this, other);
        return *this;
    }
    Matrice& operator = (Matrice const &other) {
        if(this == &other)
            return *this;
        if(this->n != other.n || this->m != other.m) {
            for(int i = 0; i < n; i++) {
                delete []a[i];
            }
            delete []a;
            this->n = other.n;
            this->m = other.m;
            a = new int*[n];
            for(int i = 0; i < n; i++) {
                a[i] = new int[m];
            }
        }
        for(int i = 0; i < n; i++)
            for(int j = 0; j < m; j++)
                a[i][j] = other.a[i][j];
        cout << "Matrice Assignment\n";
    }
    const int get_m() const {
        return m;
    }
    const int get_n() const {
        return n;
    }

    T *&operator [](int index) {
        if (index >= n)
            throw "Index out of range";
        return a[index];
    }
    friend ostream & operator << (ostream &out, const Matrice &obj) {
        for(int i = 0; i < obj.n; i++) {
            for(int j = 0; j < obj.m; j++)
                cout << obj.a[i][j] << " ";
            cout << '\n';
        }
        return out;
    }

    friend istream & operator >> (istream &in, Matrice &obj) {
        int n, m;
        cout << "Nr linii si nr coloane: ";
        cin >> n >> m;
        Matrice<T> temp(n, m);
        cout << "Dati elementele: ";
        for(auto i = 0; i < n; i++)
            for(auto j = 0; j < m; j++)
                cin >> temp.a[i][j];
        swap(obj, temp);
        return in;
    }

};



#endif // MATRICE_H_INCLUDED
