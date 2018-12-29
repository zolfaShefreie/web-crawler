#ifndef TREE_NODE_H
#define TREE_NODE_H

#include"node.h"
#include<vector>
#include<QStringList>
using namespace std;


class tree_node
{
public:
    tree_node();
    tree_node(node b);
    node key;
    tree_node* parent;
    vector<tree_node *> child;

};

class web_tree
{
public:
    tree_node * root;
    int cnt;
    tree_node* search(tree_node & f);
    bool insert(tree_node * f);
    int size();
    bool isEmpty();
    web_tree(node m);
    QStringList children(tree_node j);
    void clear();
    //bool insert(tree_node &f);
    //QStringList children(node j);
    //tree_node* search(node f);
    //void tree_traversal();
    //bool insert(node a,node b);


};

#endif // TREE_NODE_H
