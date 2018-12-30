#include "result_page.h"
#include "ui_result_page.h"

Result_page::Result_page(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Result_page)
{
    ui->setupUi(this);
}

Result_page::~Result_page()
{
    delete ui;
}
