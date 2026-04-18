#pragma once

#include <QObject>

class KeysWidgetTests : public QObject
{
    Q_OBJECT

private Q_SLOTS:
    void testButtonNum0();
    void testButtonNum1();
    void testButtonNum2();
    void testButtonNum3();
    void testButtonNum4();
    void testButtonNum5();
    void testButtonNum6();
    void testButtonNum7();
    void testButtonNum8();
    void testButtonNum9();
    void testButtonNumA();
    void testButtonNumB();
    void testButtonNumC();
    void testButtonNumD();
    void testButtonNumE();
    void testButtonNumF();
    void testButtonEqual();
    void testButtonDiv();
    void testButtonMult();
    void testButtonMinus();
    void testButtonPlus();
    void testButtonLeftBrace();
    void testButtonRightBrace();
    void testButtonUndo();
    void testButtonClear();
    void testKeyPressEvent();
};