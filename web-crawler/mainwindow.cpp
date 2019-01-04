#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    thread=new QThread();
    ui->pushButton->setToolTip("click to start show the result");
    ui->pushButton_2->setToolTip("show the web page on the internet");
    ui->pushButton_4->setEnabled(false);
    ui->pushButton_5->setEnabled(false);
    parent_item=new tree_node();
    pre_parent_item=new tree_node();

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::check_url()
{
    for(int i=0;i<url.length();i++)
        if (url[i]==' ')
            url.remove(i,1);
    if(url!=NULL)
    {
        regex r1("https://.*");
        regex r2("http://.*");
        if(std::regex_match(url.toStdString(),r1))
            url.remove (4,1);
        else if(!std::regex_match(url.toStdString(),r2))
        {
            string str1="";
            str1+="http://";
            str1+=url.toStdString();
            url=QString::fromStdString(str1);
        }
    }
}

void MainWindow::fill_list_widget()
{
    ui->listWidget->clear();
    QIcon file_back;
    file_back.addFile(":/new/prefix2/icons8-arrow-pointing-left-64.png");
    ui->listWidget->addItem(new QListWidgetItem (file_back,NULL));
    QIcon file;
    file.addFile(":/new/prefix2/icons8-html-filetype-48.png");
    ui->listWidget->addItem(new QListWidgetItem (file,parent_item->key.url_name));

    for(auto i=0;i<parent_item->child.size();i++)
    {
        QIcon file_or_dir;
        tree_node * item=new tree_node();
        item=parent_item->child.at(i);
        if(item->key.which_item==1)
            file_or_dir.addFile(":/new/prefix2/icons8-opened-folder-48.png");
        else if(item->key.which_item==2)
            file_or_dir.addFile(":/new/prefix2/icons8-picture-48.png");
        else if(item->key.which_item==3)
            file_or_dir.addFile(":/new/prefix2/icons8-gif-48.png");
        else if(item->key.which_item==4)
            file_or_dir.addFile(":/new/prefix2/icons8-document-48.png");

        ui->listWidget->addItem(new QListWidgetItem (file_or_dir,item->key.url_name));
    }
}

void MainWindow::on_pushButton_clicked()
{
    //start
    url=ui->lineEdit->text();
    check_url();
    QUrl *u=new QUrl(url);
    if(url==NULL && !u->isValid())
    {
        QMessageBox *message=new QMessageBox();
        message->setText("invalid url");
        message->show();

    }
    else
    {
        depth_page=ui->spinBox->value();
        downloader=new download_files();
        downloader->depth=depth_page;
        downloader->page_address=url;
        downloader->url_str=url;
        downloader->set_thread(thread);
        downloader->moveToThread(thread);
        thread->start();
        //downloader->run();
        connect(downloader,SIGNAL(finsh_all_files()),this,SLOT(finish_process()));
        connect(downloader,SIGNAL(disconnect()),this,SLOT());
        connect(downloader,SIGNAL(warning_conction()),this,SLOT());
        QMovie *gif=new QMovie(":/new/prefix1/0_cWpsf9D3g346Va20.gif");
        ui->label_2->setMovie(gif);
        gif->setScaledSize(QSize(ui->label_2->width(),ui->label_2->height()));
        gif->start();


    }

}

void MainWindow::on_pushButton_2_clicked()
{
    QString url=ui->lineEdit->text();
    check_url();
    QUrl *u=new QUrl(url);
    if(url==NULL && !u->isValid())
    {
        QMessageBox *message=new QMessageBox();
        message->setText("invalid url");
        message->show();
    }
    else
    {

        QDesktopServices::openUrl(QUrl(url));
    }


}

void MainWindow::on_pushButton_4_clicked()
{
    int item_index=ui->listWidget->currentRow();
    //az 0
    if(item_index==0)
    {
        //back
        if(parent_item->parent!=NULL)
        {
            tree_node * tmp=new tree_node();
            tmp=parent_item;
            parent_item=pre_parent_item;
            pre_parent_item=tmp->parent;
            fill_list_widget();
        }

    }
    else if(item_index==1)
    {
        //file html
        QDesktopServices::openUrl(QUrl(parent_item->key.path));
    }
    else if(item_index>1)
    {
        tree_node *item=new tree_node();
        item=parent_item->child.at(item_index-2);
        if(item->key.which_item==1)
        {
            pre_parent_item=parent_item;
            parent_item=item;
            fill_list_widget();
        }
        else if(item->key.which_item==2)
        {
            QByteArray data;
            QFile *file=new QFile(item->key.path);
            if(file->open(QIODevice::ReadOnly))
            {
                data=file->readAll();
                file->close();
            }
            QPixmap p;
            p.loadFromData(data);
            ui->label_2->setPixmap(p.scaled(ui->label_2->width(),ui->label_2->height(),Qt::KeepAspectRatio));


        }
        else if(item->key.which_item==3)
        {
            //gif
            QDesktopServices::openUrl(QUrl(item->key.url_name));
        }
        else
        {
            //kar nemikoneh
           // QDesktopServices::openUrl(QUrl(item->key.path));
        }
    }

}

void MainWindow::on_pushButton_5_clicked()
{
    Result_page * page2=new Result_page();
    page2->w=downloader->tree;
    page2->start();
    page2->show();
}

void MainWindow::finish_process()
{
    //QStringList list_str_children=downloader->tree->children(*downloader->tree->root);
    parent_item=downloader->tree->root;
    pre_parent_item=downloader->tree->root;
    fill_list_widget();
    ui->pushButton_4->setEnabled(true);
    ui->pushButton_5->setEnabled(true);
    QMovie* movie=new QMovie();
    ui->label_2->setMovie(movie);

}

void MainWindow::dis_connect()
{
    thread->quit();
    QMessageBox *message=new QMessageBox();
    message->setText("please check the your connection internet and the try again");
    message->show();

}

void MainWindow::warning()
{
    QMessageBox *message=new QMessageBox();
    message->setText("Unknown Accessibility connection");
    message->show();
}

