#include "displaywidget.h"
#include "ui_displaywidget.h"

#include <lib/Calculator.h>
#include "errormessagebox.h"

DisplayWidget::DisplayWidget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::DisplayWidget)
    , tokenEmiter(nullptr)
    , calculatorDevice(nullptr)
    , errorMessage(nullptr)
{
    ui->setupUi(this);
}

DisplayWidget::~DisplayWidget()
{
    delete ui;
}

void DisplayWidget::setTokenEmiter(TokenEmiter* emiter)
{
    if (tokenEmiter != nullptr)
    {
        qWarning() << __PRETTY_FUNCTION__ << ":" << __LINE__
                   << " tokenEmiter was set. You cannot set once again";
        return;
    }
    if (emiter == nullptr)
    {
        qWarning() << __PRETTY_FUNCTION__ << ":" << __LINE__
                   << " emiter is nullptr";
        return;
    }

    tokenEmiter = emiter;
    connect(tokenEmiter, SIGNAL(token(const QString&)), this, SLOT(onTokenReceived(const QString&)));
    connect(tokenEmiter, SIGNAL(equal()), this, SLOT(onEqual()));
    connect(tokenEmiter, SIGNAL(undo()), this, SLOT(onUndo()));
    connect(tokenEmiter, SIGNAL(clear()), this, SLOT(onClear()));
}

void DisplayWidget::setCalculatorDevice(ICalculatorDevice* device)
{
    if (calculatorDevice != nullptr)
    {
        qWarning() << __PRETTY_FUNCTION__ << ":" << __LINE__
                   << " calculatorDevice was set. You cannot set once again";
        return;
    }
    if (device == nullptr)
    {
        qWarning() << __PRETTY_FUNCTION__ << ":" << __LINE__
                   << " device is nullptr";
        return;
    }
    calculatorDevice = device;
}

void DisplayWidget::setErrorMessage(IErrorMessage* errorMessage)
{
    if (this->errorMessage != nullptr)
    {
        qWarning() << __PRETTY_FUNCTION__ << ":" << __LINE__
                   << " errorMessage was set. You cannot set once again";
        return;
    }
    if (errorMessage == nullptr)
    {
        qWarning() << __PRETTY_FUNCTION__ << ":" << __LINE__
                   << " errorMessage is nullptr";
        return;
    }
    this->errorMessage = errorMessage;
}

void DisplayWidget::onTokenReceived(const QString& token)
{
    qDebug() << __PRETTY_FUNCTION__ << ":" << __LINE__ << ": token: " << token;
    QString currText = ui->inputFormula->text();
    currText.append(token);
    ui->inputFormula->setText(currText);
}

void DisplayWidget::onEqual()
{
    qDebug() << __PRETTY_FUNCTION__ << ":" << __LINE__
             << ui->inputFormula->text();
    if (calculatorDevice == nullptr)
    {
        qWarning() << __PRETTY_FUNCTION__ << __LINE__
                   << " calculatorDevice is not set";
        return;
    }
    try
    {
        ui->outputResult->setText(calculatorDevice->calculate(ui->inputFormula->text()));
    }
    catch(std::exception& err)
    {
        qWarning() << __PRETTY_FUNCTION__ << __LINE__ << err.what();
        if (errorMessage != nullptr)
        {
            errorMessage->show(QString(err.what()));
        }
    }
}

void DisplayWidget::onUndo()
{
    qDebug() << __PRETTY_FUNCTION__ << ":" << __LINE__;
    QString currText = ui->inputFormula->text();
    if (currText.isEmpty())
    {
        return;
    }
    currText.chop(1);
    ui->inputFormula->setText(currText);
}

void DisplayWidget::onClear()
{
    qDebug() << __PRETTY_FUNCTION__ << ":" << __LINE__;
    if (ui->inputFormula->text().isEmpty())
    {
        return;
    }
    ui->inputFormula->clear();
    ui->outputResult->setText(QString("0"));
}
