#include "DBus_Ser.h"
#include <QtDBus/QDBusConnection>
#include <QtDBus/QDBusMessage>
DBus_Ser::DBus_Ser(QWidget *parent)
    : QMainWindow(parent)
{
    ui.setupUi(this);
    connect(ui.btnStart, SIGNAL(clicked()), this, SLOT(onStart()));

    QDBusConnection::sessionBus().connect(QString(), "/path", "com.message.test", "send_to_service", this, SLOT(onSerGet(QString)));
}

DBus_Ser::~DBus_Ser()
{}

void DBus_Ser::onStart()
{
    QDBusMessage message = QDBusMessage::createSignal("/path", "com.message.test", "send_to_control");
    message << ui.leText->text();
    QDBusConnection::sessionBus().send(message);
    ui.peList->appendPlainText("Ser send :" + ui.leText->text());
}

void DBus_Ser::onSerGet(QString str)
{
    ui.peList->appendPlainText("get message:" + str);
}

void DBus_Ser::onMin()
{
    ui.peList->appendPlainText("call min");
}