#include "exp_2_Client.h"

exp_2_Client::exp_2_Client(QWidget* parent)
	: QMainWindow(parent)
{
	ui.setupUi(this);
	udpSocket = new QUdpSocket(this);

	ui.PB_send->setEnabled(false);

	connect(ui.PB_connect, &QPushButton::clicked, [&]() {
		udpSocket->bind(ui.LE_localPort->text().toInt());
		ui.PB_send->setEnabled(true);
		});

	connect(ui.PB_send, &QPushButton::clicked, [&]() {
		QString address = ui.LE_adderss->text();
		QHostAddress targetAddress(address);
		QByteArray message = ui.LE_message->text().toUtf8();
		quint16 targetPort = ui.LE_targetPort->text().toInt();
		udpSocket->writeDatagram(message, targetAddress, targetPort);

		QDateTime currentDateTime = QDateTime::currentDateTime();
		QString currentDateTimeString = "[" + currentDateTime.toString("yyyy-MM-dd hh:mm:ss") + "]";
		QString senderMessage = "[me->" + targetAddress.toString() + ": " + QString::number(targetPort) + "]: ";
		ui.TB_message->append(currentDateTimeString + senderMessage + QString(message));
		ui.LE_message->clear();
		});

	connect(udpSocket, &QUdpSocket::readyRead, this, [&]() {
		while (udpSocket->hasPendingDatagrams()) {
			QByteArray datagram;
			datagram.resize(udpSocket->pendingDatagramSize());
			QHostAddress sender;
			quint16 senderPort;

			udpSocket->readDatagram(datagram.data(), datagram.size(), &sender, &senderPort);
			QDateTime currentDateTime = QDateTime::currentDateTime();
			QString currentDateTimeString = "[" + currentDateTime.toString("yyyy-MM-dd hh:mm:ss") + "]";
			QString senderMessage = "[" + QHostAddress(sender.toIPv4Address()).toString() + ": " + QString::number(senderPort) + "->me]: ";
			ui.TB_message->append(currentDateTimeString + senderMessage + QString(datagram));
		}
		});

}

exp_2_Client::~exp_2_Client()
{}
