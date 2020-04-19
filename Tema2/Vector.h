#ifndef VECTOR_H_INCLUDED
#define VECTOR_H_INCLUDED
#include <bits/stdc++.h>
#include "exception.h"
using namespace std;
template<class T>
class Vector {
  private:
    size_t dim;
    size_t dim_max = 0;
    T *v;
  public:
    friend void swap(Vector<T>& first, Vector<T>& second) { // nothrow
        // enable ADL (not necessary in our case, but good practice)
        using std::swap;

        // by swapping the members of two objects,
        // the two objects are effectively swapped
        swap(first.dim, second.dim);
        swap(first.dim_max, second.dim_max);
        swap(first.v, second.v);
    }
    Vector<T>(size_t dim = 0): dim(dim) {
        if (dim > dim_max)
            dim_max = 2 *dim + 1;
        try {
            v = dim_max ? new T[dim_max] : nullptr;
            std::cout << "Vector<T> Constructor\n";
        } catch(bad_alloc&ba) {
            cerr << "Bad_alloc caught in Vector<T>: " << ba.what() << '\n';
        }
    }
    ~Vector<T>() {
        std::cout << "Vector<T> Destructor\n";
        delete []v;

    };
    Vector<T>(const Vector<T> &other):dim(other.dim),dim_max(other.dim_max),v(other.dim_max? new T[other.dim_max]:nullptr){
        std::cout << "Vector<T> Copy Constructor\n";
      copy(other.v,other.v+other.dim_max,v);
    }
    Vector<T>(Vector<T> &&other) noexcept: Vector<T>() {
        swap(*this, other);
        std::cout << "Vector<T> Move Constructor\n";
    }
//    Vector<T>& operator = (Vector<T> const &other) {
//        if(this == &other)
//            return *this;
//        if(dim_max != other.dim_max) {
//            delete []v;
//            dim_max = other.dim_max;
//            v = dim_max? new T[dim_max]:nullptr;
//        }
//        dim = other.dim;
//        copy(other.v,other.v+other.dim,v);
//    }
    Vector<T> & operator = (Vector<T> other) noexcept {
        swap(*this, other);
        std::cout << "Vector<T> Move\n";
        return *this; // Always return this
    }
    T & operator [](int index) {
        if (index >= dim)
            throw MyException(__LINE__,__FILE__,__FUNCTION__, "Vector Index Out Of Range");
        return v[index];
    }
    void push_back(T val) {
        if(dim < dim_max)
            v[dim++] = val;
        else
            try {
                dim_max = 2 * dim;
                T *temp = new T[dim_max];
                copy(v,v+dim,temp);
                v = move(temp);
                v[dim++] = val;
            } catch(bad_alloc&  ba) {
                cerr << "Bad_alloc caught in Vector<T> push_back resize: " << ba.what() << '\n';
            }
    }
    int size() {
        return dim;
    }
    bool empty() {
        if (dim > 1)
            return false;
        return true;
    }
    void pop() {
        dim--;
    }

    friend ostream & operator << (ostream &out, Vector<T> const&other) {
        for(auto i = 0; i <  other.dim; i++)
            out << other.v[i] << " ";
        out << '\n';
        return out;
    }

    friend istream & operator >> (istream &in, Vector<T> &other) {
        auto temp = 0;
        T x;
        cout << "Nr elemente: ";
        cin >> temp;
        cout<<"Dati elementele: ";
        for(auto i = 0; i < temp; i++) {
            cin >> x;
            other.push_back(x);
        }
        return in;
    }
};


#endif // VECTOR_H_INCLUDED
