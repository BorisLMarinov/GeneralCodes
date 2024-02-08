#include <stdio.h>

void printcharsonnewline(char *s);

int main() {
  char input[] = "someString";
  printcharsonnewline(input);

  return 0;
}

void printcharsonnewline(char *s) {

  for (char index = 0; s[index] != '\0'; index++) {
    char currentchar = s[index];
    printf("%c\n", currentchar);
  }
}