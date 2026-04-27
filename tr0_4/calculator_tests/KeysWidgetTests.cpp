#include "KeysWidgetTests.h"

#include "keyswidget.h"

#include <QTest>
#include <QSignalSpy>
#include <QPushButton>

void KeysWidgetTests::testButtonNum0()
{
    KeysWidget widget;
    QSignalSpy spy(&widget, &KeysWidget::buttonPressed);

    QPushButton *buttonNum0 = widget.findChild<QPushButton*>("buttonNum0");
    QVERIFY(buttonNum0 != nullptr);

    QTest::mouseClick(buttonNum0, Qt::LeftButton);
    QCOMPARE(spy.count(), 1);

    QList<QVariant> args = spy.takeFirst();
    QCOMPARE(args.at(0).value<Qt::Key>(), Qt::Key_0);
}

void KeysWidgetTests::testButtonNum1()
{
    KeysWidget widget;
    QSignalSpy spy(&widget, &KeysWidget::buttonPressed);

    QPushButton *buttonNum1 = widget.findChild<QPushButton*>("buttonNum1");
    QVERIFY(buttonNum1 != nullptr);

    QTest::mouseClick(buttonNum1, Qt::LeftButton);
    QCOMPARE(spy.count(), 1);

    QList<QVariant> args = spy.takeFirst();
    QCOMPARE(args.at(0).value<Qt::Key>(), Qt::Key_1);
}

void KeysWidgetTests::testButtonNum2()
{
    KeysWidget widget;
    QSignalSpy spy(&widget, &KeysWidget::buttonPressed);

    QPushButton *buttonNum2 = widget.findChild<QPushButton*>("buttonNum2");
    QVERIFY(buttonNum2 != nullptr);

    QTest::mouseClick(buttonNum2, Qt::LeftButton);
    QCOMPARE(spy.count(), 1);

    QList<QVariant> args = spy.takeFirst();
    QCOMPARE(args.at(0).value<Qt::Key>(), Qt::Key_2);
}

void KeysWidgetTests::testButtonNum3()
{
    KeysWidget widget;
    QSignalSpy spy(&widget, &KeysWidget::buttonPressed);

    QPushButton *buttonNum3 = widget.findChild<QPushButton*>("buttonNum3");
    QVERIFY(buttonNum3 != nullptr);

    QTest::mouseClick(buttonNum3, Qt::LeftButton);
    QCOMPARE(spy.count(), 1);

    QList<QVariant> args = spy.takeFirst();
    QCOMPARE(args.at(0).value<Qt::Key>(), Qt::Key_3);
}

void KeysWidgetTests::testButtonNum4()
{
    KeysWidget widget;
    QSignalSpy spy(&widget, &KeysWidget::buttonPressed);

    QPushButton *buttonNum4 = widget.findChild<QPushButton*>("buttonNum4");
    QVERIFY(buttonNum4 != nullptr);

    QTest::mouseClick(buttonNum4, Qt::LeftButton);
    QCOMPARE(spy.count(), 1);

    QList<QVariant> args = spy.takeFirst();
    QCOMPARE(args.at(0).value<Qt::Key>(), Qt::Key_4);
}

void KeysWidgetTests::testButtonNum5()
{
    KeysWidget widget;
    QSignalSpy spy(&widget, &KeysWidget::buttonPressed);

    QPushButton *buttonNum5 = widget.findChild<QPushButton*>("buttonNum5");
    QVERIFY(buttonNum5 != nullptr);

    QTest::mouseClick(buttonNum5, Qt::LeftButton);
    QCOMPARE(spy.count(), 1);

    QList<QVariant> args = spy.takeFirst();
    QCOMPARE(args.at(0).value<Qt::Key>(), Qt::Key_5);
}

void KeysWidgetTests::testButtonNum6()
{
    KeysWidget widget;
    QSignalSpy spy(&widget, &KeysWidget::buttonPressed);

    QPushButton *buttonNum6 = widget.findChild<QPushButton*>("buttonNum6");
    QVERIFY(buttonNum6 != nullptr);

    QTest::mouseClick(buttonNum6, Qt::LeftButton);
    QCOMPARE(spy.count(), 1);

    QList<QVariant> args = spy.takeFirst();
    QCOMPARE(args.at(0).value<Qt::Key>(), Qt::Key_6);
}

void KeysWidgetTests::testButtonNum7()
{
    KeysWidget widget;
    QSignalSpy spy(&widget, &KeysWidget::buttonPressed);

    QPushButton *buttonNum7 = widget.findChild<QPushButton*>("buttonNum7");
    QVERIFY(buttonNum7 != nullptr);

    QTest::mouseClick(buttonNum7, Qt::LeftButton);
    QCOMPARE(spy.count(), 1);

    QList<QVariant> args = spy.takeFirst();
    QCOMPARE(args.at(0).value<Qt::Key>(), Qt::Key_7);
}

