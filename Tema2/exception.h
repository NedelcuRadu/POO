#ifndef EXCEPTION_H_INCLUDED
#define EXCEPTION_H_INCLUDED
#include <exception>
#include <cstring>
class MyException: public std::exception
{   int line;
    const char* file;
    const char* function;
    std::string info;
    public:
        MyException(int line,const char* file, const char * function, std::string info=""):line(line),file(file),function(function),info(info){};
    int get_line() const throw()
    {   return line;
    }
    const char * get_file() const throw()
    {   return file;
    }
    const char * get_function() const throw()
    {   return function;
    }
    const char* what() const throw()
    {
        std::cout<<"Error in "<<file<<" in function "<<function<<" at line "<<line<<'\n';
        if (info!="")
        std::cout<<"Description: "<<info<<'\n';
        return "Not Good";
    }
};

#endif // EXCEPTION_H_INCLUDED
