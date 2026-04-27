#pragma once

#include <QObject>

class MainWindowTests : public QObject
{
    Q_OBJECT

private Q_SLOTS:
    void testHandleOnButtonPressedSignal();
};