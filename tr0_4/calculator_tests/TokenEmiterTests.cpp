#include "TokenEmiterTests.h"

#include "tokenemiter.h"

#include <QTest>
#include <QSignalSpy>

void TokenEmiterTests::testNum0()
{
    TokenEmiter emiter;
    QSignalSpy spy(&emiter, &TokenEmiter::token);

    emiter.emitToken(Qt::Key_0);
    QCOMPARE(spy.count(), 1);

    QList<QVariant> args = spy.takeFirst();
    QCOMPARE(args.at(0).value<QString>(), "0");
}

void TokenEmiterTests::testNum1()
{
    TokenEmiter emiter;
    QSignalSpy spy(&emiter, &TokenEmiter::token);

    emiter.emitToken(Qt::Key_1);
    QCOMPARE(spy.count(), 1);

    QList<QVariant> args = spy.takeFirst();
    QCOMPARE(args.at(0).value<QString>(), "1");
}

void TokenEmiterTests::testNum2()
{
    TokenEmiter emiter;
    QSignalSpy spy(&emiter, &TokenEmiter::token);

    emiter.emitToken(Qt::Key_2);
    QCOMPARE(spy.count(), 1);

    QList<QVariant> args = spy.takeFirst();
    QCOMPARE(args.at(0).value<QString>(), "2");
}

void TokenEmiterTests::testNum3()
{
    TokenEmiter emiter;
    QSignalSpy spy(&emiter, &TokenEmiter::token);

    emiter.emitToken(Qt::Key_3);
    QCOMPARE(spy.count(), 1);

    QList<QVariant> args = spy.takeFirst();
    QCOMPARE(args.at(0).value<QString>(), "3");
}

void TokenEmiterTests::testNum4()
{
    TokenEmiter emiter;
    QSignalSpy spy(&emiter, &TokenEmiter::token);

    emiter.emitToken(Qt::Key_4);
    QCOMPARE(spy.count(), 1);

    QList<QVariant> args = spy.takeFirst();
    QCOMPARE(args.at(0).value<QString>(), "4");
}

void TokenEmiterTests::testNum5()
{
    TokenEmiter emiter;
    QSignalSpy spy(&emiter, &TokenEmiter::token);

    emiter.emitToken(Qt::Key_5);
    QCOMPARE(spy.count(), 1);

    QList<QVariant> args = spy.takeFirst();
    QCOMPARE(args.at(0).value<QString>(), "5");
}

void TokenEmiterTests::testNum6()
{
    TokenEmiter emiter;
    QSignalSpy spy(&emiter, &TokenEmiter::token);

    emiter.emitToken(Qt::Key_6);
    QCOMPARE(spy.count(), 1);

    QList<QVariant> args = spy.takeFirst();
    QCOMPARE(args.at(0).value<QString>(), "6");
}

void TokenEmiterTests::testNum7()
{
    TokenEmiter emiter;
    QSignalSpy spy(&emiter, &TokenEmiter::token);

    emiter.emitToken(Qt::Key_7);
    QCOMPARE(spy.count(), 1);

    QList<QVariant> args = spy.takeFirst();
    QCOMPARE(args.at(0).value<QString>(), "7");
}

void TokenEmiterTests::testNum8()
{
    TokenEmiter emiter;
    QSignalSpy spy(&emiter, &TokenEmiter::token);

    emiter.emitToken(Qt::Key_8);
    QCOMPARE(spy.count(), 1);

    QList<QVariant> args = spy.takeFirst();
    QCOMPARE(args.at(0).value<QString>(), "8");
}

void TokenEmiterTests::testNum9()
{
    TokenEmiter emiter;
    QSignalSpy spy(&emiter, &TokenEmiter::token);

    emiter.emitToken(Qt::Key_9);
    QCOMPARE(spy.count(), 1);

    QList<QVariant> args = spy.takeFirst();
    QCOMPARE(args.at(0).value<QString>(), "9");
}

void TokenEmiterTests::testNumA()
{
    TokenEmiter emiter;
    QSignalSpy spy(&emiter, &TokenEmiter::token);

    emiter.emitToken(Qt::Key_A);
    QCOMPARE(spy.count(), 1);

    QList<QVariant> args = spy.takeFirst();
    QCOMPARE(args.at(0).value<QString>(), "A");
}

void TokenEmiterTests::testNumB()
{
    TokenEmiter emiter;
    QSignalSpy spy(&emiter, &TokenEmiter::token);

    emiter.emitToken(Qt::Key_B);
    QCOMPARE(spy.count(), 1);

    QList<QVariant> args = spy.takeFirst();
    QCOMPARE(args.at(0).value<QString>(), "B");
}

void TokenEmiterTests::testNumC()
{
    TokenEmiter emiter;
    QSignalSpy spy(&emiter, &TokenEmiter::token);

    emiter.emitToken(Qt::Key_C);
    QCOMPARE(spy.count(), 1);

    QList<QVariant> args = spy.takeFirst();
    QCOMPARE(args.at(0).value<QString>(), "C");
}

void TokenEmiterTests::testNumD()
{
    TokenEmiter emiter;
    QSignalSpy spy(&emiter, &TokenEmiter::token);

    emiter.emitToken(Qt::Key_D);
    QCOMPARE(spy.count(), 1);

    QList<QVariant> args = spy.takeFirst();
    QCOMPARE(args.at(0).value<QString>(), "D");
}

void TokenEmiterTests::testNumE()
{
    TokenEmiter emiter;
    QSignalSpy spy(&emiter, &TokenEmiter::token);

    emiter.emitToken(Qt::Key_E);
    QCOMPARE(spy.count(), 1);

    QList<QVariant> args = spy.takeFirst();
    QCOMPARE(args.at(0).value<QString>(), "E");
}

