//
// Created by Administrator on 2015/12/30.
//

#ifndef CHAPTER4_USERPROFILE_H
#define CHAPTER4_USERPROFILE_H

using namespace std;

#include <list>
#include <string>
#include <map>

class UserProfile {
public:
    enum uLevel { Beginner, Intermediate, Advanced, Guru };
    UserProfile(string loggin, uLevel level = Beginner);
    UserProfile();
    bool operator==(const UserProfile& rhs);
    bool operator!=(const UserProfile& rhs);

    //读取数据
    string loggin() const { return _loggin; }
    string user_name() const { return _user_name; }
    int times_loggin() const { return _times_loggin; }
    int guesses() const { return _guesses; }
    int correct_guesses() const { return _correct_guesses; }
    string level() const;
    double correct_percent() const;

    //写入数据
    void loggin( const string& loggin ) { _loggin = loggin; }
    void user_name( const string& user_name ) { _user_name = user_name; }
    void times_loggin( int val ) { _times_loggin = val; }
    void guesses( int val ) { _guesses = val; }
    void correct_guesses( int val ) { _correct_guesses = val; }
    void level(const string& level );

private:
    string _loggin;
    string _user_name;
    int _times_loggin;
    int _guesses;
    int _correct_guesses;
    uLevel _level;

    static map<string, uLevel> _level_map;
    static void init_level_map();

};

inline UserProfile::UserProfile(string loggin, uLevel level)
    : _loggin(loggin), _times_loggin(1), _guesses(0), _correct_guesses(0), _level(Beginner){}

inline bool UserProfile::operator==(const UserProfile& rhs){
    if ( _loggin == rhs._loggin && _user_name == rhs._loggin )
        return true;
    return false;
}

inline bool UserProfile::operator!=(const UserProfile &rhs) {
    return !(*this == rhs);
}

inline double UserProfile::correct_percent() const {
    if (_guesses == 0)
        return (double)0.0;
    return (double)_correct_guesses/(double)_guesses * 100;
}

#endif //CHAPTER4_USERPROFILE_H
