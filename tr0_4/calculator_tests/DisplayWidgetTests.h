#pragma once

#include <QObject>

class DisplayWidgetTests : public QObject
{
    Q_OBJECT

private Q_SLOTS:
    void testSetNullTokenEmiter();
    void testSetDoubleTokenEmiter();
    void testSetNullCalculatorDevice();
    void testSetDoubleCalculatorDevice();
    void testSetNullErrorMessage();
    void testSetDoubleErrorMessage();
    void testOnUndoWhenInputFormulaIsEmpty();
    void testOnUndoInputFormulaWithText();
    void testOnClearInputFormulaIsEmpty();
    void testOnClearInputFormulaWithText();
    void testOnEqualCalculatorDeviceNotSet();
    void testOnEqualThrowException();
    void testOnEqualResultReturned();
};