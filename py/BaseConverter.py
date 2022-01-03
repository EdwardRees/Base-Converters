from sys import argv

base64 = {
    '0': 0,
    '1': 1,
    '2': 2,
    '3': 3,
    '4': 4,
    '5': 5,
    '6': 6,
    '7': 7,
    '8': 8,
    '9': 9,
    'A': 10,
    'B': 11,
    'C': 12,
    'D': 13,
    'E': 14,
    'F': 15,
    'G': 16,
    'H': 17,
    'I': 18,
    'J': 19,
    'K': 20,
    'L': 21,
    'M': 22,
    'N': 23,
    'O': 24,
    'P': 25,
    'Q': 26,
    'R': 27,
    'S': 28,
    'T': 29,
    'U': 30,
    'V': 31,
    'W': 32,
    'X': 33,
    'Y': 34,
    'Z': 35,
    'a': 36,
    'b': 37,
    'c': 38,
    'd': 39,
    'e': 40,
    'f': 41,
    'g': 42,
    'h': 43,
    'i': 44,
    'j': 45,
    'k': 46,
    'l': 47,
    'm': 48,
    'n': 49,
    'o': 50,
    'p': 51,
    'q': 52,
    'r': 53,
    's': 54,
    't': 55,
    'u': 56,
    'v': 57,
    'w': 58,
    'x': 59,
    'y': 60,
    'z': 61,
    '-': 62,
    '_': 63,
}


def binaryToDecimal(binary):
    decimal = 0
    for i in range(len(binary)):
        decimal += int(binary[i]) * 2 ** (len(binary) - i - 1)
    return decimal

def decimalToBinary(decimal):
    binaryString = ''
    while decimal > 0:
        binaryString += str(decimal % 2)
        decimal = decimal // 2
    return binaryString[::-1]

def base64ToDecimal(value):
    decimal = 0
    for i in range(len(value)):
        val = base64.get(value[i], 0)
        decimal += val * 64 ** (len(value) - i - 1)
    return decimal

def decimalToBase64(decimal):
    base64String = ''
    while decimal > 0:
        base64String += list(base64.keys())[decimal % 64]
        decimal = decimal // 64
    return base64String[::-1]

def hexadecimalToDecimal(hexadecimal):
    decimal = 0
    for i in range(len(hexadecimal)):
        val = hexadecimal[i]
        if val in "ABCDEF":
            val = ord(val) - 55
        else:
            val = int(val)
        decimal += val * 16 ** (len(hexadecimal) - i - 1)
    return decimal

def baseToDecimal(value : str, base : int):
  if(base > 64):
    return -1
  decimal = 0
  for i in range(len(value)):
    val = base64.get(value[i], 0)
    decimal += val * base ** (len(value) - i - 1)
  return decimal
    
def decimalToBase(decimal : int, base : int):
  if(base > 64):
    return None
  string = ''
  while decimal > 0:
    string += list(base64.keys())[decimal % base]
    decimal = decimal // base
  return string[::-1]

def decimalToHexadecimal(decimal):
    hexadecimal = ''
    while decimal > 0:
        hexadecimal += list(base64.keys())[decimal % 16]
        decimal = decimal // 16
    return hexadecimal[::-1]


def binaryToBase64(binary):
    decimal = binaryToDecimal(binary)
    return decimalToBase64(decimal)

def base64ToBinary(base64String):
    decimal = base64ToDecimal(base64String)
    return decimalToBinary(decimal)


def main():
  if(len(argv) < 1):
    print("Usage: BaseConverter.py <base> <value>")
    print("Example: BaseConverter.py 2 100")
    print("Example: BaseConverter.py 10 0b1010101")
    print("Example: BaseConverter.py 10 0xFF")
    print("Example: BaseConverter.py 10 0+777")
    return 1
  base = argv[1]
  value = argv[2]
  if(len(value) > 0 and value[0] == '0'):
    if(value[1] == 'b'):
      value = value[2:]
      if(base == '2'):
        print(value)
      elif(base == '10'):
        print(binaryToDecimal(value))
      elif(base == '16'):
        print(decimalToHexadecimal(binaryToDecimal(value)))
      elif(base == '64'):
        print(decimalToBase64(binaryToDecimal(value)))
      else:
        print("Invalid base")
    elif(value[1] == 'x'):
      value = value[2:]
      if(base == '2'):
        print(decimalToBinary(hexadecimalToDecimal(value)))
      elif(base == '10'):
        print(hexadecimalToDecimal(value))
      elif(base == '16'):
        print(value)
      elif(base == '64'):
        print(decimalToBase64(hexadecimalToDecimal(value)))
      else:
        print("Invalid base")
    elif(value[1] == '+'):
      value = value[2:]
      if(base == '2'):
        print(decimalToBinary(base64ToDecimal(value)))
      elif(base == '10'):
        print(base64ToDecimal(value))
      elif(base == '16'):
        print(decimalToHexadecimal(base64ToDecimal(value)))
      elif(base == '64'):
        print(value)
      else:
        print("Invalid base")
    else:
      print("Invalid value")
  else:
    if(base == '2'):
      print(decimalToBinary(int(value)))
    elif(base == '10'):
      print(value)
    elif(base == '16'):
      print(decimalToHexadecimal(int(value)))
    elif(base == '64'):
      print(decimalToBase64(int(value)))
    else:
      print("Invalid base")

main()
