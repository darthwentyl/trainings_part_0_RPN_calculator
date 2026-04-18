#pragma once

#include <QObject>

class MyHexParserTests : public QObject
{
    Q_OBJECT

public:
    MyHexParserTests();

private Q_SLOTS:
    void testNum0();
    void testNum1();
    void testNum2();
    void testNum3();
    void testNum4();
    void testNum5();
    void testNum6();
    void testNum7();
    void testNum8();
    void testNum9();
    void testNumA();
    void testNumB();
    void testNumC();
    void testNumD();
    void testNumE();
    void testNumF();
    void testThrowEmptyString();
    void testThrowConvertionFailed();
    void testStressNumber();

private:
    std::function<int(int)> isEmptyNum;
};