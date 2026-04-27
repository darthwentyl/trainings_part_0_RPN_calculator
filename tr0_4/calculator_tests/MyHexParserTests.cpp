#include "MyHexParserTests.h"

#include "myhexparser.h"

#include <QTest>

MyHexParserTests::MyHexParserTests()
{
    isEmptyNum = [](int c __attribute__((unused))){
        return 0;
    };
}

void MyHexParserTests::testNum0()
{
    MyHex val = MyHexParser().parse(std::string{"0"}, isEmptyNum);
    QCOMPARE(val.get(), "0");
}

void MyHexParserTests::testNum1()
{
    MyHex val = MyHexParser().parse(std::string{"1"}, isEmptyNum);
    QCOMPARE(val.get(), "1");
}

void MyHexParserTests::testNum2()
{
    MyHex val = MyHexParser().parse(std::string{"2"}, isEmptyNum);
    QCOMPARE(val.get(), "2");
}

void MyHexParserTests::testNum3()
{
    MyHex val = MyHexParser().parse(std::string{"3"}, isEmptyNum);
    QCOMPARE(val.get(), "3");
}

void MyHexParserTests::testNum4()
{
    MyHex val = MyHexParser().parse(std::string{"4"}, isEmptyNum);
    QCOMPARE(val.get(), "4");
}

void MyHexParserTests::testNum5()
{
    MyHex val = MyHexParser().parse(std::string{"5"}, isEmptyNum);
    QCOMPARE(val.get(), "5");
}

void MyHexParserTests::testNum6()
{
    MyHex val = MyHexParser().parse(std::string{"6"}, isEmptyNum);
    QCOMPARE(val.get(), "6");
}

void MyHexParserTests::testNum7()
{
    MyHex val = MyHexParser().parse(std::string{"7"}, isEmptyNum);
    QCOMPARE(val.get(), "7");
}

void MyHexParserTests::testNum8()
{
    MyHex val = MyHexParser().parse(std::string{"8"}, isEmptyNum);
    QCOMPARE(val.get(), "8");
}

void MyHexParserTests::testNum9()
{
    MyHex val = MyHexParser().parse(std::string{"9"}, isEmptyNum);
    QCOMPARE(val.get(), "9");
}

void MyHexParserTests::testNumA()
{
    MyHex val = MyHexParser().parse(std::string{"A"}, isEmptyNum);
    QCOMPARE(val.get(), "A");
    val = MyHexParser().parse(std::string{"a"}, isEmptyNum);
    QCOMPARE(val.get(), "A");
}

void MyHexParserTests::testNumB()
{
    MyHex val = MyHexParser().parse(std::string{"B"}, isEmptyNum);
    QCOMPARE(val.get(), "B");
    val = MyHexParser().parse(std::string{"b"}, isEmptyNum);
    QCOMPARE(val.get(), "B");
}

void MyHexParserTests::testNumC()
{
    MyHex val = MyHexParser().parse(std::string{"C"}, isEmptyNum);
    QCOMPARE(val.get(), "C");
    val = MyHexParser().parse(std::string{"c"}, isEmptyNum);
    QCOMPARE(val.get(), "C");
}

void MyHexParserTests::testNumD()
{
    MyHex val = MyHexParser().parse(std::string{"D"}, isEmptyNum);
    QCOMPARE(val.get(), "D");
    val = MyHexParser().parse(std::string{"d"}, isEmptyNum);
    QCOMPARE(val.get(), "D");
}

void MyHexParserTests::testNumE()
{
    MyHex val = MyHexParser().parse(std::string{"E"}, isEmptyNum);
    QCOMPARE(val.get(), "E");
    val = MyHexParser().parse(std::string{"e"}, isEmptyNum);
    QCOMPARE(val.get(), "E");
}

void MyHexParserTests::testNumF()
{
    MyHex val = MyHexParser().parse(std::string{"F"}, isEmptyNum);
    QCOMPARE(val.get(), "F");
    val = MyHexParser().parse(std::string{"f"}, isEmptyNum);
    QCOMPARE(val.get(), "F");
}

void MyHexParserTests::testThrowEmptyString()
{
    try
    {
        MyHexParser().parse(std::string{}, isEmptyNum);
        QFAIL("Expected std::runtime_error not thrown");
    }
    catch (const std::runtime_error& e)
    {
        QCOMPARE(QString(e.what()), "str cannot be empty");
    }
    catch (...)
    {
        QFAIL("Caught unexpected exception type");
    }
}

void MyHexParserTests::testThrowConvertionFailed()
{
    try
    {
        MyHexParser().parse(std::string{"*-+/"}, isEmptyNum);
        QFAIL("Expected std::runtime_error not thrown");
    }
    catch (const std::runtime_error& e)
    {
        QCOMPARE(QString(e.what()), "Convertion failed for hex num *-+/");
    }
    catch (...)
    {
        QFAIL("Caught unexpected exception type");
    }
}

void MyHexParserTests::testStressNumber()
{
    MyHex val = MyHexParser().parse(std::string{"90abcdef"}, isEmptyNum);
    QCOMPARE(val.get(), "90ABCDEF");
}