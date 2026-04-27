#pragma once

#include <QObject>

class TokenEmiterTests : public QObject
{
    Q_OBJECT

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
    void testEqual();
    void testEnter();
    void testReturn();
    void testDiv();
    void testMult();
    void testMinus();
    void testPlus();
    void testLeftBrace();
    void testParenLeft();
    void testRightBrace();
    void testParenRight();
    void testUndo();
    void testBackspace();
    void testClear();
    void testUnknown();
};