#include "MainWindowTests.h"

#include "mainwindow.h"
#include "keyswidget.h"
#include "displaywidget.h"

#include <QTest>
#include <QLabel>

void MainWindowTests::testHandleOnButtonPressedSignal()
{
    MainWindow mainWindow;
    KeysWidget* keysWidget = mainWindow.findChild<KeysWidget*>("keysWidget");
    QVERIFY(keysWidget != nullptr);

    DisplayWidget* displayWidget = mainWindow.findChild<DisplayWidget*>("displayWidget");
    QVERIFY(displayWidget != nullptr);

    QLabel* outputResult = displayWidget->findChild<QLabel*>("outputResult");
    QVERIFY(outputResult != nullptr);

    emit keysWidget->buttonPressed(Qt::Key_A);
    emit keysWidget->buttonPressed(Qt::Key_Equal);

    QCOMPARE(outputResult->text().toStdString().c_str(), "A");
}