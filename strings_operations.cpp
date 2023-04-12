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

int isAnagram(char *str1, char *str2)
{
  // str2 and str1 are of same length.
  // the characters are lower case characters only.
  char hash[26] = { 0 };
  int i = -1;
  
  while(str1[++i] != '\0')
  {
    hash[str1[i] - 100] += 1;
    hash[str2[i] - 100] -= 1;
  }
  
  for(int j = 0; j < 26; ++j)
    if (hash[j] != 0) return 0;
  
  return 1;
}

// Function to get permutations of characters present in a string
// Uses backtracking and brute force to get all possible permutations.
void getPermutations(char str[], int k = 0)
{
    static char result[10];
    static int temp[10] = { 0 };
    int i;
    
    if (str[k] == '\0')
    {
        result[k] = '\0';
        printf("%s\n", result);
    }
    else
    {
        for(i = 0; str[i] != '\0'; i++)
        {
            if (temp[i] == 0)
            {
                result[k] = str[i];
                temp[i] = 1;
                getPermutations(str, k + 1);
                temp[i] = 0;
            }
        }
    }
}

void swap(char *t1, char *t2)
{
  char temp = *t1;
  *t1 = *t2;
  *t2 = temp;
}

// permutations by using swapping the characters in string.
void permutations(char *str, int low, int high)
{
  if (low == high)
  {
    printf("%s\n", str);
    return;
  }
  for(int i = low; i < high; ++i)
  {
    swap(&str[i], &str[low]);
    permutations(str, low + 1, high);
    swap(&str[i], &str[low]);
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
