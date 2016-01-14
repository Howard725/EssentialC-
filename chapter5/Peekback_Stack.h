//
// Created by Administrator on 2016/1/14.
//

#ifndef CHAPTER5_PEEKBACK_STACK_H
#define CHAPTER5_PEEKBACK_STACK_H

#include <vector>
#include "Stack.h"

using namespace std;

class Peekback_Stack : public Stack{
public:
    //构造函数
    Peekback_Stack( int capacity = 0 ) : _top(0)
    { _stack.reserve(capacity); }
    //data member reader
    int top() const { return _top; }
    int size() const { return _stack.size(); }
//    int size() const { return _top; }

    //堆栈操作
    bool push( const elemType& elem );
    bool pop( elemType& elem );
    bool peek( int index, elemType& elem );
    //状态标识
    bool empty() const;
    bool full() const;

    //输出
    void print(ostream& = cout) const;

private:
    vector<elemType> _stack;
    int _top;
};



#endif //CHAPTER5_PEEKBACK_STACK_H
