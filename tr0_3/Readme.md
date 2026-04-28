# Exercise
Please prepare the GUI for the calculator implemented in exercise **tr0_2**. The GUI will be operating on **MyFloat** number type. For this task please (if required) refactor your **tr0_2** source to library and put it into GUI implementation.

**MyFloat** has to implement two digits precission, for example

    2.12345 + 3.534534 = 5.65

## Requirements
* Support arithmetic operations: "+"; "-"; "*"; "/"
* Modern C++
* GUI uses QT library
* Object-oriented programming - OOP
* Unit tests - use mix google test and QTest framework
* Coverage - use gcov
* Memory leak - use valgrind
* Template metaprogramming or polymorphic programing
* Application built on QT engine (signal-slot etc.)

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
* https://en.wikipedia.org/wiki/Template_metaprogramming
* https://doc.qt.io/
* https://www.codegenes.net/blog/how-to-run-multiple-qtest-classes/
