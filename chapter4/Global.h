//
// Created by Administrator on 2015/12/30.
//

#ifndef CHAPTER4_GLOBAL_H
#define CHAPTER4_GLOBAL_H

#include <String>

using namespace std;

class Global {

public:
    static void program_name( const string& npn ){
        _program_name = npn;
    }
    static string program_name(){
        return _program_name;
    }

    static void version_stamp( const string & nvs ){
        _version_stamp = nvs;
    }
    static string version_stamp() {
        return _version_stamp;
    }

    static void version_number( int nval ){
        _version_number = nval;
    }
    static int version_number() {
        return _version_number;
    }

    static void tests_run( int nval ){
        _tests_run = nval;
    }
    static int tests_run() {
        return _tests_run;
    }

    static void tests_passed( int nval ) {
        _tests_passed = nval;
    }
    static int tests_passed() {
        return _tests_passed;
    }

private:
    static string _program_name;
    static string _version_stamp;
    static int _version_number;
    static int _tests_run;
    static int _tests_passed;
};

/*string Global::_program_name;
string Global::_version_stamp;
int Global::_version_number;
int Global::_tests_run;
int Global::_tests_passed;*/


#endif //CHAPTER4_GLOBAL_H
