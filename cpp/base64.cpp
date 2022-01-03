#include <cstdlib>
#include <string>
#include "helper.hpp"
#include "base64.hpp"
#include "decimal.hpp"
#include "binary.hpp"

char base64Key(int val)
{
  if (val < 26)
  {
    return 'A' + val;
  }
  else if (val < 52)
  {
    return 'a' + (val - 26);
  }
  else if (val < 62)
  {
    return '0' + (val - 52);
  }
  else if (val == 62)
  {
    return '-';
  }
  else if (val == 63)
  {
    return '_';
  }
  else
  {
    return '\0';
  }
}

int base64Value(char c)
{
  switch (c)
  {
  case '0':
    return 0;
  case '1':
    return 1;
  case '2':
    return 2;
  case '3':
    return 3;
  case '4':
    return 4;
  case '5':
    return 5;
  case '6':
    return 6;
  case '7':
    return 7;
  case '8':
    return 8;
  case '9':
    return 9;
  case 'A':
    return 10;
  case 'B':
    return 11;
  case 'C':
    return 12;
  case 'D':
    return 13;
  case 'E':
    return 14;
  case 'F':
    return 15;
  case 'G':
    return 16;
  case 'H':
    return 17;
  case 'I':
    return 18;
  case 'J':
    return 19;
  case 'K':
    return 20;
  case 'L':
    return 21;
  case 'M':
    return 22;
  case 'N':
    return 23;
  case 'O':
    return 24;
  case 'P':
    return 25;
  case 'Q':
    return 26;
  case 'R':
    return 27;
  case 'S':
    return 28;
  case 'T':
    return 29;
  case 'U':
    return 30;
  case 'V':
    return 31;
  case 'W':
    return 32;
  case 'X':
    return 33;
  case 'Y':
    return 34;
  case 'Z':
    return 35;
  case 'a':
    return 36;
  case 'b':
    return 37;
  case 'c':
    return 38;
  case 'd':
    return 39;
  case 'e':
    return 40;
  case 'f':
    return 41;
  case 'g':
    return 42;
  case 'h':
    return 43;
  case 'i':
    return 44;
  case 'j':
    return 45;
  case 'k':
    return 46;
  case 'l':
    return 47;
  case 'm':
    return 48;
  case 'n':
    return 49;
  case 'o':
    return 50;
  case 'p':
    return 51;
  case 'q':
    return 52;
  case 'r':
    return 53;
  case 's':
    return 54;
  case 't':
    return 55;
  case 'u':
    return 56;
  case 'v':
    return 57;
  case 'w':
    return 58;
  case 'x':
    return 59;
  case 'y':
    return 60;
  case 'z':
    return 61;
  case '-':
    return 62;
  case '_':
    return 63;
  default:
    return -1;
  }
}


std::string *binaryToBase64(std::string *binStr)
{
  unsigned long binary = binaryToDecimal(binStr);
  std::string *base64Str = decimalToBase64(binary);
  return base64Str;
}

std::string *hexToBase64(std::string *hexStr){
  unsigned long decimal = hexToDecimal(hexStr);
  std::string *base64Str = decimalToBase64(decimal);
  return base64Str;
}

std::string *octalToBase64(std::string *octStr){
  unsigned long decimal = octalToDecimal(octStr);
  std::string *base64Str = decimalToBase64(decimal);
  return base64Str;
}

std::string *decimalToBase64(unsigned long decimal)
{
  std::string * base64Str = new std::string(32, '\0');
  // char *base64Str = malloc(sizeof(char) * 32);
  int i = 0;
  while (decimal > 0)
  {
    base64Str[i] = base64Key(decimal % 64);
    decimal /= 64;
    i++;
  }
  base64Str[i] = '\0';
  reverse(base64Str);
  return base64Str;
}