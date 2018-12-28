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
    tree_node* search(node f);
    bool insert(node a,node b);
    //void tree_traversal();
    int size();
    bool isEmpty();
    web_tree(node m);
    QStringList children(node j);
};

#endif // TREE_NODE_H
