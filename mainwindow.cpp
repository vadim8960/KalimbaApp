#include "mainwindow.h"
#include "./ui_mainwindow.h"

#include <QVBoxLayout>

MainWindow::MainWindow(QWidget* parent) : QMainWindow(parent), ui(new Ui::MainWindow) {
    ui->setupUi(this);
    //    ui->pushButton->setAutoRepeat(false);
    //    ui->spinBox->setValue(9);
    //    ui->spinBox->setSingleStep(2);
    _btn_handler = new ButtonsHandler(this, 9, this->size());
}

MainWindow::~MainWindow() {
    delete ui;
}

void MainWindow::resizeEvent(QResizeEvent* iconSize) {
    _btn_handler->ButtonsResize(iconSize->size());
}
