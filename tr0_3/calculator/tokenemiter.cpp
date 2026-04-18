#include "tokenemiter.h"

#include <QDebug>

void TokenEmiter::emitToken(Qt::Key key)
{
    qDebug() << __PRETTY_FUNCTION__ << ":" << __LINE__ << ": key: " << key;
    switch(key) {
    case Qt::Key_0: emit token(QString("0")); break;
    case Qt::Key_1: emit token(QString("1")); break;
    case Qt::Key_2: emit token(QString("2")); break;
    case Qt::Key_3: emit token(QString("3")); break;
    case Qt::Key_4: emit token(QString("4")); break;
    case Qt::Key_5: emit token(QString("5")); break;
    case Qt::Key_6: emit token(QString("6")); break;
    case Qt::Key_7: emit token(QString("7")); break;
    case Qt::Key_8: emit token(QString("8")); break;
    case Qt::Key_9: emit token(QString("9")); break;
    case Qt::Key_A: emit token(QString("A")); break;
    case Qt::Key_B: emit token(QString("B")); break;
    case Qt::Key_C: emit token(QString("C")); break;
    case Qt::Key_D: emit token(QString("D")); break;
    case Qt::Key_E: emit token(QString("E")); break;
    case Qt::Key_F: emit token(QString("F")); break;
    case Qt::Key_Slash: emit token(QString("/")); break;
    case Qt::Key_Asterisk: emit token(QString("*")); break;
    case Qt::Key_Minus: emit token(QString("-")); break;
    case Qt::Key_Plus: emit token(QString("+")); break;
    case Qt::Key_BraceLeft:
    case Qt::Key_ParenLeft:
        emit token(QString("(")); break;
    case Qt::Key_BraceRight:
    case Qt::Key_ParenRight:
        emit token(QString(")")); break;
    case Qt::Key_Equal:
    case Qt::Key_Enter:
    case Qt::Key_Return:
        emit equal(); break;
    case Qt::Key_Undo:
    case Qt::Key_Backspace:
        emit undo(); break;
    case Qt::Key_Delete: emit clear(); break;
    default: emit unknown(key);
    }
}
