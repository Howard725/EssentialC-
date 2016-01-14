//
// Created by WangHoward on 16/1/13.
//

#ifndef CHAPTER5_STACK_H
#define CHAPTER5_STACK_H

#include <string>
#include <iostream>

using namespace std;

typedef string elemType;


class Stack {
public:
    virtual bool pop( elemType& elem ) = 0;
    virtual bool push( const elemType& elem ) = 0;
    virtual int size() const = 0;
    virtual bool empty() const = 0;
    virtual bool full() const = 0;
    virtual void print( ostream& = cout ) const = 0;
    virtual bool peek( int index, elemType& elem ) = 0;
    virtual int top() const = 0;
};

    ostream& operator<<(ostream& os, const Stack &Stack);

#endif //CHAPTER5_STACK_H
