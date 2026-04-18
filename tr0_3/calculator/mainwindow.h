#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

#include "tokenemiter.h"
#include "calculatordevice.h"
#include "errormessagebox.h"

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private Q_SLOTS:
    void onButtonPressed(Qt::Key key);

private:
    Ui::MainWindow *ui;
    TokenEmiter tokenEmiter;
    CalculatorDevice calculatorDevice;
    ErrorMessageBox errorMessageBox;
};
#endif // MAINWINDOW_H
