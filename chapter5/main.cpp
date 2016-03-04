#include <iostream>
#include <stdlib.h>
#include "LIFO_Stack.h"
#include "Peekback_Stack.h"

using namespace std;

istream& operator>>( istream& is, LIFO_Stack& lifo_stack )
{
    elemType elem;
    while( is >> elem )
    {
        if ( ! lifo_stack.push(elem) )
            break;
    }
    return is;
}

void ex5_1_1()
{
    //初始化一个LIFO_Stack
    LIFO_Stack lifo_stack;
    //输入操作
    cin >> lifo_stack;
    //输出操作
    lifo_stack.print(cout);
    //pop操作
    elemType elem;
    if ( lifo_stack.pop(elem) )
    {
        cout << "poped: " << elem << endl;
    }
    else
    {
        cout << "an error occure during pop. " << endl;
    }
    //输出操作
    lifo_stack.print(cout);
}

void ex5_1_2()
{
    Peekback_Stack peekback_stack;
    string elem;
    while (cin >> elem && elem != "q" )
    {
        peekback_stack.push(elem);
    }
    peekback_stack.print(cout);
    if ( peekback_stack.pop(elem) )
        cout << "poped: " << elem << endl;
    else
        cout << "pop failed. " << endl;

    peekback_stack.print(cout);

    int index;
    cout << "type the peed index: ";
    cin >> index;
    if ( peekback_stack.peek(index, elem))
        cout << "peek index = " << index << ", elem = " << elem << endl;
    else
        cout << "peek failed." << endl;

    return;
}

int main() {
    cout << "Hello, World!" << endl;
//    ex5_1_1();
    ex5_1_2();

    system("PAUSE");
    return 0;
}