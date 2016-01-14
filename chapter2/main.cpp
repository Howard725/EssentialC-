#include <iostream>
#include <vector>
#include <stdlib.h>
#include <bits/stl_algo.h>

using namespace std;

template<typename T>
void display_message(const string &msg, const vector<T> &vec) {
    cout << msg;
    for (int ix = 0; ix < vec.size(); ++ix) {
        cout << vec[ix] << ' ';
    }
    cout << endl;
}

inline bool pent_valid(int n_elems, const vector<int> &seq) {
    if (n_elems <= 0 || n_elems > 10000 || seq.size() > n_elems)
        return false;
    else
        return true;
}

bool pent_seq(int n_elems, vector<int> &seq) {
    pent_valid(n_elems, seq);
    for (int ix = seq.size() + 1; ix <= n_elems; ++ix) {
        seq.push_back(ix * (3 * ix - 1) / 2);
    }
    return true;
}

template<typename T>
void display_vector(const vector<T> &seq, const string type) {
    cout << "The type of vector is " << type << endl;
    for (int ix = 0; ix < seq.size(); ++ix) {
        cout << seq[ix] << '\t';
    }
    cout << endl;

}

const vector<int> *pent_seq_ptr(int n_elems) {
    if (n_elems <= 0 || n_elems > 10000)
        return NULL;

    static vector<int> pent_seq;
    if (pent_seq.size() < n_elems) {
        for (int ix = pent_seq.size() + 1; ix <= n_elems; ++ix)
            pent_seq.push_back(ix * (3 * ix - 1) / 2);
    }
    return &pent_seq;
}

int pick_pent(int position, const vector<int> *pent_ptr) {
    if (position <= 0 || position > 10000)
        return -1;
    if (pent_ptr && (*pent_ptr).size() >= position)
        return (*pent_ptr)[position];
    else
        return (*pent_seq_ptr(position))[position - 1];
}

inline int max(int a, int b) {
    return a > b ? a : b;
}

inline float max(float a, float b) {
    return a > b ? a : b;
}

inline string max(string a, string b) {
    return a > b ? a : b;
}

inline int max(const vector<int> &vec){
    return *max_element(vec.begin(), vec.end());
}

int main() {
    /* exc2_2 exc2_3
    vector<int> elem_seq;
    int n_seq = 0;
    cout << "Please specify the number of elements: ";
    cin >> n_seq;
    if (!pent_seq(n_seq, elem_seq))
        exit(-1);
    display_vector(elem_seq, "int");
     */

    int position = 0;
    const vector<int> *pent_seq = pent_seq_ptr(1);
    cout << "Please specify the positioin of pent_seq: ";
    cin >> position;
    cout << pick_pent(position, pent_seq) << endl;

    system("pause");

    return 0;
}