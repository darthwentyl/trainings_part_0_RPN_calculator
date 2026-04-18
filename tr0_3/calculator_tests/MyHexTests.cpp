#include "MyHexTests.h"

#include "myhex.h"

#include <QTest>

void MyHexTests::testOperatorPlus()
{
    MyHex hex1{10};
    MyHex hex2{16};
    MyHex result = hex1 + hex2;
    QCOMPARE(result.get(), "1A");
}

void MyHexTests::testOperatorMinus()
{
    MyHex hex1{16};
    MyHex hex2{3};
    MyHex result = hex1 - hex2;
    QCOMPARE(result.get(), "D");
}

void MyHexTests::testOperatorMinusAbs()
{
    MyHex hex1{3};
    MyHex hex2{16};
    MyHex result = hex1 - hex2;
    QCOMPARE(result.get(), "D");
}

void MyHexTests::testOperatorMult()
{
    MyHex hex1{14};
    MyHex hex2{2};
    MyHex result = hex1 * hex2;
    QCOMPARE(result.get(), "1C");
}

void MyHexTests::testOperatorDiv()
{
    MyHex hex1{121};
    MyHex hex2{11};
    MyHex result = hex1 / hex2;
    QCOMPARE(result.get(), "B");
}

void MyHexTests::testOperatorDiv_0()
{
    MyHex hex1{123};
    MyHex hex2{0};
    try
    {
        hex1 / hex2;
        QFAIL("Expected std::runtime_error not thrown");
    }
    catch (const std::runtime_error& e)
    {
        QCOMPARE(QString(e.what()), "div 0");
    }
    catch (...)
    {
        QFAIL("Caught unexpected exception type");
    }
}

void MyHexTests::testOperatorDiv_Ge()
{
    MyHex hex1{2};
    MyHex hex2{4};
    MyHex result = hex1 / hex2;
    QCOMPARE(result.get(), "0");
}