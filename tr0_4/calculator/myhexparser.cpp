#include <myhexparser.h>

#include <stdexcept>

#include <QDebug>
#include <QString>

MyHex MyHexParser::parse(const std::string& str, std::function<int(int)> isNumber __attribute__((unused)))
{
    if (str.empty()) {
        throw std::runtime_error("str cannot be empty");
    }

    bool ok = false;
    QString hexNum = str.c_str();
    unsigned number = hexNum.toUInt(&ok, 16);
    if (!ok) {
        QString warning = "Convertion failed for hex num " + hexNum;
        qWarning() << warning;
        throw std::runtime_error(warning.toStdString());
    }
    return MyHex{number};
}
