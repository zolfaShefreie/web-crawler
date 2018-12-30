#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->pushButton->setToolTip("click to start show the result");
    ui->pushButton_2->setToolTip("show the web page on the internet");
    ui->pushButton_3->setEnabled(false);
    ui->pushButton_4->setEnabled(false);
    ui->pushButton_5->setEnabled(false);

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::check_url()
{
    for(int i=0;i<url.length();i++)
        if (url[i]==' ')
            url.remove(i);
    if(url!=NULL)
    {
        regex r1("https://.*");
        regex r2("http://.*");
        if(std::regex_match(url.toStdString(),r1))
            url.remove (5);
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
    QIcon file_or_dir;
    file_or_dir.addFile(":/new/prefix2/icons8-html-filetype-48.png");

    ui->listWidget->addItem(new QListWidgetItem (file_or_dir,parent_item->key.url_name));
    for(auto i=0;i<parent_item->child.size();i++)
    {
        tree_node * item=parent_item->child.at(i);
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
    if(url==NULL)
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
        downloader->url_str=url;
        downloader->start();
        connect(downloader,SIGNAL(finsh_all_files()),this,SLOT(finish_process()));
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
    if(url==NULL)
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
    //check shavad az 0 ya az 1 shuro' mishavad
    tree_node *item=parent_item->child.at(item_index-1);
    if(item->key.which_item==1)
    {
        parent_item=item;
        fill_list_widget();
    }
    else if(item->key.which_item==2)
    {
        //show img
    }
    else if(item->key.which_item==3)
    {
        //gif
    }
    else
    {
        QDesktopServices::openUrl(QUrl(item->key.path));
    }

}

void MainWindow::on_pushButton_5_clicked()
{
    //page 2
}

void MainWindow::finish_process()
{
    //QStringList list_str_children=downloader->tree->children(*downloader->tree->root);
    parent_item=downloader->tree->root;
    fill_list_widget();
    ui->pushButton_3->setEnabled(true);
    ui->pushButton_4->setEnabled(true);
    ui->pushButton_5->setEnabled(true);
    QMovie* movie=new QMovie();
    ui->label_2->setMovie(movie);

}

void MainWindow::on_lineEdit_textChanged(const QString &arg1)
{

}
