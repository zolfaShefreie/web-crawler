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

}

void MainWindow::on_pushButton_5_clicked()
{
    //page 2
}

void MainWindow::finish_process()
{

}

void MainWindow::on_lineEdit_textChanged(const QString &arg1)
{

}
