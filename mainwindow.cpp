#include "mainwindow.h"
#include "./ui_mainwindow.h"

#define SPIN_BOX_MIN_VALUE 1
#define SPIN_BOX_MAX_VALUE MAX_COUNT_KEYS
#define SPIN_BOX_BEGIN_VALUE 11
#define BTN_SAVE_COUNT_BNTS_SPC 10

MainWindow::MainWindow(QWidget* parent) : QMainWindow(parent), ui(new Ui::MainWindow) {
    ui->setupUi(this);
    this->setMinimumSize(300, 300);
    _spin_box = new QSpinBox(this);
    _spin_box->setValue(SPIN_BOX_BEGIN_VALUE);
    _spin_box->setSingleStep(2);

    _btn_change_ck = new QPushButton(this);
    _btn_change_ck->setGeometry(
            _spin_box->geometry().x(),
            _spin_box->geometry().y() + _spin_box->geometry().height() + BTN_SAVE_COUNT_BNTS_SPC,
            _spin_box->geometry().width(),
            _spin_box->geometry().height());
    _btn_change_ck->setText("Save");
    connect(_btn_change_ck, &QPushButton::clicked, this, &MainWindow::_change_value);

    _btn_handler = new ButtonsHandler(this, _spin_box->value(), this->size());
}

MainWindow::~MainWindow() {
    delete ui;
}

void MainWindow::resizeEvent(QResizeEvent* iconSize) {
    _btn_handler->ButtonsResize(iconSize->size());
}

void MainWindow::keyPressEvent(QKeyEvent* event) {
    _btn_handler->KeyPressedHandler(event->key());
}

void MainWindow::keyReleaseEvent(QKeyEvent* event) {
    //    ui->pushButton->released();
    //    ui->pushButton->setFlat(false);
    //    auto pal = ui->pushButton->palette();
    //    pal.setColor(QPalette::Button, QColor::fromRgb(128, 128, 128));
    //    ui->pushButton->setPalette(pal);
    //    ui->pushButton->update();
    //    Qt::Key_0
    _btn_handler->KeyReleaseHandler(event->key());
}

void MainWindow::_change_value() {
    if (_spin_box->value() < SPIN_BOX_MIN_VALUE) {
        _spin_box->setValue(SPIN_BOX_MIN_VALUE);
        return;
    }

    if (_spin_box->value() > SPIN_BOX_MAX_VALUE) {
        _spin_box->setValue(SPIN_BOX_MAX_VALUE);
        return;
    }

    delete _btn_handler;

    _btn_handler = new ButtonsHandler(this, _spin_box->value(), this->size());
}
