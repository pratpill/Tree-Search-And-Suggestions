//
//  btree.cpp
//  HW3
//
//  Created by Prathyusha Pillari on 10/20/17.
//  Copyright © 2017 Prathyusha Pillari. All rights reserved.
//

#include <iostream>
#include "btree.hpp"
#include "ItemPrice.hpp"
#include <math.h>
#include <string>
#include <cmath>
using namespace std;

// binary search tree

btree::btree(){
    root=NULL;
}

btree::~btree(){
}

void btree::destroy_tree(node *leaf){
    if(leaf!=NULL){
        destroy_tree(leaf->left);
        destroy_tree(leaf->right);
        delete leaf;
    }
}

void btree::insert(ItemPrice key, node *leaf){
    if(key.price < leaf->key_value.price){
        if(leaf->left!=NULL){
            size++;
            insert(key, leaf->left);
        }
        else{
            size++;
            leaf->left=new node;
            leaf->left->key_value=key;
            leaf->left->left=NULL;    //Sets the left child of the child node to null
            leaf->left->right=NULL;   //Sets the right child of the child node to null
        }
    }
    else if(key.price>=leaf->key_value.price){
        if(leaf->right!=NULL){
            size++;
            insert(key, leaf->right);
        }
        else{
            size++;
            leaf->right=new node;
            leaf->right->key_value=key;
            leaf->right->left=NULL;  //Sets the left child of the child node to null
            leaf->right->right=NULL; //Sets the right child of the child node to null
        }
    }
}

btree::node *btree::search(int key, node *leaf){
    if(leaf!=NULL){
        if(key==leaf->key_value.price){
            zPoint = aPoint;
            aPoint = bPoint;
            bPoint = point;
            point = leaf;
            return leaf;
        }
        if(key < leaf->key_value.price){
            zPoint = aPoint;
            aPoint = bPoint;
            bPoint = point;
            point = leaf;
            node *now = search(key, leaf->left);
            return now;
        }
        else{
            zPoint = aPoint;
            aPoint = bPoint;
            bPoint = point;
            point = leaf;
            node *now1 = search(key, leaf->right);
            return now1;
        }
    }
    else return NULL;
}

void btree::insert(ItemPrice key)
{
    if(root!=NULL){
        insert(key, root);
        head = root;
    }
    else
    {
        root=new node;
        root->key_value=key;
        root->left=NULL;
        root->right=NULL;
    }
}

void btree::search(int key){
    node *x = search(key, root);
    if(x == NULL){
        cout << "Your price $" << key << " was not found. Here are some suggestions: " << endl;
        node *now = NULL;
        if(key < head->key_value.price){
            cout << "#0: " << head->key_value.name << ", $";
            cout << head->key_value.price << endl;
            suggestForFour(head);
        }
        else{
            int key1 = key;
            while(now == NULL){
                now = search(key1-1, root);
                key1--;
            }
            cout << "#0: " << now->key_value.name << ", $";
            cout << now->key_value.price << endl;
            suggestForFour(now);
        }
    }
    else{
    cout << "Your price was found:" << endl;
    cout << x->key_value.name << ", $";
    cout << x->key_value.price << " " << endl << endl;

    cout << "Suggestions: " << endl;
        if(size >= 4){
            suggestForMore(x);
        }
        if(size == 4){
            suggestForFour(x);
        }
        else if(size == 3){
            suggestForThree(x);
        }
        else if(size == 1){
            suggestForTwo(x);
        }
        else if(size <1){
            cout << "No more suggestions" << endl;
        }
    }
}

