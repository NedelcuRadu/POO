#ifndef FIRMA_H_INCLUDED
#define FIRMA_H_INCLUDED
#include "Gestiune.h"
class Firma //SINGLETON
{
private:
    std::string proprietar;
    std::string adresa;
    Gestiune<Casa> Case;
    Gestiune<Apartament> apartamente;
    static Firma* instance;
    Firma(std::string proprietar, std::string adresa);
    public:
    Firma(const Firma&) = delete;
    void operator = (Firma const &) = delete;
    static Firma* get_instance(std::string proprietar, std::string adresa);
    void add(Locuinta &obj);
    void afis();
    void total_chirie();
};


#endif // FIRMA_H_INCLUDED
