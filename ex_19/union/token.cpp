//
// Created by 谁敢反对宁宁，我就打爆他狗头！ on 2020/11/12.
//

#include "token.h"

using namespace std;
//using namespace std;
void Token::CopyUnion(const Token &rhs) {
    switch(rhs.tok){
        case INT    :ival=rhs.ival;break;
        case DOU    :dval=rhs.dval;break;
        case CHAR   :cval=rhs.cval;break;
        case STR    :new(&sval) string(rhs.sval);break;
    }
    //std::cout<<"copy";
}

void Token::MoveUnion(Token&& rhs){
    switch(rhs.tok){
        case INT    :ival=rhs.ival;break;
        case DOU    :dval=rhs.dval;break;
        case CHAR   :cval=rhs.cval;break;
        case STR    :new(&sval) string(std::move(rhs.sval));break;
    }
    //std::cout<<"move";
}
Token& Token::operator=(Token const& rhs){
    if(tok==STR && rhs.tok==STR){
        sval=rhs.sval;
    }
    else if(tok==STR && rhs.tok!=STR){
        sval.~string();
    }
    else{
        CopyUnion(rhs);
    }

    tok=rhs.tok;
    return *this;
}

Token& Token::operator=(Token && rhs)noexcept{
    if(tok==STR && rhs.tok==STR){
        sval=std::move(rhs.sval);
    }
    else if(tok==STR && rhs.tok!=STR){
        sval.~string();
    }
    else{
        MoveUnion(std::move(rhs));
    }

    tok=rhs.tok;
    return *this;
}

Token& Token::operator=(int i)noexcept{
    if(tok==STR) sval.~string();
    ival=i;
    tok=INT;
    return *this;
}

Token& Token::operator=(double d)noexcept{
    if(tok==STR) sval.~string();
    dval=d;
    tok=DOU;
    return *this;
}

Token& Token::operator=(char c)noexcept{
    if(tok==STR) sval.~string();
    cval=c;
    tok=CHAR;
    return *this;
}

Token& Token::operator=(string s)noexcept{
    if(tok==STR)
        sval=s;
    else
        new(&sval) string(s);

    tok=STR;
    return *this;
}

Token::~Token(){
    if(tok==STR)
        sval.~string();
}
