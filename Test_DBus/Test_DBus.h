#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_Test_DBus.h"

class Test_DBus : public QMainWindow
{
    Q_OBJECT

public:
    Test_DBus(QWidget *parent = nullptr);
    ~Test_DBus();

protected slots:
    void onSerGet(QString);

    void onStart();
private:
    Ui::Test_DBusClass ui;
};
