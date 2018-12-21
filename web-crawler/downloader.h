#ifndef DOWNLOADER_H
#define DOWNLOADER_H

#include <QObject>
#include<QTcpSocket>
#include<QList>
#include<regex>
using namespace std;

class downloader : public QObject
{
    Q_OBJECT
public:
    enum downloader_state
    {
        connect=10,
        disconnect=20,

    };

    explicit downloader(QObject *parent = 0);
    QString page_address;
    QByteArray html;
    QList<string> listOfLinks;
    QTcpSocket * socket;
    downloader_state connectAndGetHtml();
    void get_links();

signals:

public slots:
};

#endif // DOWNLOADER_H
