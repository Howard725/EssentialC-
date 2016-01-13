//
// Created by WangHoward on 16/1/13.
//

#ifndef CHAPTER5_STACK_H
#define CHAPTER5_STACK_H

#include <string>

using namespace std;

typedef string elemType;


class Stack {
public:
    virtual bool pop( elemType& elem ) = 0;
    virtual bool push( const elemType& elem ) = 0;
    virtual int size() const = 0;
    virtual bool empty() const = 0;
    virtual bool full() const = 0;
    virtual elemType& peek() const = 0;//查看栈顶元素而不移除
    virtual void print() const = 0;
};


#endif //CHAPTER5_STACK_H
