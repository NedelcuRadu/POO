#include <bits/stdc++.h>
#include <memory>
using namespace std;
class Singleton
{
private:
    static Singleton * instance ;
    Singleton () {};

public:
    Singleton(const Singleton&) = delete;
    void operator = (Singleton const &);
    static Singleton* get_instance()
    {
        if(!instance)
            instance = new Singleton;
        return instance;
    }
    void afis()
    {
        cout<<"Mesaj";
    }
};
Singleton* Singleton::instance = nullptr;
int main()
{
    unique_ptr<Singleton> A (Singleton::get_instance());
    A->afis();
    return 0;
}
