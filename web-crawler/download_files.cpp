#include "download_files.h"

download_files::download_files(QObject *parent) : QObject(parent)
{
    i=0;
    queue_download.clear();
    //tree.clear();
}

void download_files::start_process()
{
    while (true)
    {
        if(firstOrNot == 0)
        {
            // first step
            tree->root->key.which_item=1;
            tree->root->key.url_name=page_address;
            parent_pointer=tree->root;
            url_str=tree->root->key.url_name;
            this->download_file();
            this->get_links();
            this->get_img();
            this->get_script();

            firstOrNot=1;
            //depth--;
            numberOfChildren.push_back(tree->root->child.size());
            numberOfChildren.push_back(0);
        }
        else if(firstOrNot!=0 && !queue_download.empty())
        {
            current_data=queue_download.first();
            parent_pointer=current_data->parent;
            url_str=current_data->key.url_name;
            if(store_downloaded_file.find(url_str)!=store_downloaded_file.end())
                this->download_file();
            else insert_to_tree();
            if(depth==numberOfChildren.size()-1)
            {

                if(current_data->key.which_item==1)
                {
                    this->get_links();
                    this->get_img();
                    this->get_script();
                }

                numberOfChildren[i+1]+=current_data->child.size();
                if(numberOfChildren[i]==0)
                {
                    i++;
                    numberOfChildren.push_back(0);
                }
                else numberOfChildren[i]--;
            }
        }
        else if(firstOrNot!=0 && queue_download.empty())
        {
            emit finsh_all_files();
            break;
        }
    }
}

void download_files::download_file()
{
    networkManger=new QNetworkAccessManager(this);
    connect(networkManger,SIGNAL(finished(QNetworkReply*)),this,SLOT(finish_download_process(QNetworkReply*)));
    QNetworkConfigurationManager manager;
    networkManger->setConfiguration(manager.defaultConfiguration());

    connect(networkManger, SIGNAL(networkAccessibleChanged(QNetworkAccessManager::NetworkAccessibility)), this, SLOT(change_stats(QNetworkAccessManager::NetworkAccessibility)));
    QUrl url=QUrl(url_str);
    request= new QNetworkRequest(url);
    networkManger->get(*request);

}

void download_files::insert_to_tree()
{
    tree->insert(current_data);
    if(current_data->key.which_item==1)
        save_in_a_folser(current_data->key.url_name,current_data->parent->key.path,0);
    else
        save_in_a_folser(current_data->key.url_name,current_data->parent->key.path,1);

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

        tree_node * data;
        data->parent=this->parent_pointer;
        while(std::regex_search(html_str,match,r))
        {
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
            data->key.url_name=QString::fromStdString(str1);
            data->key.which_item=1;
            //tree->insert(data->parent->key,data->key);
            queue_download.enqueue(data);
            html_str=match.suffix().str();

        }

    }
}

void download_files::get_img()
{
    string html_str=downloaded_data.toStdString();
    smatch match;
    regex r("img .*?src[\n ]*?=[\n ]*?\"(.*?)\"");
    tree_node * data;
    data->parent=this->parent_pointer;
    while(std::regex_search(html_str,match,r))
    {
        string str1=match[1].str();
        data->key.url_name=QString::fromStdString(match[1].str());
        //img or gif
        //nemifahme
        regex r1(".+?\\.gif");
        if(std::regex_match(str1,r1))
            data->key.which_item=3;
        else data->key.which_item=2;
        //tree->insert(data->parent->key,data->key);
        queue_download.enqueue(data);
        //listOfImg.push_back(match[1].str());
        html_str=match.suffix().str();
    }
}

void download_files::get_script()
{
    string html_str=downloaded_data.toStdString();
    smatch match;
    regex r("script .*?src[\n ]*?=[\n ]*?\"(.*?)\"");
    tree_node * data;
    data->parent=this->parent_pointer;
    while(std::regex_search(html_str,match,r))
    {
        data->key.url_name=QString::fromStdString(match[1].str());
        data->key.which_item=4;
        //tree->insert(data->parent->key,data->key);
        queue_download.enqueue(data);
        //listOfImg.push_back(match[1].str());
        html_str=match.suffix().str();
    }
}

void download_files::save_in_a_folser(QString child, QString father, int dirOrFile)
{
    QString child_path=make_name_of_dirOrFile(child);
    QString path="";
    if(dirOrFile==0)
    {
        path+=father;
        path+="/";
        path+=child_path;
        QDir dir(path);
        dir.mkdir(".");
        current_data->key.path=path;
        path+="/";
        path+=make_name_of_dirOrFile(current_data->parent->key.url_name);
        path+=".txt";
        QFile *file=new QFile(path);
        if(file->open(QFile::Append))
        {
            file->write(downloaded_data);
            file->flush();
            file->close();
        }
    }
    else if(dirOrFile==1)
    {
        path+=father;
        path+="/";
        path+=child_path;
        path+=".txt";
        QFile *file=new QFile(path);
        if(file->open(QFile::Append))
        {
            file->write(downloaded_data);
            file->flush();
            file->close();
        }
        current_data->key.path=path;
    }



}


void download_files::finish_download_process(QNetworkReply *reply)
{
    downloaded_data=reply->readAll();
    if(firstOrNot==0)
        save_in_a_folser(url_str,".",0);
    else
    {
        if(current_data->key.which_item==1)
            save_in_a_folser(url_str,current_data->parent->key.path,0);
        else
            save_in_a_folser(url_str,current_data->parent->key.path,1);
        tree->insert(current_data);
    }
    store_downloaded_file.insert(url_str,0);
}

void download_files::change_stats(QNetworkAccessManager::NetworkAccessibility)
{
    //????
    emit disconnect();
}

QString download_files::make_name_of_dirOrFile(QString child)
{
    QString child_path="";
    for(int j=0;j<child.length();j++)
    {
        // invalid character for name of file  or dir
        if(child[j]=='/')
            child_path+="()";
        else if(child[j]=='|'||child[j]=='\\' || child[j]==':' || child[j]=='<' ||child[j]=='>'||child[j]=='?' ||child[j]=='*'||child[j]=='"')
            child_path+=" ";
        else child_path+=child[j];
    }
    return child_path;
}

