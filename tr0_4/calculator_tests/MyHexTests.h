#pragma once

#include <QObject>

class MyHexTests : public QObject
{
    Q_OBJECT

private Q_SLOTS:
    void testOperatorPlus();
    void testOperatorMinus();
    void testOperatorMinusAbs();
    void testOperatorMult();
    void testOperatorDiv();
    void testOperatorDiv_0();
    void testOperatorDiv_Ge();
};