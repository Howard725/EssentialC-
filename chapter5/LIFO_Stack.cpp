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

void LIFO_Stack::print() const {
    cout << "elems: " << "\n";
    vector<elemType>::const_iterator iter = _stack.end();
}
