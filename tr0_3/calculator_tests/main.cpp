#include <QTest>
#include <QDebug>
#include <QApplication>

#include "KeysWidgetTests.h"
#include "MainWindowTests.h"
#include "TokenEmiterTests.h"
#include "DisplayWidgetTests.h"
#include "MyHexTests.h"
#include "MyHexParserTests.h"

int main(int argc, char** argv) {
    int status = 0;

    QApplication app(argc, argv);

    auto runTest = [&status, &argc, argv](QObject* test) {
        qDebug() << "Running " << test->metaObject()->className() << "...";
        status |= QTest::qExec(test, argc, argv);
        delete test;
    };

    runTest(new KeysWidgetTests{});
    runTest(new MainWindowTests{});
    runTest(new TokenEmiterTests{});
    runTest(new DisplayWidgetTests{});
    runTest(new MyHexTests{});
    runTest(new MyHexParserTests{});

    return status;
}