void KeysWidgetTests::testButtonNum8()
{
    KeysWidget widget;
    QSignalSpy spy(&widget, &KeysWidget::buttonPressed);

    QPushButton *buttonNum8 = widget.findChild<QPushButton*>("buttonNum8");
    QVERIFY(buttonNum8 != nullptr);

    QTest::mouseClick(buttonNum8, Qt::LeftButton);
    QCOMPARE(spy.count(), 1);

    QList<QVariant> args = spy.takeFirst();
    QCOMPARE(args.at(0).value<Qt::Key>(), Qt::Key_8);
}

void KeysWidgetTests::testButtonNum9()
{
    KeysWidget widget;
    QSignalSpy spy(&widget, &KeysWidget::buttonPressed);

    QPushButton *buttonNum9 = widget.findChild<QPushButton*>("buttonNum9");
    QVERIFY(buttonNum9 != nullptr);

    QTest::mouseClick(buttonNum9, Qt::LeftButton);
    QCOMPARE(spy.count(), 1);

    QList<QVariant> args = spy.takeFirst();
    QCOMPARE(args.at(0).value<Qt::Key>(), Qt::Key_9);
}

void KeysWidgetTests::testButtonNumA()
{
    KeysWidget widget;
    QSignalSpy spy(&widget, &KeysWidget::buttonPressed);

    QPushButton *buttonNumA = widget.findChild<QPushButton*>("buttonNumA");
    QVERIFY(buttonNumA != nullptr);

    QTest::mouseClick(buttonNumA, Qt::LeftButton);
    QCOMPARE(spy.count(), 1);

    QList<QVariant> args = spy.takeFirst();
    QCOMPARE(args.at(0).value<Qt::Key>(), Qt::Key_A);
}

void KeysWidgetTests::testButtonNumB()
{
    KeysWidget widget;
    QSignalSpy spy(&widget, &KeysWidget::buttonPressed);

    QPushButton *buttonNumB = widget.findChild<QPushButton*>("buttonNumB");
    QVERIFY(buttonNumB != nullptr);

    QTest::mouseClick(buttonNumB, Qt::LeftButton);
    QCOMPARE(spy.count(), 1);

    QList<QVariant> args = spy.takeFirst();
    QCOMPARE(args.at(0).value<Qt::Key>(), Qt::Key_B);
}

void KeysWidgetTests::testButtonNumC()
{
    KeysWidget widget;
    QSignalSpy spy(&widget, &KeysWidget::buttonPressed);

    QPushButton *buttonNumC = widget.findChild<QPushButton*>("buttonNumC");
    QVERIFY(buttonNumC != nullptr);

    QTest::mouseClick(buttonNumC, Qt::LeftButton);
    QCOMPARE(spy.count(), 1);

    QList<QVariant> args = spy.takeFirst();
    QCOMPARE(args.at(0).value<Qt::Key>(), Qt::Key_C);
}

void KeysWidgetTests::testButtonNumD()
{
    KeysWidget widget;
    QSignalSpy spy(&widget, &KeysWidget::buttonPressed);

    QPushButton *buttonNumD = widget.findChild<QPushButton*>("buttonNumD");
    QVERIFY(buttonNumD != nullptr);

    QTest::mouseClick(buttonNumD, Qt::LeftButton);
    QCOMPARE(spy.count(), 1);

    QList<QVariant> args = spy.takeFirst();
    QCOMPARE(args.at(0).value<Qt::Key>(), Qt::Key_D);
}

void KeysWidgetTests::testButtonNumE()
{
    KeysWidget widget;
    QSignalSpy spy(&widget, &KeysWidget::buttonPressed);

    QPushButton *buttonNumE = widget.findChild<QPushButton*>("buttonNumE");
    QVERIFY(buttonNumE != nullptr);

    QTest::mouseClick(buttonNumE, Qt::LeftButton);
    QCOMPARE(spy.count(), 1);

    QList<QVariant> args = spy.takeFirst();
    QCOMPARE(args.at(0).value<Qt::Key>(), Qt::Key_E);
}

void KeysWidgetTests::testButtonNumF()
{
    KeysWidget widget;
    QSignalSpy spy(&widget, &KeysWidget::buttonPressed);

    QPushButton *buttonNumF = widget.findChild<QPushButton*>("buttonNumF");
    QVERIFY(buttonNumF != nullptr);

    QTest::mouseClick(buttonNumF, Qt::LeftButton);
    QCOMPARE(spy.count(), 1);

    QList<QVariant> args = spy.takeFirst();
    QCOMPARE(args.at(0).value<Qt::Key>(), Qt::Key_F);
}

void KeysWidgetTests::testButtonEqual()
{
    KeysWidget widget;
    QSignalSpy spy(&widget, &KeysWidget::buttonPressed);

    QPushButton *buttonEqual = widget.findChild<QPushButton*>("buttonEqual");
    QVERIFY(buttonEqual != nullptr);

    QTest::mouseClick(buttonEqual, Qt::LeftButton);
    QCOMPARE(spy.count(), 1);

    QList<QVariant> args = spy.takeFirst();
    QCOMPARE(args.at(0).value<Qt::Key>(), Qt::Key_Equal);
}

