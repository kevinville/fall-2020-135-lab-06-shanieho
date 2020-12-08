#include <iostream>
#include "funcs.h"
#include "caesar.h"
#include "vigenere.h"
#include "decrypt.h"
#include "decode.h"

// Replaced all endl with \n
// Added comments and refined main to look visually appealing when run (not saying it wasn't :o)
// Removed namespace std


int main()
{
  // Testing ASCII
  std::cout << "Testing ASCII with phrase 'Good Morning'\n";
  test_ascii("Good morning!");

  std::cout << "\nTesting ASCII with phrase 'Cat :3 Dog'\n";
  test_ascii("Cat :3 Dog");

  std::cout << "Testing ASCII with phrase   5  67   8'\n";
  test_ascii("  5  67   8");

  // Testing Caesar Encryption
  std::cout << "\nTesting Caesar Encryption\n";
  std::string a = encryptCaesar("Way to Go!", 5);
  std::cout << "\n";

  cout << "Way to Go! encrypted with a right shift of 5 is: " << a << "\n";
  a = encryptCaesar("Wow", 3);

  cout << "\nWow encrypted with a right shift of 3 is: " << a <<"\n";
  a = encryptCaesar("Wow", -1);

  cout << "\nWow encrypted with right shift of -1 is: " << a <<"\n";
  a = encryptCaesar("Wow", 52);

  cout << "\nWow encrypted with right shift of 52 is: " << a <<"\n";

  // Testing Viginere Encryption
  std::string b = encryptVigenere("Hello, World!","cake");
  cout << "\nTesting Viginere on phrase 'Hello World' and code 'cake': "<< b << "\n";

  b = encryptVigenere("Good Morning!", "afternoon");
  cout << "Testing Viginere on phrase 'Good Morning!' and code 'afternoon': " << b <<"\n";

  // Testing Caesar Decryption
  std::cout << "\nTesting Caesar Decryption on phrase 'Rovvy, Gybvn!' with rotation of 10: ";
  std::string c = decryptCaesar("Rovvy, Gybvn!", 10);
  std::cout << c <<"\n";
  std::cout << "Testing Caesar Decryption on phrase 'Iqqf oqtpkpi' with rotation of 2: ";
  c = decryptCaesar("Iqqf oqtpkpi", 2);
  std::cout << c <<"\n";

  // Testing Viginere Decryption
  std::cout << "\nTesting Viginere Decryption on phrase 'Jevpq, Wyvnd!' with phrase 'cake': ";
  std::string d = decryptVigenere("Jevpq, Wyvnd!", "cake");
  std::cout << d <<"\n";
  std::cout << "Testing Viginere Decryption on phrase '1 2 3' with phrase 'cake': ";
  d = decryptVigenere("1 2 3 ", "cake");
  std::cout << d <<"\n";
  
  // Testing Caesar Encryption
  std::cout << "\nCaesar Encrypting the phrase 'what a wonderful time it is to be alive right now' with a rotation of 5\n";
  std::string f = encryptCaesar("what a wonderful time it is to be alive right now",5);
  std::cout << f <<"\n";
  std::cout << "\nCaesar Encrypting the phrase 'I like long walks at the beach while watching the sunset' with a rotation of 8\n";
  f = encryptCaesar("I like long walks at the beach while watching the sunset", 8);
  std::cout << f << "\n\n";

  // Testing Decode
  std::cout << "Decoding the previous 2 Phrases:\n";
  std::string e = decode("bmfy f btsijwkzq ynrj ny nx yt gj fqnaj wnlmy stb");
  std::cout << e << "\n";
  e = decode ("Q tqsm twvo eitsa ib bpm jmikp epqtm eibkpqvo bpm acvamb");
  std::cout << e <<"\n\n";
  
  return 0;
}
