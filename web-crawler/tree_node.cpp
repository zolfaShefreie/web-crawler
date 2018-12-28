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

web_tree::web_tree(node m)
{
    tree_node* a=new tree_node(m);
    root=a;
    cnt=1;
}


