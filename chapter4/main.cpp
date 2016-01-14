#include <iostream>
#include <stdlib.h>
#include "Stack.h"
#include "Global.h"
//#include "UserProfile.h"
#include "Matrix.h"

using namespace std;

string Global::_program_name;
string Global::_version_stamp;
int Global::_version_number;
int Global::_tests_run;
int Global::_tests_passed;

bool ex4_1() {
    Stack st;
    string word;

    while ( (cin >> word) && word != "q" )
    //while  ( cin >> word )
    {
        if ( st.full() )
            break;
        st.push(word);
    }
//    while ( st.pop(word) )
//    {
//        cout << word << endl;
//    }
    while ( cin >> word  && word != "q")
    {
        cout << st.find(word) << endl;
    }
    while ( cin >> word && word != "q")
    {
        cout << st.count(word) << endl;
    }

    return true;
}

bool ex4_3(){
    //class Global test
    Global::program_name("class Global test...");
    cout << Global::program_name() << endl;
    return true;
}

/*istream& operator>>(istream& is, UserProfile &rhs){
    string loggin, level, user_name;
    is >> loggin >> level >> user_name;

    rhs.loggin(loggin);
    rhs.level(level);
    rhs.user_name(user_name);

    int times_loggin, guesses, correct_guesses;
    rhs.times_loggin(times_loggin);
    rhs.guesses(guesses);
    rhs.correct_guesses(guesses);
}

ostream& operator<<(ostream& os, UserProfile &rhs){
    os << "loggin:  " << rhs.loggin()
    << "level:  " << rhs.level()
    << "user_name:  " << rhs.user_name()
    << "times_loggin:   " << rhs.times_loggin()
    << "guesses:    " << rhs.guesses()
    << "correct_guesses:    " << rhs.correct_guesses()
    << "correct_percent:    " << rhs.correct_percent() << "%"
    << endl;
}

void ex4_4(){
    //class UserProfile test
    UserProfile anon;
    cout << anon;
    UserProfile anon2;
    cout << anon2;
}*/

void ex4_5(){
    //创建一个空Matrix
    Matrix matrix1(1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1);
    matrix1.print();

    //使用一个数组创建一个Matrix
    float array[] = { 1, 2, 3, 4,
                      5, 6, 7, 8,
                      9, 10, 11, 12,
                      13, 14, 15, 16};
    Matrix matrix2(array);
    matrix2.print();

    Matrix matrix3 = matrix1 + matrix2;
    matrix3.print();

    Matrix matrix4 = matrix1 * matrix2;
    matrix4.print();

    matrix1 += matrix2;
    matrix1.print();
}

int main() {
//    cout << ex4_1() << endl;
//    cout << (ex4_3() ? "succeed!" : "failed!" ) << endl;
//    ex4_4();
    ex4_5();

    system("PAUSE");
    return 0;
}

