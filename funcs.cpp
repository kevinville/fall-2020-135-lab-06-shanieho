#include <iostream>
#include "funcs.h"

using namespace std;

// add functions here

void test_ascii(string s){
    for (int i = 0; i < s.length(); i ++){
        cout << s[i] << " " << (int)s[i] <<endl;
    }
    cout << endl;
}