#include "download_files.h"

download_files::download_files(QObject *parent) : QObject(parent)
{

}

void download_files::download_file()
{
    networkManger=new QNetworkAccessManager(this);
    connect(networkManger,SIGNAL(finished(QNetworkReply*)),this,SLOT(finish_download_process(QNetworkReply*)));
    QUrl url=QUrl(page_address);
    request= new QNetworkRequest(url);
    networkManger->get(*request);

}

void download_files::get_links()
{
    string html_str=downloaded_data.toStdString();
    smatch match;
    regex r("href[\n ]*?=[\n ]*?\"(.+?)\"");
    regex r1("\"https?://(.*)\"");
    while(std::regex_search(html_str,match,r))
    {
        smatch match1;
        string str1=match.str();
        while(std::regex_search(str1,match1,r1))
        {
            listOfLinks.push_back(match1[1].str());
            str1=match1.suffix().str();
        }
        //mo'tabar budansh bayad check beshe
        //listOfLinks.push_back(match[1].str());
        html_str=match.suffix().str();

    }
}

void download_files::get_img()
{
    string html_str=downloaded_data.toStdString();
    smatch match;
    regex r("img[ \n.]*?src[\n ]*?=[\n ]*?\"(.*?)\"");
    while(std::regex_search(html_str,match,r))
    {
        listOfImg.push_back(match[1].str());
        html_str=match.suffix().str();
    }
}

void download_files::finish_download_process(QNetworkReply *reply)
{
    downloaded_data=reply->readAll();
}
