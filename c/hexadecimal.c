#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "convert.h"
#include "decimal.h"
#include "helper.h"

char *decimalToHex(unsigned long decimal)
{
  char *hexStr = malloc(sizeof(char) * 32);
  int i = 0;
  while (decimal > 0)
  {
    int temp = decimal % 16;
    if (temp < 10)
    {
      hexStr[i] = temp + '0';
    }
    else
    {
      hexStr[i] = temp - 10 + 'A';
    }
    decimal /= 16;
    i++;
  }
  hexStr[i] = '\0';
  reverse(hexStr);
  return hexStr;
}

char *octalToHex(char *octStr){
  unsigned long decimal = octalToDecimal(octStr);
  char *hexStr = malloc(sizeof(char) * 32);
  int i = 0;
  while (decimal > 0)
  {
    int temp = decimal % 16;
    if (temp < 10)
    {
      hexStr[i] = temp + '0';
    }
    else
    {
      hexStr[i] = temp - 10 + 'A';
    }
    decimal /= 16;
    i++;
  }
  hexStr[i] = '\0';
  reverse(hexStr);
  return hexStr;
}

char *binaryToHex(char *binStr)
{
  unsigned long decimal = binaryToDecimal(binStr);
  char *hexStr = malloc(sizeof(char) * 32);
  int i = 0;
  while (decimal > 0)
  {
    int temp = decimal % 16;
    if (temp < 10)
    {
      hexStr[i] = temp + '0';
    }
    else
    {
      hexStr[i] = temp - 10 + 'A';
    }
    decimal /= 16;
    i++;
  }
  hexStr[i] = '\0';
  reverse(hexStr);
  return hexStr;
}

char *base64ToHex(char *base64Str)
{
  unsigned long decimal = base64ToDecimal(base64Str);
  char *hexStr = malloc(sizeof(char) * 32);
  int i = 0;
  while (decimal > 0)
  {
    int temp = decimal % 16;
    if (temp < 10)
    {
      hexStr[i] = temp + '0';
    }
    else
    {
      hexStr[i] = temp - 10 + 'A';
    }
    decimal /= 16;
    i++;
  }
  hexStr[i] = '\0';
  reverse(hexStr);
  return hexStr;
}
