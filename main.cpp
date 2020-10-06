#include <iostream>

using namespace std;

#include "funcs.h"
#include "caesar.h"
#include "vigenere.h"
#include "decrypt.h"

int main()
{
  test_ascii("Good morning!");
  test_ascii("Cat :3 Dog");
  test_ascii("  5  67   8");

  string a = encryptCaesar("Way to Go!", 5);
  cout << "Way to Go! encrypted with a right shift of 5 is: " << a <<endl;
  a = encryptCaesar("Wow", 3);
  cout << "Wow encrypted with a right shift of 3 is: " << a <<endl;
  a = encryptCaesar("Wow", -1);
  cout << "Wow encrypted with right shift of -1 is: " << a <<endl;

  string b = encryptVigenere("Hello, World!","cake");
  cout << b<< endl;
  b = encryptVigenere("Good Morning!", "afternoon");
  cout << b <<endl;

  string c = decryptCaesar("Rovvy, Gybvn!", 10);
  cout << c <<endl;
  c = decryptCaesar("Iqqf oqtpkpi", 2);
  cout << c <<endl;

  string d = decryptVigenere("Jevpq, Wyvnd!", "cake");
  cout << d <<endl;
  d = decryptVigenere("1 2 3 ", "cake");
  cout << d <<endl;
  
  return 0;
}
