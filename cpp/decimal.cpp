#include <cstdlib>
#include <cstring>
#include <string>
#include <math.h>
#include "helper.hpp"
#include "decimal.hpp"
#include "base64.hpp"
#include <iostream>

unsigned long binaryToDecimal(std::string *binStr)
{
  unsigned long decimal = 0;
  for (int i = 0; i < binStr->length(); i++)
  {
    if (binStr->at(i) == '1')
    {
      decimal += (unsigned long)pow(2, binStr->length() - i - 1);
    }
  }
  return decimal;
}

unsigned long octalToDecimal(std::string *octStr)
{
  unsigned long decimal = 0;
  for (int i = 0; i < octStr->length(); i++)
  {
    char val = octStr->at(i);
    decimal += (unsigned long)((val - '0') * pow(8, octStr->length() - i - 1));
  }
  return decimal;
}

unsigned long hexToDecimal(std::string *hexStr)
{
  unsigned long decimal = 0;
  for (int i = 0; i < hexStr->length(); i++)
  {
    char val = hexStr->at(i);
    if (val >= '0' && val <= '9')
    {
      decimal += (unsigned long)((val - '0') * pow(16, hexStr->length() - i - 1));
    }
    else if (val >= 'a' && val <= 'f')
    {
      decimal += (unsigned long)((val - 'a' + 10) * pow(16, hexStr->length() - i - 1));
    }
    else if (val >= 'A' && val <= 'F')
    {
      decimal += (unsigned long)((val - 'A' + 10) * pow(16, hexStr->length() - i - 1));
    }
  }
  return decimal;
}

unsigned long base64ToDecimal(std::string *base64Str)
{
  unsigned long decimal = 0;
  const char* str = base64Str->c_str();
  for (int i = 0; i < base64Str->length(); i++)
  {
    char val = str[i];
    decimal += base64Value(val) * (unsigned long) (pow(64, base64Str->length() - i - 1));
  }
  return decimal;
}