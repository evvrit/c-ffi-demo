#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

void let_the_show_begin(void) {
  printf("dun dun dun...\n");
}

int add(int a, int b) {
  return a + b;
}

/* We need to iterate over paren_string. But in C, there are no objects or
   iterators. Thus, paren_string is not an object. It is actually just a
   single number, a "pointer" to a location in the computer's memory.
   The first character of the parenthesis sequence exists precisely
   at the location paren_string points to. The second character exists at
   the location directly after that. And so on, until we reach the end
   of the parenthesis sequence. Say, for instance, that the first byte
   of the sequence lies at memory location 4505:


                     paren_string = 4505
                       |
                       v
   Address:   ...  |  4505  |  4506  |  4507  |  ...  |  4505 + len(paren_string) - 1  |  4505 + len(paren_string)  |  ...
   Value:     ...  |  '('   |  '('   |  ')'   |  ...  |           ')'                  |           '\0'             |  ...


   Problem: we want to iterate over paren_string. How do we do that, when
   paren_string is just the pointer to the *start* of the string? We don't
   know how long the string is, and we don't have a pointer to its end!

   Answer: in order to iterate over strings in C, programmers decided on
   the convention that a string would always be terminated by a null byte.
   In binary, the null byte is '00000000'. It is sometimes symbolized
   as '\0' or '\NUL'. In order to iterate over paren_string, we need to keep
   increasing our index until we find the null byte, at which point we are
   finished iterating over paren_string. */

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
