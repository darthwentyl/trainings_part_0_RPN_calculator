#ifndef CALCULATORDEVICE_H
#define CALCULATORDEVICE_H

#include <icalculatordevice.h>

class CalculatorDevice : public ICalculatorDevice
{
public:
    ~CalculatorDevice() = default;

    QString calculate(const QString& formula) override;
};

#endif // CALCULATORDEVICE_H
