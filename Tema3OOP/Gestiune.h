#ifndef GESTIUNE_H_INCLUDED
#define GESTIUNE_H_INCLUDED
#include "Casa.h"
#include "Apartament.h"
template <class T>
class Gestiune
{
private:
    set<pair<Locuinta*,T>> *multime;

public:
    friend void swap(Gestiune &first, Gestiune &second) noexcept
    {
        using std::swap;
        swap(first.multime,second.multime);
    }
    Gestiune()
    {
        multime = new set<pair<Locuinta*,T> >;
    };
    ~Gestiune()
    {
        delete multime;
    }
    Gestiune(const Gestiune&other):multime(new  set<pair<Locuinta*,T>>(other.multime)) {};
    Gestiune& operator = (Gestiune other)
    {
        swap(*this,other);
        return *this;
    }
    int const get_size() const
    {
        return multime->size()+1;
    }
    void operator +=(T&obj)
    {
        //obj.set_index(multime->size()+1);
        multime->insert({dynamic_cast<Locuinta*>(&obj),obj});
    }
    template <class T2>
    friend istream & operator >> (istream &in, T2 &obj)
    {
        T temp;
        in>>temp;
        obj+=temp;
        return in;
    }
    template<class T2>
    friend ostream &operator << (ostream &out, T2 &obj)
    {
        for(auto i = obj.multime->begin(); i!=obj.multime->end(); ++i)
            out<<(*i).first->get_index()<<'\n'<<(*i).second;
        return out;
    }
};
template<>
class Gestiune<Casa>
{
private:
    set<pair<Locuinta*,Casa>> * multime;
    int nr_case;
public:
    friend void swap(Gestiune<Casa> &first, Gestiune<Casa> &second) noexcept
    {
        using std::swap;
        swap(first.multime,second.multime);
    }
    Gestiune()
    {
        multime = new set<pair<Locuinta*,Casa> >;
        nr_case = 0;
    };
    ~Gestiune()
    {
        delete multime;
    }
    Gestiune(const Gestiune<Casa>&other):nr_case(other.nr_case)
    {
        multime = new set<pair<Locuinta*,Casa>>;
        for(auto i=other.multime->begin(); i!=other.multime->end(); i++)
            multime->insert(*i);
    };
    Gestiune<Casa>& operator = ( Gestiune<Casa> other)
    {
        swap(*this,other);
        return *this;
    }
    void operator +=(Casa&obj)
    {
       // obj.set_index(nr_case);
        multime->insert({dynamic_cast<Locuinta*>(&obj),obj});
        nr_case+=1;
    }
    double total_chirie()
    {
        double sum =0;
        for(auto i = multime->begin(); i!=multime->end(); ++i)
            sum+=(const_cast<pair<Locuinta*,Casa>&>(*i)).second.calc_chirie();
        return sum;
    }
    friend istream & operator >> (istream &in, Gestiune<Casa> &obj)
    {
        int nr_case;
        cout<<"Numarul de case:\n";
        cin>>nr_case;
        obj.nr_case = nr_case;
        while(nr_case--)
        {
            Casa temp;
            in>>temp;
            obj+=temp;
        }
        return in;
    }
    friend ostream &operator << (ostream &out, Gestiune<Casa> &obj)
    {
        for(auto i = obj.multime->begin(); i!=obj.multime->end(); ++i)
            out<<(*i).first->get_index()<<'\n'<<(*i).second;
        return out;
    }
    int const get_nr_case() const
    {
        return nr_case;
    }

};


#endif // GESTIUNE_H_INCLUDED
