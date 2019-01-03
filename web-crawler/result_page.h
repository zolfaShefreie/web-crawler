#ifndef RESULT_PAGE_H
#define RESULT_PAGE_H

#include <QWidget>
#include<tree_node.h>

namespace Ui {
class Result_page;
}

class Result_page : public QWidget
{
    Q_OBJECT

public:
    web_tree* w;
    explicit Result_page(QWidget *parent = 0);
    void start();
    ~Result_page();

private:
    Ui::Result_page *ui;
};

#endif // RESULT_PAGE_H
