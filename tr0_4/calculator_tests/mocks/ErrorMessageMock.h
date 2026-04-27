#pragma once

#include <gmock/gmock.h>

#include "ierrormessage.h"

class ErrorMessageMock : public IErrorMessage
{
public:
    ~ErrorMessageMock() = default;

    MOCK_METHOD(void, show, (const QString&), (override));
};