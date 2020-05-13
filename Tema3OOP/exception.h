#ifndef EXCEPTION_H_INCLUDED
#define EXCEPTION_H_INCLUDED
#include <exception>
#pragma once
#include <bits/stdc++.h>
class MyException: public std::exception
{   int line;
    const char* file;
    const char* function;
    std::string info;
    public:
        MyException(int line,const char* file, const char * function, std::string info="");
    int get_line() const noexcept;
    const char * get_file() const noexcept;
    const char * get_function() const noexcept;
    const char* what() const noexcept;
};

#endif // EXCEPTION_H_INCLUDED
