#include "mainwindow.h"
//#include "./ui_mainwindow.h"

#include <QHBoxLayout>

MainWindow::MainWindow(QWidget* parent) : QMainWindow(parent) /*ui(new Ui::MainWindow)*/ {
    //    ui->setupUi(this);
    //    ui->pushButton->setAutoRepeat(false);
    //    ui->spinBox->setValue(9);
    //    ui->spinBox->setSingleStep(2);
    //  _btn_handler = new ButtonsHandler(this, 9, this->size());
    QHBoxLayout* tmp = new QHBoxLayout;
    QWidget* centralWgt = new QWidget;

    centralWgt->setLayout(tmp);
    tmp->setSpacing(30);

    for (int i = 0; i < 5; i++) {
        QPushButton* tmp_button = new QPushButton(QString::number(i));
        tmp_button->setMinimumSize(100, 100);
        tmp->addWidget(tmp_button);
    }

    setCentralWidget(centralWgt);
}

MainWindow::~MainWindow() {
    // delete ui;
}

void MainWindow::resizeEvent(QResizeEvent* iconSize) {
    //    _btn_handler->ButtonsResize(iconSize->size());
}
