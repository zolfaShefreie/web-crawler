#include "downloader.h"
#include<QNetworkProxy>
downloader::downloader(QObject *parent) : QObject(parent)
{

}

downloader::downloader_state downloader::connectAndGetHtml()
{

    socket=new QTcpSocket(this);
    socket->setProxy(QNetworkProxy::NoProxy);

    socket->connectToHost(page_address,80);


    if(!socket->waitForConnected(3000))
    {
        return downloader_state::disconnect;
    }
    else
    {

        socket->write("GET /index.html HTTP/1.1\r\n\r\n");
        socket->waitForBytesWritten(30000);
        while(socket->waitForReadyRead(30000))
        {

            while(socket->bytesAvailable()>0)
            {
                html.append(socket->readAll());
                socket->flush();
            }
        }
        socket->close();
    }
    return downloader_state::connect;
}

void downloader::get_links()
{
    string html_str=html.toStdString();
    smatch match;
    regex r("href[\n ]*?=[\n ]*?\"(.+?)\"");
    while(std::regex_search(html_str,match,r))
    {
        listOfLinks.push_back(match[1].str());
        html_str=match.suffix().str();

    }
}

