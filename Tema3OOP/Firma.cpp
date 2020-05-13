#include "Firma.h"
Firma * Firma::instance = nullptr;


Firma::Firma(std::string proprietar, std::string adresa):proprietar(proprietar),adresa(adresa) {};

Firma* Firma::get_instance(std::string proprietar, std::string adresa)
{
    if(!instance)
        instance = new Firma(proprietar,adresa);
    return instance;
}
void Firma::add(Locuinta &obj)
{
    // obj.set_index(Case.get_nr_case()+apartamente.get_size());
    if(auto temp = dynamic_cast<Casa*>(&obj))
        Case+=*temp;
    else if(auto temp = dynamic_cast<Apartament*>(&obj))
        apartamente+=*temp;
    else
        cout<<"Firma nu gestioneaza astfel de proprietati\n";
}
void Firma::afis()
{
    cout<<Case;
    cout<<apartamente;
}
void Firma::total_chirie()
{
    cout<<"Total chirie pe "<<Case.get_nr_case()<<" case: "<<Case.total_chirie()<<" $/luna\n";
}
