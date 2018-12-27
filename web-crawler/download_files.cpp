#include "download_files.h"

download_files::download_files(QObject *parent) : QObject(parent)
{

}

void download_files::start_process()
{
    if(firstOrNot == 0)
    {
        // first step
        firstOrNot=1;
    }
    else if(firstOrNot!=0 && !queue_download.isEmpty())
    {

    }
    else if(firstOrNot!=0 && queue_download.isEmpty())
    {
        emit finsh_all_files();
    }
}

void download_files::download_file()
{
    networkManger=new QNetworkAccessManager(this);
    connect(networkManger,SIGNAL(finished(QNetworkReply*)),this,SLOT(finish_download_process(QNetworkReply*)));
    QNetworkConfigurationManager manager;
    networkManger->setConfiguration(manager.defaultConfiguration());

    connect(networkManger, SIGNAL(networkAccessibleChanged(QNetworkAccessManager::NetworkAccessibility)), this, SLOT(change_stats(QNetworkAccessManager::NetworkAccessibility)));
    QUrl url=QUrl(page_address);
    request= new QNetworkRequest(url);
    networkManger->get(*request);

}

void download_files::get_links()
{
    if(depth>0)
    {
        string html_str=downloaded_data.toStdString();
        smatch match;
        regex r("href[\n ]*?=[\n ]*?\"(.+?)\"");
        regex r1("https://.*");
        regex r2("http://.*");

        while(std::regex_search(html_str,match,r))
        {
            smatch match1;
            string str1=match[1].str();
            if(std::regex_match(str1,r1))
                str1.erase (str1.begin()+4);
            else if(!std::regex_match(str1,r2))
            {
                str1="";
                str1=page_address.toStdString()+match[1].str();
            }

//            while(std::regex_search(str1,match1,r1))
//            {
//                listOfLinks.push_back(match1[1].str());
//                str1=match1.suffix().str();
//            }
            //mo'tabar budansh bayad check beshe
            listOfLinks.push_back(str1);
            html_str=match.suffix().str();

        }
        depth--;
    }
}

void download_files::get_img()
{
    string html_str=downloaded_data.toStdString();
    smatch match;
    regex r("img .*?src[\n ]*?=[\n ]*?\"(.*?)\"");
    while(std::regex_search(html_str,match,r))
    {
        listOfImg.push_back(match[1].str());
        html_str=match.suffix().str();
    }
}

void download_files::get_script()
{
    string html_str=downloaded_data.toStdString();
    smatch match;
    regex r("script .*?src[\n ]*?=[\n ]*?\"(.*?)\"");
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

void download_files::change_stats(QNetworkAccessManager::NetworkAccessibility)
{
    //????
    emit disconnect();
}

