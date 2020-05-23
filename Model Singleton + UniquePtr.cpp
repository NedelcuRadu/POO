#include <bits/stdc++.h>
class MyException: public std::exception
{   int line;
    const char* file;
    const char* function;
    std::string info;
    public:
MyException(int line, const char* file, const char * function, std::string info=""): line(line), file(file), function(function), info(info) {};
int  get_line() const noexcept {
    return line;
}
const char *  get_file() const noexcept {
    return file;
}
const char *  get_function() const noexcept {
    return function;
}
const char*  what() const noexcept {
    std::cout << "Error in " << file << " in function " << function << " at line " << line << '\n';
    if (info != "")
        std::cout << "Description: " << info << '\n';
    return "Check constructor arguments\n";
}
};
using namespace std;
class Singleton
{
private:
    static Singleton * instance ;
    Singleton () {};

public:
    Singleton(const Singleton&) = delete;
    void operator = (Singleton const &) = delete;
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
