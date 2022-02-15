#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

void let_the_show_begin() {
  printf("dun dun dun...\n");
}

int add(int a, int b) {
  return a + b;
}

// We need to iterate over paren_string. But in C, there are no objects or
// iterators. Here, paren_string is a raw sequence of bytes. It has no
// methods or attributes, like it would in Python.
// Problem: we want to iterate over paren_string. How do we do that, when
// it can't tell us how long it is?
//
// Answer: in order to iterate over strings in C, programmers decided on
// the convention that the final byte of a string would always be the null
// byte. In binary, the null byte is '00000000'. It is sometimes symbolized
// as '\0' or '\NUL'. In order to iterate over paren_string, we need to keep
// increasing our index until we find the null byte, at which point we are
// finished iterating over paren_string.
bool parens_balanced(char* paren_string) {
  int paren_depth = 0;
  size_t index = 0;

  while (paren_string[index] != '\0') {
    if (paren_depth < 0) {
      return false;
    }

    char current_char = paren_string[index];
    if (current_char == '(') {
      paren_depth += 1;
    } else if (current_char == ')') {
      paren_depth -= 1;
    } else {
      printf("paren_string included a non-parenthesis: %c\n", current_char);
      exit(1);
    }

    index += 1;
  }

  return paren_depth == 0;
}
