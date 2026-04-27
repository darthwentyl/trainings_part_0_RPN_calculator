#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    setFixedSize(370, 460);

    ui->setupUi(this);
    ui->displayWidget->setTokenEmiter(&tokenEmiter);
    ui->displayWidget->setCalculatorDevice(&calculatorDevice);
    ui->displayWidget->setErrorMessage(&errorMessageBox);

    connect(ui->keysWidget, SIGNAL(buttonPressed(Qt::Key)), this, SLOT(onButtonPressed(Qt::Key)));
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::onButtonPressed(Qt::Key key) {
    qDebug() << __PRETTY_FUNCTION__ << ":" << __LINE__ << ": key: " << key;
    tokenEmiter.emitToken(key);
}
