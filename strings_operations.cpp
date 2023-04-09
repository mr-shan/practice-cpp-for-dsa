#include <iostream>
using namespace std;

int length(char *str)
{
  int i = -1;
  while (str[++i] != '\0') {};
  return i;
}

char* reverse(char *str)
{
  int i = 0;
  int lenStr = length(str);
  while (i < lenStr / 2)
  {
    char temp = str[lenStr - i -1];
    str[lenStr - i -1] = str[i];
    str[i] = temp;
    i++;
  }
  return str;
}

int isPalindrom(char *str)
{
  int i = -1;
  int lenStr = length(str);
  while (str [++i] != '\0')
  {
    if (str[i] != str[lenStr - i - 1])
      return 0;
  }
  return 1;
}

// This uses bitwise operations to find the duplicate.
// It makes use of left shifting of bits 
// Then it uses masking (AND) and merging (OR)
// to check if duplicate exists.
int checkDuplicate(char *str)
{
  int lenStr = length(str);
  long int hex = 0, temp = 0;
  int i = -1;
  
  while(str[++i] != '\0')
  {
    temp = 1;
    temp = temp << str[i];

    if ((temp & hex) > 0)
      printf("Duplicate found: %c\n", str[i]);
    else
      hex = hex | temp;
  }
}

int main() 
{
    char name[] = "Madam";
    int result = isPalindrom(name);
    
    printf("The string is palindrom? %d\n", isPalindrom(name));
    
    char *reverseName = reverse(name);
    printf("\n%s", reverseName);
    
    return 0;
}
