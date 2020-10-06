#include <iostream>
using namespace std;
#include "vigenere.h"

string encryptVigenere (string plaintext, string keyword){
    string encrypt = "";
    int keyIndex = 0;
    int key = 0;
    int ascii = 0;
    for (int i = 0; i < plaintext.length(); i ++){
        if (isalpha(plaintext[i])){
           
            key = keyIndex % keyword.length();   //key is used to keep the string keyword repeating,
                                                //since it is in a pattern of the length of keyword
                                                //we can use mod to know which letter of the keyword it is in
                                                //for ex: if keyword has a length of 4, and we are on 5th letter, we would have to use the 
                                                //1st letter of keyword and we can use mod to access that
            ascii = (int)(plaintext[i]) + (int)(keyword[key]-97);   //subtract 97 to indicate the number of
                                                                    //shifts based on the letter in keyword
            if (isupper(plaintext[i]) && ascii > 90){ //used to loop around from A-Z only
                ascii = ascii - 26;
            }
            if (islower(plaintext[i])&& ascii > 122){   //used to loop around from a-z only
                ascii = ascii - 26;
            }
            encrypt += char(ascii);
            keyIndex++;
        }
        else{
            encrypt += plaintext[i];    //used for non alpha characters
        }
    }
    return encrypt;
}