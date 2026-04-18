#include "DisplayWidgetTests.h"

#include "displaywidget.h"
#include "tokenemiter.h"
#include "errormessagebox.h"

#include <gtest/gtest.h>
#include "mocks/CalculatorDeviceMock.h"
#include "mocks/ErrorMessageMock.h"

#include <QTest>
#include <QLabel>
#include <QPushButton>
#include <QMessageBox>

using namespace testing;

namespace {
    const QString INPUT_FORMULA_LABEL = "inputFormula";
    const QString OUTPUT_FORMULA_LABEL = "outputResult";
} // anonymous

void DisplayWidgetTests::testSetNullTokenEmiter()
{
    DisplayWidget widget;
    TokenEmiter emiter;
    QLabel* inputFormula = widget.findChild<QLabel*>(INPUT_FORMULA_LABEL);
    QVERIFY(inputFormula != nullptr);

    widget.setTokenEmiter(nullptr);
    emiter.emitToken(Qt::Key_0);

    QVERIFY(inputFormula->text().isEmpty());
}

void DisplayWidgetTests::testSetDoubleTokenEmiter()
{
    DisplayWidget widget;
    TokenEmiter emiter1;
    TokenEmiter emiter2;
    QLabel* inputFormula = widget.findChild<QLabel*>(INPUT_FORMULA_LABEL);
    QVERIFY(inputFormula != nullptr);

    widget.setTokenEmiter(&emiter1);
    widget.setTokenEmiter(&emiter2);

    emiter2.emitToken(Qt::Key_0);
    QVERIFY(inputFormula->text().isEmpty());

    emiter1.emitToken(Qt::Key_0);
    QCOMPARE(inputFormula->text(), "0");
}

void DisplayWidgetTests::testSetNullCalculatorDevice()
{
    DisplayWidget widget;
    TokenEmiter emiter;
    CalculatorDeviceMock calculatorDevice;

    EXPECT_CALL(calculatorDevice, calculate(_)).Times(0);

    widget.setTokenEmiter(&emiter);
    widget.setCalculatorDevice(nullptr);

    emiter.emitToken(Qt::Key_Equal);
    QVERIFY(Mock::VerifyAndClearExpectations(&calculatorDevice));
}

void DisplayWidgetTests::testSetDoubleCalculatorDevice()
{
    DisplayWidget widget;
    TokenEmiter emiter;
    CalculatorDeviceMock calculatorDevice1;
    CalculatorDeviceMock calculatorDevice2;

    QLabel* outputResult = widget.findChild<QLabel*>(OUTPUT_FORMULA_LABEL);
    QVERIFY(outputResult != nullptr);

    EXPECT_CALL(calculatorDevice1, calculate(_)).WillOnce(Return(QString("F")));
    EXPECT_CALL(calculatorDevice2, calculate(_)).Times(0);

    widget.setTokenEmiter(&emiter);
    widget.setCalculatorDevice(&calculatorDevice1);
    widget.setCalculatorDevice(&calculatorDevice2);

    emiter.emitToken(Qt::Key_F);
    emiter.emitToken(Qt::Key_Equal);

    QVERIFY(Mock::VerifyAndClearExpectations(&calculatorDevice1));
    QVERIFY(Mock::VerifyAndClearExpectations(&calculatorDevice2));
    QCOMPARE(outputResult->text(), "F");
}

void DisplayWidgetTests::testSetNullErrorMessage()
{
    DisplayWidget widget;
    TokenEmiter emiter;
    CalculatorDeviceMock calculatorDevice;

    EXPECT_CALL(calculatorDevice, calculate(_)).WillOnce(
        []() {
            std::runtime_error("Throw runtime_error");
            return QString();
        }
    );

    widget.setTokenEmiter(&emiter);
    widget.setCalculatorDevice(&calculatorDevice);
    widget.setErrorMessage(nullptr);

    emiter.emitToken(Qt::Key_Equal);

    QVERIFY(Mock::VerifyAndClearExpectations(&calculatorDevice));
}

void DisplayWidgetTests::testSetDoubleErrorMessage()
{
    DisplayWidget widget;
    TokenEmiter emiter;
    CalculatorDeviceMock calculatorDevice;
    ErrorMessageMock errorMessage1;
    ErrorMessageMock errorMessage2;

    EXPECT_CALL(calculatorDevice, calculate(_)).WillOnce(
        []() {
            throw std::runtime_error("Throw runtime_error");
            return QString();
        }
    );

    EXPECT_CALL(errorMessage1, show(_)).Times(1);
    EXPECT_CALL(errorMessage2, show(_)).Times(0);

    widget.setTokenEmiter(&emiter);
    widget.setCalculatorDevice(&calculatorDevice);
    widget.setErrorMessage(&errorMessage1);
    widget.setErrorMessage(&errorMessage2);

    emiter.emitToken(Qt::Key_Equal);

    QVERIFY(Mock::VerifyAndClearExpectations(&calculatorDevice));
    QVERIFY(Mock::VerifyAndClearExpectations(&errorMessage1));
    QVERIFY(Mock::VerifyAndClearExpectations(&errorMessage2));
}

