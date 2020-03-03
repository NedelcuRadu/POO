#include "polinom.h"
#include <bits/stdc++.h>
using namespace std;
    Polinom::Polinom() {
        root->set_monom(0, 0);
    }
    Polinom::Polinom(int put, double coeff) {
        root->set_monom(0, 0);
        add_monom(put, coeff);
    }
    Polinom::Polinom(const Polinom &p2) {
        pNod A = p2.root->get_urm();
        for(int i = 0; i < p2.nr_elem; i++) {
            add_monom(A->get_coef(), A->get_putere());
            A = A->get_urm();
        }
    }
    Polinom::~Polinom(){
        pNod current = root->get_urm();
        pNod next;
        for(int i = 0; i < nr_elem; i++) {
            next = current->get_urm();
        delete(current);
        current = next;
        }
        delete root;
    }
    int Polinom::get_nrelem() {
        return nr_elem;
    }
    double Polinom::calcul(double x) {
        double S = 0;
        if (nr_elem == 0)
            return S;
        else {
            pNod p = root->get_urm();
            for(int i = 0; i < nr_elem; i++) {
                if(!(AreDoubleSame(p->get_coef(), 0)))
                    S += p->get_coef() * pow(x, p->get_putere());
                p = p->get_urm();
            }
            return S;
        }
    }
    void Polinom::afis() { // Afiseaza polinomul
        pNod p = root->get_urm();
        for(int i = 0; i < nr_elem; i++) { // Pt fiecare element din polinom
            double coef = p->get_coef(); // Tinem minte coeficientul
            if(AreDoubleSame(coef, 0)) {
                // Daca coef e 0, monomul e 0
            } else if(AreDoubleSame(coef, 1)) // Daca coef e 1, printam doar X^putere
                cout << "X^" << p->get_putere();
            else {
                if(p->get_putere() == 0) // Daca puterea e 0, afisam coef
                    cout << p->get_coef();
                else if(p->get_putere() == 1) // Daca puterea e 1, afisam coef * X;
                    cout << p->get_coef() << "*X";
                else
                    cout << p->get_coef() << "*X^" << p->get_putere(); // Afisam coef * X ^ Putere
            }
            p = p->get_urm(); // Trecem la urm monom
            if (i < nr_elem - 1 && p->get_coef() > 0) // Daca nu suntem la ultimul monom si semnul e pozitiv
                cout << "+";
        }
        cout << endl;
    }
    pNod Polinom::get_root() { return root;}

    void Polinom::add_monom(double coeff, int exp) {
        pNod p = new nod;
        pNod a = root;
        p->set_monom(coeff, exp);
        for(int i = 0; i < nr_elem; i++)
            a = a->get_urm();
        nr_elem += 1;
        a->set_urm(p);
    }

    bool Polinom::AreDoubleSame(double dFirstVal, double dSecondVal) {
        return std::fabs(dFirstVal - dSecondVal) < std::numeric_limits<double>::epsilon();
    }

    istream & operator >> (istream &in,  Polinom &c) {
    int nr;
    cout << "Nr de elemente: ";
    in >> nr;
    int coef, exp;
    for(int i = 1; i <= nr; i++) {
        cout << "Coeficientul termenului " << i << ": ";
        in >> coef;
        cout << "Puterea termenului " << i << ": ";
        in >> exp;
        c.add_monom(coef, exp);
    }
    return in;
    }
    ostream & operator << (ostream &out, const Polinom &c) {
    // Afiseaza polinomul
    pNod p = c.root->get_urm();
    for(int i = 0; i < c.nr_elem; i++) { // Pt fiecare element din polinom
        double coef = p->get_coef(); // Tinem minte coeficientul
        if(std::fabs(coef) < std::numeric_limits<double>::epsilon()) {
            // Daca coef e 0, monomul e 0
        } else if(std::fabs(coef - 1) < std::numeric_limits<double>::epsilon()) // Daca coef e 1, printam doar X^putere
            out << "X^" << p->get_putere();
        else {
            if(p->get_putere() == 0) // Daca puterea e 0, afisam coef
                out << p->get_coef();
            else if(p->get_putere() == 1) // Daca puterea e 1, afisam coef * X;
                out << p->get_coef() << "*X";
            else
                out << p->get_coef() << "*X^" << p->get_putere(); // Afisam coef * X ^ Putere
        }
        p = p->get_urm(); // Trecem la urm monom
        if (i < c.nr_elem - 1 && p->get_coef() > 0) // Daca nu suntem la ultimul monom si semnul e pozitiv
            out << "+";
    }
    out << endl;
    return out;
}


