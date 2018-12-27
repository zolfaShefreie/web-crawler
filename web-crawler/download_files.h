#ifndef DOWNLOAD_FILES_H
#define DOWNLOAD_FILES_H

#include <QObject>
#include<QtNetwork>
#include<regex>
#include<QQueue>
#include<tree_node.h>
using namespace std;


class download_files : public QObject
{
    Q_OBJECT
public:

    explicit download_files(QObject *parent = 0);
    QString page_address;
    //QString url_dtr;
    int depth;
    int firstOrNot=0;
    QByteArray downloaded_data;
    QQueue<tree_node> queue_download;
    QList<string> listOfLinks;
    QList<string> listOfImg;
    QNetworkAccessManager * networkManger;
    //QNetworkReply rely;
    QNetworkRequest* request;
    void start_process();
    void download_file();
    void get_links();
    void get_img();
    void get_script();

signals:
    void finsh_all_files();
    void disconnect();

public slots:
    void finish_download_process(QNetworkReply *);
    void change_stats(QNetworkAccessManager::NetworkAccessibility);

};

#endif // DOWNLOAD_FILES_H
