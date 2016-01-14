//
// Created by WangHoward on 16/1/13.
//

#include "Stack.h"

ostream& operator<<(ostream& os, const Stack &stack)
{ stack.print(os); return os; }
