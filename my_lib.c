#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

void let_the_show_begin() {
  printf("dun dun dun...\n");
}

int add(int a, int b) {
  return a + b;
}

bool parens_balanced(char* paren_string) {
  int paren_depth = 0;
  size_t index = 0;

  // In C, there are no iterators, and there is no len() function.
  // We need to iterate over the string, which is a raw sequence of bytes.
  //
  // In order to find the end of a C string, you look for the first occurrence
  // of the "null byte" 00000000.
  //
  // This value is expressed by the character '\0' or '\NUL' depending on the
  // context.
  while (paren_string[index] != '\0') {
    if (paren_depth < 0) {
      return false;
    }

    char current_char = paren_string[index];
    if (current_char == '(') {
      paren_depth = paren_depth + 1;
    } else if (current_char == ')') {
      paren_depth = paren_depth - 1;
    } else {
      printf("paren_string included a non-parenthesis: %c\n", current_char);
      exit(1);
    }

    index = index + 1;
  }

  return paren_depth == 0;
}
