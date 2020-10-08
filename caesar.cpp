#include <iostream>
#include "caesar.h"

using namespace std;

char shiftChar (char c, int rshift){
    char newCh;
    if (!isalpha(c) || isspace(c)){
        newCh = c;
    }
    int ascii = 0;
    if (isupper(c)){
        ascii = ((int)c + rshift);
        while (ascii >90){
            ascii = ascii - 26;
        }
        newCh = char(ascii);
        }
    else if (islower(c)){
        ascii = ((int)c + rshift);
        while (ascii > 122){
            ascii = ascii - 26;
        }
        newCh = char(ascii);
    }
    return newCh;
}

string encryptCaesar(string plaintext, int rshift){
    string encrypt = "";
    for (int i = 0; i < plaintext.length(); i++){
        encrypt += shiftChar(plaintext[i], rshift);
    }
    return encrypt;
}
