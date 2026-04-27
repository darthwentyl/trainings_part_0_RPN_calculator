#pragma once

#include <gmock/gmock.h>

#include "icalculatordevice.h"

class CalculatorDeviceMock : public ICalculatorDevice
{
public:
    ~CalculatorDeviceMock() = default;

    MOCK_METHOD(QString, calculate, (const QString& formula), (override));
};