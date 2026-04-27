# Exercise
Please implement an RPN calculator. The calculator has to operate on complex numbers.

## Requirements
* Support arithmetic operations: "+"; "-"; "*"; "/"
* Modern C++
* Object-oriented programming - OOP
* Unit tests - use google test framework
* Coverage - use gcov
* Memory leak - use valgrind

# Building
Prepare build system using cmake.

## Unit tests
Procedure to build unit tests

```
mkdir build
cd build
cmake ..
make -j8
```

# Test coverage
Prepare a bash script which prepares the tests coverage report. Let's script launch by command below

```
./coverage.sh
```

# Links
* https://en.wikipedia.org/wiki/Reverse_Polish_notation
* https://en.wikipedia.org/wiki/Object-oriented_programming
* https://google.github.io/googletest/
* https://valgrind.org/docs/manual/index.html
* https://gcc.gnu.org/onlinedocs/gcc/Gcov.html
