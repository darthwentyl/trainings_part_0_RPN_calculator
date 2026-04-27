#include <QDebug>
#include <QKeyEvent>

#include "keyswidget.h"
#include "ui_keyswidget.h"

KeysWidget::KeysWidget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::KeysWidget)
{
    qDebug() << __PRETTY_FUNCTION__ << ":" << __LINE__;

    setFocusPolicy(Qt::StrongFocus);

    ui->setupUi(this);

    connect(ui->buttonNum0, SIGNAL(pressed()), this, SLOT(onPressedButtonNum0()));
    connect(ui->buttonNum1, SIGNAL(pressed()), this, SLOT(onPressedButtonNum1()));
    connect(ui->buttonNum2, SIGNAL(pressed()), this, SLOT(onPressedButtonNum2()));
    connect(ui->buttonNum3, SIGNAL(pressed()), this, SLOT(onPressedButtonNum3()));
    connect(ui->buttonNum4, SIGNAL(pressed()), this, SLOT(onPressedButtonNum4()));
    connect(ui->buttonNum5, SIGNAL(pressed()), this, SLOT(onPressedButtonNum5()));
    connect(ui->buttonNum6, SIGNAL(pressed()), this, SLOT(onPressedButtonNum6()));
    connect(ui->buttonNum7, SIGNAL(pressed()), this, SLOT(onPressedButtonNum7()));
    connect(ui->buttonNum8, SIGNAL(pressed()), this, SLOT(onPressedButtonNum8()));
    connect(ui->buttonNum9, SIGNAL(pressed()), this, SLOT(onPressedButtonNum9()));
    connect(ui->buttonNumA, SIGNAL(pressed()), this, SLOT(onPressedButtonNumA()));
    connect(ui->buttonNumB, SIGNAL(pressed()), this, SLOT(onPressedButtonNumB()));
    connect(ui->buttonNumC, SIGNAL(pressed()), this, SLOT(onPressedButtonNumC()));
    connect(ui->buttonNumD, SIGNAL(pressed()), this, SLOT(onPressedButtonNumD()));
    connect(ui->buttonNumE, SIGNAL(pressed()), this, SLOT(onPressedButtonNumE()));
    connect(ui->buttonNumF, SIGNAL(pressed()), this, SLOT(onPressedButtonNumF()));
    connect(ui->buttonEqual, SIGNAL(pressed()), this, SLOT(onPressedButtonEqual()));
    connect(ui->buttonDiv, SIGNAL(pressed()), this, SLOT(onPressedButtonDiv()));
    connect(ui->buttonMult, SIGNAL(pressed()), this, SLOT(onPressedButtonMult()));
    connect(ui->buttonMinus, SIGNAL(pressed()), this, SLOT(onPressedButtonMinus()));
    connect(ui->buttonPlus, SIGNAL(pressed()), this, SLOT(onPressedButtonPlus()));
    connect(ui->buttonLeftBrace, SIGNAL(pressed()), this, SLOT(onPressedButtonLeftBrace()));
    connect(ui->buttonRightBrace, SIGNAL(pressed()), this, SLOT(onPressedButtonRightBrace()));
    connect(ui->buttonUndo, SIGNAL(pressed()), this, SLOT(onPressedButtonUndo()));
    connect(ui->buttonClear, SIGNAL(pressed()), this, SLOT(onPressedButtonClear()));
}

KeysWidget::~KeysWidget()
{
    qDebug() << __PRETTY_FUNCTION__ << ":" << __LINE__;
    delete ui;
}

void KeysWidget::keyPressEvent(QKeyEvent* event) {
    qDebug() << __PRETTY_FUNCTION__ << ":" << __LINE__ << ": event:" << event->text();
    Qt::Key key = static_cast<Qt::Key>(event->key());
    emit buttonPressed(key);
}

void KeysWidget::onPressedButtonNum0()
{
    qDebug() << __PRETTY_FUNCTION__ << ":" << __LINE__;
    emit buttonPressed(Qt::Key_0);
}

void KeysWidget::onPressedButtonNum1()
{
    qDebug() << __PRETTY_FUNCTION__ << ":" << __LINE__;
    emit buttonPressed(Qt::Key_1);
}

void KeysWidget::onPressedButtonNum2()
{
    qDebug() << __PRETTY_FUNCTION__ << ":" << __LINE__;
    emit buttonPressed(Qt::Key_2);
}

