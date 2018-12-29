#include "tree_node.h"
#include<queue>

tree_node::tree_node()
{
}

tree_node::tree_node(node b)
{
    this->key=b;
}

//tree_node *web_tree::search(node f)
//{
//    queue<tree_node*> q;
//    q.push(root);
//    while(!q.empty())
//    {
//        int n=q.size();
//        while(n>0)
//        {
//            tree_node* p=q.front();
//            if(p->key==f)
//                return p;
//            q.pop();
//            for(int i=0;i<p->child.size();i++)
//                q.push(p->child[i]);
//            n--;
//        }
//    }
//    return 0;
//}



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

QStringList web_tree::children(tree_node j)
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

void web_tree::clear()
{
    tree_node* b=root;
    for(int i=0;i<b->child.size();i++)
    {
        tree_node* a=b->child[i];
        a->parent=0;
    }
    delete root;
    b=0;
}

//QStringList web_tree::children(node j)
//{
//    QStringList l;
//    l.clear();
//    if(search(j)!=0)
//    {
//        tree_node* k=search(j);
//        for(int i=0;i<k->child.size();i++)
//        {
//            tree_node* a=k->child[i];
//            l.push_back(a->key.url_name);
//        }
//    }
//    return l;
//}



tree_node *web_tree::search(tree_node &f)
{
    tree_node* m=&f;
    queue<tree_node*> q;
    q.push(root);
    while(!q.empty())
    {
        int n=q.size();
        while(n>0)
        {
            tree_node* p=q.front();
            if(p->key==m->key && p->parent==m->parent)
                return p;
            q.pop();
            for(int i=0;i<p->child.size();i++)
                q.push(p->child[i]);
            n--;
        }
    }
    return 0;
}

bool web_tree::insert(tree_node &f)
{
    tree_node*m=&f;
    m->parent->child.push_back(m);
    cnt++;
}

//bool web_tree::insert(tree_node &f)
//{
//    if(cnt==0)
//        return false;
//    tree_node* a=f.parent;
//    queue<tree_node*> q;
//    q.push(root);
//    while(!q.empty())
//    {
//        int n=q.size();
//        while(n>0)
//        {
//            tree_node* p=q.front();
//            if(p==a)
//            {
//                for(int i=0;i<p->child.size();i++)
//                {
//                    tree_node* e=p->child[i];
//                    if(e->key==f.key)
//                        return false;
//                }
//                tree_node* m=& f;
//                p->child.push_back(m);
//                cnt++;
//                return true;
//            }
//            q.pop();
//            for(int i=0;i<p->child.size();i++)
//                q.push(p->child[i]);
//            n--;
//        }
//    }
//    return false;
//}
