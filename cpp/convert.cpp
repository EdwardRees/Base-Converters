#include "helper.hpp"
#include "decimal.hpp"
#include <string>
#include <iostream>
// #include <boost/multiprecision/cpp_int.hpp>


using namespace std;

int main(void){
  // string str = "0b123";
  // cout << "str: " << str << endl;
  // int base = getBase(str);
  // cout << "base: " << base << endl;
  // reverse(&str);
  // cout << "str: " << str << endl;
  string str;
  cout << "Enter a binary number: ";
  cin >> str;
  cout << "binary to decimal: " << binaryToDecimal(&str) << endl;
  cout << "Enter a hex number: ";
  cin >> str;
  cout << "hex to decimal: " << hexToDecimal(&str) << endl;
  // cout << hexToDecimal(&str) << endl;
  // convert(base, str);
  // cout << "str: " << str << endl;
  return 0;
}