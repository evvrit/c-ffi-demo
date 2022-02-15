# Python - C FFI demo

This repo includes a demonstration of the Python ctypes FFI library.

It picks a task that C is significantly faster at, and benchmarks a C and a Python solution to the problem.
The problem is checking whether a sequence of parentheses is balanced.

To benchmark with gcc, run `make gcc && make benchmark`.
To benchmark with clang, run `make clang && make benchmark`.

Here are some examples of balanced sequences of parentheses:
```
()()()()()
```
```
((()))
```
```
(()()((())))
```

And here are some examples of unbalanced sequences of parentheses:
```
)
```
```
(((())))(
```
```
(()()))(())
```
