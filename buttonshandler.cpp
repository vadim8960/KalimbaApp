#include "buttonshandler.h"

#define HEIGHT_MARGIN_PERCENT 0.03
#define WIDTH_MARGIN_PERCENT 0.05

#define COUNT_NOTES 7

ButtonsHandler::ButtonsHandler(QWidget* parent, int count_keys, QSize win_size) {
    QString notes[COUNT_NOTES] = {"C\n", "D\n", "E\n", "F\n", "G\n", "A\n", "B\n"};
    int keycodes[MAX_COUNT_KEYS] = {
            Qt::Key_E,         Qt::Key_R,     Qt::Key_A,      Qt::Key_S, Qt::Key_D, Qt::Key_F,
            Qt::Key_Z,         Qt::Key_X,     Qt::Key_C,      Qt::Key_V, Qt::Key_B, Qt::Key_N,
            Qt::Key_M,         Qt::Key_Comma, Qt::Key_Period, Qt::Key_J, Qt::Key_K, Qt::Key_L,
            Qt::Key_Semicolon, Qt::Key_I,     Qt::Key_O};

    _keys.resize(count_keys);

    int ind = MAX_COUNT_KEYS / 2 - count_keys / 2;
    for (int i = 0; i < count_keys; ++i) {
        _keys[i] = QPair<int, QPushButton*>(keycodes[ind++], new QPushButton(parent));
        _keys[i].second->setStyleSheet("text-align: bottom;");
    }

    QString key_txt;
    for (int j = 1; j <= _keys.size(); ++j) {
        for (int i = 0; i < (j - 1) / COUNT_NOTES; ++i)
            key_txt += "*\n";
        key_txt += QString::number((j - 1) % COUNT_NOTES + 1) + "\n";
        key_txt += notes[(j - 1) % COUNT_NOTES] + "\n";
        if (j % 2) {
            _keys[_keys.size() / 2 + j / 2].second->setText(key_txt);
        } else {
            _keys[_keys.size() / 2 - j / 2].second->setText(key_txt);
        }
        key_txt = "";
    }

    ButtonsResize(win_size);

    for (auto& i : _keys)
        i.second->show();
}

void ButtonsHandler::ButtonsResize(QSize win_size) {
    int current_x = win_size.width() * WIDTH_MARGIN_PERCENT;
    int space_btw_keys = win_size.width() * 0.2 / _keys.size();
    int key_width =
            (win_size.width() - 2 * current_x - space_btw_keys * (_keys.size() - 1)) / _keys.size();

    int start_y = win_size.height() / 2;
    int max_h =
            win_size.height() - win_size.height() * HEIGHT_MARGIN_PERCENT - win_size.height() / 2;
    int min_h = max_h / 2;
    int dh = (max_h - min_h) / _keys.size();
    int current_h = min_h;

    int i = 0;
    for (; i <= _keys.size() / 2; ++i) {
        _keys[i].second->setGeometry(current_x, start_y, key_width, current_h);
        current_x += key_width + space_btw_keys;
        current_h += 2 * dh;
    }
    current_h -= 5 * dh;
    for (; i < _keys.size(); ++i) {
        _keys[i].second->setGeometry(current_x, start_y, key_width, current_h);
        current_x += key_width + space_btw_keys;
        current_h -= 2 * dh;
    }
}

void ButtonsHandler::KeyPressedHandler(int key_code) {
    for (auto& key : _keys) {
        if (key.first == key_code) {
            key.second->pressed();
            key.second->animateClick();
            auto pal = key.second->palette();
            pal.setColor(QPalette::Button, QColor::fromRgb(0, 0, 0));
            key.second->setPalette(pal);
            key.second->update();
        }
    }
}

void ButtonsHandler::KeyReleaseHandler(int key_code) {
    for (auto& key : _keys) {
        if (key.first == key_code) {
            key.second->pressed();
            key.second->animateClick();
            auto pal = key.second->palette();
            pal.setColor(QPalette::Button, QColor::fromRgb(250, 250, 250));
            key.second->setPalette(pal);
            key.second->update();
        }
    }
}

ButtonsHandler::~ButtonsHandler() {
    for (auto& i : _keys)
        delete i.second;
}