void btree::suggestForMore(node *x){
    if(head == x){
        node z = *x->right;
        node z1 = *z.right;
        node z2 = *z1.right;
        compare(x, z, z1, z2);
        printList();
    }
    else if(x->right != NULL){
        node *up = zPoint;
        node *upOne = aPoint;
        node *upOneMore = bPoint;
        node z = *x->right;

        if( x->right == NULL || z.right == NULL || z.right->right == NULL){
            suggestForFiveTop(x);
            return;
        }
        else if(upOne == NULL || upOneMore == NULL || up == NULL){
            if(upOne == NULL){
                suggestForFour(x);
                return;
            }
            else{
            suggestForFiveBottom(x);
            return;
             }
        }
        
        node z1 = *z.right;
        node z3 = *z1.right;
        if(abs(x->key_value.price - z.key_value.price) > abs(x->key_value.price - upOneMore->key_value.price)){
            if(abs(x->key_value.price - z.key_value.price) > abs(x->key_value.price - upOne->key_value.price)){
                if(abs(x->key_value.price - z.key_value.price) > abs(x->key_value.price - up->key_value.price)){
                    compare(x, *upOneMore, *upOne, *up);
                    printList();
                }
                else{
                    compare(x, *upOneMore, *upOne, z);
                    printList();
                }
            }
            else if(abs(x->key_value.price - z1.key_value.price) > abs(x->key_value.price - upOne->key_value.price)){
                compare(x, *upOneMore, *upOne, z);
                printList();
            }
            else{
                compare(x, *upOneMore, z1, z);
                printList();
            }
        }
        else if(abs(x->key_value.price - z.key_value.price) < abs(x->key_value.price - upOneMore->key_value.price)){
            if(abs(x->key_value.price - z1.key_value.price) > abs(x->key_value.price - upOneMore->key_value.price)){
                if(abs(x->key_value.price - z1.key_value.price) > abs(x->key_value.price - upOne->key_value.price)){
                    compare(x, z, *upOneMore, *upOne);
                    printList();
                }
                else{
                    compare(x, z, *upOneMore, z1);
                    printList();
                }
            }
            else if(abs(x->key_value.price - z3.key_value.price) < abs(x->key_value.price - upOneMore->key_value.price)){
                compare(x, z3, z1 , z);
                printList();
            }
            else{
                compare(x, *upOneMore, z1, z);
                printList();
            }
        }
        else if(abs(x->key_value.price - z.key_value.price) == abs(x->key_value.price - upOneMore->key_value.price)){
            if(abs(x->key_value.price - z1.key_value.price) > abs(x->key_value.price - upOne->key_value.price)){
                compare(x, z, *upOne, *upOneMore);
                printList();
            }
            else{
                compare(x, z, z1, *upOneMore);
                printList();
            }
        }
        else if(abs(x->key_value.price - z1.key_value.price) > abs(x->key_value.price - upOneMore->key_value.price)){
            compare(x, z, z1, *upOneMore);
            printList();
        }
        else{
            node *up = aPoint;
            compare(x, z, *upOne, *up);
            printList();
        }
    }
    else{
        node *upOneMore = bPoint;
        node *up = aPoint;
        node *upOne = zPoint;
        compare(x, *upOneMore, *upOne, *up);
        printList();
    }
}

void btree::suggestForFiveTop(node *x){
    node *up = zPoint;
    node *upOne = aPoint;
    node *upOneMore = bPoint;
    node z = *x->right;
    
    if(abs(x->key_value.price - z.key_value.price) > abs(x->key_value.price - upOneMore->key_value.price)){
        if(abs(x->key_value.price - z.key_value.price) > abs(x->key_value.price - upOne->key_value.price)){
            if(abs(x->key_value.price - z.key_value.price) > abs(x->key_value.price - up->key_value.price)){
            compare(x, *upOneMore, *upOne, *up);
                printList();
            }
            else{
                compare(x, *upOneMore, *upOne, z);
                printList();
            }
        }
        else{
            compare(x, *upOneMore, *upOne, z);
            printList();
        }
    }
    else if(abs(x->key_value.price - z.key_value.price) < abs(x->key_value.price - upOneMore->key_value.price)){
        if(z.right == NULL){
            compare(x, *upOneMore, *upOne, z);
            printList();
            return;
        }
        node z1 = *z.right;
        if(abs(x->key_value.price - z1.key_value.price) > abs(x->key_value.price - upOneMore->key_value.price)){
             if(abs(x->key_value.price - z1.key_value.price) > abs(x->key_value.price - upOne->key_value.price)){
                  compare(x, *upOneMore, *upOne, z);
                  printList();
             }
             else{
                 compare(x, *upOneMore, z1, z);
                 printList();
             }
        }
        else{
                compare(x, *upOneMore, z1, z);
                printList();
          }
    }
    
}

void btree::suggestForFiveBottom(node *x){
    node *upOne = aPoint;
    node *upOneMore = bPoint;
    node z = *x->right;
    node z1 = *z.right;
    node z3 = *z1.right;
    
    if(z.right != NULL && abs(x->key_value.price - z.key_value.price) > abs(x->key_value.price - upOneMore->key_value.price)){
        if(abs(x->key_value.price - z.key_value.price) > abs(x->key_value.price - upOne->key_value.price)){
            compare(x, *upOneMore, *upOne, z);
            printList();
        }
        else{
            if(abs(x->key_value.price - z1.key_value.price) > abs(x->key_value.price - upOne->key_value.price)){
                compare(x, *upOneMore, *upOne, z);
                printList();
            }
            else{
               compare(x, *upOneMore, z1, z);
               printList();
            }
        }
    }
    else if(z.right != NULL && abs(x->key_value.price - z.key_value.price) < abs(x->key_value.price - upOneMore->key_value.price)){
        if(abs(x->key_value.price - z1.key_value.price) > abs(x->key_value.price - upOneMore->key_value.price)){
            if(abs(x->key_value.price - z1.key_value.price) > abs(x->key_value.price - upOne->key_value.price)){
                compare(x, *upOneMore, *upOne, z);
                printList();
            }
            else{
                compare(x, *upOneMore, z1, z);
                printList();
            }
        }
        else{
            if(abs(x->key_value.price - z3.key_value.price) > abs(x->key_value.price - upOneMore->key_value.price)){
                compare(x, *upOneMore, z1, z);
                printList();
            }
            else{
                compare(x, z3, z1, z);
                printList();
            }
        }
    }
    
}


