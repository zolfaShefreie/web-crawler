#include "tree_node.h"
#include<queue>

tree_node::tree_node()
{
}

tree_node::tree_node(node b)
{
    this->key=b;
}

tree_node *web_tree::search(node f)
{
    queue<tree_node*> q;
    q.push(root);
    while(!q.empty())
    {
        int n=q.size();
        while(n>0)
        {
            tree_node* p=q.front();
            if(p->key==f)
                return p;
            q.pop();
            for(int i=0;i<p->child.size();i++)
                q.push(p->child[i]);
            n--;
        }
    }
    return 0;
}

bool web_tree::insert(node a, node b)
{
    if(search(a)!=0)
    {
        tree_node* m=new tree_node(b);
        tree_node* k=search(a);
        m->parent=k;
        k->child.push_back(m);
        cnt++;
        return true;
    }
    return false;
}

//void web_tree::tree_traversal()
//{
//    queue<tree_node*> q;
//    q.push(root);
//    while(!q.empty())
//    {
//        int n=q.size();
//        while(n>0)
//        {
//            tree_node* p=q.front();
//            q.pop();
//            cout<<p->key.url_name<<" ";
//            for(int i=0;i<p->child.size();i++)
//                q.push(p->child[i]);
//            n--;
//        }
//        cout<<endl;
//    }
//}

int web_tree::size()
{
    return cnt;
}

bool web_tree::isEmpty()
{
    if(cnt==0)
        return true;
    else return false;
}

web_tree::web_tree(node m)
{
    tree_node* a=new tree_node(m);
    root=a;
    cnt=1;
}

QStringList web_tree::children(node j)
{
    QStringList l;
    l.clear();
    if(search(j)!=0)
    {
        tree_node* k=search(j);
        for(int i=0;i<k->child.size();i++)
        {
            tree_node* a=k->child[i];
            l.push_back(a->key.url_name);
        }
    }
    return l;
}


