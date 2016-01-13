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
    elemType& peek() const;
    void print() const;
private:
    vector<elemType> _stack;
    const int _max_size = 10;
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

inline elemType& LIFO_Stack::peek() const {
    return _stack[size() - 1];
}


#endif //CHAPTER5_LIFO_STACK_H
