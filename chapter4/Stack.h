//
// Created by Administrator on 2015/12/14.
//

#ifndef CHAPTER4_STACK_H
#define CHAPTER4_STACK_H

#include <string>
#include <vector>

using namespace std;

class Stack {
public:
    bool push( const string &);
    bool pop( string &elem );
    bool peek( string &elem);
    bool find( const string &) const;
    int count( const string &) const;

    bool empty();
    bool full();

    int size() { return _stack.size(); }

private:
    vector<string> _stack;
};

inline bool Stack::empty() {
    return _stack.empty();
}

inline bool Stack::full() {
    return _stack.size() == _stack.max_size();
}

#endif //CHAPTER4_STACK_H
