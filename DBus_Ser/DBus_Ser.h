#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_DBus_Ser.h"

class DBus_Ser : public QMainWindow
{
    Q_OBJECT

    Q_CLASSINFO("D-Bus Interface","com.widget.test.show")
public:
    DBus_Ser(QWidget *parent = nullptr);
    ~DBus_Ser();

public slots:
    void onStart();

    void onSerGet(QString str);

    void onMin();
private:
    Ui::DBus_SerClass ui;
};