void TokenEmiterTests::testNumF()
{
    TokenEmiter emiter;
    QSignalSpy spy(&emiter, &TokenEmiter::token);

    emiter.emitToken(Qt::Key_F);
    QCOMPARE(spy.count(), 1);

    QList<QVariant> args = spy.takeFirst();
    QCOMPARE(args.at(0).value<QString>(), "F");
}

void TokenEmiterTests::testEqual()
{
    TokenEmiter emiter;
    QSignalSpy spy(&emiter, &TokenEmiter::equal);

    emiter.emitToken(Qt::Key_Equal);
    QCOMPARE(spy.count(), 1);
}

void TokenEmiterTests::testEnter()
{
    TokenEmiter emiter;
    QSignalSpy spy(&emiter, &TokenEmiter::equal);

    emiter.emitToken(Qt::Key_Enter);
    QCOMPARE(spy.count(), 1);
}

void TokenEmiterTests::testReturn()
{
    TokenEmiter emiter;
    QSignalSpy spy(&emiter, &TokenEmiter::equal);

    emiter.emitToken(Qt::Key_Return);
    QCOMPARE(spy.count(), 1);
}

void TokenEmiterTests::testDiv()
{
    TokenEmiter emiter;
    QSignalSpy spy(&emiter, &TokenEmiter::token);

    emiter.emitToken(Qt::Key_Slash);
    QCOMPARE(spy.count(), 1);

    QList<QVariant> args = spy.takeFirst();
    QCOMPARE(args.at(0).value<QString>(), "/");
}

void TokenEmiterTests::testMult()
{
    TokenEmiter emiter;
    QSignalSpy spy(&emiter, &TokenEmiter::token);

    emiter.emitToken(Qt::Key_Asterisk);
    QCOMPARE(spy.count(), 1);

    QList<QVariant> args = spy.takeFirst();
    QCOMPARE(args.at(0).value<QString>(), "*");
}

void TokenEmiterTests::testMinus()
{
    TokenEmiter emiter;
    QSignalSpy spy(&emiter, &TokenEmiter::token);

    emiter.emitToken(Qt::Key_Minus);
    QCOMPARE(spy.count(), 1);

    QList<QVariant> args = spy.takeFirst();
    QCOMPARE(args.at(0).value<QString>(), "-");
}

void TokenEmiterTests::testPlus()
{
    TokenEmiter emiter;
    QSignalSpy spy(&emiter, &TokenEmiter::token);

    emiter.emitToken(Qt::Key_Plus);
    QCOMPARE(spy.count(), 1);

    QList<QVariant> args = spy.takeFirst();
    QCOMPARE(args.at(0).value<QString>(), "+");
}

void TokenEmiterTests::testLeftBrace()
{
    TokenEmiter emiter;
    QSignalSpy spy(&emiter, &TokenEmiter::token);

    emiter.emitToken(Qt::Key_BraceLeft);
    QCOMPARE(spy.count(), 1);

    QList<QVariant> args = spy.takeFirst();
    QCOMPARE(args.at(0).value<QString>(), "(");
}

void TokenEmiterTests::testParenLeft()
{
    TokenEmiter emiter;
    QSignalSpy spy(&emiter, &TokenEmiter::token);

    emiter.emitToken(Qt::Key_ParenLeft);
    QCOMPARE(spy.count(), 1);

    QList<QVariant> args = spy.takeFirst();
    QCOMPARE(args.at(0).value<QString>(), "(");
}

void TokenEmiterTests::testRightBrace()
{
    TokenEmiter emiter;
    QSignalSpy spy(&emiter, &TokenEmiter::token);

    emiter.emitToken(Qt::Key_BraceRight);
    QCOMPARE(spy.count(), 1);

    QList<QVariant> args = spy.takeFirst();
    QCOMPARE(args.at(0).value<QString>(), ")");
}

void TokenEmiterTests::testParenRight()
{
    TokenEmiter emiter;
    QSignalSpy spy(&emiter, &TokenEmiter::token);

    emiter.emitToken(Qt::Key_ParenRight);
    QCOMPARE(spy.count(), 1);

    QList<QVariant> args = spy.takeFirst();
    QCOMPARE(args.at(0).value<QString>(), ")");
}

void TokenEmiterTests::testUndo()
{
    TokenEmiter emiter;
    QSignalSpy spy(&emiter, &TokenEmiter::undo);

    emiter.emitToken(Qt::Key_Undo);
    QCOMPARE(spy.count(), 1);
}

void TokenEmiterTests::testBackspace()
{
    TokenEmiter emiter;
    QSignalSpy spy(&emiter, &TokenEmiter::undo);

    emiter.emitToken(Qt::Key_Backspace);
    QCOMPARE(spy.count(), 1);
}

void TokenEmiterTests::testClear()
{
    TokenEmiter emiter;
    QSignalSpy spy(&emiter, &TokenEmiter::clear);

    emiter.emitToken(Qt::Key_Delete);
    QCOMPARE(spy.count(), 1);
}

void TokenEmiterTests::testUnknown()
{
    TokenEmiter emiter;
    QSignalSpy spy(&emiter, &TokenEmiter::unknown);

    emiter.emitToken(Qt::Key_Exit);
    QCOMPARE(spy.count(), 1);

    QList<QVariant> args = spy.takeFirst();
    QCOMPARE(args.at(0).value<Qt::Key>(), Qt::Key_Exit);
}