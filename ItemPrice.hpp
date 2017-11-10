//
//  ItemPrice.hpp
//  HW3Tree
//
//  Created by Prathyusha Pillari on 10/21/17.
//  Copyright © 2017 Prathyusha Pillari. All rights reserved.
//

#ifndef ItemPrice_hpp
#define ItemPrice_hpp
#include <string>
#include <stdio.h>
using namespace std;

class ItemPrice{
public:
    ItemPrice();
    ItemPrice(string n, int p);
    ~ItemPrice();
    string name;
    int price;
    
};

#endif /* ItemPrice_hpp */
