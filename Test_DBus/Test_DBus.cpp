#include "Test_DBus.h"
#include <QtDBus/QDBusConnection>
#include <QtDBus/QDBusMessage>
Test_DBus::Test_DBus(QWidget *parent)
    : QMainWindow(parent)
{
    ui.setupUi(this);
    connect(ui.btnStart, SIGNAL(clicked()), this, SLOT(onStart()));

	QDBusConnection::sessionBus().connect(QString(), "/path", "com.message.test", "send_to_control", this, SLOT(onSerGet(QString)));
}

Test_DBus::~Test_DBus()
{}
#include <QDebug>
void Test_DBus::onStart()
{
	ui.peList->appendPlainText("call:" + ui.leText->text());

	QDBusMessage message = QDBusMessage::createMethodCall("com.widget.test", "/test/objects", "com.widget.test.show", ui.leText->text());
	
	QDBusMessage res = QDBusConnection::sessionBus().call(message);

	if (res.type() == QDBusMessage::ReplyMessage)
	{
		//int value = res.arguments().takeFirst().toInt();
		ui.peList->appendPlainText(QString("call sccessfully."));
	}
	else
	{
		ui.peList->appendPlainText("get message failed:" + QString("%1").arg(res.type()));
	}
}

void Test_DBus::onSerGet(QString msg)
{
	ui.peList->appendPlainText(msg);
}
