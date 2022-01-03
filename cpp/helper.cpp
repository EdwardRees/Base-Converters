#include "helper.hpp"
#include <cstdlib>
#include <string>

int getBase(std::string str)
{
  int len = str.length();
  if (len > 2 && str[0] == '0')
  {
    switch (str[1])
    {
    case 'b':
      return 2;
    case 'o':
      return 8;
    case 'd':
      return 10;
    case 'x':
      return 16;
    case '+':
      return 64;
    default:
      return 10;
    }
  }
  return 10;
}

void reverse(std::string* str)
{
  int len = (*str).length();
  int i;
  for (i = 0; i < len / 2; i++)
  {
    char temp = (*str)[i];
    (*str)[i] = (*str)[len - i - 1];
    (*str)[len - i - 1] = temp;
  }
}