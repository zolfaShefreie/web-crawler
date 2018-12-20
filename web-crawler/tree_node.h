#ifndef TREE_NODE_H
#define TREE_NODE_H

#include"node.h"
#include<vector>
using namespace std;


class tree_node
{
public:
    tree_node();
    tree_node(node b);
    node key;
    vector<tree_node *> child;
};

class web_tree
{
    tree_node * root;
    int cnt;
    tree_node* search(node f);
    bool insert(node a,node b);
    //void tree_traversal();
    int size();
    //bool isEmpty();
    web_tree(node m);
};

#endif // TREE_NODE_H
