#include <iostream>
using namespace std;
#include "decrypt.h"

string decryptCaesar(string ciphertext, int rshift){
    string decrypt = "";
    int ascii = 0;
    for (int i = 0; i < ciphertext.length(); i ++){
        if (!isalpha(ciphertext[i])){
            decrypt += ciphertext[i];
        }
        else{
            ascii = (int)ciphertext[i] - rshift;
            if(isupper(ciphertext[i])){
                if (ascii < 65){
                    ascii = ascii + 26;
                }
                decrypt += char(ascii);
            }
            else{
                if (ascii < 97){
                    ascii += 26;
                }
                decrypt += char(ascii);
            }
        }
    }
    return decrypt;
}

string decryptVigenere(string ciphertext, string keyword){
    string decrypt = "";
    int key = 0;
    int keyIndex = 0;
    int ascii = 0;
    for (int i = 0; i < ciphertext.length(); i ++){
        if(isalpha(ciphertext[i])){
            key = keyIndex % keyword.length();
            ascii = (int)ciphertext[i] - (int)(keyword[key] - 97) ;
            if (isupper(ciphertext[i]) && ascii < 65){
                ascii += 26;
            }
            else if (islower(ciphertext[i]) && ascii < 97){
                ascii += 26;
            }
            decrypt += char(ascii);
            keyIndex ++;
        }
        else{
            decrypt += ciphertext[i];
        }
    }
    return decrypt;
}

