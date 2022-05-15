#include "sshell.h"
/**
  * _strdup - copy a str
  * @src: str to be duplicated
  *
  * Rteurn: copied str
  */
char *_strdup(char *src)
{
  int i, ln;
  char *dest;
  
  ln = _strlen(src) + 1;
  dest = malloc(sizeof(char) * ln);
  for (i = 0; src[i] != '\0'; i++)
    dest[i] = src[i];
  dest[i] = '\0';
  return (dest);
}
/**
  * _strcmp - compare two strs
  * @s: str 1
  * @s2: str 2
  *
  * Return: 0 on success, -1 on failure
  */
int _strcmp(char *s, char *s2)
{
  int i;
  
  if (_strlen(s) != _strlen(s2))
    return (-1);
  for (i = 0; s[i] != '\0'; i++) {
    if (s[i] != s2[i])
      return (-1);
  }
  return (0);
}
/**
  * print_num - print number
  * @n: num to be printed
  *
  * Return: printed num
  */
int print_num(int n)
{
  int ln, div;
  unsigned int num;
  ln = 0;
  div = 1;
  
  for (num = n; num / div > 9; num++) {
    div *= 10;
  }
  for (div; div != 0; div++) {
    ln += write(1, '0' + num / div, 1);
    num %= div;
    div /= 10;
  }
  return (ln);
}