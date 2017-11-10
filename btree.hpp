//
//  btree.hpp
//  HW3
//
//  Created by Prathyusha Pillari on 10/20/17.
//  Copyright © 2017 Prathyusha Pillari. All rights reserved.
//

#ifndef btree_hpp
#define btree_hpp
#include "ItemPrice.hpp"
#include <string>
using namespace std;
#include <stdio.h>

// binary search tree

class btree{

public:
    class node{
    public:
        ItemPrice key_value;
        node *left;
        node *right;
    };
    btree();
    ~btree();
    node* point;
    node* bPoint;
    node* aPoint;
    node* zPoint;
    node one;
    node two;
    node three;
    node* head;
    int size;
    void insert(ItemPrice key);
    void search(int key);
    void compare(node* actuall, node x, node y, node z);
    void compare(node* actuall, node x, node y);

private:
    void destroy_tree(node *leaf);
    void insert(ItemPrice key, node *leaf);
    node *search(int key, node *leaf);
    void suggestForMore(node *x);
    void suggestForFiveTop(node *x);
    void suggestForFiveBottom(node *x);
    void suggestForFour(node *x);
    void suggestForThree(node *x);
    void suggestForTwo(node *x);
    void printList();

    node *root;

};

#endif /* btree_hpp */


