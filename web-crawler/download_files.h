#ifndef DOWNLOAD_FILES_H
#define DOWNLOAD_FILES_H

#include <QObject>
#include<QThread>
#include<QtNetwork>
#include<regex>
#include<QQueue>
#include<QHash>
#include<QFile>
#include<QDir>
#include<tree_node.h>
using namespace std;


class download_files : public QThread
{
    Q_OBJECT
public:

    explicit download_files(QObject *parent = 0);
    QString page_address;
    QString url_str;
    int depth;
    int firstOrNot=0;
    int i=0;
    vector<int> numberOfChildren;
    QByteArray downloaded_data;
    QQueue<tree_node*> queue_download;
    QHash<QString,int> store_downloaded_file;
    web_tree* tree;
    tree_node* parent_pointer;
    tree_node* current_data;
//    QList<string> listOfLinks;
//    QList<string> listOfImg;
    QNetworkAccessManager * networkManger;
    //QNetworkReply rely;
    QNetworkRequest* request;
    void run();
    void download_file();
    void insert_to_tree();
    void get_links();
    void get_img();
    void get_script();
    void save_in_a_folser(QString child,QString father,int dirOrFile);//0=dir  1=file
    QString make_name_of_dirOrFile(QString);

signals:
    void finsh_all_files();
    void disconnect();
    void warning_conction();

public slots:
    void finish_download_process(QNetworkReply *);
    void change_stats(QNetworkAccessManager::NetworkAccessibility state);

};

#endif // DOWNLOAD_FILES_H