void KeysWidget::onPressedButtonNum3()
{
    qDebug() << __PRETTY_FUNCTION__ << ":" << __LINE__;
    emit buttonPressed(Qt::Key_3);
}

void KeysWidget::onPressedButtonNum4()
{
    qDebug() << __PRETTY_FUNCTION__ << ":" << __LINE__;
    emit buttonPressed(Qt::Key_4);
}

void KeysWidget::onPressedButtonNum5()
{
    qDebug() << __PRETTY_FUNCTION__ << ":" << __LINE__;
    emit buttonPressed(Qt::Key_5);
}

void KeysWidget::onPressedButtonNum6()
{
    qDebug() << __PRETTY_FUNCTION__ << ":" << __LINE__;
    emit buttonPressed(Qt::Key_6);
}

void KeysWidget::onPressedButtonNum7()
{
    qDebug() << __PRETTY_FUNCTION__ << ":" << __LINE__;
    emit buttonPressed(Qt::Key_7);
}

void KeysWidget::onPressedButtonNum8()
{
    qDebug() << __PRETTY_FUNCTION__ << ":" << __LINE__;
    emit buttonPressed(Qt::Key_8);
}

void KeysWidget::onPressedButtonNum9()
{
    qDebug() << __PRETTY_FUNCTION__ << ":" << __LINE__;
    emit buttonPressed(Qt::Key_9);
}

void KeysWidget::onPressedButtonNumA()
{
    qDebug() << __PRETTY_FUNCTION__ << ":" << __LINE__;
    emit buttonPressed(Qt::Key_A);
}

void KeysWidget::onPressedButtonNumB()
{
    qDebug() << __PRETTY_FUNCTION__ << ":" << __LINE__;
    emit buttonPressed(Qt::Key_B);
}

void KeysWidget::onPressedButtonNumC()
{
    qDebug() << __PRETTY_FUNCTION__ << ":" << __LINE__;
    emit buttonPressed(Qt::Key_C);
}

void KeysWidget::onPressedButtonNumD()
{
    qDebug() << __PRETTY_FUNCTION__ << ":" << __LINE__;
    emit buttonPressed(Qt::Key_D);
}

void KeysWidget::onPressedButtonNumE()
{
    qDebug() << __PRETTY_FUNCTION__ << ":" << __LINE__;
    emit buttonPressed(Qt::Key_E);
}

void KeysWidget::onPressedButtonNumF()
{
    qDebug() << __PRETTY_FUNCTION__ << ":" << __LINE__;
    emit buttonPressed(Qt::Key_F);
}

void KeysWidget::onPressedButtonEqual()
{
    qDebug() << __PRETTY_FUNCTION__ << ":" << __LINE__;
    emit buttonPressed(Qt::Key_Equal);
}

void KeysWidget::onPressedButtonDiv()
{
    qDebug() << __PRETTY_FUNCTION__ << ":" << __LINE__;
    emit buttonPressed(Qt::Key_Slash);
}

void KeysWidget::onPressedButtonMult()
{
    qDebug() << __PRETTY_FUNCTION__ << ":" << __LINE__;
    emit buttonPressed(Qt::Key_Asterisk);
}

void KeysWidget::onPressedButtonMinus()
{
    qDebug() << __PRETTY_FUNCTION__ << ":" << __LINE__;
    emit buttonPressed(Qt::Key_Minus);
}

void KeysWidget::onPressedButtonPlus()
{
    qDebug() << __PRETTY_FUNCTION__ << ":" << __LINE__;
    emit buttonPressed(Qt::Key_Plus);
}

void KeysWidget::onPressedButtonLeftBrace()
{
    qDebug() << __PRETTY_FUNCTION__ << ":" << __LINE__;
    emit buttonPressed(Qt::Key_BraceLeft);
}

void KeysWidget::onPressedButtonRightBrace()
{
    qDebug() << __PRETTY_FUNCTION__ << ":" << __LINE__;
    emit buttonPressed(Qt::Key_BraceRight);
}

void KeysWidget::onPressedButtonUndo()
{
    qDebug() << __PRETTY_FUNCTION__ << ":" << __LINE__;
    emit buttonPressed(Qt::Key_Undo);
}

void KeysWidget::onPressedButtonClear()
{
    qDebug() << __PRETTY_FUNCTION__ << ":" << __LINE__;
    emit buttonPressed(Qt::Key_Delete);
}
