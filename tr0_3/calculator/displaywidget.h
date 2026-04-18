#ifndef DISPLAYWIDGET_H
#define DISPLAYWIDGET_H

#include <QWidget>

#include "icalculatordevice.h"
#include "tokenemiter.h"
#include "ierrormessage.h"

namespace Ui {
class DisplayWidget;
}

class DisplayWidget : public QWidget
{
    Q_OBJECT

public:
    explicit DisplayWidget(QWidget *parent = nullptr);
    ~DisplayWidget();

    void setTokenEmiter(TokenEmiter* emiter);
    void setCalculatorDevice(ICalculatorDevice* device);
    void setErrorMessage(IErrorMessage* errorMessage);

private Q_SLOTS:
    void onTokenReceived(const QString& token);
    void onEqual();
    void onUndo();
    void onClear();

private:
    Ui::DisplayWidget *ui;
    TokenEmiter* tokenEmiter;
    ICalculatorDevice* calculatorDevice;
    IErrorMessage* errorMessage;
};

#endif // DISPLAYWIDGET_H
