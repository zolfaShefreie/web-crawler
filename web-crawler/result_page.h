#ifndef RESULT_PAGE_H
#define RESULT_PAGE_H

#include <QWidget>

namespace Ui {
class Result_page;
}

class Result_page : public QWidget
{
    Q_OBJECT

public:
    explicit Result_page(QWidget *parent = 0);
    ~Result_page();

private:
    Ui::Result_page *ui;
};

#endif // RESULT_PAGE_H
