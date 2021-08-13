//
//  BinaryTree.hpp
//  Project 5 2250
//
//  Created by Charissa M Martin on 5/2/18.
//  Copyright © 2018 Charissa M Martin. All rights reserved.
//

#ifndef BinaryTree_hpp
#define BinaryTree_hpp
#include <string>



class BinaryTree {
private:
    struct node{
        node * right;
        node * left;
        std::string holder = "";
        int xtimes = 0;
    };
public:
    node * root;
    BinaryTree();
    void output(node *);
    void insert(node *, std::string);
    void increment(node *); //function that will increment xtimes variable
    ~BinaryTree();
};

#include <stdio.h>

#endif /* BinaryTree_hpp */