void btree::suggestForFour(node *x){
    if(head == x){
        node z = *x->right;
        node z1 = *z.right;
        node z2 = *z1.right;
        compare(x, z, z1, z2);
        printList();
    }
    else if(x->right != NULL){
        node z = *x->right;
        node *upOne = bPoint;
        if(z.right != NULL){
            node z1 = *z.right;
            compare(x, *upOne, z, z1);
            printList();
        }
        else{
        node *upOneMore = aPoint;
        compare(x, *upOne, z, *upOneMore);
        printList();
        }
    }
    else{
        node *upOneMore = bPoint;
        node *up = aPoint;
        node *upOne = zPoint;
        compare(x, *upOneMore, *upOne, *up);
        printList();
    }
}


void btree::suggestForThree(node *x){
    if(head == x){
        node z = *x->right;
        node z1 = *z.right;
        compare(x, z, z1);
        printList();
        cout << "There's only three nodes" << endl;
        cout << endl;
    }
    else if(x->right != NULL){
        node *upOne = bPoint;
        node z = *x->right;
        compare(x, *upOne, z);
        printList();
        cout << "There's only three nodes" << endl;
        cout << endl;
    }
    else{
        node *upOneMore = bPoint;
        node *up = aPoint;
        compare(x, *upOneMore, *up);
        printList();
        cout << "There's only three nodes" << endl;
        cout << endl;
    }
}

void btree::suggestForTwo(node *x){
    if(head == x){
        node z = *x->right;
        cout << "#1: " << z.key_value.name << ", $";
        cout << z.key_value.price << " " << endl;
        cout << "There's only two nodes" << endl;
        cout << endl;
    }
    else{
        node *upOneMore = bPoint;
        cout << "#1: " << upOneMore->key_value.name << ", $";
        cout << upOneMore->key_value.price << " " << endl;
        cout << "There's only two nodes" << endl;
        cout << endl;
    }
}

void btree::compare(node* actuall, node x, node y, node z){
    if(abs(actuall->key_value.price - x.key_value.price) > abs(actuall->key_value.price - y.key_value.price)){
        if(abs(actuall->key_value.price - x.key_value.price) > abs(actuall->key_value.price - z.key_value.price)){
            one = x;
            if(abs(actuall->key_value.price - y.key_value.price) > abs(actuall->key_value.price - z.key_value.price)){
                two = y;
                three = z;
            }
            else{
                two = z;
                three = y;
            }
        }
        else{
            one = z;
            two = x;
            three = y;
        }
    }
    else if(abs(actuall->key_value.price - y.key_value.price) > abs(actuall->key_value.price - z.key_value.price)){
        one = y;
        if(abs(actuall->key_value.price - x.key_value.price) > abs(actuall->key_value.price - z.key_value.price)){
            two = x;
            three = z;
        }
        else{
            two = z;
            three = x;
        }
    }
    else{
        one = z;
        two = y;
        three = x;
    }

}

void btree::compare(node* actuall, node x, node y){
    if(abs(actuall->key_value.price - x.key_value.price) > abs(actuall->key_value.price - y.key_value.price)){
        one = x;
        two = y;
    }
    else{
        one = y;
        two = x;
    }
}

void btree::printList(){
    if(size >= 4){
    cout << "#1: " << three.key_value.name << ", $";
    cout << three.key_value.price << " " << endl;
    cout << "#2: " << two.key_value.name << ", $";
    cout << two.key_value.price << " " << endl;
    cout << "#3: " << one.key_value.name << ", $";
    cout << one.key_value.price << " " << endl;
    cout << endl;
    }
    else if(size == 3){
        cout << "#1: " << two.key_value.name << ", $";
        cout << two.key_value.price << endl;
        cout << "#2: " << one.key_value.name << ", $";
        cout << one.key_value.price << endl;
        cout << endl;
    }
}




