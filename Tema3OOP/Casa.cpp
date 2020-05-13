#include "Casa.h"
     void swap(Casa& first, Casa& second) noexcept   // nothrow
    {
        // enable ADL (not necessary in our case, but good practice)
        using std::swap;
        // by swapping the members of two objects,
        // the two objects are effectively swapped
        swap(dynamic_cast<Locuinta&>(first),dynamic_cast<Locuinta&>(second));
        swap(first.curte, second.curte);
        swap(first.pret_curte,second.pret_curte);
        swap(first.suprafete, second.suprafete);
    }
    Casa::Casa(std::string nume, double suprafata, int discount, double pretmp,double curte,double pret_curte,vector<double> suprafete):Locuinta(nume,suprafata,discount,pretmp), curte(curte),pret_curte(pret_curte),suprafete(suprafete) {};
    Casa::~Casa()  {};
   Casa:: Casa(const Casa &other):Locuinta(other), curte(other.curte), pret_curte(other.pret_curte),suprafete(other.suprafete) {};
    Casa::Casa(Casa &&other)
    {
        swap(*this,other);
    };
    Casa& Casa::operator = (Casa other)
    {
        swap(*this,other);
        return *this;
    };
    void Casa::add_etaj(int suprafata)
    {
        suprafete.push_back(suprafata);
    }
    int const Casa::get_etaje() const
    {
        return suprafete.size()+1;
    }
    double Casa::calc_chirie()
    {
        double sum = 0;
        for_each(suprafete.begin(),suprafete.end(),[&sum](double &elem)
        {
            sum+=elem;
        });
        return curte*pret_curte + sum*pretmp*discount/100;
    }
    void const Casa::afis()
    {
        Locuinta::afis();
        cout<<"Dimensiune curte: "<<curte<<" mp\n";
        cout<<"Pret mp curte: "<<pret_curte<<" $\n";
        cout<<"Etajul si suprafata sa:\n";
        for(size_t i =0; i<suprafete.size(); i++)
            cout<<"Etajul "<<i+1<<" are suprafata "<<suprafete[i]<<'\n';
    }
     ostream & operator << (ostream &out, const Casa &other)
    {
        const_cast<Casa&>(other).afis();
        return out;
    }
     istream & operator >> (istream &in, Casa &other)
    {
        int nr_etaje;
        double aux;
        in>>static_cast<Locuinta&>(other);
        cout<<"Dimensiune curte:\n";
        in>>other.curte;
        while(other.curte<=0)
        {
            cout<<"Dimensiunea curtii nu poate fi <= 0(Ce fel de suprafata e aia?), incearca iar\n";
            in>>other.curte;
        }
        cout<<"Pret mp curte:\n";
        in>>other.pret_curte;
        while(other.pret_curte<1)
        {
            cout<<"Pretul curtii nu poate fi mai mic decat 1, incearca iar\n";
            in>>other.pret_curte;
        }

        cout<<"Nr etaje (fara parterul):\n";
        in>>nr_etaje;
        while(nr_etaje<0)
        {
            cout<<"Numarul etajelor nu poate fi mai mic decat 0 (Doar nu daramam parterul), incearca iar\n";
            in>>nr_etaje;
        }
        for(int i=0; i<nr_etaje; i++)
        {
            cout<<"Suprafata etajului "<<i+1<<": ";
            in>>aux;
            while(aux<=0)
            {
                cout<<"Suprafata nu poate fi <= 0(Ce fel de suprafata e aia?), incearca iar\n";
                in>>aux;
            }
            other.suprafete.push_back(aux);
        }
        return in;
    }
