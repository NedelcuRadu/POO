#include "Locuinta.h"
int Locuinta::index =1;
void swap(Locuinta &first, Locuinta &second) noexcept
{
    using std::swap;
    swap(first.mIndex,second.mIndex);
    swap(first.nume, second.nume);
    swap(first.suprafata, second.suprafata);
    swap(first.pretmp, second.pretmp);
    swap(first.discount, second.discount);
}
Locuinta::Locuinta(std::string nume, double suprafata, int discount, double pretmp): mIndex(index),nume(nume), suprafata(suprafata),pretmp(pretmp), discount(discount)
{
    index+=1;
    for(auto &i:nume)
        if((i<'A' || i>'z') && i!=' ')
            throw MyException(__LINE__,__FILE__,__FUNCTION__, "Asta e numele copilului lui Elon Musk?");
    if(discount<0 || discount>10)
        throw MyException(__LINE__,__FILE__,__FUNCTION__, "Discount-ul nu se potriveste cu cerintele management-ului");
    if(suprafata<0)
        throw MyException(__LINE__,__FILE__,__FUNCTION__, "Suprafata nu poate fi negativa");
    if(pretmp<0)
        throw MyException(__LINE__,__FILE__,__FUNCTION__, "Pretul pe metru patrat nu poate fi negativ (Doar nu-i dai bani sa-l inchirieze)");
};
Locuinta::~Locuinta() {};
Locuinta::Locuinta(const Locuinta &other): nume(other.nume), suprafata(other.suprafata),pretmp(other.pretmp), discount(other.discount)
{
};
Locuinta::Locuinta(Locuinta &&other)
{
    swap(*this,other);
};

std::string const Locuinta::get_nume() const
{
    return nume;
}
void Locuinta::set_nume(std::string new_nume)
{
    nume = new_nume;
}
int const Locuinta::get_index () const
{
    return mIndex;
}
void Locuinta::set_index(int val)
{
    mIndex = val;
}
void  const Locuinta::afis()
{
    std::cout<<"Numele proprietarului: "<<nume<<'\n';
    std::cout<<"Suprafata locuintei: "<<suprafata<<" mp\n";
    std::cout<<"Pretul pe metru patrat: "<<pretmp<<"$\n";
    std::cout<<"Discountul oferit: "<<discount<<"%\n";

}
bool Locuinta::operator < (const Locuinta &other) const
{
    return nume<other.nume;
}
ostream & operator << (ostream &out, const Locuinta &other)
{
    out<<"Numele proprietarului: "<<other.nume<<'\n';
    out<<"Suprafata locuintei: "<<other.suprafata<<" mp\n";
    out<<"Pretul pe metru patrat: "<<other.pretmp<<"$\n";
    out<<"Discountul oferit: "<<other.discount<<"%\n";
    return out;
}
istream & operator >> (istream &in, Locuinta &other)
{
    std::cout<<"Numele proprietarului:\n";
    in>>other.nume;
    std::cout<<"Suprafata locuintei (mp):\n";
    in>>other.suprafata;
    while(other.suprafata<0)
    {
        std::cout<<"Suprafata nu poate fi negativa, incercati iar.\n";
        in>>other.suprafata;
    }
    std::cout<<"Pretul pe metru patrat ($):\n";
    in>>other.pretmp;
    while(other.pretmp<0)
    {
        std::cout<<"Pretul pe mp nu poate fi negativ (Doar nu il platim ca sa inchirieze), incearca iar.\n";
        in>>other.pretmp;
    }
    std::cout<<"Discountul oferit (%):\n";
    in>>other.discount;
    while(other.discount<0 || other.discount > 10)
    {
        std::cout<<"Discountul nu se potriveste specificatiilor date de management (intre 0% si 10%), incearca iar.\n";
        in>>other.discount;
    }
    return in;
}
