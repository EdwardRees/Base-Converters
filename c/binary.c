#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include "decimal.h"
#include "helper.h"


char *decimalToBinary(unsigned long decimal)
{
  char *binStr = malloc(sizeof(char) * 32);
  int i = 0;
  while (decimal > 0)
  {
    binStr[i] = decimal % 2 + '0';
    decimal /= 2;
    i++;
  }
  binStr[i] = '\0';
  reverse(binStr);
  return binStr;
}

char* octalToBinary(char *octStr){
  unsigned long decimal = octalToDecimal(octStr);
  char *binStr = malloc(sizeof(char) * 32);
  int i = 0;
  while (decimal > 0)
  {
    binStr[i] = decimal % 2 + '0';
    decimal /= 2;
    i++;
  }
  binStr[i] = '\0';
  reverse(binStr);
  return binStr;
}

char *hexToBinary(char *hexStr)
{
  unsigned long decimal = hexToDecimal(hexStr);
  char *binStr = malloc(sizeof(char) * 32);
  int i = 0;
  while (decimal > 0)
  {
    binStr[i] = decimal % 2 + '0';
    decimal /= 2;
    i++;
  }
  binStr[i] = '\0';
  reverse(binStr);
  return binStr;
}

char *base64ToBinary(char *base64Str)
{
  unsigned long decimal = base64ToDecimal(base64Str);
  char *binStr = malloc(sizeof(char) * 32);
  int i = 0;
  while (decimal > 0)
  {
    binStr[i] = decimal % 2 + '0';
    decimal /= 2;
    i++;
  }
  binStr[i] = '\0';
  reverse(binStr);
  return binStr;
}
