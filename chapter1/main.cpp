#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>

using namespace std;

int exc_1_7 ()
{
    vector<string> strs_in;
    string str_in;

    ifstream infile("text.txt");
    if ( !infile )
    {
        cerr << "The input file \"text.txt\" cannot be opened!" << endl;
        return -1;
    }

    ofstream outfile("text_sorted.txt");
    if ( !outfile )
    {
        cerr << "The output file \"text_sorted.txt\" cannot be opened!" << endl;
        return -2;
    }

    while ( infile >> str_in)
    {
        cout << str_in << endl;
        strs_in.push_back(str_in);
    }

    sort ( strs_in.begin(), strs_in.end() );

    for ( int ix = 0; ix < strs_in.size(); ++ix)
    {
        outfile << strs_in[ix] << ' ';
    }
    outfile << endl;

    return 0;

}

int exc_1_8()
{
    const int max_tries = 3;
    string responses[max_tries] = {
            "opps! your first time!",
            "oh no! your second time!",
            "unfortunately. you failed."
    };

    for ( int ix = 0; ix < max_tries; ++ix )
    {
        cout << responses[ix] << endl;
    }
    return 0;
}

int main() {
   // int res = exc_1_7();
   // cout << res << endl;
    int res = exc_1_8();
    return 0;
}