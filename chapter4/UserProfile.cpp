//
// Created by Administrator on 2015/12/30.
//

#include "UserProfile.h"

#include <stdio.h>
#include <iterator>

UserProfile::UserProfile()
        : _loggin("guest"), _times_loggin(1), _guesses(0), _correct_guesses(0), _level(Beginner){
    static int loggin_sequence = 1;
    char buffer[10];
    sprintf( buffer, "%d", loggin_sequence );
    _loggin += loggin_sequence;
}

/*void UserProfile::init_level_map() {
    _level_map["Beginner"] = Beginner;
    _level_map["Intermediate"] = Intermediate;
    _level_map["Advanced"] = Advanced;
    _level_map["Guru"] = Guru;
}*/

void UserProfile::level(const string& level) {
    if ( _level_map.empty() )
        init_level_map();

    map<string, uLevel>::iterator itr = _level_map.begin();
    _level = (itr = _level_map.find(level)) == _level_map.end() ? Beginner : itr->second;
}

string UserProfile::level() const {
    static string level_str[] = {
        "Beginner",
        "Intermediate",
        "Advanced",
        "Guru"
    };

    return level_str[_level];
}

