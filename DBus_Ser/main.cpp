#include "DBus_Ser.h"
#include <iostream>
#include <QtWidgets/QApplication>
#include <QtDBus/QDBusConnection>
#include <QtDBus/QDBusMessage>
#include <QtDBus/QDBusError>
#include <QProcess>
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    QProcess pro;
    pro.setWorkingDirectory("./dbus");

	QStringList args;

    args << "--print-address";

    args << "--config-file=.\\dbus\\session.conf";

    pro.startDetached("dbus-daemon.exe",args);

    QDBusConnection connection = QDBusConnection::sessionBus();

    if (!connection.registerService("com.widget.test"))
    {
        std::cout << "error:" << connection.lastError().message().toStdString() << std::endl;
        exit(-1);
    }

    DBus_Ser w;

    connection.registerObject("/test/objects", &w, QDBusConnection::ExportAllSlots);

    w.show();
    return a.exec();
}
