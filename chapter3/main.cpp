#include <iostream>
#include <vector>
#include <stdlib.h>
#include <algorithm>
#include <map>
#include <set>
#include <fstream>
#include <iterator>

using namespace std;

vector<int> less_than_10(const vector<int> &vec) {
    vector<int> nvec;
    for (int ix = 0; ix < vec.size(); ++ix) {
        if (vec[ix] < 10)
            nvec.push_back(vec[ix]);
    }
    return nvec;
}

/*
template <typename InputIterator, typename OutputIterator, typename ElemType, typename Comp>
OutputIterator filter( InputIterator first, InputIterator last, OutputIterator at, const ElemType &val, Comp pred)
{
    while (( first = find_if( first, last, bind2nd(pred, val))) != last)
    {
        *at++ = *first++;
    }
    return at;
};
 */

template<typename InputIterator, typename OutputType, typename OutputIterator, typename ElemType, typename Comp>
OutputType
sub_container(InputIterator first, InputIterator last, OutputType &local_ctn, OutputIterator local_ctn_begin,
              const ElemType &val, Comp pred) {
    copy(first, last, local_ctn_begin);
    sort(first, last, not2(pred));

    OutputIterator iter = find_if(local_ctn_begin, local_ctn.end(), bind2nd(pred, val));
    local_ctn.erase(iter, local_ctn.end());

    return local_ctn;
};

template<typename InputIterator, typename OutputIterator, typename ElemType, typename Comp>
OutputIterator
filter(InputIterator first, InputIterator last, OutputIterator at, const ElemType &val, Comp pred) {
    while ((first = find_if(first, last, bind2nd(pred, val))) != last) {
        cout << "found value: " << *first << endl;
        *at++ = *first++;
    }
    return at;
};

void initialize_exlusion_set(set<string> &exclusion) {
    static string _excluded_words[6] = {
            "a", "an", "or", "the", "and", "but"
    };
    exclusion.insert(_excluded_words, _excluded_words + 6);
}

void process_file(ifstream &infile, const set<string> &exclusion, map<string, int> &words) {
    string word;

    while (infile >> word) {
        if (exclusion.count(word))
            continue;
        words[word]++;
    }
}

void query_word(const map<string,int> &words){
    map<string, int>::const_iterator iter;
    string word;

    cout << "Please type in word you wanna check, if you like. Type in EOF otherwise: " << endl;
    while (cin >> word) {
        if ((iter = words.find(word)) != words.end())
            cout << "Yes, it exists in the file. It shows " << iter->second << " times." << endl;
        else
            cout << "No, it does'n exist in the file." << endl;
    }
}

void print_words_count(const map<string, int> &words){

    map<string,int>::const_iterator iter;

    cout << "The words list: " << endl;
    for (iter = words.begin(); iter != words.end(); iter++) {
        cout << iter->first << "\t" << iter->second << endl;
    }

}


bool ex3_1() {
    ifstream infile("MooCat.txt");
    if (!infile)
        return false;

    map<string, int> words;
    set<string> exclusion;

    initialize_exlusion_set(exclusion);

    process_file(infile, exclusion, words);

    //function query_word
    query_word(words);

    //function print words count
    print_words_count(words);

    return true;
}

void load_file( ifstream &infile, vector<string> &vec){
    string word;
    while ( infile >> word )
        vec.push_back(word);
}

class less_than {
public:
    bool operator() (const string & s1, const string s2){
        return s1.size() < s2.size();
    }
};

void display_sorted_words(const vector<string> &vec){
    for ( int ix = 0; ix < vec.size(); ++ix )
        cout << vec[ix] << " ";
    cout << endl;
}

template <typename elemType>
void display_vector( const vector<elemType> &vec, ostream &os = cout, int len = 8)
{
    typename vector<elemType>::const_iterator
            iter = vec.begin(),
            iter_end = vec.end();

    int elem_cnt = 1;
    while (iter != iter_end){
        os << *iter++ << ( ! ( elem_cnt++ % len) ? '\n' : ' ');
    }
    os << endl;
}

