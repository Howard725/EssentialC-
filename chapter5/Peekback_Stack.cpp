//
// Created by Administrator on 2016/1/14.
//

#include "Peekback_Stack.h"

bool Peekback_Stack::push(const elemType &elem) {
    if ( full() )
        return false;
    _stack.push_back(elem);
    ++_top;
    return true;
}

bool Peekback_Stack::pop(elemType &elem) {
    if ( empty() )
        return false;
    elem = _stack[--_top];
    _stack.pop_back();
    return true;
}

bool Peekback_Stack::peek(int index, elemType &elem) {
    if ( empty() && index > size() - 1 )
        return false;
    elem = _stack[index];
    return true;
}

bool Peekback_Stack::empty() const {
    return !_top;
}

bool Peekback_Stack::full() const {
    return size() >= _stack.max_size();
}

void Peekback_Stack::print( ostream& os ) const {
    if ( empty() )
        return;
    vector<elemType>::const_iterator iter = _stack.end();
    os << "elem: ";
    while( iter != _stack.begin() )
    {
        os << *(--iter) << "\t";
    }
    os << endl;
}
