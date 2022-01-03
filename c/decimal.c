#include <stdlib.h>
#include <string.h>
#include <math.h>
#include "helper.h"
#include "decimal.h"
#include "base64.h"

unsigned long binaryToDecimal(char *binStr)
{
  unsigned long decimal = 0;
  for (int i = 0; i < strlen(binStr); i++)
  {
    if (binStr[i] == '1')
    {
      decimal += pow(2, strlen(binStr) - i - 1);
    }
  }
  return decimal;
}

unsigned long octalToDecimal(char *octStr)
{
  unsigned long decimal = 0;
  for (int i = 0; i < strlen(octStr); i++)
  {
    char val = octStr[i];
    decimal += (val - '0') * pow(8, strlen(octStr) - i - 1);
  }
  return decimal;
}

unsigned long hexToDecimal(char *hexStr)
{
  unsigned long decimal = 0;
  for (int i = 0; i < strlen(hexStr); i++)
  {
    char val = hexStr[i];
    if (val >= '0' && val <= '9')
    {
      decimal += (val - '0') * pow(16, strlen(hexStr) - i - 1);
    }
    else if (val >= 'A' && val <= 'F')
    {
      decimal += (val - 'A' + 10) * pow(16, strlen(hexStr) - i - 1);
    }
    else if (val >= 'a' && val <= 'f')
    {
      decimal += (val - 'a' + 10) * pow(16, strlen(hexStr) - i - 1);
    }
  }
  return decimal;
}

unsigned long base64ToDecimal(char *base64Str)
{
  unsigned long decimal = 0;
  for (int i = 0; i < strlen(base64Str); i++)
  {
    decimal += base64Value(base64Str[i]) * pow(64, strlen(base64Str) - i - 1);
  }
  return decimal;
}
