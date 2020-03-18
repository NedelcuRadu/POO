#ifndef POLINOM_H_INCLUDED
#define POLINOM_H_INCLUDED
#pragma once
#include <bits/stdc++.h>
#include "lista.h"
using namespace std;
typedef nod *pNod;
class  Polinom {
  private:
    pNod root = new nod;
    int nr_elem = 0;
  public:
    Polinom() ;
    Polinom(int put, double coeff) ;
    Polinom(const Polinom &p2) ;
    //~Polinom();
    int get_nrelem() ;
    pNod get_root();
    double calcul(double x) ;
    void afis();
    void add_monom(double coeff, int exp) ;
    bool AreDoubleSame(double dFirstVal, double dSecondVal) ;
    Polinom operator + (Polinom const &obj) {
        Polinom res;
        int i = 0;
        int j = 0;
        pNod A = root->get_urm();
        pNod B = obj.root->get_urm();
        while( i < nr_elem && j < obj.nr_elem) {
            int putere_A = A->get_putere();
            int putere_B = B->get_putere();
            if (putere_A == putere_B) {
                res.add_monom(A->get_coef() + B->get_coef(), putere_A);
                i += 1;
                j += 1;
                A = A->get_urm();
                B = B->get_urm();
            } else if(putere_A < putere_B) {
                res.add_monom(A->get_coef(), putere_A);
                i += 1;
                A = A->get_urm();
            } else {
                res.add_monom(B->get_coef(), putere_B);
                j += 1;
                B = B->get_urm();
            }
        }
        while(i < nr_elem) {
            res.add_monom(A->get_coef(), A->get_putere());
            i++;
            A = A->get_urm();
        }
        while(j < obj.nr_elem) {
            res.add_monom(B->get_coef(), B->get_putere());
            j++;
            B = B->get_urm();
        }


        return res;
    }

    Polinom operator - (Polinom const &obj) {
        Polinom res;
        int i = 0;
        int j = 0;
        pNod A = root->get_urm();
        pNod B = obj.root->get_urm();
        while( i < nr_elem && j < obj.nr_elem) {
            int putere_A = A->get_putere();
            int putere_B = B->get_putere();
            if (putere_A == putere_B) {
                res.add_monom(A->get_coef() - B->get_coef(), putere_A);
                i += 1;
                j += 1;
                A = A->get_urm();
                B = B->get_urm();
            } else if(putere_A < putere_B) {
                res.add_monom(A->get_coef(), putere_A);
                i += 1;
                A = A->get_urm();
            } else {
                res.add_monom(-B->get_coef(), putere_B);
                j += 1;
                B = B->get_urm();
            }
        }
        while(i < nr_elem) {
            res.add_monom(A->get_coef(), A->get_putere());
            i++;
            A = A->get_urm();
        }
        while(j < obj.nr_elem) {
            res.add_monom(-B->get_coef(), B->get_putere());
            j++;
            B = B->get_urm();
        }


        return res;
    }

    Polinom operator * (Polinom const &obj) {
        Polinom res;
        pNod A = root->get_urm();
        for(int i = 0; i < nr_elem; i++) {
            Polinom P;
            pNod B = obj.root;
            for(int j = 0; j < obj.nr_elem; j++) {
                B = B->get_urm();
                P.add_monom(A->get_coef()*B->get_coef(), A->get_putere() + B->get_putere());
            }
            A = A->get_urm();
            res = res+P;
        }
        return res;
    }
    Polinom * citire_polinoame(int nr) {
        Polinom A[nr + 1];
        for(int i = 0; i < nr; i++) {
            cin >> A[i];
        }
        for(int i = 0; i < nr; i++)
            cout << A[i];
        return A;
    }

    friend ostream & operator << (ostream &out, const Polinom &c);
    friend istream & operator >> (istream &in,  Polinom &c);

};




#endif // POLINOM_H_INCLUDED
