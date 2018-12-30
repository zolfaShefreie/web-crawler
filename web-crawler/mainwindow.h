#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QMessageBox>
#include <QMovie>
#include <QDesktopServices>
#include <download_files.h>
#include<result_page.h>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    Result_page * r;
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    QString url;
    tree_node * parent_item;
    int depth_page;
    download_files * downloader;
    void check_url();
    void fill_list_widget();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_4_clicked();

    void on_pushButton_5_clicked();

    void finish_process();

    void on_lineEdit_textChanged(const QString &arg1);

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
