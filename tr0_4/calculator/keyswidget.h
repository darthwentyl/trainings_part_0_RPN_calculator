#ifndef KEYSWIDGET_H
#define KEYSWIDGET_H

#include <QWidget>

namespace Ui {
class KeysWidget;
}

class KeysWidget : public QWidget
{
    Q_OBJECT

public:
    explicit KeysWidget(QWidget *parent = nullptr);
    ~KeysWidget();

Q_SIGNALS:
    void buttonPressed(Qt::Key key);

protected:
    void keyPressEvent(QKeyEvent* event) override;

private Q_SLOTS:
    void onPressedButtonNum0();
    void onPressedButtonNum1();
    void onPressedButtonNum2();
    void onPressedButtonNum3();
    void onPressedButtonNum4();
    void onPressedButtonNum5();
    void onPressedButtonNum6();
    void onPressedButtonNum7();
    void onPressedButtonNum8();
    void onPressedButtonNum9();
    void onPressedButtonNumA();
    void onPressedButtonNumB();
    void onPressedButtonNumC();
    void onPressedButtonNumD();
    void onPressedButtonNumE();
    void onPressedButtonNumF();
    void onPressedButtonEqual();
    void onPressedButtonDiv();
    void onPressedButtonMult();
    void onPressedButtonMinus();
    void onPressedButtonPlus();
    void onPressedButtonLeftBrace();
    void onPressedButtonRightBrace();
    void onPressedButtonUndo();
    void onPressedButtonClear();

private:
    Ui::KeysWidget *ui;
};

#endif // KEYSWIDGET_H
