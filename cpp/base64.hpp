#include <string>

char base64Key(int val);
int base64Value(char c);

std::string *binaryToBase64(std::string *binStr);
std::string *hexToBase64(std::string *hexStr);
std::string *octalToBase64(std::string *octStr);
std::string *decimalToBase64(unsigned long decimal);