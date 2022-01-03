#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include "convert.h"
#include "base64.h"
#include "decimal.h"
#include "binary.h"
#include "helper.h"
#include "hexadecimal.h"

void convert(int base, char *value)
{
  int originalBase = getBase(value);
  char *string = malloc(strlen(value));
  if (originalBase != 10)
  {
    strncpy(string, value + 2, strlen(value) - 2);
    string[strlen(value) - 2] = '\0';
  }
  else
  {
    strncpy(string, value, strlen(value));
    string[strlen(value)] = '\0';
  }
  if (base == 2)
  { // _toBinary
    char *binary;
    if (originalBase == 10)
    {
      binary = decimalToBinary(atoi(string));
      printf("0b%s\n", binary);
      free(binary);
    }
    else if (originalBase == 2)
    {
      printf("0b%s\n", string);
    }
    else if (originalBase == 8)
    {
      binary = octalToBinary(string);
      printf("0b%s\n", binary);
      free(binary);
    }
    else if (originalBase == 16)
    {
      binary = hexToBinary(string);
      printf("0b%s\n", binary);
      free(binary);
    }
    else if (originalBase == 64)
    {
      binary = base64ToBinary(string);
      printf("0b%s\n", binary);
      free(binary);
    }
    else
    {
      printf("Unsupported base\n");
    }
  }
  else if (base == 10)
  { // _toDecimal
    unsigned long decimal;
    if (originalBase == 10)
    {
      printf("%s\n", string);
    }
    else if (originalBase == 2)
    {
      decimal = binaryToDecimal(string);
      printf("%lu\n", decimal);
    }
    else if (originalBase == 8)
    {
      decimal = octalToDecimal(string);
      printf("%lu\n", decimal);
    }
    else if (originalBase == 16)
    {
      decimal = hexToDecimal(string);
      printf("%lu\n", decimal);
    }
    else if (originalBase == 64)
    {
      decimal = base64ToDecimal(string);
      printf("%lu\n", decimal);
    }
    else
    {
      printf("Unsupported base\n");
    }
  }
  else if (base == 16)
  { // _toDecimal
    char *hexStr;
    if (originalBase == 10)
    {
      hexStr = decimalToHex(atoi(string));
      printf("0x%s\n", hexStr);
      free(hexStr);
    }
    else if (originalBase == 2)
    {
      hexStr = binaryToHex(string);
      printf("0x%s\n", hexStr);
      free(hexStr);
    }
    else if (originalBase == 8)
    {
      hexStr = octalToHex(string);
      printf("0x%s\n", hexStr);
      free(hexStr);
    }
    else if (originalBase == 16)
    {
      printf("0x%s\n", string);
    }
    else if (originalBase == 64)
    {
      hexStr = base64ToHex(string);
      printf("0x%s\n", hexStr);
      free(hexStr);
    }
    else
    {
      printf("Unsupported base\n");
    }
  }
  else if (base == 64)
  { // _toDecimal
    char *base64Str;
    if (originalBase == 2)
    {
      base64Str = binaryToBase64(string);
      printf("%s\n", base64Str);
      free(base64Str);
    }
    else if (originalBase == 8)
    {
      base64Str = octalToBase64(string);
      printf("%s\n", base64Str);
      free(base64Str);
    }
    else if (originalBase == 10)
    {
      base64Str = decimalToBase64(atoi(string));
      printf("%s\n", base64Str);
      free(base64Str);
    }
    else if (originalBase == 16)
    {
      base64Str = hexToBase64(string);
      printf("%s\n", base64Str);
      free(base64Str);
    }
    else if (originalBase == 64)
    {
      printf("%s\n", string);
    }
    else
    {
      printf("Unsupported base\n");
    }
  }
  else
  {
    printf("Unsupported base\n");
  }
  free(string);
}

int main(int argc, char *argv[])
{
  if (argc < 2)
  {
    printf("Usage: %s <base> <number>\n", argv[0]);
    return 1;
  }
  char *str = argv[2];
  int base = getBase(str);
  int num;
  if (base == 10)
  {
    num = atol(str);
  }
  else
  {
    num = atol(str + 2);
  }
  int baseConversion = atoi(argv[1]);
  printf("Num = %d, ", num);
  printf("Base = %d, ", base);
  printf("Converted base = %d.\n", baseConversion);
  printf("Converted Value: ");
  convert(baseConversion, argv[2]);
  printf("\n");
  return 0;
}