void KeysWidgetTests::testButtonDiv()
{
    KeysWidget widget;
    QSignalSpy spy(&widget, &KeysWidget::buttonPressed);

    QPushButton *buttonDiv = widget.findChild<QPushButton*>("buttonDiv");
    QVERIFY(buttonDiv != nullptr);

    QTest::mouseClick(buttonDiv, Qt::LeftButton);
    QCOMPARE(spy.count(), 1);

    QList<QVariant> args = spy.takeFirst();
    QCOMPARE(args.at(0).value<Qt::Key>(), Qt::Key_Slash);
}

void KeysWidgetTests::testButtonMult()
{
    KeysWidget widget;
    QSignalSpy spy(&widget, &KeysWidget::buttonPressed);

    QPushButton *buttonMult = widget.findChild<QPushButton*>("buttonMult");
    QVERIFY(buttonMult != nullptr);

    QTest::mouseClick(buttonMult, Qt::LeftButton);
    QCOMPARE(spy.count(), 1);

    QList<QVariant> args = spy.takeFirst();
    QCOMPARE(args.at(0).value<Qt::Key>(), Qt::Key_Asterisk);
}

void KeysWidgetTests::testButtonMinus()
{
    KeysWidget widget;
    QSignalSpy spy(&widget, &KeysWidget::buttonPressed);

    QPushButton *buttonMinus = widget.findChild<QPushButton*>("buttonMinus");
    QVERIFY(buttonMinus != nullptr);

    QTest::mouseClick(buttonMinus, Qt::LeftButton);
    QCOMPARE(spy.count(), 1);

    QList<QVariant> args = spy.takeFirst();
    QCOMPARE(args.at(0).value<Qt::Key>(), Qt::Key_Minus);
}

void KeysWidgetTests::testButtonPlus()
{
    KeysWidget widget;
    QSignalSpy spy(&widget, &KeysWidget::buttonPressed);

    QPushButton *buttonPlus = widget.findChild<QPushButton*>("buttonPlus");
    QVERIFY(buttonPlus != nullptr);

    QTest::mouseClick(buttonPlus, Qt::LeftButton);
    QCOMPARE(spy.count(), 1);

    QList<QVariant> args = spy.takeFirst();
    QCOMPARE(args.at(0).value<Qt::Key>(), Qt::Key_Plus);
}

void KeysWidgetTests::testButtonLeftBrace()
{
    KeysWidget widget;
    QSignalSpy spy(&widget, &KeysWidget::buttonPressed);

    QPushButton *buttonLeftBrace = widget.findChild<QPushButton*>("buttonLeftBrace");
    QVERIFY(buttonLeftBrace != nullptr);

    QTest::mouseClick(buttonLeftBrace, Qt::LeftButton);
    QCOMPARE(spy.count(), 1);

    QList<QVariant> args = spy.takeFirst();
    QCOMPARE(args.at(0).value<Qt::Key>(), Qt::Key_BraceLeft);
}

void KeysWidgetTests::testButtonRightBrace()
{
    KeysWidget widget;
    QSignalSpy spy(&widget, &KeysWidget::buttonPressed);

    QPushButton *buttonRightBrace = widget.findChild<QPushButton*>("buttonRightBrace");
    QVERIFY(buttonRightBrace != nullptr);

    QTest::mouseClick(buttonRightBrace, Qt::LeftButton);
    QCOMPARE(spy.count(), 1);

    QList<QVariant> args = spy.takeFirst();
    QCOMPARE(args.at(0).value<Qt::Key>(), Qt::Key_BraceRight);
}

void KeysWidgetTests::testButtonUndo()
{
    KeysWidget widget;
    QSignalSpy spy(&widget, &KeysWidget::buttonPressed);

    QPushButton *buttonUndo = widget.findChild<QPushButton*>("buttonUndo");
    QVERIFY(buttonUndo != nullptr);

    QTest::mouseClick(buttonUndo, Qt::LeftButton);
    QCOMPARE(spy.count(), 1);

    QList<QVariant> args = spy.takeFirst();
    QCOMPARE(args.at(0).value<Qt::Key>(), Qt::Key_Undo);
}

void KeysWidgetTests::testButtonClear()
{
    KeysWidget widget;
    QSignalSpy spy(&widget, &KeysWidget::buttonPressed);

    QPushButton *buttonClear = widget.findChild<QPushButton*>("buttonClear");
    QVERIFY(buttonClear != nullptr);

    QTest::mouseClick(buttonClear, Qt::LeftButton);
    QCOMPARE(spy.count(), 1);

    QList<QVariant> args = spy.takeFirst();
    QCOMPARE(args.at(0).value<Qt::Key>(), Qt::Key_Delete);
}

void KeysWidgetTests::testKeyPressEvent()
{
    KeysWidget widget;
    QSignalSpy spy(&widget, &KeysWidget::buttonPressed);

    QTest::keyClick(&widget, Qt::Key_0);
    QCOMPARE(spy.count(), 1);

    QList<QVariant> args = spy.takeFirst();
    QCOMPARE(args.at(0).value<Qt::Key>(), Qt::Key_0);
}

// #include "KeysWidgetTests.moc"