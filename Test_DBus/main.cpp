#include "Test_DBus.h"
#include <QtWidgets/QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Test_DBus w;
    w.show();
    return a.exec();
}
