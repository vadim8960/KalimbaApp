#include "mainwindow.h"
#include "./ui_mainwindow.h"

#define SPIN_BOX_MIN_VALUE 1
#define SPIN_BOX_MAX_VALUE 21

MainWindow::MainWindow(QWidget* parent) : QMainWindow(parent), ui(new Ui::MainWindow) {
    ui->setupUi(this);
    this->setMinimumSize(300, 300);
    _spin_box = new QSpinBox(this);
    _spin_box->setValue(9);
    _spin_box->setSingleStep(2);
    _btn_handler = new ButtonsHandler(this, _spin_box->value(), this->size());

    connect(_spin_box, &QSpinBox::valueChanged, this, &MainWindow::_change_value);
}

MainWindow::~MainWindow() {
    delete ui;
}

void MainWindow::resizeEvent(QResizeEvent* iconSize) {
    _btn_handler->ButtonsResize(iconSize->size());
}

void MainWindow::_change_value(int value) {
    if (value < SPIN_BOX_MIN_VALUE) {
        _spin_box->setValue(SPIN_BOX_MIN_VALUE);
        return;
    }

    if (value > SPIN_BOX_MAX_VALUE) {
        _spin_box->setValue(SPIN_BOX_MAX_VALUE);
        return;
    }

    delete _btn_handler;

    _btn_handler = new ButtonsHandler(this, value, this->size());
}
