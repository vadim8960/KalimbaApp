#ifndef BUTTONSHANDLER_H
#define BUTTONSHANDLER_H

#include <QColor>
#include <QDebug>
#include <QObject>
#include <QPushButton>
#include <QSize>
#include <QSound>
#include <QVector>
#include <QWidget>
#include <QtGui>

class ButtonsHandler : public QWidget {
    Q_OBJECT

  public:
    ButtonsHandler(QWidget* parent, int count_keys, QSize win_size);
    void ButtonsResize(QSize win_size);
    void KeyPressedHandler(int key_code);
    void KeyReleaseHandler(int key_code);

    ~ButtonsHandler();

  private:
    QVector<QPair<int, QPushButton*>> _keys;
};

#endif    // BUTTONSHANDLER_H
