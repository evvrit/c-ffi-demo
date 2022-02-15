clang:
	clang -shared -Ofast -o my_lib.so my_lib.c

gcc:
	gcc -shared -Ofast -o my_lib.so my_lib.c

example:
	python main.py example

benchmark:
	python main.py benchmark
