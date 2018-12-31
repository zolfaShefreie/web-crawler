#include "mainwindow.h"
#include"result_page.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();
    Result_page r;
    r.show();

    return a.exec();
}
