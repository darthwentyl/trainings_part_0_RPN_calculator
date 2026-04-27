#ifndef TOKENEMITER_H
#define TOKENEMITER_H

#include <QObject>
#include <QString>

class TokenEmiter : public QObject
{
    Q_OBJECT

public:
    void emitToken(Qt::Key key);

Q_SIGNALS:
    void token(const QString& token);
    void equal();
    void undo();
    void clear();
    void unknown(Qt::Key key);
};

#endif // TOKENEMITER_H
