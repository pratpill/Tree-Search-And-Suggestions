//  main.cpp
//  HW3Tree
//  Created by Prathyusha Pillari on 10/20/17.
//  Copyright © 2017 Prathyusha Pillari. All rights reserved.

/*
 * HOW TO USE THE CODE
 *
 * Use the insert function to insert the object ItemPrice
 * Ex:  object.insert(ItemPrice("Candy", 1));
 *
 * Use the search function to search a price of the object ItemPrice
 * Ex:  object.search(2);
 * 
 * We assume that we insert items already sorted
 * Ex. After you insert 10, don't insert prices less than 10
 *
 * The search function prints suggestions closest the price inserted
 * If the price is not found, it suggests #0 price lesser than the entered price
 * and then prices closest to the #0 price.
 *
 */

//• Implementation (10 Points Total):
//o [2 Points] Basic search method. Additional search functionality --> Line 61 btree.cpp
//§ [4 Points] Additional suggestions --> Line 131 btree.cpp
//§ [4 Points] Rankings of most likely to least likely results --> Line 422 btree.cpp
//• Demonstration (8 Points Total):
//o [1 Point] Written instructions on how to execute your program --> Line 7 main.cpp
//o [1 Point] Screen capture of program execution --> In the zip file
//o [1 Point] A structure containing at least 10 items to search through --> Line 50 main.cpp
//o [1 Point] Demonstration of search where search term is found --> Line 59 main.cpp
//o [1 Point] Demonstration of search where search term is NOT found --> Line 69 main.cpp
//o [1 Point] Demonstration of search after items in the data structure has
//  been added/modified/removed --> Line 67 main.cpp
//• Big-O Analysis (2 Points Total):
//o [2 Points] Search algorithm analysis --> Line 79 main.cpp
//• Extra Credit:
//o [2 Points] Search algorithm that has O(log n) complexity (binary search) --> Line 61 btree.cpp
//o [2 Points] Tree data structure (own implementation, NOT STL) (BST) --> Line 16 btree.hpp

#include <iostream>
#include "btree.hpp"
using namespace std;

int main(int argc, const char * argv[]) {
    btree tree;
    // structure containing at least 10 items to search through
    tree.insert(ItemPrice("Candy", 1));
    tree.insert(ItemPrice("Pen", 2));
    tree.insert(ItemPrice("Coffee", 6));
    tree.insert(ItemPrice("Frame", 7));
    tree.insert(ItemPrice("Bottle", 8));
    tree.insert(ItemPrice("Apples", 9));
    tree.insert(ItemPrice("Ice Cream", 11));
//    cout << "**First Searched Price**" << endl; // search where search term is found
//    tree.search(7);
    
//    tree.insert(ItemPrice("Planner", 23));
//    tree.insert(ItemPrice("Purse", 27));
//    tree.insert(ItemPrice("Camera", 31));
//    tree.insert(ItemPrice("Book", 87));
//    tree.insert(ItemPrice("Beats", 90));
//    tree.insert(ItemPrice("iPhone X", 1000));
//    // search after items in the data structure has been added/ modified
//    cout << "**Second Searched Price After Adding Items To The List**" << endl;
//    tree.search(31);
//    cout << "**Third Searched Price (Not Found)**" << endl; // search where search term is NOT found
//    tree.search(90);
    cout << "End Program" << endl;

    
    return 0;
}

/**
 * BIG O ANALYSIS FOR SEARCH FUNCTION
 *
 * I'm using a binary tree as my data structure, so the implementaion of the search function is binary.
 * The best case and the worst case complexity of a binary search is O(log n)
 * The worst case complexity, however, is O(n)
 * Since we're assuming that our list is already sorted while entering data, it functions like a linked list
 * Hence, even though my implementation of the search function is O(log n), it works with worst case so it's O(n)
 *
 */

