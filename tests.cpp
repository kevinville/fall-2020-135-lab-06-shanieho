#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"
#include "funcs.h"
#include "caesar.h"
#include "vigenere.h"
#include "decrypt.h"
#include "decode.h"

// add your tests here
TEST_CASE("small rshift"){
    CHECK(encryptCaesar("Way to Go!", 5) == "Bfd yt Lt!");
    CHECK(encryptCaesar("Good morning", 2) == "Iqqf oqtpkpi");
    CHECK(encryptCaesar("hi :)", 0 )== "hi :)");
}

TEST_CASE("large rshift"){
    CHECK(encryptCaesar("Hello, World!",10) == "Rovvy, Gybvn!");
    CHECK(encryptCaesar("Good morning", 25) == "Fnnc lnqmhmf");
    CHECK(encryptCaesar("Good afternoon", 26) == "Good afternoon");
}

TEST_CASE("viginere"){
    CHECK(encryptVigenere("Hello, World!", "cake") == "Jevpq, Wyvnd!");
    CHECK(encryptVigenere("hi", "ab") == "hj");
    CHECK(encryptVigenere("hi", "abcdefg") == "hj");  
    CHECK(encryptVigenere("1 2 3 ", "ab") == "1 2 3 ");     
}

TEST_CASE("decrypt caesar"){
    CHECK(decryptCaesar("Rovvy, Gybvn!", 10) == "Hello, World!");
    CHECK(decryptCaesar("Fnnc lnqmhmf", 25) == "Good morning"); 
    CHECK(decryptCaesar("Good afternoon", 26) == "Good afternoon");       
    CHECK(decryptCaesar("hi :)", 0) == "hi :)"); 
    CHECK(decryptCaesar("Iqqf oqtpkpi", 2) == "Good morning");   
    CHECK(decryptCaesar("Bfd yt Lt!", 5) == "Way to Go!");
    CHECK(decryptCaesar("Good afternoon", 78) == "Good afternoon");
}

TEST_CASE("decrypt vigenere"){
    CHECK(decryptVigenere("Jevpq, Wyvnd!", "cake") == "Hello, World!");
    CHECK(decryptVigenere("hj", "abcdefg") == "hi");
    CHECK(decryptVigenere("1 2 3 ", "cake") == "1 2 3 ");  
    CHECK(decryptVigenere("1 2 3 ", "a") == "1 2 3 ");  
}

TEST_CASE("decode phrases"){
    CHECK(decode("bmfy f btsijwkzq ynrj ny nx yt gj fqnaj wnlmy stb") == "what a wonderful time it is to be alive right now");
    CHECK(decode("Bmfy f btsijwkzq ynrj ny nx yt gj fqnaj wnlmy stb!") == "What a wonderful time it is to be alive right now!");
    CHECK(decode("Q tqsm twvo eitsa ib bpm jmikp epqtm eibkpqvo bpm acvamb") == "I like long walks at the beach while watching the sunset");

}