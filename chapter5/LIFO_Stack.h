//
// Created by WangHoward on 16/1/13.
//

#ifndef CHAPTER5_LIFO_STACK_H
#define CHAPTER5_LIFO_STACK_H

#include <vector>
#include "Stack.h"

using namespace std;

class LIFO_Stack : public Stack{
public:
    bool pop(elemType& elem);
    bool push(const elemType& elem);
    int size() const;
    bool empty() const;
    bool full() const;
    bool peek( int index, elemType& elem ) { return false; }
    void print( ostream& ) const;
    int top() const { return _top;}
private:
    vector<elemType> _stack;
    const int _max_size = 10;
    int _top;//该类中并未用到该字段，只是为了编译通过而加上该字段；该字段的应用见Peekback_Stack;
};

inline int LIFO_Stack::size() const {
    return _stack.size();
}

inline bool LIFO_Stack::empty() const {
    return _stack.empty();
}

inline bool LIFO_Stack::full() const {
    return size() >= _max_size;
}


#endif //CHAPTER5_LIFO_STACK_H
