#include "lista.h"
typedef nod *pNod;
void nod::set_monom(double coeff, int put) {
        coef = coeff;
        putere = put;
    };
    nod::~nod()
    {
        coef=0;
        putere=0;
        urm=nullptr;
    }
    void nod::set_putere(int put) {
        putere = put;
    }
    void nod::set_urm(pNod&p) {
        urm = p;
    }
    double nod::get_coef() const {
        return coef;
    };
    int nod::get_putere() const {
        return putere;
    };
    pNod nod::get_urm() const {
        return urm;
    };
    void nod::add_monom(pNod &dest, double coeff, int exp) {
        pNod p = new nod;
        p->set_monom(exp, coeff);
        dest->set_urm(p);
    }
