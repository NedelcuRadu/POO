
#include "exception.h"
#include <cstring>

         MyException::MyException(int line,const char* file, const char * function, std::string info):line(line),file(file),function(function),info(info){};
    int  MyException::get_line() const throw()
    {   return line;
    }
    const char *  MyException::get_file() const throw()
    {   return file;
    }
    const char *  MyException::get_function() const throw()
    {   return function;
    }
    const char*  MyException::what() const throw()
    {
        std::cout<<"Error in "<<file<<" in function "<<function<<" at line "<<line<<'\n';
        if (info!="")
        std::cout<<"Description: "<<info<<'\n';
        return "Not Good";
    }
