#include "errormessagebox.h"

#include <QMessageBox>

void ErrorMessageBox::show(const QString& msg)
{
    QMessageBox messageBox;
    messageBox.setIcon(QMessageBox::Warning);
    messageBox.setText("An warning occured");
    messageBox.setInformativeText(msg);
    messageBox.exec();
}
