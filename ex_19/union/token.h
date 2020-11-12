//
// Created by 谁敢反对宁宁，我就打爆他狗头！ on 2020/11/12.
// C++ primer ex_19~24

#ifndef TEST_TOKEN_H
#define TEST_TOKEN_H

#include <iostream>
#include <string>
#include <utility>

//sales_data 无
//因为与string处理方式一样

class Token{
public:
    constexpr Token()
    :tok{INT},ival(){}
    constexpr Token(int i)
    :tok{INT},ival(i){}
    constexpr Token(double d)
    :tok{DOU},dval(d){}
    constexpr Token(char c)
    :tok{CHAR},cval(c){}
    Token(std::string s)
    :tok{STR},sval(s){}
    Token(Token const& rhs)
    :tok(rhs.tok){ CopyUnion(rhs); }
    Token(Token && rhs)noexcept
    :tok(rhs.tok){ MoveUnion(std::move(rhs)); }

    Token& operator=(Token const&);
    Token& operator=(Token &&)noexcept;
    Token& operator=(int i)noexcept;
    Token& operator=(double d)noexcept;
    Token& operator=(char c)noexcept;
    Token& operator=(std::string s)noexcept;
    ~Token();

    int    getINT()noexcept{ return ival; }
    double getDOU()noexcept{ return dval; }
    char   getCHAR()noexcept{ return cval; }
    std::string const& getSTR(){ return sval; }
private:
    enum {INT,DOU,CHAR,STR}tok;
    union{
        int ival;
        double dval;
        char cval;
        std::string sval;
    };
    void CopyUnion(Token const&);
    void MoveUnion(Token&&);
};
#endif //TEST_TOKEN_H
