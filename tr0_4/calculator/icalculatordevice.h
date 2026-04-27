#ifndef ICALCULATORDEVICE_H
#define ICALCULATORDEVICE_H

#include <QString>

class ICalculatorDevice
{
public:
    virtual ~ICalculatorDevice() = default;

    virtual QString calculate(const QString& formula) = 0;

};

#endif // ICALCULATORDEVICE_H
