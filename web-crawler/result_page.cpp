#include "result_page.h"
#include "ui_result_page.h"
#include<queue>

Result_page::Result_page(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Result_page)
{
    ui->setupUi(this);
    web_tree* w=new web_tree();

    if(w->size()!=0)
    {
        queue<tree_node*> q;
        q.push(w->root);
        while(!q.empty())
        {
            int n=q.size();
            while(n>0)
            {
                tree_node*p=q.front();

                if(p->key.which_item==1)
                    ui->listWidget->addItem(p->key.url_name);

                else if(p->key.which_item==2)
                    ui->listWidget_2->addItem(p->key.url_name);

                else if(p->key.which_item==3)
                    ui->listWidget_3->addItem(p->key.url_name);

                else if(p->key.which_item==4)
                    ui->listWidget_4->addItem(p->key.url_name);

                q.pop();

                for(int i=0;i<p->child.size();i++)
                    q.push(p->child[i]);
                n--;
            }
        }
    }
}

Result_page::~Result_page()
{
    delete ui;
}
