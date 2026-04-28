# Exercise
Please integrate your calculator library prepared in exercise **tr0_3** with my GUI. Based on ICalculatorDevice implementation, prepare your device version which will call your calculator solution.

The GUI operates on **MyHex** numbers type.

## Requirements
The integration shouldn't change the original source code. Your integration should be done by **ICalculatorDevice** implementation - **CalculatorDevice** is a file which you can modify.

If you need you can add new objects and modify **CMakeLists.txt** files. New objects should be covered by UT. When you finish please check memory usage by valgrind.

# Building

## GUI
```
cd calculator
mkdir build
cd build
cmake ..
make -j8
./calculator
```

## Unit tests
```
cd calculator_tests
mkdir build
cd build
cmake ..
make -j8
./calculator_tests
```

## Test coverage
```
cd calculator_tests
./coverage.sh
```
