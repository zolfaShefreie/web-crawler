#ifndef NODE_H
#define NODE_H

#include<QString>
#include<QImage>
#include<QByteArray>
using namespace std;

class node
{
public:
    node();
    QString url_name;
    QByteArray html;


    bool operator ==(node const & n)
    {
        if(this->url_name==n.url_name)
            return true;
        else return false;
    }
};

#endif // NODE_H