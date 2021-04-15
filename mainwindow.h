#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "buttonshandler.h"

// QT_BEGIN_NAMESPACE
// namespace Ui {
// class MainWindow;
//}
// QT_END_NAMESPACE

class MainWindow : public QMainWindow {
    Q_OBJECT

  public:
    MainWindow(QWidget* parent = nullptr);
    ~MainWindow();
    void resizeEvent(QResizeEvent* iconSize);

  private:
    //    Ui::MainWindow* ui;

    ButtonsHandler* _btn_handler;
};
#endif    // MAINWINDOW_H
