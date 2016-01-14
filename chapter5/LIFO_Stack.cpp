//
// Created by WangHoward on 16/1/13.
//

#include <iostream>
#include "LIFO_Stack.h"
bool LIFO_Stack::pop(elemType &elem) {
    if (empty())
        return false;
    elem = _stack[size() - 1];
    _stack.pop_back();
    return true;
}

bool LIFO_Stack::push(const elemType &elem) {
    if ( full() )
        return false;
    _stack.push_back(elem);
    return true;
}

void LIFO_Stack::print( ostream& os) const {
    if ( empty() ){
        os << "There are no elements in the stack." << endl;
        return;
    }
    os << "elems: " << "\n";
    //将iter指向vector的最后一个元素的下一个地址
    vector<elemType>::const_iterator iter = _stack.end();
    while (iter != _stack.begin()) {
        os << *(--iter) << "\t";
    }
    os << endl;
}

