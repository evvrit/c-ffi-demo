import main
import ctypes

def test():
  balanced_parens = [
    '()()()()()',
    '((()))',
    '(()()((())))'
  ]

  unbalanced_parens = [
    ')',
    '(((())))(',
    '(()()))(())'
  ]

  for parens in balanced_parens:
    assert main.parens_balanced(parens)
    c_parens = ctypes.c_char_p(parens.encode('ascii'))
    assert main.my_lib.parens_balanced(c_parens)

  for parens in unbalanced_parens:
    assert not main.parens_balanced(parens)
    c_parens = ctypes.c_char_p(parens.encode('ascii'))
    assert not main.my_lib.parens_balanced(c_parens)

  print('OK: tests passed')

if __name__ == '__main__':
  test()