void DisplayWidgetTests::testOnUndoWhenInputFormulaIsEmpty()
{
    DisplayWidget widget;
    TokenEmiter emiter;
    QLabel* inputFormula = widget.findChild<QLabel*>(INPUT_FORMULA_LABEL);
    QVERIFY(inputFormula != nullptr);

    widget.setTokenEmiter(&emiter);
    emiter.emitToken(Qt::Key_Undo);

    QVERIFY(inputFormula->text().isEmpty());
}

void DisplayWidgetTests::testOnUndoInputFormulaWithText()
{
    DisplayWidget widget;
    TokenEmiter emiter;
    QLabel* inputFormula = widget.findChild<QLabel*>(INPUT_FORMULA_LABEL);
    QVERIFY(inputFormula != nullptr);

    widget.setTokenEmiter(&emiter);
    inputFormula->setText("123");

    emiter.emitToken(Qt::Key_Undo);
    QCOMPARE(inputFormula->text(), "12");
}

void DisplayWidgetTests::testOnClearInputFormulaIsEmpty()
{
    DisplayWidget widget;
    TokenEmiter emiter;
    QLabel* inputFormula = widget.findChild<QLabel*>(INPUT_FORMULA_LABEL);
    QVERIFY(inputFormula != nullptr);

    widget.setTokenEmiter(&emiter);

    emiter.emitToken(Qt::Key_Delete);
    QVERIFY(inputFormula->text().isEmpty());
}

void DisplayWidgetTests::testOnClearInputFormulaWithText()
{
    DisplayWidget widget;
    TokenEmiter emiter;
    QLabel* inputFormula = widget.findChild<QLabel*>(INPUT_FORMULA_LABEL);
    QVERIFY(inputFormula != nullptr);
    QLabel* outputResult = widget.findChild<QLabel*>(OUTPUT_FORMULA_LABEL);
    QVERIFY(outputResult != nullptr);

    widget.setTokenEmiter(&emiter);
    inputFormula->setText("123");
    outputResult->setText("123");

    emiter.emitToken(Qt::Key_Delete);
    QVERIFY(inputFormula->text().isEmpty());
    QCOMPARE(outputResult->text(), "0");
}

void DisplayWidgetTests::testOnEqualCalculatorDeviceNotSet()
{
    DisplayWidget widget;
    TokenEmiter emiter;
    QLabel* outputResult = widget.findChild<QLabel*>(OUTPUT_FORMULA_LABEL);
    QVERIFY(outputResult != nullptr);
    CalculatorDeviceMock calculatorDevice;

    EXPECT_CALL(calculatorDevice, calculate(_)).Times(0);

    widget.setTokenEmiter(&emiter);
    emiter.emitToken(Qt::Key_Equal);
    QCOMPARE(outputResult->text(), "0");
    QVERIFY(Mock::VerifyAndClearExpectations(&calculatorDevice));
}

void DisplayWidgetTests::testOnEqualThrowException()
{
    DisplayWidget widget;
    TokenEmiter emiter;
    CalculatorDeviceMock calculatorDevice;
    ErrorMessageMock errorMessage;

    const QString error = "runtime_error";

    EXPECT_CALL(calculatorDevice, calculate(_)).WillOnce(
        [&error](){
            throw std::runtime_error(error.toStdString().c_str());
            return QString();
        }
    );

    EXPECT_CALL(errorMessage, show(error)).Times(1);

    widget.setTokenEmiter(&emiter);
    widget.setCalculatorDevice(&calculatorDevice);
    widget.setErrorMessage(&errorMessage);

    emiter.emitToken(Qt::Key_Equal);

    QVERIFY(Mock::VerifyAndClearExpectations(&calculatorDevice));
    QVERIFY(Mock::VerifyAndClearExpectations(&errorMessage));
}

void DisplayWidgetTests::testOnEqualResultReturned()
{
    DisplayWidget widget;
    TokenEmiter emiter;
    QLabel* outputResult = widget.findChild<QLabel*>(OUTPUT_FORMULA_LABEL);
    QVERIFY(outputResult != nullptr);
    CalculatorDeviceMock calculatorDevice;

    const QString hex = "E";

    EXPECT_CALL(calculatorDevice, calculate(hex)).WillOnce(Return(hex));

    widget.setTokenEmiter(&emiter);
    widget.setCalculatorDevice(&calculatorDevice);

    emiter.emitToken(Qt::Key_E);
    emiter.emitToken(Qt::Key_Equal);

    QCOMPARE(outputResult->text().toStdString().c_str(), hex.toStdString().c_str());
    QVERIFY(Mock::VerifyAndClearExpectations(&calculatorDevice));
}