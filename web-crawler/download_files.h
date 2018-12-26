#ifndef DOWNLOAD_FILES_H
#define DOWNLOAD_FILES_H

#include <QObject>
#include<QtNetwork>
#include<regex>
using namespace std;


class download_files : public QObject
{
    Q_OBJECT
public:
    explicit download_files(QObject *parent = 0);
    QString page_address;
    int depth;
    QByteArray downloaded_data;
    QList<string> listOfLinks;
    QList<string> listOfImg;
    QNetworkAccessManager * networkManger;
    //QNetworkReply rely;
    QNetworkRequest* request;
    void download_file();
    void get_links();
    void get_img();

signals:
    void finsh_all_files();

public slots:
    void finish_download_process(QNetworkReply *);

};

#endif // DOWNLOAD_FILES_H
