#ifndef LISTA_H_INCLUDED
#define LISTA_H_INCLUDED
class nod {
    typedef nod *pNod;
  private:
    double coef;
    int putere;
    nod *urm;
  public:
    void set_monom(double coeff, int put);
    void set_putere(int put);
    void set_urm(pNod&p);
    double get_coef() const;
    int get_putere() const;
    pNod get_urm() const;
    void add_monom(pNod &dest, double coeff, int exp);

};

#endif // LISTA_H_INCLUDED
