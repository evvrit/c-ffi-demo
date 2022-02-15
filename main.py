from ctypes import *
from sys import argv
import timeit


my_lib = cdll.LoadLibrary("./my_lib.so")
my_lib.parens_balanced.restype = c_bool


def parens_balanced(paren_string):
  paren_depth = 0

  for paren in paren_string:
    if paren_depth < 0:
      return False

    if paren == '(':
      paren_depth += 1
    elif paren == ')':
      paren_depth -= 1
    else:
      raise ValueError("paren_string included a non-parenthesis:", paren)

  return paren_depth == 0


def benchmark(py_str, c_str):
  runs = 100

  # make sure the function works
  if not parens_balanced(py_str):
    raise ValueError('not balanced:', py_str)
  py_time_total = timeit.timeit(lambda: parens_balanced(py_str), number=runs)
  py_time_avg_ms = 1000 * py_time_total / runs
  print(f"average Python runtime: {py_time_avg_ms:.3f} milliseconds")

  # make sure the function works
  if not my_lib.parens_balanced(c_str):
    raise ValueError('not balanced:', c_str)
  c_time_total = timeit.timeit(lambda: my_lib.parens_balanced(c_str), number=runs)
  c_time_avg_ms = 1000 * c_time_total / runs
  print(f"average C runtime: {c_time_avg_ms:.3f} milliseconds")

  c_time_percentage = c_time_total / py_time_total
  percentage = '{:.3%}'.format(c_time_percentage)
  print(f'The C version took {percentage} of the time of the Python version')


def example(py_str, c_str):
  if my_lib.parens_balanced(c_str):
    print('C says balanced!')
  else:
    print('C says not balanced!')

  if parens_balanced(py_str):
    print('Python says balanced!')
  else:
    print('Python says not balanced!')


if __name__ == '__main__':
  my_lib.let_the_show_begin()  

  if len(argv) < 2:
    quit()

  if argv[1] == 'example':
    py_str = input()
    c_str = c_char_p(py_str.encode('ascii'))
    example(py_str, c_str)

  if argv[1] == 'benchmark':
    py_str = 10000 * '((((())(((((()((((()())))(())))))))((((((())))))))))'
    c_str = c_char_p(py_str.encode('ascii'))
    benchmark(py_str, c_str)
