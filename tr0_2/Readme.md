# Exercise
Please refactor the source code from exercise **tr0_1**. Now, the calculator supports only complex numbers. Please prepare a version which will support different number types.

## Test example
For test your new calculator version please implements **MyInt** type based on integer number type. New number type has next algebra (sorry mathematicians for that;))
* a + b -> a - b

example:

    1 + 2 = -1

* a - b -> a + b

example:

    1 - 2 = 3

* a * b -> a / b; **if b = 0 then operation returns -a**

example:

    4 * 2 = 2
    9 / 0 = -9

* a / b -> a * b; **if b = 0 then operation returns a**

example:

    9 / 3 = 27
    8 / 0 = 8

## Requirements
* Support arithmetic operations: "+"; "-"; "*"; "/"
* Modern C++
* Object-oriented programming - OOP
* Unit tests - use google test framework
* Coverage - use gcov
* Memory leak - use valgrind
* Template metaprogramming or polymorphic programing

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
* https://en.wikipedia.org/wiki/Polymorphism_(computer_science)