bool ex3_2() {
    ifstream infile("MooCat.txt");
    if (!infile)
        return false;

    vector<string> words_vec;

    //function load_file
    load_file(infile, words_vec);

    //sort words_vec;
    sort(words_vec.begin(), words_vec.end(), less_than());

    //display words_vec;
    display_sorted_words(words_vec);
    display_vector(words_vec, cout);
}

void init_families(map<string, set<string>> &families)
{
    string firstName, lastName;

    cout << "Please enter first name(q to quit): " << endl;
    while ( (cin >> firstName) && firstName != "q" ){
        if (families[firstName].empty())
            cout << firstName << " didn't exist. Please enter last names";
        else
            cout << firstName << " already exists. Please enter last names";
        cout << "(q to quit): " << endl;
        while ( (cin >> lastName) && lastName != "q" ){
            if ( families[firstName].count(lastName))
                cout << lastName << " already exits. Please try another, or q to quit: " << endl;
            else
                families[firstName].insert(lastName);
        }
        cout << "Please enter first name(q to quit): " << endl;
    }
}

void family_query(const map<string, set<string>> &families){
    if ( families.empty())
        return;
    string firstName;
    map<string, set<string>>::const_iterator iter;
    cout << "Type in the family's first name you wanna know(q to quit): " << endl;

    while ( (cin >> firstName) && firstName != "q" ){
        if ( ( iter = families.find(firstName)) != families.end() ){
            cout << "Family's first name: " << iter->first << endl;
            set<string>::iterator iter_lastNames = iter->second.begin();
            cout << "Family's last names: ";
            while ( iter_lastNames != iter->second.end())
                cout << *iter_lastNames++ << '\t';
            cout << endl;
        }
        cout << "Type in the family's first name you wanna know(q to quit): " << endl;
    }

}

bool ex3_3() {
    map<string, set<string>> families;

    //initialize families
    init_families(families);

    //user query
    family_query(families);
}

bool ex3_4() {
    ofstream odd_out("odd_numbers.txt"), even_out("even_numbers.txt");
    if ( ! odd_out || ! even_out )
        return false;

    istream_iterator<int> is(cin), eof;
    ostream_iterator<int> os_odd(odd_out, " "), os_even(even_out, " ");

    vector<int> numbers;

    //load numbers from cin
    copy(is, eof, back_inserter(numbers));

    //
    vector<int>::iterator
        iter = numbers.begin(),
        iter_end = numbers.end();
    while ( iter != iter_end ){
        if ( (*iter) % 2 )
            copy(iter, iter+1, os_odd);
        else
            copy(iter, iter+1, os_even);
        iter++;
    }

    return true;
}

int main() {
    cout << "Hello, World!" << endl;

    /*
    const int arr_size = 5;
    int array[arr_size] = { 1, 5, 10, 22, 32};
    vector<int> vec_seq(array, array + arr_size);
    vector<int> vec_res(vec_seq);

    sub_container(vec_seq.begin(), vec_seq.end(), vec_res, vec_res.begin(), 30, greater<int>());

    system("PAUSE");

    const int elem_size = 8;
    int ia[elem_size] = { 12, 8, 43, 0, 6, 21, 3, 7 };
    vector<int> ivec( ia, ia + elem_size);

    int ia2[elem_size];
    vector<int> ivec2(elem_size);

    filter( ia, ia+elem_size, ia2, elem_size, less<int>() );

    filter( ivec.begin(), ivec.end(), ivec2.begin(), elem_size, greater<int>());

    system("PAUSE");
    */

    /*
    map<string, int> words;
    string tword;
    while ( cin >> tword )
        words[tword]++;

    int count = words.count("hello");

     */
    //cout << ex3_1() << endl;
    //cout << ex3_2() << endl;
    //cout << ex3_3() << endl;
    cout << ex3_4() << endl;

    system("PAUSE");

    return 0;
}