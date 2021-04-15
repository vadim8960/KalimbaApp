#include "buttonshandler.h"

ButtonsHandler::ButtonsHandler(QWidget* parent, int count_keys, QSize win_size) {
    _keys.resize(count_keys);

    for (int i = 0; i < _keys.size(); ++i)
        _keys[i] = new QPushButton(parent);

    ButtonsResize(win_size);
}

void ButtonsHandler::ButtonsResize(QSize win_size) {
    int current_x = win_size.width() * 0.05;
    int space_btw_keys = win_size.width() * 0.03;
    int key_width =
            (win_size.width() - 2 * current_x - space_btw_keys * (_keys.size() - 1)) / _keys.size();

    int start_y = win_size.height() / 2;
    int max_h = win_size.height() - win_size.height() * 0.05 - win_size.height() / 2;
    int min_h = max_h / 2;
    int dh = (max_h - min_h) / _keys.size();
    int current_h = min_h;

    int i = 0;
    for (; i <= _keys.size() / 2; ++i) {
        _keys[i]->setGeometry(current_x, start_y, key_width, current_h);
        current_x += key_width + space_btw_keys;
        current_h += dh * 2;
    }
    current_h -= 3 * dh;
    for (; i < _keys.size(); ++i) {
        _keys[i]->setGeometry(current_x, start_y, key_width, current_h);
        current_x += key_width + space_btw_keys;
        current_h -= dh * 2;
    }
}

void ButtonsHandler::keyPressEvent(QKeyEvent* event) {
    //    if (event->key() == Qt::Key_Space)
    //        return;
    //    ui->pushButton->pressed();
    //    ui->pushButton->animateClick();
    //    ui->pushButton->setFlat(true);
    //    auto pal = ui->pushButton->palette();
    //    pal.setColor(QPalette::Button, QColor::fromRgb(0, 0, 0));
    //    ui->pushButton->setPalette(pal);
    //    ui->pushButton->update();
}

void ButtonsHandler::keyReleaseEvent(QKeyEvent* event) {
    //    ui->pushButton->released();
    //    ui->pushButton->setFlat(false);
    //    auto pal = ui->pushButton->palette();
    //    pal.setColor(QPalette::Button, QColor::fromRgb(128, 128, 128));
    //    ui->pushButton->setPalette(pal);
    //    ui->pushButton->update();
}

ButtonsHandler::~ButtonsHandler() {
    for (auto& i : _keys)
        delete i;
}
