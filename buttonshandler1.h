#ifndef BUTTONSHANDLER_H
#define BUTTONSHANDLER_H

#include <QColor>
#include <QDebug>
#include <QObject>
#include <QPushButton>
#include <QSize>
#include <QVector>
#include <QWidget>
#include <QtGui>

class ButtonsHandler : public QObject {
    Q_OBJECT

  public:
    ButtonsHandler(QWidget* parent, int count_keys, QSize win_size);
    void ButtonsResize(QSize win_size);
    void keyPressEvent(QKeyEvent* event);
    void keyReleaseEvent(QKeyEvent* event);

    ~ButtonsHandler();

  private:
    QVector<QPushButton*> _keys;
};

#endif    // BUTTONSHANDLER_H
